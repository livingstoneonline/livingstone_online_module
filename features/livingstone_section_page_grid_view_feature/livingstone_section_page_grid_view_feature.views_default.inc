<?php
/**
 * @file
 * livingstone_section_page_grid_view_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function livingstone_section_page_grid_view_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'section_pages_grid';
  $view->description = 'Section Pages displayed as a grid of images.';
  $view->tag = 'livingstone';
  $view->base_table = 'node';
  $view->human_name = 'Section Page: Grid';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'about_this_site' => 0,
    'behind_the_scenes' => 0,
    'in_his_own_words' => 0,
    'level_two_nodequeue' => 0,
    'life_times' => 0,
    'our_technology' => 0,
    'resouces' => 0,
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Field: Content: Grid Image */
  $handler->display->display_options['fields']['field_section_grid_image']['id'] = 'field_section_grid_image';
  $handler->display->display_options['fields']['field_section_grid_image']['table'] = 'field_data_field_section_grid_image';
  $handler->display->display_options['fields']['field_section_grid_image']['field'] = 'field_section_grid_image';
  $handler->display->display_options['fields']['field_section_grid_image']['label'] = '';
  $handler->display->display_options['fields']['field_section_grid_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_section_grid_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_section_grid_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_section_grid_image']['settings'] = array(
    'image_style' => 'section_grid_image',
    'image_link' => '',
  );
  /* Field: Content: Pre-Title */
  $handler->display->display_options['fields']['field_section_pre_title']['id'] = 'field_section_pre_title';
  $handler->display->display_options['fields']['field_section_pre_title']['table'] = 'field_data_field_section_pre_title';
  $handler->display->display_options['fields']['field_section_pre_title']['field'] = 'field_section_pre_title';
  $handler->display->display_options['fields']['field_section_pre_title']['label'] = '';
  $handler->display->display_options['fields']['field_section_pre_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_section_pre_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_section_pre_title']['alter']['text'] = '<em>[field_section_pre_title]</em><br/>';
  $handler->display->display_options['fields']['field_section_pre_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_section_teaser']['id'] = 'field_section_teaser';
  $handler->display->display_options['fields']['field_section_teaser']['table'] = 'field_data_field_section_teaser';
  $handler->display->display_options['fields']['field_section_teaser']['field'] = 'field_section_teaser';
  $handler->display->display_options['fields']['field_section_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_section_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_section_teaser']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Outbound Link */
  $handler->display->display_options['fields']['field_section_outbound_link']['id'] = 'field_section_outbound_link';
  $handler->display->display_options['fields']['field_section_outbound_link']['table'] = 'field_data_field_section_outbound_link';
  $handler->display->display_options['fields']['field_section_outbound_link']['field'] = 'field_section_outbound_link';
  $handler->display->display_options['fields']['field_section_outbound_link']['label'] = '';
  $handler->display->display_options['fields']['field_section_outbound_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_section_outbound_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_section_outbound_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_section_outbound_link']['empty'] = '[path]';
  $handler->display->display_options['fields']['field_section_outbound_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_section_outbound_link']['hide_alter_empty'] = FALSE;
  /* Field: Content: Open in New Tab */
  $handler->display->display_options['fields']['field_section_open_in_new_tab']['id'] = 'field_section_open_in_new_tab';
  $handler->display->display_options['fields']['field_section_open_in_new_tab']['table'] = 'field_data_field_section_open_in_new_tab';
  $handler->display->display_options['fields']['field_section_open_in_new_tab']['field'] = 'field_section_open_in_new_tab';
  $handler->display->display_options['fields']['field_section_open_in_new_tab']['label'] = '';
  $handler->display->display_options['fields']['field_section_open_in_new_tab']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_section_open_in_new_tab']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[field_section_outbound_link]" target="[field_section_open_in_new_tab]">
  <div class="views-field views-field-field-image"><div class="field-content">[field_section_grid_image]</div></div>
  <div class="hover">
    <div class="fields">
      <div class="views-field views-field-title"><div class="field-content">[field_section_pre_title][title]</div></div>
      <div class="views-field views-field-field-teaser"><div class="field-content">[field_section_teaser]</div></div>
    </div>
  </div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'section' => 'section',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'section_page' => 'section_page',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['filters']['in_queue']['group'] = 1;

  /* Display: About this Site */
  $handler = $view->new_display('page', 'About this Site', 'page_about_this_site');
  $handler->display->display_options['display_description'] = 'Shows Sections Pages in the \'About this Site\' section as a grid of images.';
  $handler->display->display_options['path'] = 'about-this-site';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'About this Site';
  $handler->display->display_options['menu']['description'] = 'Section Pages: About this Site';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: In His Own Words */
  $handler = $view->new_display('page', 'In His Own Words', 'page_in_his_own_words');
  $handler->display->display_options['display_description'] = 'Shows Sections Pages in the \'In His Own Words\' section as a grid of images.';
  $handler->display->display_options['path'] = 'in-his-own-words';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'In His Own Words';
  $handler->display->display_options['menu']['description'] = 'Section Pages: In His Own Words ';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Spectral Imaging */
  $handler = $view->new_display('page', 'Spectral Imaging', 'page_spectral_imaging');
  $handler->display->display_options['display_description'] = 'Shows Sections Pages in the \'Spectral Imaging\' section as a grid of images.';
  $handler->display->display_options['path'] = 'spectral-imaging';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Spectral Imaging';
  $handler->display->display_options['menu']['description'] = 'Section Pages: Spectral Imaging';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Life and Times */
  $handler = $view->new_display('page', 'Life and Times', 'page_life_and_times');
  $handler->display->display_options['display_description'] = 'Shows Sections Pages in the \'Life and Times\' section as a grid of images.';
  $handler->display->display_options['path'] = 'life-and-times';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Life and Times';
  $handler->display->display_options['menu']['description'] = 'Section Pages: Life and Times';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Behind the Scenes */
  $handler = $view->new_display('page', 'Behind the Scenes', 'page_behind_the_scenes');
  $handler->display->display_options['display_description'] = 'Shows Sections Pages in the \'Behind the Scenes\' section as a grid of images.';
  $handler->display->display_options['path'] = 'behind-the-scenes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Behind the Scenes';
  $handler->display->display_options['menu']['description'] = 'Section Pages: Behind the Scenes';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Resources */
  $handler = $view->new_display('page', 'Resources', 'page_resources');
  $handler->display->display_options['display_description'] = 'Shows Sections Pages in the \'Resources\' section as a grid of images.';
  $handler->display->display_options['path'] = 'resources';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Resources';
  $handler->display->display_options['menu']['description'] = 'Section Pages: Resources';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['section_pages_grid'] = array(
    t('Master'),
    t('<none>'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('term'),
    t('<em>[field_section_pre_title]</em><br/>'),
    t('[path]'),
    t('<a href="[field_section_outbound_link]" target="[field_section_open_in_new_tab]">
  <div class="views-field views-field-field-image"><div class="field-content">[field_section_grid_image]</div></div>
  <div class="hover">
    <div class="fields">
      <div class="views-field views-field-title"><div class="field-content">[field_section_pre_title][title]</div></div>
      <div class="views-field views-field-field-teaser"><div class="field-content">[field_section_teaser]</div></div>
    </div>
  </div>
</a>'),
    t('All'),
    t('About this Site'),
    t('Shows Sections Pages in the \'About this Site\' section as a grid of images.'),
    t('In His Own Words'),
    t('Shows Sections Pages in the \'In His Own Words\' section as a grid of images.'),
    t('Spectral Imaging'),
    t('Shows Sections Pages in the \'Spectral Imaging\' section as a grid of images.'),
    t('Life and Times'),
    t('Shows Sections Pages in the \'Life and Times\' section as a grid of images.'),
    t('Behind the Scenes'),
    t('Shows Sections Pages in the \'Behind the Scenes\' section as a grid of images.'),
    t('Resources'),
    t('Shows Sections Pages in the \'Resources\' section as a grid of images.'),
  );
  $export['section_pages_grid'] = $view;

  return $export;
}
