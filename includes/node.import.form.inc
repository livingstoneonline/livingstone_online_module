<?php

/**
 * @file
 */

/**
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
 * @todo Document
 */
function livingstone_node_import_form_validate(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
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
      elseif (!in_array('islandora:manuscriptCModel', $object->models)) {
        form_error($form['import_fieldset']['import_pid'], t('%pid is not a Manuscript.', array(
              '%pid' => $values['import_pid'],
            )));
      }
    }
  }
}

/**
 * @todo Document
 */
function livingstone_node_import_form_remove_submit(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $pid = $form_state['values']['remove_pid'];
  livingstone_node_import_node_delete($pid);
  drupal_set_message(t('Deleted node'));
}

/**
 * @todo Document
 */
function livingstone_node_import_form_remove_all_submit(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $count = livingstone_node_import_node_delete_all();
  if (!$count) {
    drupal_set_message(t('No nodes to delete.'), 'warning');
  }
  else {
    drupal_set_message(t('Deleted %count nodes', array('%count' => $count)));
  }
}

/**
 * @todo Document
 */
function livingstone_node_import_form_import_submit(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  $pid = $form_state['values']['import_pid'];
  $node = livingstone_node_import_node_load($pid);
  if ($node) {
    if ($node = livingstone_node_import_update($pid)) {
      drupal_set_message(t('Updated !link.', array(
        '!link' => l($pid, "node/{$node->nid}", array()),
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
      drupal_set_message(t('Imported !link.', array(
        '!link' => l($pid, "node/{$node->nid}", array()),
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
 * @todo Document
 */
function livingstone_node_import_form_import_all_submit(array $form, array &$form_state) {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  module_load_include('inc', 'livingstone', 'includes/node.import.batch');
  $batch = livingstone_node_import_sync_batch();
  batch_set($batch);
}