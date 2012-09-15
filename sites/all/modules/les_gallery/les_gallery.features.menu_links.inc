<?php
/**
 * @file
 * les_gallery.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function les_gallery_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:galerii
  $menu_links['main-menu:galerii'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'galerii',
    'router_path' => 'galerii',
    'link_title' => 'Galerii',
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
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add/galerii
  $menu_links['navigation:node/add/galerii'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/galerii',
    'router_path' => 'node/add/galerii',
    'link_title' => 'Galerii',
    'options' => array(
      'attributes' => array(
        'title' => 'Lisa uus album galeriisse.',
      ),
    ),
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
  t('Galerii');


  return $menu_links;
}
