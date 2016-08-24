<?php

/**
 * @file
 * Forms for managing the import of content from the FTP into Fedora.
 */

require_once dirname(__FILE__) . '/fedora.import.form.objects.inc';
require_once dirname(__FILE__) . '/fedora.import.batch.inc';

define('LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS', 'livingstone_fedora_import_add_objects_form_settings');

/**
 * Shows a form for viewing local objects.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_add_objects_form(array $form, array &$form_state) {
  $columns = array(
    'PID',
    'TYPE',
    'PRIVATE',
    'CONTENT_MODEL',
  );
  $form = livingstone_fedora_import_objects_form($form, $form_state, $columns, LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS);
  $form['operations'] = array(
    '#type' => 'fieldset',
    '#title' => t('Operations'),
    'description' => array(
      '#markup' => t('<p>Due to memory limitations, <strong>only 1000</strong> objects can be processed at any time.</p>'),
    ),
    'all' => array(
      '#type' => 'submit',
      '#value' => t('Add All'),
      '#submit' => array('livingstone_fedora_import_add_objects_form_all_submit'),
    ),
    'selected' => array(
      '#type' => 'submit',
      '#value' => t('Add Selected'),
      '#submit' => array('livingstone_fedora_import_add_objects_form_selected_submit'),
    ),
  );
  $form['top_pager'] = array(
    '#theme' => 'pager',
  );
  $form['table'] = livingstone_fedora_import_add_objects_form_table($columns);
  $form['bottom_pager'] = array(
    '#theme' => 'pager',
  );
  return $form;
}

/**
 * Builds the table for the add objects form.
 * @param $columns
 * @return array
 */
function livingstone_fedora_import_add_objects_form_table($columns) {
  $query = livingstone_fedora_import_add_objects_query();
  $header = livingstone_fedora_import_objects_query_apply_settings($query, LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS, LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS);
  $rows = $query->execute()->fetchAllAssoc(0, PDO::FETCH_NUM);
  return array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#empty' => t('No objects to add.'),
  );
}

/**
 * Adds all the missing objects.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_add_objects_form_all_submit(array $form, array &$form_state) {
  $batch = livingstone_fedora_import_add_objects_batch();
  batch_set($batch);
}

/**
 * Adds selected missing objects.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_add_objects_form_selected_submit(array $form, array &$form_state) {
  $pids = array_filter($form_state['values']['table']);
  if (!empty($pids)) {
    $batch = livingstone_fedora_import_add_objects_batch($pids);
    batch_set($batch);
  }
}
