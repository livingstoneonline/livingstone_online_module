<?php

/**
 * @file
 * Handles the importing of Fedora content as Drupal Nodes via Solr.
 */

/**
 * Sets up a batch operation.
 *
 * @param array $operands
 *   All the pages to operate on.
 * @param array $context
 *   The context of this batch operation.
 * @param array $message
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed when the batch is finished. Placeholders include, but are not
 *   limited to: @successful, @failed, @total.
 *
 * @return mixed
 *   The current operand the operation will process.
 */
function livingstone_node_import_start_batch_operation(array $operands, &$context, array $message = array()) {
  if (!isset($context['sandbox']['progress'])) {
    $results =& $context['results'];
    if (empty($results)) {
      // "files" will be deleted upon failure or success of the batch.
      // "successful" an array of boolean values indicating operation success.
      // "messages" array of messages to display on finishing the batch
      // values are used as parameters to t() and drupal_set_message().
      $results = array(
        'files' => array(),
        'successful' => array(),
        'messages' => array(),
      );
    }
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['total'] = count($operands);
    $context['results']['messages'][] = $message;
  }
  $operand_index = $context['sandbox']['progress'];
  return isset($operands[$operand_index]) ? $operands[$operand_index] : FALSE;
}

/**
 * Ends the batch operation.
 *
 * @param array $context
 *   The context of this batch operation.
 * @param int $count
 *   The number of steps taken in the operation, typically 1.
 * @param array $message
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed when the batch is finished.
 *
 * @see islandora_paged_contnet_start_batch_operation()
 *
 * @return bool
 *   TRUE if the batch operation is complete, FALSE otherwise.
 */
function livingstone_node_import_end_batch_operation(&$context, $count = 1, $message = array()) {
  $context['sandbox']['progress'] += $count;
  if ($context['sandbox']['progress'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['total'];
    return FALSE;
  }
  $context['results']['messages'][] = $message;
  return TRUE;
}

/**
 * The batch 'finished' callback.
 */
function livingstone_node_import_batch_finished($success, $results, $operations) {
  if ($success) {
    // Delete any lingering files.
    if (isset($results['files'])) {
      foreach ($results['files'] as $file) {
        if (file_exists($file)) {
          file_unmanaged_delete($file);
        }
      }
    }
    // Build generic place holders for the message.
    if (isset($results['successful'])) {
      $total = count($results['successful']);
      $successful = count(array_filter($results['successful']));
      $failed = $total - $successful;
      $place_holders = array(
        '@successful' => $successful,
        '@failed' => $failed,
        '@total' => $total,
      );
      // Display all messages/errors/warnings.
      $messages = array_filter($results['messages']);
      foreach ($messages as $message) {
        $vars = isset($message[1]) ? array_merge($message[1], $place_holders) : $place_holders;
        $status = isset($message[2]) ? $message[2] : 'status';
        $message = format_string($message[0], $vars);
        drupal_set_message(check_plain($message), $status);
      }
    }
  }
  else {
    // Generic Error Message.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
                 '%error_operation' => $error_operation[0],
                 '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}

/**
 * This defines a batch to import all the Fedora manuscript nodes into Drupal.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_node_import_delete_all_batch() {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $nodes = livingstone_node_import_list_nodes();
  $remove = array_values($nodes);
  return array(
    'operations' => array(
      array('livingstone_node_import_remove_nodes_batch_operation', array($remove)),
    ),
    'finished' => 'livingstone_node_import_batch_finished',
    'title' => t('Removing content...'),
    'init_message' => t('Preparing to remove content...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/node.import.batch.inc',
  );
}

/**
 * This defines a batch to import all the Fedora manuscript nodes into Drupal.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_node_import_sync_batch() {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $pids = livingstone_node_import_list_pids();
  $nodes = livingstone_node_import_list_nodes();
  // Remove nodes whose pids are no longer in Fedora.
  $remove = array_values(array_diff($nodes, $pids));
  $import = array_diff($pids, $nodes);
  $update = array_intersect($pids, $nodes);
  // Execute Solr Query.
  return array(
    'operations' => array(
      array('livingstone_node_import_remove_nodes_batch_operation', array($remove)),
      array('livingstone_node_import_import_nodes_batch_operation', array($import)),
      array('livingstone_node_import_update_nodes_batch_operation', array($update)),
    ),
    'finished' => 'livingstone_node_import_batch_finished',
    'title' => t('Importing content...'),
    'init_message' => t('Preparing to import content...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/node.import.batch.inc',
  );
}

/**
 * Batch operation for removing nodes that should no longer exist.
 *
 * Nodes which have PID's that are not included in the solr search results are
 * to be removed.
 */
function livingstone_node_import_remove_nodes_batch_operation(array $pids, &$context) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $pid = livingstone_node_import_start_batch_operation($pids, $context);
  $node = livingstone_node_import_node_load($pid);
  if ($node) {
    node_delete($node);
    $context['message'] = t('Remove node @page of @total...', array(
      '@page' => $context['sandbox']['progress'],
      '@total' => $context['sandbox']['total']));
    $finished_message = array('Removed @count nodes.', array('@count' => count($pids)));
    livingstone_node_import_end_batch_operation($context, 1, $finished_message);
  }
}

/**
 * Batch operation for updating nodes.
 */
function livingstone_node_import_import_nodes_batch_operation(array $pids, &$context) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $pid = livingstone_node_import_start_batch_operation($pids, $context);
  if ($pid) {
    livingstone_node_import($pid);
    $context['message'] = t('Imported node @page of @total...', array(
      '@page' => $context['sandbox']['progress'],
      '@total' => $context['sandbox']['total']));
    $finished_message = array('Imported @count nodes.', array('@count' => count($pids)));
    livingstone_node_import_end_batch_operation($context, 1, $finished_message);
  }
}

/**
 * Batch operation for updating nodes.
 */
function livingstone_node_import_update_nodes_batch_operation(array $pids, &$context) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $pid = livingstone_node_import_start_batch_operation($pids, $context);
  if ($pid) {
    livingstone_node_import_update($pid);
    $context['message'] = t('Updated node @page of @total...', array(
      '@page' => $context['sandbox']['progress'],
      '@total' => $context['sandbox']['total']));
    $finished_message = array('Removed @count nodes.', array('@count' => count($pids)));
    livingstone_node_import_end_batch_operation($context, 1, $finished_message);
  }
}