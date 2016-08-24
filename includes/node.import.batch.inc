<?php

/**
 * @file
 * Handles the importing of Fedora content as Drupal Nodes via Solr.
 */

require_once dirname(__FILE__) . '/batch.inc';
require_once dirname(__FILE__) . '/node.import.inc';

/**
 * This defines a batch to import all the Fedora manuscript nodes into Drupal.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_node_import_remove_all_manuscript_nodes_batch() {
  $query = db_select('node', 'n');
  $query->addField('f', 'pid_value', 'pid');
  $query->addJoin('INNER', 'field_data_pid', 'f', 'f.entity_id = n.nid');
  $query->condition('f.entity_type', 'node');
  $query->condition('n.type', 'manuscript');
  $count = $query->countQuery()->execute()->fetchField();
  return array(
    'operations' => array(
      array('livingstone_node_import_remove_all_manuscript_nodes_batch_operation', array($count)),
    ),
    'finished' => 'livingstone_batch_finished',
    'title' => t('Removing content...'),
    'init_message' => t('Preparing to remove content...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'livingstone') . '/includes/node.import.batch.inc',
  );
}

/**
 * Batch operation for removing all manuscript nodes.
 *
 * @param int $total
 *   The number of nodes to remove.
 *
 * @param array &$context
 *   The batch context.
 */
function livingstone_node_import_remove_all_manuscript_nodes_batch_operation($total, &$context) {
  $removed = livingstone_start_batch_operation_iteration($total, $context);
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->condition('n.type', 'manuscript');
  $nids = $query->extend('PagerDefault')->limit(500)->execute()->fetchCol(0);
  $count = count($nids);
  try {
    node_delete_multiple($nids);
    $args = array('@removed' => $removed + $count, '@total' => $total);
    livingstone_set_progress_message($context, 'Removing @removed of @total Manuscript Nodes.', $args);
    if (livingstone_end_batch_operation_iteration($context, $count)) {
      livingstone_append_result_message($context, 'Removed @removed of @total Manuscript Nodes.', $args);
    }
  }
  catch (Exception $e) {
    $args = array('@removed' => $removed, '@total' => $total);
    livingstone_exit_batch_operation($context, FALSE, 'Removed @removed of @total Manuscript Nodes.', $args);
  }
}

/**
 * This defines a batch to import all the Fedora manuscript nodes into Drupal.
 *
 * @return array
 *   The batch definition.
 */
function livingstone_node_import_sync_batch() {
  $pids = livingstone_node_import_list_pids();
  $nodes = livingstone_node_import_list_nodes();
  // Remove nodes whose pids are no longer in Fedora.
  $remove = array_values(array_diff($nodes, $pids));
  $import = array_diff($pids, $nodes);
  $update = array_intersect($pids, $nodes);
  $operations = array();
  if (count($remove)) {
    $operations[] = array('livingstone_node_import_remove_nodes_batch_operation', array($remove));
  }
  if (count($import)) {
    $operations[] = array('livingstone_node_import_import_nodes_batch_operation', array($import));
  }
  if (count($update)) {
    $operations[] = array('livingstone_node_import_update_nodes_batch_operation', array($update));
  }
  // Execute Solr Query.
  return array(
    'operations' => $operations,
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
 *
 * @param array $pids
 *   The nodes to remove identified by PID.
 *
 * @param array &$context
 *   The batch context.
 */
function livingstone_node_import_remove_nodes_batch_operation(array $pids, &$context) {
  list(, $pid) = livingstone_start_batch_operation_iteration($pids, $context);
  livingstone_set_progress_message($context, 'Removing @progress of @total Manuscript Nodes.');
  $node = livingstone_node_import_node_load($pid);
  if ($node) {
    node_delete($node->nid);
  }
  livingstone_end_batch_operation_iteration($context, 1, 'Removed @removed Manuscript Nodes.', array(
    '@removed' => count($pids),
  ));
}


/**
 * Batch operation for updating nodes.
 *
 * @param array $pids
 *   The nodes to remove identified by PID.
 *
 * @param array &$context
 *   The batch context.
 */
function livingstone_node_import_import_nodes_batch_operation(array $pids, &$context) {
  list(,$pid) = livingstone_start_batch_operation_iteration($pids, $context);
  livingstone_set_progress_message($context, 'Importing @progress of @total Manuscript Nodes.');
  if ($pid) {
    livingstone_node_import($pid);
  }
  livingstone_end_batch_operation_iteration($context, 1, 'Imported @count Manuscript Nodes.', array(
    '@count' => count($pids)
  ));
}

/**
 * Batch operation for updating nodes.
 *
 * @param array $pids
 *   The nodes to remove identified by PID.
 *
 * @param array &$context
 *   The batch context.
 */
function livingstone_node_import_update_nodes_batch_operation(array $pids, &$context) {
  list(,$pid) = livingstone_start_batch_operation_iteration($pids, $context);
  livingstone_set_progress_message($context, 'Updating @progress of @total Manuscript Nodes.');
  if ($pid) {
    livingstone_node_import_update($pid);
  }
  livingstone_end_batch_operation_iteration($context, 1, 'Updated @count Manuscript Nodes.', array(
    '@count' => count($pids)
  ));
}