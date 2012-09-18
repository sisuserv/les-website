<?php
/**
 * @file
 * les_news.features.inc
 */

/**
 * Implements hook_views_api().
 */
function les_news_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function les_news_image_default_styles() {
  $styles = array();

  // Exported image style: news_thumbnail.
  $styles['news_thumbnail'] = array(
    'name' => 'news_thumbnail',
    'effects' => array(
      4 => array(
        'label' => 'Skaleeri ja lõika',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '120',
          'height' => '80',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
