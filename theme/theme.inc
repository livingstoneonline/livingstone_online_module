<?php

/**
 * @file
 * Theme functions for livingstone_manuscript.
 */

/**
 * Renders the search box type selector.
 *
 * @param $variables
 *
 * @return string
 *  The HTML representing this form element.
 */
function theme_livingstone_form_search_block_search_type($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] .= ' ' . implode(' ', $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  $element['#children'];
  foreach (element_children($element) as $key) {
    $element['#children'] .= '<div>' . drupal_render($element[$key]) . '</div>';
  }
  return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}
