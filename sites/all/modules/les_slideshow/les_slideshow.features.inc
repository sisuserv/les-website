<?php
/**
 * @file
 * les_slideshow.features.inc
 */

/**
 * Implements hook_views_api().
 */
function les_slideshow_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function les_slideshow_image_default_styles() {
  $styles = array();

  // Exported image style: slider_image_full.
  $styles['slider_image_full'] = array(
    'name' => 'slider_image_full',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '590',
          'height' => '335',
        ),
        'weight' => '-10',
      ),
    ),
  );

  // Exported image style: slider_image_thumb.
  $styles['slider_image_thumb'] = array(
    'name' => 'slider_image_thumb',
    'effects' => array(
      2 => array(
        'label' => 'Muuda suurust',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => '210',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function les_slideshow_node_info() {
  $items = array(
    'slideshow' => array(
      'name' => t('Slaidiseanss'),
      'base' => 'node_content',
      'description' => t('Lisa uus slaid esilehele.'),
      'has_title' => '1',
      'title_label' => t('Pealkiri'),
      'help' => '',
    ),
  );
  return $items;
}
