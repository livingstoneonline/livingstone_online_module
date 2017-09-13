<?php
/**
 * @file
 * livingstone_manuscript_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_manuscript_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function livingstone_manuscript_feature_node_info() {
  $items = array(
    'manuscript' => array(
      'name' => t('Manuscript'),
      'base' => 'node_content',
      'description' => t('Manuscript data synced from Fedora, do not create manually.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
