<?php

/**
 * @file
 * Helper functions for building the local and remote objects forms.
 */

require_once dirname(__FILE__) . '/fedora.import.inc';

/**
 * Gets a reference to the settings for the given form.
 *
 * We store the settings in the $_SESSION for the given user.
 *
 * @param string $settings_identifier
 *   The settings to get.
 *
 * @return array
 *   A reference to the settings storage.
 */
function &livingstone_fedora_import_form_settings($settings_identifier) {
  if (!isset($_SESSION[$settings_identifier])) {
    $_SESSION[$settings_identifier] = array(
      'search' => NULL,
      'search_field' => 'PID',
      'columns' => array('PID', 'TYPE', 'PRIVATE', 'CONTENT_MODEL'),
      'types' => array_keys(livingstone_fedora_import_types()),
    );
  }
  return $_SESSION[$settings_identifier];
}

/**
 * Clears the given form settings.
 *
 * @param string $settings_identifier
 *   The settings to reset.
 */
function livingstone_fedora_import_reset_form_settings($settings_identifier) {
  unset($_SESSION[$settings_identifier]);
}

/**
 * Shows a form for viewing remote objects.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 * @param array $columns
 *   The columns to show in the table.
 * @param string $settings_identifier
 *   The identifier for fetching and storing settings.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_objects_form(array $form, array &$form_state, array $columns, $settings_identifier) {
  form_load_include($form_state, 'inc', 'livingstone_fedora_import', 'fedora.import.form.objects');
  $module_path = drupal_get_path('module', 'livingstone_fedora_import');
  $settings = livingstone_fedora_import_form_settings($settings_identifier);
  $column_options = drupal_map_assoc($columns);
  return array(
    '#attached' => array(
      'css' => array(
        "$module_path/css/fedora.import.object.form.css",
      ),
    ),
    'settings' => array(
      '#type' => 'hidden',
      '#value' => $settings_identifier,
    ),
    'filter' => array(
      '#type' => 'fieldset',
      '#title' => t('Show only items where'),
      'search_field' => array(
        '#type' => 'select',
        '#title' => t('Field'),
        '#options' => $column_options,
        '#default_value' => $settings['search_field'],
      ),
      'search' => array(
        '#type' => 'textfield',
        '#title' => t('Contains'),
        '#default_value' => $settings['search'],
      ),
      'columns' => array(
        '#type' => 'checkboxes',
        '#title' => t('Show Column(s)'),
        '#options' => $column_options,
        '#default_value' => array_values(array_filter($settings['columns'])),
      ),
      'types' => array(
        '#type' => 'checkboxes',
        '#title' => t('Filter by Type(s)'),
        '#options' => livingstone_fedora_import_titles(),
        '#default_value' => $settings['types'],
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Update'),
        '#submit' => array('livingstone_fedora_import_objects_form_update_submit'),
      ),
      'reset' => array(
        '#type' => 'submit',
        '#value' => t('Reset'),
        '#submit' => array('livingstone_fedora_import_objects_form_reset_submit'),
      ),
    ),
  );
}

/**
 * Rebuilds the objects form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_objects_form_update_submit(array $form, array &$form_state) {
  $settings_identifier = $form_state['values']['settings'];
  $settings = &livingstone_fedora_import_form_settings($settings_identifier);
  foreach (array('search_field', 'search', 'columns', 'types') as $setting) {
    $settings[$setting] = $form_state['values'][$setting];
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Resets the objects form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_objects_form_reset_submit(array $form, array &$form_state) {
  $settings_identifier = $form_state['values']['settings'];
  livingstone_fedora_import_reset_form_settings($settings_identifier);
  $form_state['rebuild'] = FALSE;
}

/**
 * Gets the objects table for either remote or local.
 *
 * @param string $table_identifier
 *   The table to perform the Query against.
 * @param string $settings_identifier
 *   The identifier for fetching and storing settings.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_objects_table($table_identifier, $settings_identifier) {
  $table_alias = 't';
  $query = db_select($table_identifier, $table_alias);
  $header = livingstone_fedora_import_objects_query_apply_settings($query, $table_alias, $settings_identifier);
  $rows = $query->execute()->fetchAll(PDO::FETCH_NUM);
  return array(
    'top_pager' => array(
      '#theme' => 'pager',
    ),
    'table' => array(
      '#prefix' => '<div class="livingstone-import-fedora-objects-table">',
      '#suffix' => '</div>',
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#empty' => 'No objects found (Something went wrong).',
    ),
    'bottom_pager' => array(
      '#theme' => 'pager',
    ),
  );
}

/**
 * Apply the form settings to the query and returns a header for table display.
 *
 * @param SelectQuery $query
 *   The query to apply the settings to.
 * @param string $table_alias
 *   The table to apply the display settings to.
 * @param string $settings_identifier
 *   The settings to use in updating the query.
 * @param int $limit
 *   The number of rows to return.
 *
 * @return array
 *    Drupal table header description.
 */
function livingstone_fedora_import_objects_query_apply_settings(SelectQuery &$query, $table_alias, $settings_identifier, $limit = 500) {
  $settings = livingstone_fedora_import_form_settings($settings_identifier);
  $fields = array_values(array_filter($settings['columns']));
  $header = livingstone_fedora_import_objects_table_header($fields, $table_alias);
  $query->fields($table_alias, $fields);
  $query->condition("$table_alias.TYPE", $settings['types'], 'IN');
  if ($settings['search']) {
    $query->condition("$table_alias.{$settings['search_field']}", '%' . db_like($settings['search']) . '%', 'LIKE');
  }
  $query = $query->extend('PagerDefault')->limit($limit);
  $query = $query->extend('TableSort')->orderByHeader($header);
  return $header;
}

/**
 * Creates the header for the given columns.
 *
 * @param array $fields
 *   The columns to include in the header.
 * @param string $table_alias
 *   The alias of the table from which the fields are drawn.
 *
 * @return array
 *   The header as is needed by theme_table().
 */
function livingstone_fedora_import_objects_table_header(array $fields, $table_alias) {
  return array_map(function ($val) use ($table_alias) {
    return array('data' => $val, 'field' => "$table_alias.$val");
  }, $fields);
}
