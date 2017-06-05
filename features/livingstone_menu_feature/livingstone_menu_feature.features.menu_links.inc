<?php
/**
 * @file
 * livingstone_menu_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function livingstone_menu_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-fixed-header-menu_:<front>.
  $menu_links['menu-fixed-header-menu_:<front>'] = array(
    'menu_name' => 'menu-fixed-header-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => '',
    'options' => array(
      'identifier' => 'menu-fixed-header-menu_:<front>',
      'attributes' => array(
        'title' => 'Home',
        'class' => array(
          0 => 'fa',
          1 => 'home',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-fixed-header-menu_:uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903.
  $menu_links['menu-fixed-header-menu_:uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903'] = array(
    'menu_name' => 'menu-fixed-header-menu',
    'link_path' => 'uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903',
    'router_path' => 'uuid',
    'link_title' => '',
    'options' => array(
      'identifier' => 'menu-fixed-header-menu_:uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903',
      'attributes' => array(
        'title' => 'Site Guide',
        'class' => array(
          0 => 'fa',
          1 => 'site-guide',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-secondary_:<front>.
  $menu_links['menu-secondary_:<front>'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => '',
    'options' => array(
      'attributes' => array(
        'title' => 'Home',
        'class' => array(
          0 => 'fa',
          1 => 'home',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary_:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-secondary_:http://livingstoneonline.wordpress.com/.
  $menu_links['menu-secondary_:http://livingstoneonline.wordpress.com/'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => 'http://livingstoneonline.wordpress.com/',
    'router_path' => '',
    'link_title' => '',
    'options' => array(
      'attributes' => array(
        'title' => 'Blog',
        'class' => array(
          0 => 'fa',
          1 => 'blog',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary_:http://livingstoneonline.wordpress.com/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-secondary_:mailto:awisnicki@yahoo.com.
  $menu_links['menu-secondary_:mailto:awisnicki@yahoo.com'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => 'mailto:awisnicki@yahoo.com',
    'router_path' => '',
    'link_title' => '',
    'options' => array(
      'attributes' => array(
        'title' => 'Email',
        'class' => array(
          0 => 'fa',
          1 => 'email',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary_:mailto:awisnicki@yahoo.com',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-secondary_:uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903.
  $menu_links['menu-secondary_:uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => 'uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903',
    'router_path' => 'uuid',
    'link_title' => '',
    'options' => array(
      'attributes' => array(
        'title' => 'Site Guide',
        'class' => array(
          0 => 'fa',
          1 => 'site-guide',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary_:uuid/node/78d62fa4-716c-41ee-94ef-b09eb07b8903',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('');
  t('');
  t('');
  t('');

  return $menu_links;
}
