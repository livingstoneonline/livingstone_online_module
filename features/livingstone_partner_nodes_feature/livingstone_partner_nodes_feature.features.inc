<?php
/**
 * @file
 * livingstone_partner_nodes_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livingstone_partner_nodes_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
