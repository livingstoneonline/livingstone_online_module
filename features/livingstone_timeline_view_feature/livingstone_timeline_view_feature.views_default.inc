<?php
/**
 * @file
 * livingstone_timeline_view_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function livingstone_timeline_view_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'timeline';
  $view->description = '';
  $view->tag = 'livingstone';
  $view->base_table = 'node';
  $view->human_name = 'Timeline';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Timeline';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '300';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'simple_timeline_style';
  $handler->display->display_options['row_plugin'] = 'simple_timeline_row';
  $handler->display->display_options['row_options']['simple_timeline_date'] = array(
    'field_manuscript_dates' => 'field_manuscript_dates',
    'edit_node' => 0,
    'title' => 0,
    'field_manuscript_image' => 0,
    'field_manuscript_creators' => 0,
  );
  $handler->display->display_options['row_options']['simple_timeline_date_separator'] = '';
  $handler->display->display_options['row_options']['simple_timeline_text'] = array(
    'edit_node' => 'edit_node',
    'title' => 'title',
    'field_manuscript_creators' => 'field_manuscript_creators',
    'field_manuscript_image' => 0,
    'field_manuscript_dates' => 0,
  );
  $handler->display->display_options['row_options']['simple_timeline_text_separator'] = '<br/>';
  $handler->display->display_options['row_options']['simple_timeline_image'] = 'field_manuscript_image';
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
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/in-his-own-words/catalogue?query="[field_manuscript_pid]"&view_pid=[field_manuscript_pid]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date(s) */
  $handler->display->display_options['fields']['field_manuscript_dates']['id'] = 'field_manuscript_dates';
  $handler->display->display_options['fields']['field_manuscript_dates']['table'] = 'field_data_field_manuscript_dates';
  $handler->display->display_options['fields']['field_manuscript_dates']['field'] = 'field_manuscript_dates';
  $handler->display->display_options['fields']['field_manuscript_dates']['label'] = '';
  $handler->display->display_options['fields']['field_manuscript_dates']['element_label_colon'] = FALSE;
  /* Field: Content: Creator(s) */
  $handler->display->display_options['fields']['field_manuscript_creators']['id'] = 'field_manuscript_creators';
  $handler->display->display_options['fields']['field_manuscript_creators']['table'] = 'field_data_field_manuscript_creators';
  $handler->display->display_options['fields']['field_manuscript_creators']['field'] = 'field_manuscript_creators';
  $handler->display->display_options['fields']['field_manuscript_creators']['label'] = '';
  $handler->display->display_options['fields']['field_manuscript_creators']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_manuscript_image']['id'] = 'field_manuscript_image';
  $handler->display->display_options['fields']['field_manuscript_image']['table'] = 'field_data_field_manuscript_image';
  $handler->display->display_options['fields']['field_manuscript_image']['field'] = 'field_manuscript_image';
  $handler->display->display_options['fields']['field_manuscript_image']['label'] = '';
  $handler->display->display_options['fields']['field_manuscript_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_manuscript_image']['alter']['path'] = '/in-his-own-words/catalogue?query="[field_manuscript_pid]"&view_pid=[field_manuscript_pid]';
  $handler->display->display_options['fields']['field_manuscript_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_manuscript_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_manuscript_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_manuscript_image']['settings'] = array(
    'image_style' => 'timeline_image',
    'image_link' => '',
  );
  /* Sort criterion: Content: Date Range Start (field_manuscript_start_date) */
  $handler->display->display_options['sorts']['field_manuscript_start_date_value']['id'] = 'field_manuscript_start_date_value';
  $handler->display->display_options['sorts']['field_manuscript_start_date_value']['table'] = 'field_data_field_manuscript_start_date';
  $handler->display->display_options['sorts']['field_manuscript_start_date_value']['field'] = 'field_manuscript_start_date_value';
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
  $handler->display->display_options['filters']['title']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
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
  $handler = $view->new_display('block', 'Block', 'block_timeline');
  $handler->display->display_options['block_caching'] = '8';
  $translatables['timeline'] = array(
    t('Master'),
    t('Timeline'),
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
    t('Edit'),
    t('Title'),
    t('Block'),
  );
  $export['timeline'] = $view;

  return $export;
}
