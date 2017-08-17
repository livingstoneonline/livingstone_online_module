<?php

// More changes since last convert.

$file = __DIR__ . '/section_page_nodes.php';

eval('$nodes = ' . file_get_contents($file) . ';');

function map(&$node, $old, $new) {
  $node->{$new} = $node->{$old};
  unset($node->{$old});
}

$map_uid = array(
  '0' => '0',
  '1' => '1',
  '9' => '3',
);

$map_tid = array(
  // About this site.
  '4' => '2',
  // In his own words.
  '8' => '6',
  // Spectral Imaging.
  '7' => '3',
  // Behind the Scenes.
  '3' => '4',
  // Life and Times.
  '2' => '1',
  // Resources.
  '1' => '5',
);

module_load_include('inc', 'node_export', 'formats/drupal');
foreach ($nodes as &$node) {
  // Remove fields.
  unset($node->field_section_page_main_image);
  unset($node->field_level_2_intro_node);
  unset($node->field_level_2_photocredit);
  unset($node->field_turn_off_hover);
  // topmenu doesn't exist, we'll manually create these afterwards. along with
  // using pathauto.
  unset($node->menu);
  $node->path = array(
    'pathauto' => TRUE,
  );
  // Rename fields.
  map($node, 'field_section_page_sections', 'field_section');
  map($node, 'body', 'field_section_body');
  map($node, 'field_section_page_tag_line', 'field_section_overview');
  map($node, 'field_carousel_image', 'field_section_carousel_image');
  map($node, 'field_section_page_image', 'field_section_grid_image');
  map($node, 'field_section_page_byline', 'field_section_byline');
  map($node, 'field_section_page_date', 'field_section_date');
  map($node, 'field_subtitle', 'field_section_subtitle');
  map($node, 'field_level_2_teaser', 'field_section_teaser');
  map($node, 'field_pre_title', 'field_section_pre_title');
  map($node, 'field_outbound_link', 'field_section_outbound_link');
  map($node, 'field_open_new_tab', 'field_section_open_in_new_tab');
  map($node, 'field_transcriptions', 'field_section_page_transcription');
  // New fields Author and Editors are empty.
  // Need to clean up css for hardcoded widths (Do after import with other file), this can be done manually.
  // Need to fix links in the body for fuck sakes (Do after import with other file).
  // Fix location of image files to be in the appropriate folders.
  // What about sections.
  $tid = $node->field_section['und'][0]['tid'];
  if ($tid) {
    $node->field_section['und'][0]['tid'] = $map_tid[$tid];
  }

  // Need to remap uid for nodes and files.
  $uid = $node->uid;
  if ($uid) {
    $node->uid = $map_uid[$uid];
  }
  $uid = $node->field_section_carousel_image['und'][0]['uid'];
  if ($uid) {
    $node->field_section_carousel_image['und'][0]['uid'] = $map_uid[$uid];
  }
  $uid = $node->field_section_grid_image['und'][0]['uid'];
  if ($uid) {
    $node->field_section_grid_image['und'][0]['uid'] = $map_uid[$uid];
  }

  // Need to remap file locations for Grid / Carousel Image.
  $uri = $node->field_section_carousel_image['und'][0]['uri'];
  if ($uri) {
    $uri = 'public://section_page/carousel_images/' . substr($uri, strlen('public://'));
    $node->field_section_carousel_image['und'][0]['uri'] = $uri;
  }
  $uri = $node->field_section_grid_image['und'][0]['uri'];
  if ($uri) {
    $uri = 'public://section_page/grid_images/' . substr($uri, strlen('public://'));
    $node->field_section_grid_image['und'][0]['uri'] = $uri;
  }

  // Need to remap URL's for embedded content
}

$outfile = __DIR__ . '/section_page_nodes.out.php';

file_put_contents($outfile, node_export_drupal_export($nodes, 'drupal'));