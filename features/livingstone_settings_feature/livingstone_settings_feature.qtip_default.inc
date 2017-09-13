<?php
/**
 * @file
 * livingstone_settings_feature.qtip_default.inc
 */

/**
 * Implements hook_qtip_default_qtips().
 */
function livingstone_settings_feature_qtip_default_qtips() {
  $export = array();

  $qtip = new stdClass();
  $qtip->disabled = FALSE; /* Edit this to true to make a default qtip disabled initially */
  $qtip->api_version = 1.0;
  $qtip->machine_name = 'livingstone';
  $qtip->name = 'Livingstone';
  $qtip->settings = array(
    'content' => array(
      'button' => 0,
    ),
    'style' => array(
      'tip' => array(
        'width' => '6',
        'height' => '6',
        'border' => '',
        'corner_position' => '',
        'mimic' => '',
        'offset' => '',
        'corner' => 0,
      ),
      'classes' => 'qtip-bootstrap',
      'classes_custom' => '',
      'shadow' => 0,
      'rounded_corners' => 0,
    ),
    'position' => array(
      'at' => 'top center',
      'my' => '',
      'viewport' => 1,
      'target' => 0,
      'adjust' => array(
        'method' => 'shift',
      ),
    ),
    'show' => array(
      'event' => array(
        'mouseenter' => 'mouseenter',
        'focus' => 0,
        'click' => 0,
      ),
      'solo' => 1,
      'ready' => 0,
    ),
    'hide' => array(
      'event' => array(
        'mouseleave' => 'mouseleave',
        'unfocus' => 'unfocus',
        'click' => 'click',
        'blur' => 0,
      ),
      'fixed' => 1,
      'delay' => '',
      'inactive' => '',
    ),
    'miscellaneous' => array(
      'button_title_text' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Livingstone');

  $export['livingstone'] = $qtip;

  return $export;
}
