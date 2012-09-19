<?php
/**
 * @file
 * les_quick_tabs.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function les_quick_tabs_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'quick_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Quick Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_uudised-block',
      'hide_title' => 1,
      'title' => 'Uudised',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'comment_delta_recent',
      'hide_title' => 1,
      'title' => 'Kommentaarid',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Basic';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Kommentaarid');
  t('Quick Tabs');
  t('Uudised');

  $export['quick_tabs'] = $quicktabs;

  return $export;
}
