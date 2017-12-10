<?php

/**
 * @file
 * Handles the importing of Fedora content from a FTP server.
 */

require_once drupal_get_path('module', 'livingstone') . '/includes/batch.inc';
require_once dirname(__FILE__) . '/fedora.import.inc';

const LIVINGSTONE_SOLR_REINDEX_CID = 'livingstone-solr-reindex';

/**
 * Updates the import table.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_update_table_batch() {
  return array(
    'operations' => array(
      array('livingstone_fedora_import_update_tables_batch_operation', array()),
    ),
    'finished' => 'livingstone_batch_finished',
    'title' => t('Updating the Import table...'),
    'init_message' => t('Preparing to update the import table...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Updates the the import tables for both remote and local.
 *
 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_update_tables_batch_operation(&$context) {
  livingstone_start_batch_operation_iteration(range(0, 3), $context);
  livingstone_set_progress_message($context, 'Waiting for Solr index to update...');
  sleep(2);
  if (livingstone_end_batch_operation_iteration($context, 1, 'Updated import table.')) {
    livingstone_set_progress_message($context, 'Updating import tables...');
    livingstone_fedora_import_update_tables();
  }
}

/**
 * Adds the given objects, or all missing objects if none given.
 *
 * @param array $pids
 *   The objects to add, if not given then all missing objects will be added.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_add_objects_batch(array $pids = NULL) {
  if (!livingstone_fedora_import_safe_to_run_batch()) {
    return array();
  }
  if (empty($pids)) {
    $query = livingstone_fedora_import_add_objects_query();
    $results = $query->execute();
    $pids = $results->fetchCol(0);
  }
  foreach($pids as $pid) {
    $operations[] = array(
      'livingstone_fedora_import_add_object_batch_operation',
      array($pid)
    );
    livingstone_fedora_import_add_parent_to_solr_reindex_cache($pid);
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Adding Objects...'),
    'init_message' => t('Preparing to add objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for adding objects to Fedora.
 *
 * @param string $pid
 *   The object identifier.
 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_add_object_batch_operation($pid, &$context) {
  $info = livingstone_fedora_import_object_information($pid);
  list($dsid, $datastream_info) = livingstone_start_batch_operation_iteration($info['datastreams'], $context);
  $remote_file = $datastream_info['file'];
  $md5 = $datastream_info['md5'];
  $cache = &livingstone_batch_operation_cache($context);
  if (!isset($cache[$dsid])) {
    // Check that the object doesn't exist to save time.
    if (islandora_object_load($pid)) {
      livingstone_exit_batch_operation($context, FALSE, 'Object: @pid already exists.', array(
        '@pid' => $pid,
      ));
      return;
    }
    // Start the download.
    $cache[$dsid] = livingstone_fedora_import_start_ftp_download($remote_file);
    list($local_file, $output_file) = $cache[$dsid];
    // Keep reference to files so they get cleaned up.
    livingstone_batch_track_file($local_file, $context);
    livingstone_batch_track_file($output_file, $context);
    livingstone_continue_batch_operation($context, 'Downloading @file...', array(
      '@file' => $remote_file,
    ));
    return;
  }
  // Check on progress.
  list($local_file, $output_file, $process_id) = $cache[$dsid];
  if (livingstone_fedora_import_finished_ftp_download($process_id)) {
    // Successfully downloaded one file.
    if (livingstone_fedora_import_successful_ftp_download($local_file, $remote_file, $md5)) {
      // Successfully downloaded all the files.
      if (livingstone_end_batch_operation_iteration($context, 1)) {
        // Map to simple list of real paths for processing.
        $local_files = array();
        foreach ($cache as $dsid => $cache_info) {
          list($local_file) = $cache_info;
          $local_files[strtoupper($dsid)] = $local_file;
        }
        $object_added = FALSE;
        try {
          $object_added = livingstone_fedora_import_add_object($pid, $info['type'], $info['private'], $local_files);
        }
        catch (Exception $e) {
          watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
        }
        // Cleanup temporary files.
        foreach ($cache as $dsid => $cache_info) {
          list($local_file, $output_file) = $cache_info;
          livingstone_batch_untrack_file($local_file, $context);
          livingstone_batch_untrack_file($output_file, $context);
          file_delete($local_file);
          file_delete($output_file);
        }
        if ($object_added) {
          livingstone_exit_batch_operation($context, TRUE, 'Added object: @pid', array(
            '@pid' => $pid,
          ));

          return;
        }
        else {
          livingstone_exit_batch_operation($context, FALSE, 'Failed to add object: @pid.', array(
            '@pid' => $pid,
          ));
          return;
        }
      }
    }
    else {
      // Failed to download a single file, abort.
      livingstone_exit_batch_operation($context, FALSE, 'Failed to download @file for object: @pid.', array(
        '@file' => $remote_file,
        '@pid' => $pid,
      ));
      return;
    }
  }
  else {
    $progress = livingstone_fedora_import_ftp_download_progress($output_file);
    livingstone_continue_batch_operation($context, 'Downloading @file (@download%)...', array(
      '@file' => $remote_file,
      '@download' => $progress,
    ));
    $batch = batch_get();
    if ($batch['progressive']) {
      sleep(1);
    }
  }
}

/**
 * Removes the given objects, or all stale objects if none given.
 *
 * @param array $pids
 *   The objects to remove, if not given then all stale objects will be removed.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_remove_objects_batch(array $pids = NULL) {
  if (!livingstone_fedora_import_safe_to_run_batch()) {
    return array();
  }
  $query = livingstone_fedora_import_remove_objects_query(array('PID'));
  $removable_pids = $query->execute()->fetchCol(0);
  if (is_array($pids)) {
    $removable_pids = array_intersect($removable_pids, $pids);
  }
  foreach ($removable_pids as $pid) {
    $operations[] = array('livingstone_fedora_import_remove_object_batch_operation', array($pid));
    livingstone_fedora_import_add_parent_to_solr_reindex_cache($pid);
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Removing Objects...'),
    'init_message' => t('Preparing to remove objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param string $pid
 *   The object identifier.

 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_remove_object_batch_operation($pid, &$context) {
  livingstone_start_batch_operation_iteration(array(), $context);
  if (islandora_delete_object(islandora_object_load($pid))) {
    livingstone_exit_batch_operation($context, TRUE, 'Removed object: @pid.', array(
      '@pid' => $pid,
    ));
  }
  else {
    livingstone_exit_batch_operation($context, FALSE, 'Failed to remove object: @pid.', array(
      '@pid' => $pid,
    ));
  }
}

/**
 * Updates given objects, or all objects which require updates if none given.
 *
 * @param array $pids
 *   The objects to update, if not given then all stale objects will be updated.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_update_objects_batch(array $pids = NULL) {
  if (!livingstone_fedora_import_safe_to_run_batch()) {
    return array();
  }
  if (empty($pids)) {
    $pids = livingstone_fedora_import_update_objects_query()
      ->execute()
      ->fetchCol(0);
  }
  foreach ($pids as $pid) {
    $operations[] = array(
      'livingstone_fedora_import_update_object_batch_operation',
      array($pid),
    );
    livingstone_fedora_import_add_parent_to_solr_reindex_cache($pid);
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Updating Objects...'),
    'init_message' => t('Preparing to update objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param string $pid
 *   The object identifier.
 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_update_object_batch_operation($pid, &$context) {
  $info = livingstone_fedora_import_update_object_information($pid);
  list($dsid, $datastream_info) = livingstone_start_batch_operation_iteration($info['datastreams'], $context);
  $remote_file = $datastream_info['file'];
  $md5 = $datastream_info['md5'];
  $cache = &livingstone_batch_operation_cache($context);
  if (!isset($cache[$dsid])) {
    // Check that the object doesn't exist to save time.
    $object = islandora_object_load($pid);
    if (!$object) {
      livingstone_exit_batch_operation($context, FALSE, 'Object: @pid does not exist.', array(
        '@pid' => $pid,
      ));
      return;
    }
    // No download needed we are to remove the local datastream.
    if (empty($remote_file) && isset($object[$dsid])) {
      try {
        $object->purgeDatastream($dsid);
      }
      catch (Exception $e) {
        watchdog(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
      }
      livingstone_end_batch_operation_iteration($context, 1, 'Updated object: @pid', array(
        '@pid' => $pid
      ));
      return;
    }
    // Start the download.
    $cache[$dsid] = livingstone_fedora_import_start_ftp_download($remote_file);
    list($local_file, $output_file) = $cache[$dsid];
    // Keep reference to files so they get cleaned up.
    livingstone_batch_track_file($local_file, $context);
    livingstone_batch_track_file($output_file, $context);
    livingstone_continue_batch_operation($context, 'Downloading @file...', array(
      '@file' => $remote_file,
    ));
    return;
  }
  // Check on progress.
  list($local_file, $output_file, $process_id) = $cache[$dsid];
  if (livingstone_fedora_import_finished_ftp_download($process_id)) {
    // Successfully downloaded one file.
    if (livingstone_fedora_import_successful_ftp_download($local_file, $remote_file, $md5)) {
      $object = islandora_object_load($pid);
      // Add / Update the datastream.
      $success = livingstone_fedora_import_add_update_datastream_from_file($object, strtoupper($dsid), $local_file, $md5);
      // Clean up temporary files.
      livingstone_batch_untrack_file($local_file, $context);
      livingstone_batch_untrack_file($output_file, $context);
      file_delete($local_file);
      file_delete($output_file);
      if ($success) {
        livingstone_end_batch_operation_iteration($context, 1, 'Updated object: @pid', array(
          '@pid' => $pid
        ));
        return;
      }
      else {
        // Failed to download a single file, abort.
        livingstone_exit_batch_operation($context, FALSE, 'Failed to download @file for object: @pid.', array(
          '@file' => $remote_file,
          '@pid' => $pid,
        ));
        return;
      }
    }
    else {
      // Failed to download a single file, abort.
      livingstone_exit_batch_operation($context, FALSE, 'Failed to download @file for object: @pid.', array(
        '@file' => $remote_file,
        '@pid' => $pid,
      ));
      return;
    }
  }
  else {
    $progress = livingstone_fedora_import_ftp_download_progress($output_file);
    livingstone_continue_batch_operation($context, 'Downloading @file (@download%)...', array(
      '@file' => $remote_file,
      '@download' => $progress,
    ));
    $batch = batch_get();
    if ($batch['progressive']) {
      sleep(1);
    }
  }
}

/**
 * Publishes / conceals the given objects, or all stale objects if none given.
 *
 * @param array $pids
 *   The objects to publish, if not given all will be published
 *   (where applicable).
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_publish_objects_batch(array $pids = NULL) {
  if (!livingstone_fedora_import_safe_to_run_batch()) {
    return array();
  }
  $query = livingstone_fedora_import_publish_objects_query(array('pid', 'private'));
  $filter_pids = !empty($pids);
  // Due to memory limitations we can only process 1000 at a time, the
  // operations array becomes to large.
  if (!$filter_pids) {
    $query = $query->extend('PagerDefault')->limit(1000);
  }
  $results = $query->execute();
  $operations = array();
  while ($row = $results->fetchAssoc()) {
    if ($filter_pids && !in_array($row['pid'], $pids)) {
      continue;
    }
    $operations[] = array('livingstone_fedora_import_publish_object_batch_operation', array($row['pid'], $row['private']));
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Publishing / Concealing Objects...'),
    'init_message' => t('Preparing to publish /conceal objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param string $pid
 *   The object identifier.
 * @param bool $private
 *   TRUE to change the the object to private, FALSE to change it to public.
 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_publish_object_batch_operation($pid, $private, &$context) {
  livingstone_start_batch_operation_iteration(array(), $context);
  $object = islandora_object_load($pid);
  if (!$object) {
    livingstone_exit_batch_operation($context, FALSE, ' Object: @pid does not exist.', array('@pid' => $pid));
  }
  if ($private && isset($object['POLICY'])) {
  }
  if (!$private && empty($object['POLICY'])) {
    livingstone_exit_batch_operation($context, FALSE, 'Object: @pid is already public.', array('@pid' => $pid));
  }
  if ($private) {
    if (livingstone_fedora_import_make_private($object)) {
      livingstone_exit_batch_operation($context, TRUE, 'Object: @pid is now private.', array('@pid' => $pid));
    }
    else {
      livingstone_exit_batch_operation($context, FALSE, 'Failed to make Object: @pid private.', array('@pid' => $pid));
    }
  }
  else {
    if (livingstone_fedora_import_make_public($object)) {
      livingstone_exit_batch_operation($context, TRUE, 'Object: @pid is now public.', array('@pid' => $pid));
    }
    else {
      livingstone_exit_batch_operation($context, FALSE, 'Failed to make Object: @pid public.', array('@pid' => $pid));
    }
  }
}

/**
 * Re-index the manuscripts objects.
 *
 * @param bool $force
 *   If TRUE re-index all the manuscripts.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_reindex_manuscripts_batch($force = FALSE) {
  if (!livingstone_fedora_import_safe_to_run_batch()) {
    return array();
  }
  // Re-index all manuscripts.
  if ($force) {
    module_load_include('inc', 'livingstone', 'includes/utilities');
    $pids = livingstone_manuscripts();
  }
  else {
    $cache = cache_get(LIVINGSTONE_SOLR_REINDEX_CID);
    $pids = ($cache !== FALSE) ? $cache->data : array();
  }
  $info = array(
    'url' => variable_get('islandora_base_url', 'http://localhost:8080/fedora') . 'gsearch/rest',
    'user' => variable_get('fedora_admin_user', 'fedoraAdmin'),
    'password' => variable_get('fedora_admin_password', ''),
  );
  return array(
    'operations' => array(
      array('livingstone_fedora_import_reindex_manuscripts_batch_operation', array($pids, $info)),
    ),
    'finished' => 'livingstone_batch_finished',
    'title' => t('Updating Objects indexes...'),
    'init_message' => t('Preparing to update indexes...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param array $pids
 *   The object identifiers to re-index.
 * @param array $info
 *   Connection information.
 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_reindex_manuscripts_batch_operation(array $pids, array $info, &$context) {
  list($pos, $pid) = livingstone_start_batch_operation_iteration($pids, $context);
  $group = array_slice($pids, $pos, 5);
  foreach ($group as $pid) {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_USERPWD, "{$info['user']}:{$info['password']}");
    curl_setopt($ch, CURLOPT_URL, url($info['url'], array(
      'absolute' => TRUE,
      'query' => array(
        'operation' => 'updateIndex',
        'action' => 'fromPid',
        'value' => urlencode($pid),
      ),
    )));
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_exec($ch);
    curl_close($ch);
  }
  livingstone_set_progress_message($context, 'Indexing @pid (@pos of @count)', array(
    '@pid' => $pid,
    '@pos' => $pos + count($group),
    '@count' => count($pids),
  ));
  if (livingstone_end_batch_operation_iteration($context, count($group), 'Reindex Solr.')) {
    cache_clear_all(LIVINGSTONE_SOLR_REINDEX_CID, 'cache');
  }
}

/**
 * Re-index the manuscripts objects.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_missing_derivatives_batch() {
  $types = livingstone_fedora_import_types();
  $pids = array();
  foreach ($types as $key => $type) {
    if ($key == 'spectral_manuscript_page') {
      $pids = array_merge($pids, livingstone_fedora_import_spectral_page_derivatives_missing());
    }
    else {
      $pids = array_merge($pids, livingstone_fedora_import_derivatives_missing($type['content_model'], $type['derived_datastreams']));
    }
  }
  return array(
    'operations' => array(
      array('livingstone_fedora_import_missing_derivatives_batch_operation', array($pids)),
    ),
    'finished' => 'livingstone_batch_finished',
    'title' => t('Generating derivatives...'),
    'init_message' => t('Preparing to generating derivatives...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone_fedora_import') . '/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param array $pids
 *   The object identifiers to re-index.
 * @param &$context
 *   The batch context.
 */
function livingstone_fedora_import_missing_derivatives_batch_operation(array $pids, array &$context) {
  module_load_include('inc', 'islandora', 'includes/derivatives');
  list($pos, $pid) = livingstone_start_batch_operation_iteration($pids, $context);
  $group = array_slice($pids, $pos, 1);
  foreach ($group as $pid) {
    $object = islandora_object_load($pid);
    if ($object) {
      $sources = livingstone_fedora_import_sources_missing_derivatives($object);
      foreach ($sources as $source) {
        islandora_run_derivatives($object, $source);
      }
    }
  }
  livingstone_set_progress_message($context, 'Generating derivatives for @pid (@pos of @count)', array(
    '@pid' => $pid,
    '@pos' => $pos + count($group),
    '@count' => count($pids),
  ));
  livingstone_end_batch_operation_iteration($context, count($group), 'Generated Derivatives.');
}

/**
 * Gets the list of datastreams the given object is missing.
 */
function livingstone_fedora_import_sources_missing_derivatives(AbstractObject $object) {
  if (in_array('livingstone:spectralManuscriptPageCModel', $object->models)) {
    $datastreams = array();
    $datastream_prefixes = array(
      'OBJ' => array(),
      'JP2' => array(),
    );
    foreach ($object as $dsid => $datastream) {
      $matches = array();
      if (preg_match('/^(.*)_(OBJ|JP2)$/', $dsid, $matches)) {
        $prefix = $matches[1];
        $suffix = $matches[2];
        $datastream_prefixes[$suffix][] = $prefix;
      }
    }
    $missing = array_diff($datastream_prefixes['OBJ'], $datastream_prefixes['JP2']);
    foreach ($missing as $prefix) {
      $datastreams[] = "{$prefix}_OBJ";
    }
    return $datastreams;
  }
  return array('OBJ');
}

/**
 * Gets the PIDs of the given content model which are missing derivatives.
 *
 * @param string $content_model
 *   The content model of search.
 * @param array $datastreams
 *   The derivatives to check for.
 *
 * @return array
 *   The PID's of objects missing datastreams for the given content model.
 */
function livingstone_fedora_import_derivatives_missing($content_model, array $datastreams) {
  if (empty($datastreams)) {
    return array();
  }
  $filter_queries = array();
  foreach ($datastreams as $datastream) {
    $filter_queries[] = "(fedora_datastreams_ms:[* TO *] -fedora_datastreams_ms:$datastream)";
  }
  $params = array(
    'fl' => 'PID',
    'fq' => implode(' OR ', $filter_queries),
    'defType' => 'edismax',
  );
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search("RELS_EXT_hasModel_uri_s:\"info:fedora/$content_model\"", 0, 10000, $params, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  $response = isset($results) ? json_decode($results->getRawResponse(), TRUE) : array(
    'response' => array(
      'docs' => array(),
    ),
  );
  $pids = array();
  foreach ($response['response']['docs'] as $doc) {
    $pids[] = $doc['PID'];
  }
  return $pids;
}

/**
 * Spectral pages are a special case since there derivatives are unique to each.
 */
function livingstone_fedora_import_spectral_page_derivatives_missing() {
  $params = array(
    'fl' => 'PID,fedora_datastreams_ms',
  );
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search('RELS_EXT_hasModel_uri_s:"info:fedora/livingstone:spectralManuscriptPageCModel"', 0, 10000, $params, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  $response = isset($results) ? json_decode($results->getRawResponse(), TRUE) : array(
    'response' => array(
      'docs' => array(
      ),
    ),
  );
  $pids = array();
  foreach ($response['response']['docs'] as $doc) {
    // The number of datastreams should be divisible by 4.
    $datastreams = array_diff($doc['fedora_datastreams_ms'], array('AUDIT', 'DC', 'RELS-EXT', 'ZIP', 'GIF'));
    $sources = array_filter($datastreams, function($datastream) { return strpos($datastream, '_JP2') !== FALSE; });
    $derivatives = array_filter($datastreams, function($datastream) { return strpos($datastream, '_JP2') !== FALSE; });
    if (count($sources) !== count($derivatives)) {
      $pids[] = $doc['PID'];
    }
  }
  return $pids;
}

/**
 * Adds the given objects's parent object to the cache for re-indexing.
 *
 * @param string $pid
 *   The PID of the object to whose parent needs to be re-indexed.
 */
function livingstone_fedora_import_add_parent_to_solr_reindex_cache($pid) {
  $parent = preg_replace('/^(liv:[0-9]{6}).*$/', '$1', $pid);
  $cache = cache_get(LIVINGSTONE_SOLR_REINDEX_CID);
  $data = ($cache !== FALSE) ? $cache->data : array();
  if (!in_array($parent, $data)) {
    $data[] = $parent;
    cache_set(LIVINGSTONE_SOLR_REINDEX_CID, $data);
  }
}
