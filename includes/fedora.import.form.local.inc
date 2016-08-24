<?php

/**
 * @file
 * Forms for managing the import of content from the FTP into Fedora.
 */

require_once dirname(__FILE__) . '/fedora.import.form.objects.inc';

define('LIVINGSTONE_LOCAL_OBJECT_FORM_SETTINGS', 'livingstone_fedora_import_local_objects_form_settings');

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
function livingstone_fedora_import_local_objects_form(array $form, array &$form_state) {
  $columns = array(
    'PID',
    'TYPE',
    'PRIVATE',
    'CONTENT_MODEL',
    'MODS_MD5',
    'OBJ_MD5',
    'PDF_MD5',
    'TEI_MD5',
    'TN_MD5',
    'TXT_MD5',
    'XMP_MD5',
    'ZIP_MD5',
  );
  $form = livingstone_fedora_import_objects_form($form, $form_state, $columns, LIVINGSTONE_LOCAL_OBJECT_FORM_SETTINGS);
  $form['table'] = livingstone_fedora_import_objects_table(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, LIVINGSTONE_LOCAL_OBJECT_FORM_SETTINGS);
  return $form;
}
