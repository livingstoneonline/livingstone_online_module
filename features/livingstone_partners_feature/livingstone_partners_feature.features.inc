<?php
/**
 * @file
 * livingstone_partners_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_partners_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function livingstone_partners_feature_node_info() {
  $items = array(
    'partners' => array(
      'name' => t('Partners'),
      'base' => 'node_content',
      'description' => t('The partner organizations of that contributed to Livingstone Online in some way.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
