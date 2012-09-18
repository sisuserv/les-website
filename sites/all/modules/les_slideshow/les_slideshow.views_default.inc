<?php
/**
 * @file
 * les_slideshow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function les_slideshow_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'veel';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Lähtesta';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteerimise alus';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Kasvav';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Kahanev';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Vaikimisi',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_slider_link' => 0,
    'field_slider_image' => 0,
    'field_slider_image_1' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_slider_link' => 0,
    'field_slider_image' => 0,
    'field_slider_image_1' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Slaidi Link */
  $handler->display->display_options['fields']['field_slider_link']['id'] = 'field_slider_link';
  $handler->display->display_options['fields']['field_slider_link']['table'] = 'field_data_field_slider_link';
  $handler->display->display_options['fields']['field_slider_link']['field'] = 'field_slider_link';
  $handler->display->display_options['fields']['field_slider_link']['label'] = '';
  $handler->display->display_options['fields']['field_slider_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slider_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slider_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_slider_link']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_slider_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Slaidi Pilt */
  $handler->display->display_options['fields']['field_slider_image']['id'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['table'] = 'field_data_field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['field'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['label'] = '';
  $handler->display->display_options['fields']['field_slider_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['path'] = '[field_slider_link]';
  $handler->display->display_options['fields']['field_slider_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slider_image']['settings'] = array(
    'image_style' => 'slider_image_full',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_slider_image']['field_api_classes'] = 0;
  /* Field: Content: Slaidi Pilt */
  $handler->display->display_options['fields']['field_slider_image_1']['id'] = 'field_slider_image_1';
  $handler->display->display_options['fields']['field_slider_image_1']['table'] = 'field_data_field_slider_image';
  $handler->display->display_options['fields']['field_slider_image_1']['field'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_slider_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['path'] = '[field_slider_link]';
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_image_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slider_image_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_image_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slider_image_1']['settings'] = array(
    'image_style' => 'slider_image_thumb',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_slider_image_1']['field_api_classes'] = 0;
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
    'slideshow' => 'slideshow',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['slideshow'] = array(
    t('Master'),
    t('veel'),
    t('Apply'),
    t('Lähtesta'),
    t('Sorteerimise alus'),
    t('Kasvav'),
    t('Kahanev'),
    t('[field_slider_link]'),
    t('Block'),
    t('more'),
  );
  $export['slideshow'] = $view;

  return $export;
}
