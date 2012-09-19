<?php
/**
 * @file
 * les_quick_tabs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function les_quick_tabs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}
