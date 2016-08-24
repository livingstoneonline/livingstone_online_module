<?php

/**
 * @file
 * Handles the importing of Fedora content from a FTP server.
 */

require_once dirname(__FILE__) . '/utilities.inc';
require_once dirname(__FILE__) . '/batch.inc';
require_once dirname(__FILE__) . '/fedora.import.inc';

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
    'file' => drupal_get_path('module', 'livingstone') . '/includes/fedora.import.batch.inc',
  );
}

/**
 * Updates the the import tables for both remote and local.
 *
 * @param array &$context
 *   The batch context.
 */
function livingstone_fedora_import_update_tables_batch_operation(&$context) {
  livingstone_start_batch_operation_iteration(range(0, 3), $context);
  livingstone_set_progress_message($context, 'Waiting for Solr index to update...');
  sleep(2);
  if (livingstone_end_batch_operation_iteration($context, 1, 'Updated import table.')) {
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
  $query = livingstone_fedora_import_add_objects_query();
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
    $files = array();
    foreach (array_filter($row) as $key => $value) {
      $matches = array();
      if (preg_match('/^(.*)_(FILE|MD5)$/i', $key, $matches)) {
        list(, $dsid, $field) = $matches;
        $files[$dsid][$field] = $value;
      }
    }
    $operations[] = array('livingstone_fedora_import_add_object_batch_operation', array($row['pid'], $row['type'], $row['private'], $files));
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Adding Objects...'),
    'init_message' => t('Preparing to add objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for adding objects to Fedora.
 *
 * @param string $pid
 *   The object identifier.
 * @param string $type
 *   The type of object to add.
 * @param bool $private
 *   If the new object should be private or not.
 * @param array $files
 *   Description of files on the remote server to be downloaded.
 * @param array &$context
 *   The batch context.
 */
function livingstone_fedora_import_add_object_batch_operation($pid, $type, $private, array $files, &$context) {
  list($dsid, $datastream_info) = livingstone_start_batch_operation_iteration($files, $context);
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
          $object_added = livingstone_fedora_import_add_object($pid, $type, $private, $local_files);
        }
        catch (Exception $e) {
          watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
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
    livingstone_continue_batch_operation($context, 'Downloading @file (@progress%)...', array(
      '@file' => $remote_file,
      '@progress' => $progress,
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
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Removing Objects...'),
    'init_message' => t('Preparing to remove objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param string $pid
 *   The object identifier.

 * @param array &$context
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
  $query = livingstone_fedora_import_update_objects_query(array('pid'));
  // we need to compare the datastreams checksums to determine what to update.
  foreach (livingstone_fedora_import_datastreams() as $dsid) {
    $dsid = strtolower($dsid);
    $query->addField(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS, "{$dsid}_md5", "dest_{$dsid}_md5");
    $query->addField(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS, "{$dsid}_md5", "src_{$dsid}_md5");
    $query->addField(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS, "{$dsid}_file");
  }
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
    $files = array();
    foreach ($row as $key => $value) {
      $matches = array();
      if (preg_match('/^(.*)_FILE$/i', $key, $matches)) {
        list(, $dsid) = $matches;
        $files[strtoupper($dsid)]['file']= $value;
      }
      else if (preg_match('/^(SRC|DEST)_(.*)_MD5$/i', $key, $matches)) {
        list(, $location, $dsid) = $matches;
          $files[strtoupper($dsid)]["{$location}_md5"] = $value;
      }
    }
    // Remove file info for files that match.
    foreach ($files as $dsid => $properties) {
      if ($properties['src_md5'] == $properties['dest_md5']) {
        unset($files[strtoupper($dsid)]);
      }
    }
    $operations[] = array('livingstone_fedora_import_update_object_batch_operation', array($row['pid'], $files));
  }
  $operations[] = array('livingstone_fedora_import_update_tables_batch_operation', array());
  return array(
    'operations' => $operations,
    'finished' => 'livingstone_batch_finished',
    'title' => t('Updating Objects...'),
    'init_message' => t('Preparing to update objects...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param string $pid
 *   The object identifier.
 * @param array $files
 *   The datastreams to update.
 * @param array &$context
 *   The batch context.
 */
function livingstone_fedora_import_update_object_batch_operation($pid, array $files, &$context) {
  list($dsid, $datastream_info) = livingstone_start_batch_operation_iteration($files, $context);
  $remote_file = $datastream_info['file'];
  $md5 = $datastream_info['src_md5'];
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
      if (livingstone_fedora_import_add_update_datastream_from_file($object, strtoupper($dsid), $local_file, $md5)) {
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
    livingstone_continue_batch_operation($context, 'Downloading @file (@progress%)...', array(
      '@file' => $remote_file,
      '@progress' => $progress,
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
    'file' => drupal_get_path('module', 'livingstone') . '/includes/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param string $pid
 *   The object identifier.
 * @param bool $private
 *   TRUE to change the the object to private, FALSE to change it to public.
 * @param array &$context
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
 * @return array
 *   The batch definition.
 */
function livingstone_fedora_import_reindex_manuscripts_batch() {
  if (!livingstone_fedora_import_safe_to_run_batch()) {
    return array();
  }
  $pids = livingstone_manuscripts();
  $xml = simplexml_load_file('/opt/fedora/server/config/fedora-users.xml');
  $info = array(
    'url' => variable_get('islandora_base_url', 'http://localhost:8080/fedora') . 'gsearch/rest',
    'user' => (string) $xml->user[0]->attributes()->name,
    'password' => (string) $xml->user[0]->attributes()->password,
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
    'file' => drupal_get_path('module', 'livingstone') . '/includes/fedora.import.batch.inc',
  );
}

/**
 * Batch operation for removing objects from Fedora.
 *
 * @param array $pids
 *   The object identifiers to re-index.
 * @param array $info
 *   Connection information.
 * @param array &$context
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
        'value' => $pid,
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
  livingstone_end_batch_operation_iteration($context, count($group), 'Reindex Solr.');
}