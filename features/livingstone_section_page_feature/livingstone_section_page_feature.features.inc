<?php
/**
 * @file
 * livingstone_section_page_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_section_page_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function livingstone_section_page_feature_node_info() {
  $items = array(
    'section_page' => array(
      'name' => t('Section Page'),
      'base' => 'node_content',
      'description' => t('Makes up the bulk of the site, pages which appear in "About this Site", "Spectral Images", etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
