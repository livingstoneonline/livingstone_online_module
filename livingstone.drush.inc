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
    'livingstone_import_objects' => array(
      'description' => 'Imports files from FTP server into Fedora.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_generate_derivatives' => array(
      'description' => 'Generates missing derivatives.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
  );
}

function drush_livingstone_import_nodes() {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  module_load_include('inc', 'livingstone', 'includes/node.import.batch');
  $batch = livingstone_node_import_sync_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  drush_backend_batch_process();
}

function drush_livingstone_import_objects() {
  module_load_include('inc', 'livingstone', 'includes/fedora.import.batch');
  livingstone_fedora_import_update_tables();
  $batch = livingstone_fedora_import_add_objects_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  $batch = livingstone_fedora_import_remove_objects_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  $batch = livingstone_fedora_import_update_objects_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  $batch = livingstone_fedora_import_publish_objects_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  $batch = livingstone_fedora_import_reindex_manuscripts_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  $batch = livingstone_fedora_import_update_table_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  drush_backend_batch_process();
}

function drush_livingstone_generate_derivatives() {
  module_load_include('inc', 'livingstone', 'includes/derivatives.batch');
  $batch = livingstone_generate_derivatives_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  drush_backend_batch_process();
}