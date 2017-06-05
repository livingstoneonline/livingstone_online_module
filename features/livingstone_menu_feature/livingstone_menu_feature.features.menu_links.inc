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
  // Exported menu link: menu-livingstone-1870-diary_acknowledgments:uuid/node/8ef66730-cfc0-4101-9760-ecbb6f710bc8.
  $menu_links['menu-livingstone-1870-diary_acknowledgments:uuid/node/8ef66730-cfc0-4101-9760-ecbb6f710bc8'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/8ef66730-cfc0-4101-9760-ecbb6f710bc8',
    'router_path' => 'uuid',
    'link_title' => 'Acknowledgments',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_acknowledgments:uuid/node/8ef66730-cfc0-4101-9760-ecbb6f710bc8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0.
  $menu_links['menu-livingstone-1870-diary_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0',
    'router_path' => 'uuid',
    'link_title' => 'An Integrated Bibliography',
    'options' => array(
      'identifier' => 'menu-livingstone-1870-diary_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0',
      'attributes' => array(),
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
    'weight' => 22,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_creating-the-1870-field-diary:uuid/node/64a38b96-79b8-47a9-99d6-34c9838a0980.
  $menu_links['menu-livingstone-1870-diary_creating-the-1870-field-diary:uuid/node/64a38b96-79b8-47a9-99d6-34c9838a0980'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/64a38b96-79b8-47a9-99d6-34c9838a0980',
    'router_path' => 'uuid',
    'link_title' => 'Creating the 1870 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_creating-the-1870-field-diary:uuid/node/64a38b96-79b8-47a9-99d6-34c9838a0980',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_edition-guide:uuid/node/847e1823-0e9f-4bd4-ae02-bfb2a8ff141b.
  $menu_links['menu-livingstone-1870-diary_edition-guide:uuid/node/847e1823-0e9f-4bd4-ae02-bfb2a8ff141b'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/847e1823-0e9f-4bd4-ae02-bfb2a8ff141b',
    'router_path' => 'uuid',
    'link_title' => 'Edition Guide',
    'options' => array(
      'identifier' => 'menu-livingstone-1870-diary_edition-guide:uuid/node/847e1823-0e9f-4bd4-ae02-bfb2a8ff141b',
      'attributes' => array(),
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
  // Exported menu link: menu-livingstone-1870-diary_history--chronology-of-the-1870-field-diary:uuid/node/24ea361b-e744-409f-a28d-ae041994cf81.
  $menu_links['menu-livingstone-1870-diary_history--chronology-of-the-1870-field-diary:uuid/node/24ea361b-e744-409f-a28d-ae041994cf81'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/24ea361b-e744-409f-a28d-ae041994cf81',
    'router_path' => 'uuid',
    'link_title' => 'History & Chronology of the 1870 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_history--chronology-of-the-1870-field-diary:uuid/node/24ea361b-e744-409f-a28d-ae041994cf81',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 13,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_images--transcriptions-of-select-1870-1871-texts:in-his-own-words/catalogue.
  $menu_links['menu-livingstone-1870-diary_images--transcriptions-of-select-1870-1871-texts:in-his-own-words/catalogue'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'in-his-own-words/catalogue',
    'router_path' => 'in-his-own-words',
    'link_title' => 'Images & Transcriptions of Select 1870-1871 Texts',
    'options' => array(
      'query' => array(
        'query' => 'retrospect+letter',
        'access' => 'view_spectral',
        'f%5B%5D' => 'genre_ms:"spectral color"',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_images--transcriptions-of-select-1870-1871-texts:in-his-own-words/catalogue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_images--transcriptions-of-the-1870-field-diary:in-his-own-words/catalogue.
  $menu_links['menu-livingstone-1870-diary_images--transcriptions-of-the-1870-field-diary:in-his-own-words/catalogue'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'in-his-own-words/catalogue',
    'router_path' => 'in-his-own-words',
    'link_title' => 'Images & Transcriptions of the 1870 Field Diary',
    'options' => array(
      'query' => array(
        'query' => '"1870 Field Diary"',
        'f%5B%5D' => 'genre_ms:"spectral color"',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_images--transcriptions-of-the-1870-field-diary:in-his-own-words/catalogue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_introduction-to-the-edition:uuid/node/7fbeae31-b1a8-46f0-9529-67f90d0e36f5.
  $menu_links['menu-livingstone-1870-diary_introduction-to-the-edition:uuid/node/7fbeae31-b1a8-46f0-9529-67f90d0e36f5'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/7fbeae31-b1a8-46f0-9529-67f90d0e36f5',
    'router_path' => 'uuid',
    'link_title' => 'Introduction to the Edition',
    'options' => array(
      'identifier' => 'menu-livingstone-1870-diary_introduction-to-the-edition:uuid/node/7fbeae31-b1a8-46f0-9529-67f90d0e36f5',
      'attributes' => array(),
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
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5.
  $menu_links['menu-livingstone-1870-diary_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5',
    'router_path' => 'uuid',
    'link_title' => 'Key Terms in Livingstone\'s Manuscripts, 1870-71',
    'options' => array(
      'identifier' => 'menu-livingstone-1870-diary_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5',
      'attributes' => array(),
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
    'weight' => 16,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_livingstone-central-africa-1870:uuid/node/8903fa5b-7919-4f98-96ad-9b147e7f16d2.
  $menu_links['menu-livingstone-1870-diary_livingstone-central-africa-1870:uuid/node/8903fa5b-7919-4f98-96ad-9b147e7f16d2'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/8903fa5b-7919-4f98-96ad-9b147e7f16d2',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone, Central Africa, 1870',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_livingstone-central-africa-1870:uuid/node/8903fa5b-7919-4f98-96ad-9b147e7f16d2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_livingstones-composition-practices:uuid/node/ec4831b5-1dfb-407f-9029-5c6e5715933c.
  $menu_links['menu-livingstone-1870-diary_livingstones-composition-practices:uuid/node/ec4831b5-1dfb-407f-9029-5c6e5715933c'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/ec4831b5-1dfb-407f-9029-5c6e5715933c',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone\'s Composition Practices',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_livingstones-composition-practices:uuid/node/ec4831b5-1dfb-407f-9029-5c6e5715933c',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 14,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_livingstones-global-sources:uuid/node/c7a7c0e0-6b8a-40fb-ba23-984487fede29.
  $menu_links['menu-livingstone-1870-diary_livingstones-global-sources:uuid/node/c7a7c0e0-6b8a-40fb-ba23-984487fede29'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/c7a7c0e0-6b8a-40fb-ba23-984487fede29',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone\'s Global Sources',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_livingstones-global-sources:uuid/node/c7a7c0e0-6b8a-40fb-ba23-984487fede29',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 15,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_manuscript-citation-and-file-naming-practices:uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181.
  $menu_links['menu-livingstone-1870-diary_manuscript-citation-and-file-naming-practices:uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181',
    'router_path' => 'uuid',
    'link_title' => 'Manuscript Citation and File Naming Practices',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_manuscript-citation-and-file-naming-practices:uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 19,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_notes-on-processed-spectral-images:uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b.
  $menu_links['menu-livingstone-1870-diary_notes-on-processed-spectral-images:uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b',
    'router_path' => 'uuid',
    'link_title' => 'Notes on Processed Spectral Images',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_notes-on-processed-spectral-images:uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 17,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_project-documentation:uuid/node/1c3313a3-9c2d-4434-9034-516507fb541b.
  $menu_links['menu-livingstone-1870-diary_project-documentation:uuid/node/1c3313a3-9c2d-4434-9034-516507fb541b'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/1c3313a3-9c2d-4434-9034-516507fb541b',
    'router_path' => 'uuid',
    'link_title' => 'Project Documentation',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_project-documentation:uuid/node/1c3313a3-9c2d-4434-9034-516507fb541b',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 21,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_project-history:uuid/node/c91df526-2079-4a89-888a-313ba71cb600.
  $menu_links['menu-livingstone-1870-diary_project-history:uuid/node/c91df526-2079-4a89-888a-313ba71cb600'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/c91df526-2079-4a89-888a-313ba71cb600',
    'router_path' => 'uuid',
    'link_title' => 'Project History',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_project-history:uuid/node/c91df526-2079-4a89-888a-313ba71cb600',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_prototyping-animated-spectral-images-asis:uuid/node/af8d4263-1bd8-4a08-9155-642433fa2799.
  $menu_links['menu-livingstone-1870-diary_prototyping-animated-spectral-images-asis:uuid/node/af8d4263-1bd8-4a08-9155-642433fa2799'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/af8d4263-1bd8-4a08-9155-642433fa2799',
    'router_path' => 'uuid',
    'link_title' => 'Prototyping Animated Spectral Images (ASIs)',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_prototyping-animated-spectral-images-asis:uuid/node/af8d4263-1bd8-4a08-9155-642433fa2799',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 18,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_structuring-the-1870-field-diary:uuid/node/9b55d92a-0b4f-4465-aa88-aef50b7ed339.
  $menu_links['menu-livingstone-1870-diary_structuring-the-1870-field-diary:uuid/node/9b55d92a-0b4f-4465-aa88-aef50b7ed339'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/9b55d92a-0b4f-4465-aa88-aef50b7ed339',
    'router_path' => 'uuid',
    'link_title' => 'Structuring the 1870 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_structuring-the-1870-field-diary:uuid/node/9b55d92a-0b4f-4465-aa88-aef50b7ed339',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_the-diary-across-hands-space--time-1:uuid/node/d67ceafd-e4ff-436e-917d-f0ff4cb21795.
  $menu_links['menu-livingstone-1870-diary_the-diary-across-hands-space--time-1:uuid/node/d67ceafd-e4ff-436e-917d-f0ff4cb21795'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/d67ceafd-e4ff-436e-917d-f0ff4cb21795',
    'router_path' => 'uuid',
    'link_title' => 'The Diary across Hands, Space, & Time (1)',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_the-diary-across-hands-space--time-1:uuid/node/d67ceafd-e4ff-436e-917d-f0ff4cb21795',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_the-diary-across-hands-space--time-2:uuid/node/6851b824-bc16-4acf-8629-ab1ee03fce0d.
  $menu_links['menu-livingstone-1870-diary_the-diary-across-hands-space--time-2:uuid/node/6851b824-bc16-4acf-8629-ab1ee03fce0d'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/6851b824-bc16-4acf-8629-ab1ee03fce0d',
    'router_path' => 'uuid',
    'link_title' => 'The Diary across Hands, Space, & Time (2)',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_the-diary-across-hands-space--time-2:uuid/node/6851b824-bc16-4acf-8629-ab1ee03fce0d',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 11,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_the-diary-across-hands-space--time-3:uuid/node/dd8aea19-8bea-44e3-a772-e745848e20f4.
  $menu_links['menu-livingstone-1870-diary_the-diary-across-hands-space--time-3:uuid/node/dd8aea19-8bea-44e3-a772-e745848e20f4'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/dd8aea19-8bea-44e3-a772-e745848e20f4',
    'router_path' => 'uuid',
    'link_title' => 'The Diary across Hands, Space, & Time (3)',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_the-diary-across-hands-space--time-3:uuid/node/dd8aea19-8bea-44e3-a772-e745848e20f4',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 12,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_the-project-team:uuid/node/8bbaa4ed-e4af-42b0-aca4-4eb5d309a4f6.
  $menu_links['menu-livingstone-1870-diary_the-project-team:uuid/node/8bbaa4ed-e4af-42b0-aca4-4eb5d309a4f6'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/8bbaa4ed-e4af-42b0-aca4-4eb5d309a4f6',
    'router_path' => 'uuid',
    'link_title' => 'The Project Team',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_the-project-team:uuid/node/8bbaa4ed-e4af-42b0-aca4-4eb5d309a4f6',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1870-diary_three-versions-of-the-1870-field-diary:uuid/node/dc5f43a4-713f-4d5c-b261-d8a38c06e80f.
  $menu_links['menu-livingstone-1870-diary_three-versions-of-the-1870-field-diary:uuid/node/dc5f43a4-713f-4d5c-b261-d8a38c06e80f'] = array(
    'menu_name' => 'menu-livingstone-1870-diary',
    'link_path' => 'uuid/node/dc5f43a4-713f-4d5c-b261-d8a38c06e80f',
    'router_path' => 'uuid',
    'link_title' => 'Three Versions of the 1870 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1870-diary_three-versions-of-the-1870-field-diary:uuid/node/dc5f43a4-713f-4d5c-b261-d8a38c06e80f',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_1871-field-diary-headers:uuid/node/cd6dfca9-a8b8-4766-bc05-dcd7e247f8ad.
  $menu_links['menu-livingstone-1871-diary_1871-field-diary-headers:uuid/node/cd6dfca9-a8b8-4766-bc05-dcd7e247f8ad'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/cd6dfca9-a8b8-4766-bc05-dcd7e247f8ad',
    'router_path' => 'uuid',
    'link_title' => '1871 Field Diary Headers',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_1871-field-diary-headers:uuid/node/cd6dfca9-a8b8-4766-bc05-dcd7e247f8ad',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 19,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_acknowledgments:uuid/node/9e2b973a-2e2a-4f0e-b590-eeb58d0a8e6e.
  $menu_links['menu-livingstone-1871-diary_acknowledgments:uuid/node/9e2b973a-2e2a-4f0e-b590-eeb58d0a8e6e'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/9e2b973a-2e2a-4f0e-b590-eeb58d0a8e6e',
    'router_path' => 'uuid',
    'link_title' => 'Acknowledgments',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_acknowledgments:uuid/node/9e2b973a-2e2a-4f0e-b590-eeb58d0a8e6e',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0.
  $menu_links['menu-livingstone-1871-diary_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0',
    'router_path' => 'uuid',
    'link_title' => 'An Integrated Bibliography',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 24,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_edition-guide:uuid/node/222965a6-6231-48db-97bf-8881dfea1b28.
  $menu_links['menu-livingstone-1871-diary_edition-guide:uuid/node/222965a6-6231-48db-97bf-8881dfea1b28'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/222965a6-6231-48db-97bf-8881dfea1b28',
    'router_path' => 'uuid',
    'link_title' => 'Edition Guide',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_edition-guide:uuid/node/222965a6-6231-48db-97bf-8881dfea1b28',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_images--transcriptions-of-the-1871-field-diary:in-his-own-words/catalogue.
  $menu_links['menu-livingstone-1871-diary_images--transcriptions-of-the-1871-field-diary:in-his-own-words/catalogue'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'in-his-own-words/catalogue',
    'router_path' => 'in-his-own-words',
    'link_title' => 'Images & Transcriptions of the 1871 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'query' => array(
        'query' => '"1871 Field Diary" NOT integrated NOT segment',
        'access' => 'all',
        'limit' => 'catalogue',
      ),
      'identifier' => 'menu-livingstone-1871-diary_images--transcriptions-of-the-1871-field-diary:in-his-own-words/catalogue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_introduction-to-the-edition:uuid/node/75c25c6c-c491-4059-b446-3562d7518c95.
  $menu_links['menu-livingstone-1871-diary_introduction-to-the-edition:uuid/node/75c25c6c-c491-4059-b446-3562d7518c95'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/75c25c6c-c491-4059-b446-3562d7518c95',
    'router_path' => 'uuid',
    'link_title' => 'Introduction to the Edition',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_introduction-to-the-edition:uuid/node/75c25c6c-c491-4059-b446-3562d7518c95',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5.
  $menu_links['menu-livingstone-1871-diary_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5',
    'router_path' => 'uuid',
    'link_title' => 'Key Terms in Livingstone\'s Manuscripts, 1870-71',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 15,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_livingstone-in-1871:uuid/node/ee070bc7-7f68-4e61-962d-038e1703231a.
  $menu_links['menu-livingstone-1871-diary_livingstone-in-1871:uuid/node/ee070bc7-7f68-4e61-962d-038e1703231a'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/ee070bc7-7f68-4e61-962d-038e1703231a',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone in 1871',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_livingstone-in-1871:uuid/node/ee070bc7-7f68-4e61-962d-038e1703231a',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_livingstone-spectral-image-collection:in-his-own-words/catalogue.
  $menu_links['menu-livingstone-1871-diary_livingstone-spectral-image-collection:in-his-own-words/catalogue'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'in-his-own-words/catalogue',
    'router_path' => 'in-his-own-words',
    'link_title' => 'Livingstone Spectral Image Collection',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'query' => array(
        'access' => 'view_spectral',
      ),
      'identifier' => 'menu-livingstone-1871-diary_livingstone-spectral-image-collection:in-his-own-words/catalogue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_livingstones-composition-methods:uuid/node/ae2084e0-9536-418e-8d1e-a3fd0ae5da1e.
  $menu_links['menu-livingstone-1871-diary_livingstones-composition-methods:uuid/node/ae2084e0-9536-418e-8d1e-a3fd0ae5da1e'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/ae2084e0-9536-418e-8d1e-a3fd0ae5da1e',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone’s Composition Methods',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_livingstones-composition-methods:uuid/node/ae2084e0-9536-418e-8d1e-a3fd0ae5da1e',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_livingstones-manuscript-structure:uuid/node/f2fbbb5a-5113-4031-b5ea-0a343971a1d6.
  $menu_links['menu-livingstone-1871-diary_livingstones-manuscript-structure:uuid/node/f2fbbb5a-5113-4031-b5ea-0a343971a1d6'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/f2fbbb5a-5113-4031-b5ea-0a343971a1d6',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone\'s Manuscript Structure',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_livingstones-manuscript-structure:uuid/node/f2fbbb5a-5113-4031-b5ea-0a343971a1d6',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 11,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_manuscript-citation-and-file-naming-practices:uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181.
  $menu_links['menu-livingstone-1871-diary_manuscript-citation-and-file-naming-practices:uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181',
    'router_path' => 'uuid',
    'link_title' => 'Manuscript Citation and File Naming Practices',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_manuscript-citation-and-file-naming-practices:uuid/node/05c2bec5-31aa-4dde-b5e9-b3fdff8e3181',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 23,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_note-on-the-three-versions-of-the-text:uuid/node/3174f7e5-fce7-42b5-b846-72a0af38fba9.
  $menu_links['menu-livingstone-1871-diary_note-on-the-three-versions-of-the-text:uuid/node/3174f7e5-fce7-42b5-b846-72a0af38fba9'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/3174f7e5-fce7-42b5-b846-72a0af38fba9',
    'router_path' => 'uuid',
    'link_title' => 'Note on the Three Versions of the Text',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_note-on-the-three-versions-of-the-text:uuid/node/3174f7e5-fce7-42b5-b846-72a0af38fba9',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 13,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_overview-of-processing-objectives:uuid/node/6fb642c6-5b13-41a6-a99f-462bc4fcef2e.
  $menu_links['menu-livingstone-1871-diary_overview-of-processing-objectives:uuid/node/6fb642c6-5b13-41a6-a99f-462bc4fcef2e'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/6fb642c6-5b13-41a6-a99f-462bc4fcef2e',
    'router_path' => 'uuid',
    'link_title' => 'Overview of Processing Objectives',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_overview-of-processing-objectives:uuid/node/6fb642c6-5b13-41a6-a99f-462bc4fcef2e',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 14,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_project-documentation:uuid/node/66488668-a6e0-44d2-86f3-95361e477c40.
  $menu_links['menu-livingstone-1871-diary_project-documentation:uuid/node/66488668-a6e0-44d2-86f3-95361e477c40'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/66488668-a6e0-44d2-86f3-95361e477c40',
    'router_path' => 'uuid',
    'link_title' => 'Project Documentation',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_project-documentation:uuid/node/66488668-a6e0-44d2-86f3-95361e477c40',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 18,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_project-history-1:uuid/node/d2c119f4-4ada-4b18-9aca-6e79a46dc975.
  $menu_links['menu-livingstone-1871-diary_project-history-1:uuid/node/d2c119f4-4ada-4b18-9aca-6e79a46dc975'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/d2c119f4-4ada-4b18-9aca-6e79a46dc975',
    'router_path' => 'uuid',
    'link_title' => 'Project History (1)',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_project-history-1:uuid/node/d2c119f4-4ada-4b18-9aca-6e79a46dc975',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 16,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_project-history-2:uuid/node/73c6634d-9b48-417f-ae97-81cc19dc0f23.
  $menu_links['menu-livingstone-1871-diary_project-history-2:uuid/node/73c6634d-9b48-417f-ae97-81cc19dc0f23'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/73c6634d-9b48-417f-ae97-81cc19dc0f23',
    'router_path' => 'uuid',
    'link_title' => 'Project History (2)',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_project-history-2:uuid/node/73c6634d-9b48-417f-ae97-81cc19dc0f23',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 17,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_project-team:uuid/node/432d0dde-4054-4313-9225-24c93217b99e.
  $menu_links['menu-livingstone-1871-diary_project-team:uuid/node/432d0dde-4054-4313-9225-24c93217b99e'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/432d0dde-4054-4313-9225-24c93217b99e',
    'router_path' => 'uuid',
    'link_title' => 'Project Team',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_project-team:uuid/node/432d0dde-4054-4313-9225-24c93217b99e',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_tei-p5-encoding-guidelines:uuid/node/e3ff9ebe-6577-45e5-81b2-eb9ad2e3abba.
  $menu_links['menu-livingstone-1871-diary_tei-p5-encoding-guidelines:uuid/node/e3ff9ebe-6577-45e5-81b2-eb9ad2e3abba'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/e3ff9ebe-6577-45e5-81b2-eb9ad2e3abba',
    'router_path' => 'uuid',
    'link_title' => 'TEI P5 Encoding Guidelines',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_tei-p5-encoding-guidelines:uuid/node/e3ff9ebe-6577-45e5-81b2-eb9ad2e3abba',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 22,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_terminology-and-acronyms:uuid/node/1c8d1749-834b-4bba-a6db-76db3bc16220.
  $menu_links['menu-livingstone-1871-diary_terminology-and-acronyms:uuid/node/1c8d1749-834b-4bba-a6db-76db3bc16220'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/1c8d1749-834b-4bba-a6db-76db3bc16220',
    'router_path' => 'uuid',
    'link_title' => 'Terminology and Acronyms',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_terminology-and-acronyms:uuid/node/1c8d1749-834b-4bba-a6db-76db3bc16220',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 21,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_the-1871-field-diary-facsimile:uuid/node/69625dff-15c4-4ff8-be0b-56b8789a7944.
  $menu_links['menu-livingstone-1871-diary_the-1871-field-diary-facsimile:uuid/node/69625dff-15c4-4ff8-be0b-56b8789a7944'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/69625dff-15c4-4ff8-be0b-56b8789a7944',
    'router_path' => 'uuid',
    'link_title' => 'The 1871 Field Diary Facsimile',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_the-1871-field-diary-facsimile:uuid/node/69625dff-15c4-4ff8-be0b-56b8789a7944',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_the-date-of-the-livingstone-stanley-meeting:uuid/node/bcafb301-2e80-4e89-879a-3210c23efb12.
  $menu_links['menu-livingstone-1871-diary_the-date-of-the-livingstone-stanley-meeting:uuid/node/bcafb301-2e80-4e89-879a-3210c23efb12'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/bcafb301-2e80-4e89-879a-3210c23efb12',
    'router_path' => 'uuid',
    'link_title' => 'The Date of the Livingstone-Stanley Meeting',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_the-date-of-the-livingstone-stanley-meeting:uuid/node/bcafb301-2e80-4e89-879a-3210c23efb12',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 12,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_the-manuscript-of-the-1871-field-diary:uuid/node/9c4e1bbc-bdba-4fc9-a213-f7fb7152585c.
  $menu_links['menu-livingstone-1871-diary_the-manuscript-of-the-1871-field-diary:uuid/node/9c4e1bbc-bdba-4fc9-a213-f7fb7152585c'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/9c4e1bbc-bdba-4fc9-a213-f7fb7152585c',
    'router_path' => 'uuid',
    'link_title' => 'The Manuscript of the 1871 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_the-manuscript-of-the-1871-field-diary:uuid/node/9c4e1bbc-bdba-4fc9-a213-f7fb7152585c',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_the-third-massacre-narrative:uuid/node/6453ebdd-b8e9-41ce-937b-d534198f06a8.
  $menu_links['menu-livingstone-1871-diary_the-third-massacre-narrative:uuid/node/6453ebdd-b8e9-41ce-937b-d534198f06a8'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/6453ebdd-b8e9-41ce-937b-d534198f06a8',
    'router_path' => 'uuid',
    'link_title' => 'The Third Massacre Narrative',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_the-third-massacre-narrative:uuid/node/6453ebdd-b8e9-41ce-937b-d534198f06a8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-1871-diary_three-versions-of-the-1871-field-diary:uuid/node/b941bdf2-38e1-4447-8c38-75449da48309.
  $menu_links['menu-livingstone-1871-diary_three-versions-of-the-1871-field-diary:uuid/node/b941bdf2-38e1-4447-8c38-75449da48309'] = array(
    'menu_name' => 'menu-livingstone-1871-diary',
    'link_path' => 'uuid/node/b941bdf2-38e1-4447-8c38-75449da48309',
    'router_path' => 'uuid',
    'link_title' => 'Three Versions of the 1871 Field Diary',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-1871-diary_three-versions-of-the-1871-field-diary:uuid/node/b941bdf2-38e1-4447-8c38-75449da48309',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_acknowledgments:uuid/node/2d9c6d93-18a3-4b54-ba84-e668adbd7361.
  $menu_links['menu-livingstone-letter-bambarre_acknowledgments:uuid/node/2d9c6d93-18a3-4b54-ba84-e668adbd7361'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/2d9c6d93-18a3-4b54-ba84-e668adbd7361',
    'router_path' => 'uuid',
    'link_title' => 'Acknowledgments',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_acknowledgments:uuid/node/2d9c6d93-18a3-4b54-ba84-e668adbd7361',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0.
  $menu_links['menu-livingstone-letter-bambarre_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0',
    'router_path' => 'uuid',
    'link_title' => 'An Integrated Bibliography',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_an-integrated-bibliography:uuid/node/b33a7f9f-edeb-4611-a294-8d92020bf9f0',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_an-introduction-to-spectral-imaging:uuid/node/6b92625f-5f97-46c4-845c-54a9516137ca.
  $menu_links['menu-livingstone-letter-bambarre_an-introduction-to-spectral-imaging:uuid/node/6b92625f-5f97-46c4-845c-54a9516137ca'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/6b92625f-5f97-46c4-845c-54a9516137ca',
    'router_path' => 'uuid',
    'link_title' => 'An Introduction to Spectral Imaging',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_an-introduction-to-spectral-imaging:uuid/node/6b92625f-5f97-46c4-845c-54a9516137ca',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 11,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_background-of-the-edition:uuid/node/72224f6c-477c-4e88-9a84-a625a61d4681.
  $menu_links['menu-livingstone-letter-bambarre_background-of-the-edition:uuid/node/72224f6c-477c-4e88-9a84-a625a61d4681'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/72224f6c-477c-4e88-9a84-a625a61d4681',
    'router_path' => 'uuid',
    'link_title' => 'Background of the Edition',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_background-of-the-edition:uuid/node/72224f6c-477c-4e88-9a84-a625a61d4681',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_conservation-and-transport-:uuid/node/9d934abd-24be-4b78-bd98-8b5a4ae956e0.
  $menu_links['menu-livingstone-letter-bambarre_conservation-and-transport-:uuid/node/9d934abd-24be-4b78-bd98-8b5a4ae956e0'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/9d934abd-24be-4b78-bd98-8b5a4ae956e0',
    'router_path' => 'uuid',
    'link_title' => 'Conservation and Transport	',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_conservation-and-transport-:uuid/node/9d934abd-24be-4b78-bd98-8b5a4ae956e0',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 12,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_data-management:uuid/node/4e938263-a435-4fd2-9e4b-267153763d3f.
  $menu_links['menu-livingstone-letter-bambarre_data-management:uuid/node/4e938263-a435-4fd2-9e4b-267153763d3f'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/4e938263-a435-4fd2-9e4b-267153763d3f',
    'router_path' => 'uuid',
    'link_title' => 'Data Management',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_data-management:uuid/node/4e938263-a435-4fd2-9e4b-267153763d3f',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 15,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_edition-guide:uuid/node/55a1e9ea-f6d4-4713-a8d1-a810ecbe1c20.
  $menu_links['menu-livingstone-letter-bambarre_edition-guide:uuid/node/55a1e9ea-f6d4-4713-a8d1-a810ecbe1c20'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/55a1e9ea-f6d4-4713-a8d1-a810ecbe1c20',
    'router_path' => 'uuid',
    'link_title' => 'Edition Guide',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_edition-guide:uuid/node/55a1e9ea-f6d4-4713-a8d1-a810ecbe1c20',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_images-and-transcription-of-the-letter:in-his-own-words/catalogue.
  $menu_links['menu-livingstone-letter-bambarre_images-and-transcription-of-the-letter:in-his-own-words/catalogue'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'in-his-own-words/catalogue',
    'router_path' => 'in-his-own-words',
    'link_title' => 'Images and Transcription of the Letter',
    'options' => array(
      'query' => array(
        'query' => 'liv_002564',
        'view_pid' => 'liv:002564',
        'view_page' => 0,
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_images-and-transcription-of-the-letter:in-his-own-words/catalogue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_imaging-the-letter:uuid/node/d766c0a2-d67a-467f-b4a1-422cd48779e9.
  $menu_links['menu-livingstone-letter-bambarre_imaging-the-letter:uuid/node/d766c0a2-d67a-467f-b4a1-422cd48779e9'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/d766c0a2-d67a-467f-b4a1-422cd48779e9',
    'router_path' => 'uuid',
    'link_title' => 'Imaging the Letter',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_imaging-the-letter:uuid/node/d766c0a2-d67a-467f-b4a1-422cd48779e9',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 13,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_introduction-to-the-edition:uuid/node/8229df32-720a-4447-82e1-9f17f8de0d71.
  $menu_links['menu-livingstone-letter-bambarre_introduction-to-the-edition:uuid/node/8229df32-720a-4447-82e1-9f17f8de0d71'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/8229df32-720a-4447-82e1-9f17f8de0d71',
    'router_path' => 'uuid',
    'link_title' => 'Introduction to the Edition',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_introduction-to-the-edition:uuid/node/8229df32-720a-4447-82e1-9f17f8de0d71',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5.
  $menu_links['menu-livingstone-letter-bambarre_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5',
    'router_path' => 'uuid',
    'link_title' => 'Key Terms in Livingstone\'s Manuscripts, 1870-71',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_key-terms-in-livingstones-manuscripts-1870-71:uuid/node/749fac17-d2c6-49e7-bfed-0aca417379b5',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_livingstones-letter-with-annotations:uuid/node/e6c8584c-5b4c-4eb1-b875-ac05f66086b3.
  $menu_links['menu-livingstone-letter-bambarre_livingstones-letter-with-annotations:uuid/node/e6c8584c-5b4c-4eb1-b875-ac05f66086b3'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/e6c8584c-5b4c-4eb1-b875-ac05f66086b3',
    'router_path' => 'uuid',
    'link_title' => 'Livingstone\'s Letter with Annotations',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_livingstones-letter-with-annotations:uuid/node/e6c8584c-5b4c-4eb1-b875-ac05f66086b3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_note-on-the-text-of-the-letter:uuid/node/08909242-0281-4ba9-b57b-ed711e0b2335.
  $menu_links['menu-livingstone-letter-bambarre_note-on-the-text-of-the-letter:uuid/node/08909242-0281-4ba9-b57b-ed711e0b2335'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/08909242-0281-4ba9-b57b-ed711e0b2335',
    'router_path' => 'uuid',
    'link_title' => 'Note on the Text of the Letter',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_note-on-the-text-of-the-letter:uuid/node/08909242-0281-4ba9-b57b-ed711e0b2335',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_notes-on-processed-spectral-images:uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b.
  $menu_links['menu-livingstone-letter-bambarre_notes-on-processed-spectral-images:uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b',
    'router_path' => 'uuid',
    'link_title' => 'Notes on Processed Spectral Images',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_notes-on-processed-spectral-images:uuid/node/58a3243f-182c-4d5a-b174-293eaaf2129b',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_project-team:uuid/node/70968a8f-9950-4796-a8db-f9e6e636e34b.
  $menu_links['menu-livingstone-letter-bambarre_project-team:uuid/node/70968a8f-9950-4796-a8db-f9e6e636e34b'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/70968a8f-9950-4796-a8db-f9e6e636e34b',
    'router_path' => 'uuid',
    'link_title' => 'Project Team',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_project-team:uuid/node/70968a8f-9950-4796-a8db-f9e6e636e34b',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-livingstone-letter-bambarre_spectral-image-processing:uuid/node/b3ee9521-1ad9-4492-9298-dfa44a950820.
  $menu_links['menu-livingstone-letter-bambarre_spectral-image-processing:uuid/node/b3ee9521-1ad9-4492-9298-dfa44a950820'] = array(
    'menu_name' => 'menu-livingstone-letter-bambarre',
    'link_path' => 'uuid/node/b3ee9521-1ad9-4492-9298-dfa44a950820',
    'router_path' => 'uuid',
    'link_title' => 'Spectral Image Processing',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-livingstone-letter-bambarre_spectral-image-processing:uuid/node/b3ee9521-1ad9-4492-9298-dfa44a950820',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 14,
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
  t('1871 Field Diary Headers');
  t('Acknowledgments');
  t('An Integrated Bibliography');
  t('An Introduction to Spectral Imaging');
  t('Background of the Edition');
  t('Conservation and Transport	');
  t('Creating the 1870 Field Diary');
  t('Data Management');
  t('Edition Guide');
  t('History & Chronology of the 1870 Field Diary');
  t('Images & Transcriptions of Select 1870-1871 Texts');
  t('Images & Transcriptions of the 1870 Field Diary');
  t('Images & Transcriptions of the 1871 Field Diary');
  t('Images and Transcription of the Letter');
  t('Imaging the Letter');
  t('Introduction to the Edition');
  t('Key Terms in Livingstone\'s Manuscripts, 1870-71');
  t('Livingstone Spectral Image Collection');
  t('Livingstone in 1871');
  t('Livingstone\'s Composition Practices');
  t('Livingstone\'s Global Sources');
  t('Livingstone\'s Letter with Annotations');
  t('Livingstone\'s Manuscript Structure');
  t('Livingstone, Central Africa, 1870');
  t('Livingstone’s Composition Methods');
  t('Manuscript Citation and File Naming Practices');
  t('Note on the Text of the Letter');
  t('Note on the Three Versions of the Text');
  t('Notes on Processed Spectral Images');
  t('Overview of Processing Objectives');
  t('Project Documentation');
  t('Project History');
  t('Project History (1)');
  t('Project History (2)');
  t('Project Team');
  t('Prototyping Animated Spectral Images (ASIs)');
  t('Spectral Image Processing');
  t('Structuring the 1870 Field Diary');
  t('TEI P5 Encoding Guidelines');
  t('Terminology and Acronyms');
  t('The 1871 Field Diary Facsimile');
  t('The Date of the Livingstone-Stanley Meeting');
  t('The Diary across Hands, Space, & Time (1)');
  t('The Diary across Hands, Space, & Time (2)');
  t('The Diary across Hands, Space, & Time (3)');
  t('The Manuscript of the 1871 Field Diary');
  t('The Project Team');
  t('The Third Massacre Narrative');
  t('Three Versions of the 1870 Field Diary');
  t('Three Versions of the 1871 Field Diary');
  t('');
  t('');
  t('');
  t('');

  return $menu_links;
}
