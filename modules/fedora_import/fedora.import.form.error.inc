<?php

/**
 * @file
 * Forms for managing the import of content from the FTP into Fedora.
 */

require_once dirname(__FILE__) . '/fedora.import.inc';

define('LIVINGSTONE_ERROR_FORM_SETTINGS', 'livingstone_fedora_import_error_form_settings');

/**
 * Shows form and table for viewing relevant errors in the watchdog.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_error_form(array $form, array &$form_state) {
  $rows = array();
  $classes = array(
    WATCHDOG_DEBUG     => 'dblog-debug',
    WATCHDOG_INFO      => 'dblog-info',
    WATCHDOG_NOTICE    => 'dblog-notice',
    WATCHDOG_WARNING   => 'dblog-warning',
    WATCHDOG_ERROR     => 'dblog-error',
    WATCHDOG_CRITICAL  => 'dblog-critical',
    WATCHDOG_ALERT     => 'dblog-alert',
    WATCHDOG_EMERGENCY => 'dblog-emerg',
  );

  $header = array(
    '', // Icon column.
    array('data' => t('Date'), 'field' => 'w.wid', 'sort' => 'desc'),
    t('Message'),
    array('data' => t('User'), 'field' => 'u.name'),
  );

  $query = db_select('watchdog', 'w')->extend('PagerDefault')->extend('TableSort');
  $query->leftJoin('users', 'u', 'w.uid = u.uid');
  $query->fields('w', array('wid', 'uid', 'severity', 'timestamp', 'message', 'variables', 'link', 'type'))
    ->condition('w.type', LIVINGSTONE_FEDORA_IMPORT_ERROR)
    ->addField('u', 'name');
  $result = $query
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  foreach ($result as $dblog) {
    $rows[] = array('data' =>
      array(
        // Cells
        array('class' => 'icon'),
        format_date($dblog->timestamp, 'short'),
        theme('dblog_message', array('event' => $dblog, 'link' => TRUE)),
        theme('username', array('account' => $dblog)),
      ),
      // Attributes for tr
      'class' => array(
        drupal_html_class('dblog-' . $dblog->type),
        $classes[$dblog->severity],
      ),

    );
  }

  return array(
    'clear' => array(
      '#type' => 'submit',
      '#value' => t('Clear Error Log'),
    ),
    'dblog_pager_top' => array('#theme' => 'pager'),
    'dblog_table' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#attributes' => array('id' => 'admin-dblog'),
      '#empty' => t('No log messages available.'),
    ),
    'dblog_pager_bottom' => array('#theme' => 'pager'),
  );
}

/**
 * Deletes the log messages.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_error_form_submit(array $form, array &$form_state) {
  db_delete('watchdog')->condition('type', LIVINGSTONE_FEDORA_IMPORT_ERROR)->execute();
  drupal_set_message(t('Error log cleared.'));
}