<?php
/**
 * @file
 * controls load theme.
 */

require_once drupal_get_path('theme', 'tb_rave') . '/inc/preprocess_functions.inc';
function tb_rave_form_contact_site_form_alter(&$form, &$form_state) {
  drupal_set_title('');
}