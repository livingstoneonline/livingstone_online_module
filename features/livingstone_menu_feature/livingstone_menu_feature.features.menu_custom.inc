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
  // Exported menu: menu-livingstone-1870-diary.
  $menus['menu-livingstone-1870-diary'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'title' => 'Livingstone 1870 Field Diary',
    'description' => 'Table of contents for the Livingstone\'s 1870 Field Diary.',
  );
  // Exported menu: menu-livingstone-1871-diary.
  $menus['menu-livingstone-1871-diary'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'title' => 'Livingstone 1871 Field Diary',
    'description' => 'Table of contents for the Livingstone\'s 1871 Field Diary.',
  );
  // Exported menu: menu-livingstone-letter-bambarre.
  $menus['menu-livingstone-letter-bambarre'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'title' => 'Livingstone Letter from Bambarre',
    'description' => 'Table of contents for Livingstone’s Letter from Bambarre.',
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
  t('Livingstone 1870 Field Diary');
  t('Livingstone 1871 Field Diary');
  t('Livingstone Letter from Bambarre');
  t('Main menu');
  t('Secondary menu');
  t('Table of contents for Livingstone’s Letter from Bambarre.');
  t('Table of contents for the Livingstone\'s 1870 Field Diary.');
  t('Table of contents for the Livingstone\'s 1871 Field Diary.');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
