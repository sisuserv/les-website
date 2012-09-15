<?php
/**
 * @file
 * les_slideshow.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function les_slideshow_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:node/add/slideshow
  $menu_links['navigation:node/add/slideshow'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/slideshow',
    'router_path' => 'node/add/slideshow',
    'link_title' => 'Slaidiseanss',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Slaidiseanss');


  return $menu_links;
}
