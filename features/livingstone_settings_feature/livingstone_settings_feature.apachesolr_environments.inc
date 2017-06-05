<?php
/**
 * @file
 * livingstone_settings_feature.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function livingstone_settings_feature_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://tomcat:8080/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_direct_commit' => 1,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'manuscript',
      1 => 'section_page',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
