<?php

/**
 * @file
 * Forms for managing the import of content from the FTP into Fedora.
 */

require_once dirname(__FILE__) . '/fedora.import.inc';

define('LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS', 'livingstone_fedora_import_add_objects_form_settings');

/**
 * Shows a form for viewing remote objects.
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
  $module_path = drupal_get_path('module', 'livingstone');
  $settings = &livingstone_fedora_import_form_settings(LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS);

  $default_value = function ($field, $default) use ($settings) {
    return isset($settings[$field]) ? $settings[$field] : $default;
  };

  $search = $default_value('search', NULL);
  $search_field = $default_value('search_field', 'PID');

  $types = $default_value('types', array_keys(livingstone_fedora_import_type_titles()));
  $types = array_values(array_filter($types));

  $columns = array('PID', 'TYPE', 'PRIVATE', 'CONTENT_MODEL');
  $header = livingstone_fedora_import_objects_table_header($columns, 'r');

  $sub_query = db_select(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, 'l')
    ->fields('l', array('PID'));

  $query = db_select(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE, 'r')
    ->fields('r', array('PID', 'TYPE', 'PRIVATE', 'CONTENT_MODEL'))
    ->condition('r.PID', $sub_query, 'NOT IN')
    ->condition('TYPE', $types, 'IN');

  if ($search) {
    $query->condition("r.$search_field", '%' . db_like($search) . '%', 'LIKE');
  }

  $rows = $query->extend('PagerDefault')
    ->limit(1000)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->execute()
    ->fetchAllAssoc(0, PDO::FETCH_NUM);

  return array(
    '#attached' => array(
      'css' => array(
        "$module_path/css/import.fedora.object.form.css",
      ),
    ),
    'filter' => array(
      '#type' => 'fieldset',
      '#title' => t('Show only items where'),
      'search_field' => array(
        '#type' => 'select',
        '#title' => t('Field'),
        '#options' => drupal_map_assoc($columns),
        '#default_value' => $search_field,
      ),
      'search' => array(
        '#type' => 'textfield',
        '#title' => t('Contains'),
        '#default_value' => $search,
      ),
      'types' => array(
        '#type' => 'checkboxes',
        '#title' => t('Filter by Type(s)'),
        '#options' => livingstone_fedora_import_type_titles(),
        '#default_value' => $types,
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Update'),
      ),
      'reset' => array(
        '#type' => 'submit',
        '#limit_validation_errors' => TRUE,
        '#value' => t('Reset'),
      ),
    ),
    'operations' => array(
      '#type' => 'fieldset',
      '#title' => t('Operations'),
      'all' => array(
        '#type' => 'submit',
        '#value' => t('Add All'),
      ),
      'selected' => array(
        '#type' => 'submit',
        '#value' => t('Add Selected'),
      ),
    ),
    'table' => array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $rows,
      '#empty' => t('No objects to add.'),
    ),
  );
}

/**
 * Rebuilds the table display or kicks off a batch add process.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_add_objects_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone', 'includes/fedora.import.batch');
  $trigger_element = $form_state['triggering_element']['#value'];
  $settings = &livingstone_fedora_import_form_settings(LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS);
  switch ($trigger_element) {
    case t('Update'):
      foreach (array('search', 'search_field', 'types') as $setting) {
        $settings[$setting] = $form_state['values'][$setting];
      }
      $form_state['rebuild'] = TRUE;
      break;
    case t('Reset'):
      livingstone_fedora_import_reset_form_settings(LIVINGSTONE_ADD_OBJECT_FORM_SETTINGS);
      $form_state['rebuild'] = FALSE;
      break;
    case t('Add All'):
      $batch = livingstone_fedora_import_add_objects_batch();
      batch_set($batch);
      break;
    case t('Add Selected'):
      $batch = livingstone_fedora_import_add_objects_batch(array_filter($form_state['values']['table']));
      batch_set($batch);
      break;
  }
}

/**
 * Shows a form for viewing remote objects.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_update_objects_form(array $form, array &$form_state) {
}
