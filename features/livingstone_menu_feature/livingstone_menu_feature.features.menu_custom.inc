<?php
/**
 * @file
 * livingstone_menu_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function livingstone_menu_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-fixed-header-menu.
  $menus['menu-fixed-header-menu'] = array(
    'menu_name' => 'menu-fixed-header-menu',
    'title' => 'Fixed Header Menu',
    'description' => 'A group of icons that display in the fixed header.',
  );
  // Exported menu: menu-secondary.
  $menus['menu-secondary'] = array(
    'menu_name' => 'menu-secondary',
    'title' => 'Secondary menu',
    'description' => 'List of links to show in the secondary navigation position (typically made of icons).',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A group of icons that display in the fixed header.');
  t('Fixed Header Menu');
  t('List of links to show in the secondary navigation position (typically made of icons).');
  t('Main menu');
  t('Secondary menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
