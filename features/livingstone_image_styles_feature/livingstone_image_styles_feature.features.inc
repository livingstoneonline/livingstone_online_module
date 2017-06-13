<?php
/**
 * @file
 * livingstone_image_styles_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function livingstone_image_styles_feature_image_default_styles() {
  $styles = array();

  // Exported image style: section_carousel_image.
  $styles['section_carousel_image'] = array(
    'label' => 'Section Carousel Image',
    'effects' => array(
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 65,
          'height' => 65,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: section_grid_image.
  $styles['section_grid_image'] = array(
    'label' => 'Section Grid Image',
    'effects' => array(
      1 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 390,
          'height' => 293,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: timeline_image.
  $styles['timeline_image'] = array(
    'label' => 'Timeline Image',
    'effects' => array(),
  );

  return $styles;
}
