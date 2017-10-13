<?php
/**
 * @file
 * livingstone_partners_view_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function livingstone_partners_view_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Partners';
  $view->description = '';
  $view->tag = 'livingstone';
  $view->base_table = 'node';
  $view->human_name = 'Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span2';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'partners' => 'partners',
    'about_this_site' => 0,
    'behind_the_scenes' => 0,
    'in_his_own_words' => 0,
    'life_times' => 0,
    'our_technology' => 0,
    'resouces' => 0,
    'slides' => 0,
  );
  /* Field: Content: Partner Link */
  $handler->display->display_options['fields']['field_partner_link']['id'] = 'field_partner_link';
  $handler->display->display_options['fields']['field_partner_link']['table'] = 'field_data_field_partner_link';
  $handler->display->display_options['fields']['field_partner_link']['field'] = 'field_partner_link';
  $handler->display->display_options['fields']['field_partner_link']['label'] = '';
  $handler->display->display_options['fields']['field_partner_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_link']['element_label_colon'] = FALSE;
  /* Field: Content: Partner Logos */
  $handler->display->display_options['fields']['field_partner_logos']['id'] = 'field_partner_logos';
  $handler->display->display_options['fields']['field_partner_logos']['table'] = 'field_data_field_partner_logos';
  $handler->display->display_options['fields']['field_partner_logos']['field'] = 'field_partner_logos';
  $handler->display->display_options['fields']['field_partner_logos']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logos']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logos']['alter']['path'] = '[field_partner_link] ';
  $handler->display->display_options['fields']['field_partner_logos']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_partner_logos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logos']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logos']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'partners' => 'partners',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Partners Block';
  $translatables['Partners'] = array(
    t('Master'),
    t('Partners'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Block'),
    t('Partners Block'),
  );
  $export['Partners'] = $view;

  return $export;
}
