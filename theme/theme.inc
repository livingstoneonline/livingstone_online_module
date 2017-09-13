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
  $attributes['class'] = 'form-checkboxes dropdown-menu dropdown-menu-right';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] .= ' ' . implode(' ', $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  $element['#children'] = '<ul' . drupal_attributes($attributes)  . '>';
  foreach (element_children($element) as $key) {
    $element['#children'] .= '<li><a href="#">' . drupal_render($element[$key]) . '</a></li>';
  }
  $element['#children'].= '</ul>';
  return !empty($element['#children']) ? $element['#children'] : '';
}

/**
 * Implements hook_preprocess_theme().
 */
function livingstone_preprocess_livingstone_slide_out_menu(array &$variables) {
  // Build links.
  $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
  // Provide default theme wrapper function.
  $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  // Secondary menu links.
  $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'menu-secondary'));
  // Provide default theme wrapper function.
  $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
}
