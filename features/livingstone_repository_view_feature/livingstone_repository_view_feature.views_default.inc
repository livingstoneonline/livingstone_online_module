<?php
/**
 * @file
 * livingstone_repository_view_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function livingstone_repository_view_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'repository';
  $view->description = '';
  $view->tag = 'livingstone';
  $view->base_table = 'node';
  $view->human_name = 'Repository';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Repository list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_repo_link' => 'field_repo_link',
    'edit_node' => 'field_repo_repository',
    'field_repo_repository' => 'field_repo_repository',
    'field_repo_city' => 'field_repo_city',
    'field_repo_state' => 'field_repo_state',
    'field_repo_country' => 'field_repo_country',
    'field_repo_lcnaf' => 'field_repo_lcnaf',
  );
  $handler->display->display_options['style_options']['default'] = 'field_repo_repository';
  $handler->display->display_options['style_options']['info'] = array(
    'field_repo_link' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_repo_repository' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_repo_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_repo_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_repo_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_repo_lcnaf' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_repo_link']['id'] = 'field_repo_link';
  $handler->display->display_options['fields']['field_repo_link']['table'] = 'field_data_field_repo_link';
  $handler->display->display_options['fields']['field_repo_link']['field'] = 'field_repo_link';
  $handler->display->display_options['fields']['field_repo_link']['label'] = '';
  $handler->display->display_options['fields']['field_repo_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_repo_link']['alter']['text'] = '<a href="[field_repo_link]">[field_repo_repository]</a>[edit_node]';
  $handler->display->display_options['fields']['field_repo_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_repo_link']['empty'] = '[field_repo_repository][edit_node]';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '&nbsp;&nbsp;E';
  /* Field: Content: Repository */
  $handler->display->display_options['fields']['field_repo_repository']['id'] = 'field_repo_repository';
  $handler->display->display_options['fields']['field_repo_repository']['table'] = 'field_data_field_repo_repository';
  $handler->display->display_options['fields']['field_repo_repository']['field'] = 'field_repo_repository';
  $handler->display->display_options['fields']['field_repo_repository']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_repo_repository']['alter']['text'] = '<a href="[field_repo_link]">[field_repo_repository]</a>[edit_node]';
  $handler->display->display_options['fields']['field_repo_repository']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_repo_city']['id'] = 'field_repo_city';
  $handler->display->display_options['fields']['field_repo_city']['table'] = 'field_data_field_repo_city';
  $handler->display->display_options['fields']['field_repo_city']['field'] = 'field_repo_city';
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_repo_state']['id'] = 'field_repo_state';
  $handler->display->display_options['fields']['field_repo_state']['table'] = 'field_data_field_repo_state';
  $handler->display->display_options['fields']['field_repo_state']['field'] = 'field_repo_state';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_repo_country']['id'] = 'field_repo_country';
  $handler->display->display_options['fields']['field_repo_country']['table'] = 'field_data_field_repo_country';
  $handler->display->display_options['fields']['field_repo_country']['field'] = 'field_repo_country';
  /* Field: Content: LCNF */
  $handler->display->display_options['fields']['field_repo_lcnaf']['id'] = 'field_repo_lcnaf';
  $handler->display->display_options['fields']['field_repo_lcnaf']['table'] = 'field_data_field_repo_lcnaf';
  $handler->display->display_options['fields']['field_repo_lcnaf']['field'] = 'field_repo_lcnaf';
  $handler->display->display_options['fields']['field_repo_lcnaf']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_repo_lcnaf']['alter']['text'] = '<a href="[field_repo_lcnaf]" target="_blank">LCNAF</a>';
  /* Sort criterion: Content: Repository (field_repo_repository) */
  $handler->display->display_options['sorts']['field_repo_repository_value']['id'] = 'field_repo_repository_value';
  $handler->display->display_options['sorts']['field_repo_repository_value']['table'] = 'field_data_field_repo_repository';
  $handler->display->display_options['sorts']['field_repo_repository_value']['field'] = 'field_repo_repository_value';
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
    'repository_info' => 'repository_info',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_repository');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Repository (field_repo_repository) */
  $handler->display->display_options['sorts']['field_repo_repository_value']['id'] = 'field_repo_repository_value';
  $handler->display->display_options['sorts']['field_repo_repository_value']['table'] = 'field_data_field_repo_repository';
  $handler->display->display_options['sorts']['field_repo_repository_value']['field'] = 'field_repo_repository_value';
  /* Sort criterion: Content: City (field_repo_city) */
  $handler->display->display_options['sorts']['field_repo_city_value']['id'] = 'field_repo_city_value';
  $handler->display->display_options['sorts']['field_repo_city_value']['table'] = 'field_data_field_repo_city';
  $handler->display->display_options['sorts']['field_repo_city_value']['field'] = 'field_repo_city_value';
  /* Sort criterion: Content: State (field_repo_state) */
  $handler->display->display_options['sorts']['field_repo_state_value']['id'] = 'field_repo_state_value';
  $handler->display->display_options['sorts']['field_repo_state_value']['table'] = 'field_data_field_repo_state';
  $handler->display->display_options['sorts']['field_repo_state_value']['field'] = 'field_repo_state_value';
  /* Sort criterion: Content: Country (field_repo_country) */
  $handler->display->display_options['sorts']['field_repo_country_value']['id'] = 'field_repo_country_value';
  $handler->display->display_options['sorts']['field_repo_country_value']['table'] = 'field_data_field_repo_country';
  $handler->display->display_options['sorts']['field_repo_country_value']['field'] = 'field_repo_country_value';
  $translatables['repository'] = array(
    t('Master'),
    t('Repository list'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[field_repo_link]">[field_repo_repository]</a>[edit_node]'),
    t('[field_repo_repository][edit_node]'),
    t('&nbsp;&nbsp;E'),
    t('Repository'),
    t('City'),
    t('State'),
    t('Country'),
    t('LCNF'),
    t('<a href="[field_repo_lcnaf]" target="_blank">LCNAF</a>'),
    t('Block'),
  );
  $export['repository'] = $view;

  return $export;
}
