<?php
/**
 * @file
 * livingstone_block_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function livingstone_block_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['livingstone-livingstone_breadcrumbs'] = array(
    'cache' => 4,
    'custom' => 0,
    'delta' => 'livingstone_breadcrumbs',
    'module' => 'livingstone',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'fixed_header',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['livingstone-livingstone_browse_addressee'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'livingstone_browse_addressee',
    'module' => 'livingstone',
    'node_types' => array(),
    'pages' => 'in-his-own-words/addressee',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 20,
      ),
      'livingstone_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 20,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['livingstone-livingstone_browse_collection'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'livingstone_browse_collection',
    'module' => 'livingstone',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -22,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['livingstone-livingstone_fixed_search_form'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'livingstone_fixed_search_form',
    'module' => 'livingstone',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'fixed_header',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -22,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['livingstone-livingstone_share_icons'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'livingstone_share_icons',
    'module' => 'livingstone',
    'node_types' => array(),
    'pages' => 'about-this-site/*
in-his-own-words/*
spectral-imaging/*
life-and-times/*
behind-the-scenes/*
resources/*
search/node/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['livingstone-livingstone_slide_out_menu'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'livingstone_slide_out_menu',
    'module' => 'livingstone',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'fixed_header',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['livingstone_browse_catalogue-livingstone_browse_catalogue'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'livingstone_browse_catalogue',
    'module' => 'livingstone_browse_catalogue',
    'node_types' => array(),
    'pages' => 'in-his-own-words/catalogue',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['menu-menu-fixed-header-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-fixed-header-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'fixed_header',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-secondary'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-secondary',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['nodequeue_pager-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'module' => 'nodequeue_pager',
    'node_types' => array(),
    'pages' => 'about-this-site
about-this-site/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content_pager',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['nodequeue_pager-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 2,
    'module' => 'nodequeue_pager',
    'node_types' => array(),
    'pages' => 'in-his-own-words
in-his-own-words/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content_pager',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['nodequeue_pager-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 3,
    'module' => 'nodequeue_pager',
    'node_types' => array(),
    'pages' => 'spectral-imaging
spectral-imaging/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content_pager',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['nodequeue_pager-4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 4,
    'module' => 'nodequeue_pager',
    'node_types' => array(),
    'pages' => 'life-and-times
life-and-times/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content_pager',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['nodequeue_pager-5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 5,
    'module' => 'nodequeue_pager',
    'node_types' => array(),
    'pages' => 'behind-the-scenes
behind-the-scenes/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content_pager',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['nodequeue_pager-6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 6,
    'module' => 'nodequeue_pager',
    'node_types' => array(),
    'pages' => 'resources
resources/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content_pager',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => -11,
      ),
      'livingstone_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 1,
      ),
      'livingstone_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'livingstone_theme',
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-2663eae7b4e7c1bc05039a31c97593c2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '2663eae7b4e7c1bc05039a31c97593c2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'about-this-site/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'carousel',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-41c33f6be18527e9a82f33c410f664dc'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '41c33f6be18527e9a82f33c410f664dc',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'spectral-imaging/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'carousel',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -22,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-95ee7f15da7f54fa28bea61a8463127e'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '95ee7f15da7f54fa28bea61a8463127e',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'in-his-own-words/*
search/node/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'carousel',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-Partners-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Partners-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-dbb98f94899142e0adb8a23bf10a1263'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'dbb98f94899142e0adb8a23bf10a1263',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'resources/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'carousel',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -19,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-ef6dae3765cee87aa8cc66d9162526f2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ef6dae3765cee87aa8cc66d9162526f2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'behind-the-scenes/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'carousel',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -20,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-fe40d780b1331856e4c65b4a02935f31'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'fe40d780b1331856e4c65b4a02935f31',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'life-and-times/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'carousel',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => -21,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-geolocation-block_geolocation'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'geolocation-block_geolocation',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'in-his-own-words/location',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-repository-block_repository'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'repository-block_repository',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'in-his-own-words/repository',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-timeline-block_timeline'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'timeline-block_timeline',
    'module' => 'views',
    'node_types' => array(
      0 => 'section_page',
    ),
    'pages' => 'in-his-own-words/timeline',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'livingstone_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'livingstone_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
