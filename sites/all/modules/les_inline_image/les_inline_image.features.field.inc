<?php
/**
 * @file
 * les_inline_image.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function les_inline_image_field_default_fields() {
  $fields = array();

  // Exported field: 'node-article-field_inline_image'.
  $fields['node-article-field_inline_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_inline_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'entity_translation_sync' => array(
          0 => 'fid',
        ),
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'article',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_inline_image',
      'label' => 'Artikli Pilt',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'entity_translation_sync' => FALSE,
        'file_directory' => 'pildid/artiklid/inline',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '100x100',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 0,
              'plupload' => 'plupload',
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'move',
              'path' => 'file_attach',
            ),
            'source_imce' => array(
              'imce_mode' => 0,
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'insert' => 1,
          'insert_absolute' => 0,
          'insert_class' => 'inline',
          'insert_default' => 'colorbox__medium',
          'insert_styles' => array(
            'auto' => 0,
            'colorbox__gallery_thumbnail' => 0,
            'colorbox__large' => 'colorbox__large',
            'colorbox__medium' => 'colorbox__medium',
            'colorbox__news_thumbnail' => 0,
            'colorbox__slider_image_full' => 0,
            'colorbox__slider_image_thumb' => 0,
            'colorbox__thumbnail' => 'colorbox__thumbnail',
            'colorbox__x_large' => 0,
            'icon_link' => 0,
            'image' => 'image',
            'image_gallery_thumbnail' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_news_thumbnail' => 0,
            'image_slider_image_full' => 0,
            'image_slider_image_thumb' => 0,
            'image_thumbnail' => 0,
            'image_x_large' => 0,
            'link' => 0,
          ),
          'insert_width' => '590',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-page-field_inline_image'.
  $fields['node-page-field_inline_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_inline_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'entity_translation_sync' => array(
          0 => 'fid',
        ),
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_inline_image',
      'label' => 'Artikli Pilt',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'entity_translation_sync' => FALSE,
        'file_directory' => 'pildid/lehekuljed/inline',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '100x100',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 0,
              'plupload' => 'plupload',
              'reference' => 'reference',
              'remote' => 'remote',
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'file_attach',
            ),
            'source_imce' => array(
              'imce_mode' => 0,
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'insert' => 1,
          'insert_absolute' => 0,
          'insert_class' => 'inline',
          'insert_default' => 'colorbox__medium',
          'insert_styles' => array(
            'auto' => 0,
            'colorbox__gallery_thumbnail' => 0,
            'colorbox__large' => 'colorbox__large',
            'colorbox__medium' => 'colorbox__medium',
            'colorbox__news_thumbnail' => 0,
            'colorbox__slider_image_full' => 0,
            'colorbox__slider_image_thumb' => 0,
            'colorbox__thumbnail' => 'colorbox__thumbnail',
            'colorbox__x_large' => 0,
            'icon_link' => 0,
            'image' => 'image',
            'image_gallery_thumbnail' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_news_thumbnail' => 0,
            'image_slider_image_full' => 0,
            'image_slider_image_thumb' => 0,
            'image_thumbnail' => 0,
            'image_x_large' => 0,
            'link' => 0,
          ),
          'insert_width' => '590',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '-3',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Artikli Pilt');

  return $fields;
}
