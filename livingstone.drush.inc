<?php

/**
 * @file
 * Implementation of Drush hooks.
 */

/**
 * Implements hook_drush_command().
 */
function livingstone_drush_command() {
  return array(
    'livingstone_import_nodes' => array(
      'description' => 'Imports Fedora content into Drupal Nodes.',
      'drupal dependencies' => array(
        'date',
        'entity',
        'livingstone',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
  );
}

/**
 * Import Drupal content.
 */
function drush_livingstone_import_nodes() {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  module_load_include('inc', 'livingstone', 'includes/node.import.batch');
  $batch = livingstone_node_import_sync_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  drush_backend_batch_process();
}