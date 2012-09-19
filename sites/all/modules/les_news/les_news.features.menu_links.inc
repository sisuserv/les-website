<?php
/**
 * @file
 * les_news.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function les_news_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:uudised
  $menu_links['main-menu:uudised'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uudised',
    'router_path' => 'uudised',
    'link_title' => 'Uudised',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'langcode' => 'et',
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Uudised');


  return $menu_links;
}
