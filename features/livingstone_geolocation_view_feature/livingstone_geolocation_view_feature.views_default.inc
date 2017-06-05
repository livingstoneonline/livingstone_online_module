<?php
/**
 * @file
 * livingstone_geolocation_view_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function livingstone_geolocation_view_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'geolocation';
  $view->description = 'Block displayed in the browse by location page, shows google maps.';
  $view->tag = 'livingstone';
  $view->base_table = 'node';
  $view->human_name = 'Geolocation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Geolocation';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'gmapextended';
  $handler->display->display_options['style_options']['fallback_values'] = array(
    'text' => '',
    'rmt' => '',
    'iwq' => '',
    'iwo' => '',
    'link' => '',
    'latitude' => '',
    'longitude' => '',
    'title' => '',
    'markername' => '',
    'offset' => '',
  );
  $handler->display->display_options['style_options']['field_purposes'] = array(
    'title' => 'text',
    'field_manuscript_coordinates' => '',
    'regex_rewrite' => 'longitude',
    'regex_rewrite_1' => 'latitude',
    'field_manuscript_addressees' => 'text',
    'field_manuscript_creators' => 'text',
    'field_manuscript_dates' => 'text',
  );
  $handler->display->display_options['style_options']['datasource'] = 'fields';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: PID */
  $handler->display->display_options['fields']['field_manuscript_pid']['id'] = 'field_manuscript_pid';
  $handler->display->display_options['fields']['field_manuscript_pid']['table'] = 'field_data_field_manuscript_pid';
  $handler->display->display_options['fields']['field_manuscript_pid']['field'] = 'field_manuscript_pid';
  $handler->display->display_options['fields']['field_manuscript_pid']['label'] = '';
  $handler->display->display_options['fields']['field_manuscript_pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_manuscript_pid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/in-his-own-words/catalogue?query="[field_manuscript_pid]"&view_pid=[field_manuscript_pid]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_manuscript_coordinates']['id'] = 'field_manuscript_coordinates';
  $handler->display->display_options['fields']['field_manuscript_coordinates']['table'] = 'field_data_field_manuscript_coordinates';
  $handler->display->display_options['fields']['field_manuscript_coordinates']['field'] = 'field_manuscript_coordinates';
  $handler->display->display_options['fields']['field_manuscript_coordinates']['label'] = '';
  $handler->display->display_options['fields']['field_manuscript_coordinates']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_manuscript_coordinates']['element_label_colon'] = FALSE;
  /* Field: Longitude */
  $handler->display->display_options['fields']['regex_rewrite']['id'] = 'regex_rewrite';
  $handler->display->display_options['fields']['regex_rewrite']['table'] = 'views';
  $handler->display->display_options['fields']['regex_rewrite']['field'] = 'regex_rewrite';
  $handler->display->display_options['fields']['regex_rewrite']['ui_name'] = 'Longitude';
  $handler->display->display_options['fields']['regex_rewrite']['label'] = '';
  $handler->display->display_options['fields']['regex_rewrite']['exclude'] = TRUE;
  $handler->display->display_options['fields']['regex_rewrite']['alter']['text'] = '[field_manuscript_coordinates] ';
  $handler->display->display_options['fields']['regex_rewrite']['alter']['text_patterns'] = '/^([^,]*),([^,]*)$/';
  $handler->display->display_options['fields']['regex_rewrite']['alter']['text_replacements'] = '$2';
  $handler->display->display_options['fields']['regex_rewrite']['element_label_colon'] = FALSE;
  /* Field: Latitude */
  $handler->display->display_options['fields']['regex_rewrite_1']['id'] = 'regex_rewrite_1';
  $handler->display->display_options['fields']['regex_rewrite_1']['table'] = 'views';
  $handler->display->display_options['fields']['regex_rewrite_1']['field'] = 'regex_rewrite';
  $handler->display->display_options['fields']['regex_rewrite_1']['ui_name'] = 'Latitude';
  $handler->display->display_options['fields']['regex_rewrite_1']['label'] = '';
  $handler->display->display_options['fields']['regex_rewrite_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['regex_rewrite_1']['alter']['text'] = '[field_manuscript_coordinates] ';
  $handler->display->display_options['fields']['regex_rewrite_1']['alter']['text_patterns'] = '/^([^,]*),([^,]*)$/';
  $handler->display->display_options['fields']['regex_rewrite_1']['alter']['text_replacements'] = '$1';
  $handler->display->display_options['fields']['regex_rewrite_1']['element_label_colon'] = FALSE;
  /* Field: Content: Addressee(s) */
  $handler->display->display_options['fields']['field_manuscript_addressees']['id'] = 'field_manuscript_addressees';
  $handler->display->display_options['fields']['field_manuscript_addressees']['table'] = 'field_data_field_manuscript_addressees';
  $handler->display->display_options['fields']['field_manuscript_addressees']['field'] = 'field_manuscript_addressees';
  $handler->display->display_options['fields']['field_manuscript_addressees']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_manuscript_addressees']['hide_empty'] = TRUE;
  /* Field: Content: Creator(s) */
  $handler->display->display_options['fields']['field_manuscript_creators']['id'] = 'field_manuscript_creators';
  $handler->display->display_options['fields']['field_manuscript_creators']['table'] = 'field_data_field_manuscript_creators';
  $handler->display->display_options['fields']['field_manuscript_creators']['field'] = 'field_manuscript_creators';
  $handler->display->display_options['fields']['field_manuscript_creators']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_manuscript_creators']['hide_empty'] = TRUE;
  /* Field: Content: Date(s) */
  $handler->display->display_options['fields']['field_manuscript_dates']['id'] = 'field_manuscript_dates';
  $handler->display->display_options['fields']['field_manuscript_dates']['table'] = 'field_data_field_manuscript_dates';
  $handler->display->display_options['fields']['field_manuscript_dates']['field'] = 'field_manuscript_dates';
  $handler->display->display_options['fields']['field_manuscript_dates']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_manuscript_dates']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'manuscript' => 'manuscript',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date(s) (field_manuscript_dates) */
  $handler->display->display_options['filters']['field_manuscript_dates_value']['id'] = 'field_manuscript_dates_value';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['table'] = 'field_data_field_manuscript_dates';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['field'] = 'field_manuscript_dates_value';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['group'] = 1;
  $handler->display->display_options['filters']['field_manuscript_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_manuscript_dates_value']['expose']['operator_id'] = 'field_manuscript_dates_value_op';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['expose']['operator'] = 'field_manuscript_dates_value_op';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['expose']['identifier'] = 'field_manuscript_dates_value';
  $handler->display->display_options['filters']['field_manuscript_dates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Creator(s) (field_manuscript_creators) */
  $handler->display->display_options['filters']['field_manuscript_creators_value']['id'] = 'field_manuscript_creators_value';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['table'] = 'field_data_field_manuscript_creators';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['field'] = 'field_manuscript_creators_value';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['group'] = 1;
  $handler->display->display_options['filters']['field_manuscript_creators_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_manuscript_creators_value']['expose']['operator_id'] = 'field_manuscript_creators_value_op';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['expose']['operator'] = 'field_manuscript_creators_value_op';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['expose']['identifier'] = 'field_manuscript_creators_value';
  $handler->display->display_options['filters']['field_manuscript_creators_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_geolocation');
  $handler->display->display_options['block_caching'] = '8';
  $translatables['geolocation'] = array(
    t('Master'),
    t('Geolocation'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('[title]'),
    t('[field_manuscript_coordinates] '),
    t('$2'),
    t('$1'),
    t('Addressee(s)'),
    t('Creator(s)'),
    t('Date(s)'),
    t('Block'),
  );
  $export['geolocation'] = $view;

  return $export;
}
