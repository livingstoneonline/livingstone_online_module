<?php

/**
 * @file
 * Implements the export form for generating NINEs submission.
 */

/**
 * The form for generating the NINES export.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_nines_export_form(array $form, array &$form_state) {
  return array(
    'fieldset' => array(
      '#type' => 'fieldset',
      '#title' => t('NINES Export'),
      '#description' => t('Iterates over all content and generates RDF for NINES submission.'),
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Export'),
      ),
    ),
  );
}

/**
 * Triggers the batch for generating the RDF.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_nines_export_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone_nines', 'nines.batch');
  $batch = livingstone_nines_batch();
  batch_set($batch);
}
