<?php
/**
 * @file
 * livingstone_settings_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_settings_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "qtip" && $api == "qtip_default") {
    return array("version" => "1.0");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_islandora_solr_fields_features_default_fields().
 */
function livingstone_settings_feature_islandora_solr_fields_features_default_fields() {
  return array();
}
