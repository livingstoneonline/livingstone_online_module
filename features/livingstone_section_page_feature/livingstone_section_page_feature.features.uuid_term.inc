<?php
/**
 * @file
 * livingstone_section_page_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function livingstone_section_page_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Life and Times',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '0016c2aa-f0a2-45b1-a848-dbaade5f56a8',
    'vocabulary_machine_name' => 'section',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'About This Site',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6baf6ba0-7583-4c0d-901e-e486178c16ad',
    'vocabulary_machine_name' => 'section',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Spectral Imaging',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '832cb106-a699-49eb-be89-e0976616f4d6',
    'vocabulary_machine_name' => 'section',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Behind the Scenes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '8a626a14-b01e-472b-9c8b-fc2790a1c42d',
    'vocabulary_machine_name' => 'section',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Resources',
    'description' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam sapien diam, facilisis at est at, pellentesque imperdiet lorem. Maecenas ultrices elit nunc, nec mattis nunc consectetur in.</p>
',
    'format' => 'full_html',
    'weight' => 5,
    'uuid' => 'f6dae27f-535b-43b4-a521-102b9eaca77f',
    'vocabulary_machine_name' => 'section',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'In His Own Words',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'f84b765b-34bc-4c58-b139-b7cec8d09d08',
    'vocabulary_machine_name' => 'section',
    'url_alias' => array(),
  );
  return $terms;
}
