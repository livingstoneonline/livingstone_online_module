<?php
/**
 * @file
 * livingstone_repository_info_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_repository_info_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function livingstone_repository_info_feature_node_info() {
  $items = array(
    'repository_info' => array(
      'name' => t('Repository Info'),
      'base' => 'node_content',
      'description' => t('The libraries, archives, museums, and other institutions where these manuscripts reside. - See more at: http://livingstoneonline.org/his-own-words/repository#sthash.3QYsuXF8.dpuf'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
