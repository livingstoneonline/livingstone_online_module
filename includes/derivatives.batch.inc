<?php

/**
 * @file
 * Derivative generation.
 */

require_once dirname(__FILE__) . '/utilities.inc';
require_once dirname(__FILE__) . '/batch.inc';

/**
 * Generates missing derivatives.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_generate_derivatives_batch() {
  $query = <<<EOT
SELECT DISTINCT ?object WHERE {
    ?object <fedora-model:hasModel> <info:fedora/livingstone:spectralManuscriptPageCModel> .
    ?object <fedora-view:disseminates> ?src_dsid .
    ?src_dsid <fedora-view:mimeType>  "image/tiff" .
    OPTIONAL {
      ?object <fedora-view:disseminates> ?dest_dsid .
      ?dest_dsid <fedora-view:mimeType>  "image/jp2" .
    }
    FILTER (!BOUND(?dest_dsid))
}
EOT;
  $connection = islandora_get_tuque_connection();
  $results = $connection->repository->ri->sparqlQuery($query);
  // Get rid of the "extra" info...
  $map = function($result) {
    return $result['object']['value'];
  };
  $pids = array_map($map, $results);
  $operations = array();
  foreach ($pids as $pid) {
    $operations[] = array('livingstone_generate_derivatives_batch_operation', array($pid));
  }
  return array(
    'title' => t('Regenerating derivatives.'),
    'operations' => $operations,
    'init_message' => t('Preparing to regenerate derivatives...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/derivatives.batch.inc',
    'finished' => 'livingstone_batch_finished',
  );
}

/**
 * Updates the the import tables for both remote and local.
 *
 * @param string $pid
 *   The identifier.
 * @param &$context
 *   The batch context.
 */
function livingstone_generate_derivatives_batch_operation($pid, &$context) {
  module_load_include('inc', 'islandora', 'includes/derivatives');
  $object = islandora_object_load($pid);
  islandora_remove_defer_derivatives_flag($object);
  $options = array(
    'force' => FALSE,
  );
  $derivatives = islandora_get_derivative_list($object, $options);
  list(,$derivative) = livingstone_start_batch_operation_iteration($derivatives, $context);
  $file = FALSE;
  if (isset($derivative['file'])) {
    $file = $derivative['file'];
  }
  foreach ($derivative['function'] as $function) {
    if ($file) {
      require_once "$file";
    }
    if (function_exists($function)) {
      $logging = call_user_func($function, $object, FALSE, $derivative);
      if (!empty($logging)) {
        $context['results']['logging'][] = $logging;
      }
    }
    else {
      watchdog(LIVINGSTONE_DATASTREAM_GENERATION_ERROR, 'Unable to call derivative function @function as it was not found!', array('@function' => $function), WATCHDOG_ERROR);
    }
  }
  livingstone_end_batch_operation_iteration($context, 1, 'Updated object: @pid', array(
    '@pid' => $pid
  ));
}
