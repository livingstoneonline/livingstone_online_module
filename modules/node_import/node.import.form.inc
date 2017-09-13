<?php

/**
 * @file
 * Defines the form for importing content into Drupal from Fedora / Solr.
 */

require_once dirname(__FILE__) . '/node.import.inc';
require_once dirname(__FILE__) . '/node.import.batch.inc';

/**
 * The form for importing / removing nodes.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_node_import_form(array $form, array &$form_state) {
  return array(
    'description' => array(
      '#markup' => '<p>This form imports manuscript content from Fedora into Drupal.</p>'
    ),
    'remove_fieldset' => array(
      '#type' => 'fieldset',
      '#title' => t('Remove Manuscript Node(s)'),
      'remove_pid' => array(
        '#type' => 'textfield',
        '#title' => t('PID'),
      ),
      'remove' => array(
        '#type' => 'submit',
        '#value' => t('Remove Manuscript Node with PID'),
        '#submit' => array('livingstone_node_import_form_remove_submit'),
      ),
      'remove_all' => array(
        '#type' => 'submit',
        '#value' => t('Remove all Manuscript Nodes'),
        '#submit' => array('livingstone_node_import_form_remove_all_submit'),
      ),
    ),
    'import_fieldset' => array(
      '#type' => 'fieldset',
      '#title' => t('Import/Update Manuscript Node(s)'),
      'import_pid' => array(
        '#type' => 'textfield',
        '#title' => t('PID'),
      ),
      'import' => array(
        '#type' => 'submit',
        '#value' => t('Import/Update Manuscript Node via PID'),
        '#submit' => array('livingstone_node_import_form_import_submit'),
      ),
      'import_all' => array(
        '#type' => 'submit',
        '#value' => t('Import/Update all Manuscript Nodes'),
        '#submit' => array('livingstone_node_import_form_import_all_submit'),
      ),
    ),
  );
}

/**
 * Validates that the given values are valid.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_node_import_form_validate(array $form, array &$form_state) {
  $trigger = $form_state['triggering_element'];
  $values = $form_state['values'];
  if ($trigger['#value'] == t('Remove Manuscript Node with PID')) {
    if (empty($values['remove_pid'])) {
      form_error($form['remove_fieldset']['remove_pid'], t('PID must not be blank.'));
    }
    elseif (!livingstone_node_import_node_imported($values['remove_pid'])) {
      form_error($form['remove_fieldset']['remove_pid'], t('No nodes found with the PID: %pid.', array(
            '%pid' => $values['remove_pid'],
          )));
    }
  }
  elseif ($trigger['#value'] == t('Import Manuscript Node via PID')) {
    if (empty($values['import_pid'])) {
      form_error($form['import_fieldset']['import_pid'], t('PID must not be blank.'));
    }
    else {
      $object = islandora_object_load($values['import_pid']);
      if (!$object) {
        form_error($form['import_fieldset']['import_pid'], t('No objects found with the PID: %pid.', array(
              '%pid' => $values['import_pid'],
            )));
      }
      elseif (!in_array('islandora:manuscriptCModel', $object->models) &&
              !in_array('islandora:spectralManuscriptCModel', $object->models)) {
        form_error($form['import_fieldset']['import_pid'], t('%pid is not a Manuscript.', array(
              '%pid' => $values['import_pid'],
            )));
      }
    }
  }
}

/**
 * Deletes the given node identified by the given PID.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_node_import_form_remove_submit(array $form, array &$form_state) {
  $pid = $form_state['values']['remove_pid'];
  livingstone_node_import_node_delete_from_pid($pid);
  drupal_set_message(t('Deleted node'));
}

/**
 * Deletes all the imported nodes.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_node_import_form_remove_all_submit(array $form, array &$form_state) {
  $batch = livingstone_node_import_remove_all_manuscript_nodes_batch();
  batch_set($batch);
}

/**
 * Import form submission handler creates / updates a single node.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_node_import_form_import_submit(array $form, array &$form_state) {
  $pid = $form_state['values']['import_pid'];
  $node = livingstone_node_import_node_load_from_pid($pid);
  if ($node) {
    if ($node = livingstone_node_import_update($pid)) {
      drupal_set_message(t('Updated <a href="@url">@pid</a>.', array(
        '@url' => url("node/{$node->nid}"),
        '@pid' => $pid,
      )));
    }
    else {
      drupal_set_message(t('Failed to update %pid.', array(
        '%pid' => $pid,
      )), 'error');
    }
  }
  else {
    if ($node = livingstone_node_import($pid)) {
      drupal_set_message(t('Imported <a href="@url">@pid</a>.', array(
        '@url' => url("node/{$node->nid}"),
        '@pid' => $pid,
      )));
    }
    else {
      drupal_set_message(t('Failed to import %pid.', array(
        '%pid' => $pid,
      )), 'error');
    }
  }
}

/**
 * Import form submission handler creates / updates a all nodes.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_node_import_form_import_all_submit(array $form, array &$form_state) {
  $batch = livingstone_node_import_sync_batch();
  batch_set($batch);
}
