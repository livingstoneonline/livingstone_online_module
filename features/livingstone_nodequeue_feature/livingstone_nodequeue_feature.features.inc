<?php
/**
 * @file
 * livingstone_nodequeue_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_nodequeue_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function livingstone_nodequeue_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: about_this_site
  $nodequeues['about_this_site'] = array(
    'name' => 'about_this_site',
    'title' => 'About This Site',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'section_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: behind_the_scenes
  $nodequeues['behind_the_scenes'] = array(
    'name' => 'behind_the_scenes',
    'title' => 'Behind The Scenes',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'section_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: in_his_own_words
  $nodequeues['in_his_own_words'] = array(
    'name' => 'in_his_own_words',
    'title' => 'In His Own Words',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'section_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: life_times
  $nodequeues['life_times'] = array(
    'name' => 'life_times',
    'title' => 'Life & Times',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'section_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: our_technology
  $nodequeues['our_technology'] = array(
    'name' => 'our_technology',
    'title' => 'Spectral Imaging',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'section_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: partners
  $nodequeues['partners'] = array(
    'name' => 'partners',
    'title' => 'Partners',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'partners',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: resouces
  $nodequeues['resouces'] = array(
    'name' => 'resouces',
    'title' => 'Resouces',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'section_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: slides
  $nodequeues['slides'] = array(
    'name' => 'slides',
    'title' => 'Slides',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'slide',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
