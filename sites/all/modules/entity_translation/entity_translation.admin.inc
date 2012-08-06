<?php

/**
 * @file
 * The entity translation user interface.
 */

/**
 * Builder function for the entity translation settings form.
 */
function entity_translation_admin_form($form, $form_state) {
  $options = array();

  $form['locale_field_language_fallback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable language fallback'),
    '#description' => t('When language fallback is enabled, if a translation is not available for the requested language an existing one will be displayed.'),
    '#default_value' => variable_get('locale_field_language_fallback', TRUE),
  );

  $form['entity_translation_shared_labels'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display shared labels'),
    '#description' => t('Append a "Shared field" hint to entity form widgets shared accross translations.'),
    '#default_value' => variable_get('entity_translation_shared_labels', TRUE),
  );

  foreach (entity_get_info() as $entity_type => $info) {
    if ($info['fieldable']) {
      $options[$entity_type] = !empty($info['label']) ? t($info['label']) : $entity_type;
    }
  }

  $form['entity_translation_entity_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Translatable entity types'),
    '#description' => t('Select which entities can be translated.'),
    '#options' => $options,
    '#default_value' => variable_get('entity_translation_entity_types', array()),
  );

  $form = system_settings_form($form);

  // Menu rebuilding needs to be performed after the system settings are saved.
  $form['#submit'][] = 'entity_translation_admin_form_submit';

  return $form;
}

/**
 * Submit handler for the entity translation settings form.
 */
function entity_translation_admin_form_submit($form, $form_state) {
  // Clear the entity info cache for the new entity translation settings.
  entity_info_cache_clear();
  menu_rebuild();
}

/**
 * Translations overview page callback.
 */
function entity_translation_overview($entity_type, $entity, $callback = NULL) {
  // Entity translation and node translation share the same system path.
  if ($callback && entity_translation_node($entity_type, $entity)) {
    return entity_translation_overview_callback($callback, $entity);
  }

  $handler = entity_translation_get_handler($entity_type, $entity);

  // Initialize translations if they are empty.
  $translations = $handler->getTranslations();
  if (empty($translations->original)) {
    $handler->initTranslations();
    $handler->saveTranslations();
  }

  // Ensure that we have a coherent status between entity language and field
  // languages.
  if ($handler->initOriginalTranslation()) {
    // FIXME!
    field_attach_presave($entity_type, $entity);
    field_attach_update($entity_type, $entity);
  }

  $header = array(t('Language'), t('Source language'), t('Translation'), t('Status'), t('Operations'));
  $languages = entity_translation_languages();
  $source = $translations->original;
  $base_path = $handler->getBasePath();
  $path = $handler->getViewPath();
  $rows = array();

  if (drupal_multilingual()) {
    // If we have a view path defined for the current entity get the switch
    // links based on it.
    if ($path) {
      $links = EntityTranslationDefaultHandler::languageSwitchLinks($path);
    }

    foreach ($languages as $language) {
      $options = array();
      $language_name = $language->name;
      $langcode = $language->language;
      $edit_path = $handler->getEditPath($langcode);
      $add_path = "$base_path/edit/add/$source/$langcode";

      if ($base_path) {
        $add_links = EntityTranslationDefaultHandler::languageSwitchLinks($add_path);
        $edit_links = EntityTranslationDefaultHandler::languageSwitchLinks($edit_path);
      }

      if (isset($translations->data[$langcode])) {
        list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

        // Existing translation in the translation set: display status.
        $is_original = $langcode == $translations->original;
        $translation = $translations->data[$langcode];
        $label = _entity_translation_label($entity_type, $entity, $langcode);
        $link = isset($links->links[$langcode]['href']) ? $links->links[$langcode] : array('href' => $path, 'language' => $language);
        $row_title = l($label, $link['href'], $link);

        if (empty($link['href'])) {
          $row_title = $is_original ? $label : t('n/a');
        }

        if ($edit_path && $handler->getAccess('update') && $handler->getTranslationAccess($langcode)) {
          $link = isset($edit_links->links[$langcode]['href']) ? $edit_links->links[$langcode] : array('href' => $edit_path, 'language' => $language);
          $options[] = l(t('edit'), $link['href'], $link);
        }

        $status = $translation['status'] ? t('Published') : t('Not published');
        // @todo Add a theming function here.
        $status .= isset($translation['translate']) && $translation['translate'] ? ' - <span class="marker">' . t('outdated') . '</span>' : '';

        if ($is_original) {
          $language_name = t('<strong>@language_name</strong>', array('@language_name' => $language_name));
          $source_name = t('(original content)');
        }
        else {
          $source_name = $languages[$translation['source']]->name;
        }
      }
      else {
        // No such translation in the set yet: help user to create it.
        $row_title = $source_name = t('n/a');

        if ($source != $langcode && $handler->getAccess('update')) {
          list(, , $bundle) = entity_extract_ids($entity_type, $entity);
          $translatable = FALSE;

          foreach (field_info_instances($entity_type, $bundle) as $instance) {
            $field_name = $instance['field_name'];
            $field = field_info_field($field_name);
            if ($field['translatable']) {
              $translatable = TRUE;
              break;
            }
          }

          $link = isset($add_links->links[$langcode]['href']) ? $add_links->links[$langcode] : array('href' => $add_path, 'language' => $language);
          $options[] = $translatable ? l(t('add'), $link['href'], $link) : t('No translatable fields');
        }
        $status = t('Not translated');
      }
      $rows[] = array($language_name, $source_name, $row_title, $status, implode(" | ", $options));
    }
  }

  drupal_set_title(t('Translations of %label', array('%label' => $handler->getLabel())), PASS_THROUGH);

  // Add metadata to the build render allow to let other modules know about
  // which entity this is.
  $build['#entity_type'] = $entity_type;
  $build['#entity'] = $entity;
  $build['entity_translation_overview'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

/**
 * Calls the appropriate translation overview callback.
 */
function entity_translation_overview_callback($callback, $entity) {
  if (module_exists($callback['module'])) {
    if (isset($callback['file'])) {
      $path = isset($callback['file path']) ? $callback['file path'] : drupal_get_path('module', $callback['module']);
      require_once DRUPAL_ROOT . '/' . $path . '/' . $callback['file'];
    }
    return $callback['page callback']($entity);
  }
}

/**
 * Returns the appropriate entity label for the given language.
 */
function _entity_translation_label($entity_type, $entity, $langcode = NULL) {
  if (function_exists('title_entity_label')) {
    list (, , $bundle) = entity_extract_ids($entity_type, $entity);
    $entity_info = entity_get_info($entity_type);
    if (!empty($entity_info['entity keys']['label'])) {
      $legacy_field = $entity_info['entity keys']['label'];
      if (title_field_replacement_enabled($entity_type, $bundle, $legacy_field)) {
        return title_entity_label($entity, $entity_type, $langcode);
      }
    }
  }
  return t('view');
}

/**
 * Translation deletion confirmation form.
 */
function entity_translation_delete_confirm($form, $form_state, $entity_type, $entity, $langcode) {
  $handler = entity_translation_get_handler($entity_type, $entity);
  $languages = language_list();

  $form = array(
    '#handler' => $handler,
    '#entity_type' => $entity_type,
    '#entity' => $entity,
    '#language' => $langcode,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete the @language translation of %label?', array('@language' => $languages[$langcode]->name, '%label' => $handler->getLabel())),
    "{$handler->getBasePath()}/edit/$langcode",
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit handler for the translation deletion confirmation.
 */
function entity_translation_delete_confirm_submit($form, &$form_state) {
  $handler = $form['#handler'];
  $entity_type = $form['#entity_type'];
  $entity = $form['#entity'];
  $langcode = $form['#language'];

  // Remove the translation entry and the related fields.
  $handler->removeTranslation($langcode);
  field_attach_update($entity_type, $entity);

  // Remove any existing path alias for the removed translation.
  path_delete(array('source' => $handler->getViewPath(), 'language' => $langcode));

  $form_state['redirect'] = "{$handler->getBasePath()}/translate";
}

/*
 * Confirm form for changing field translatability.
 */
function entity_translation_translatable_form($form, &$form_state, $field_name) {
  $field = field_info_field($field_name);
  $t_args = array('%name' => $field_name);

  $warning = t('By submitting this form you will trigger a batch operation.');
  if ($field['translatable']) {
    $title = t('Are you sure you want to disable translation for the %name field?', $t_args);
    $warning .= "<br>" . t("<strong>All the existing translations of this field will be deleted.</strong><br>This action cannot be undone.");
  }
  else {
    $title = t('Are you sure you want to enable translation for the %name field?', $t_args);
  }

  // We need to keep some information for later processing.
  $form_state['field'] = $field;

  // Store the 'translatable' status on the client side to prevent outdated form
  // submits from toggling translatability.
  $form['translatable'] = array(
    '#type' => 'hidden',
    '#default_value' => $field['translatable'],
  );

  return confirm_form($form, $title, '', $warning);
}

/**
 * Submit handler for the field settings form.
 *
 * This submit handler maintains consistency between the translatability of an
 * entity and the language under which the field data is stored. When a field is
 * marked as translatable, all the data in $entity->{field_name}[LANGUAGE_NONE]
 * is moved to $entity->{field_name}[$entity_language]. When a field is marked
 * as untranslatable the opposite process occurs. Note that marking a field as
 * untranslatable will cause all of its translations to be permanently removed,
 * with the exception of the one corresponding to the entity language.
 */
function entity_translation_translatable_form_submit($form, $form_state) {
  // This is the current state that we want to reverse.
  $translatable = $form_state['values']['translatable'];
  $field_name = $form_state['field']['field_name'];
  $field = field_info_field($field_name);

  if ($field['translatable'] !== $translatable) {
    // Field translatability has changed since form creation, abort.
    $t_args = array('%field_name' => $field_name, '!translatable' => $translatable ? t('untranslatable') : t('translatable'));
    drupal_set_message(t('The field %field_name is already !translatable. No change was performed.', $t_args), 'warning');
    return;
  }

  // If a field is untranslatable, it can have no data except under
  // LANGUAGE_NONE. Thus we need a field to be translatable before we convert
  // data to the entity language. Conversely we need to switch data back to
  // LANGUAGE_NONE before making a field untranslatable lest we lose
  // information.
  $operations = array(
    array('entity_translation_translatable_batch', array(!$translatable, $field_name)),
    array('entity_translation_translatable_switch', array(!$translatable, $field_name)),
  );
  $operations = $translatable ? $operations : array_reverse($operations);

  $t_args = array('%field' => $field_name);
  $title = !$translatable ? t('Enabling translation for the %field field', $t_args) : t('Disabling translation for the %field field', $t_args);

  $batch = array(
    'title' => $title,
    'operations' => $operations,
    'finished' => 'entity_translation_translatable_batch_done',
    'file' => drupal_get_path('module', 'entity_translation') . '/entity_translation.admin.inc',
  );

  batch_set($batch);
}

/*
 * Toggle translatability of the given field.
 *
 * This is called from a batch operation, but should only run once per field.
 */
function entity_translation_translatable_switch($translatable, $field_name) {
  $field = field_info_field($field_name);

  if ($field['translatable'] === $translatable) {
    return;
  }

  $field['translatable'] = $translatable;
  field_update_field($field);

  // This is needed for versions of Drupal core 7.10 and lower.
  // See http://drupal.org/node/1380660 for details.
  drupal_static_reset('field_available_languages');
}

/**
 * Batch operation. Convert field data to or from LANGUAGE_NONE.
 */
function entity_translation_translatable_batch($translatable, $field_name, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;

    // How many entities will need processing?
    $query = new EntityFieldQuery();
    $count = $query
      ->fieldCondition($field_name)
      ->count()
      ->execute();

    if (intval($count) === 0) {
      // Nothing to do.
      $context['finished'] = 1;
      return;
    }
    $context['sandbox']['max'] = $count;
  }

  // Number of entities to be processed for each step.
  $limit = variable_get('entity_translation_translatable_batch_limit', 10);

  $offset = $context['sandbox']['progress'];
  $query = new EntityFieldQuery();
  $result = $query
    ->fieldCondition($field_name)
    ->entityOrderBy('entity_id')
    ->range($offset, $limit)
    ->execute();

  foreach ($result as $entity_type => $entities) {
    foreach (entity_load($entity_type, array_keys($entities)) as $id => $entity) {
      $context['sandbox']['progress']++;
      $handler = entity_translation_get_handler($entity_type, $entity);
      $langcode = $handler->getLanguage();

      // Skip process for language neutral entities.
      if ($langcode == LANGUAGE_NONE) {
        continue;
      }

      // We need a two-steps approach while updating field translations: given
      // that field-specific update functions might rely on the stored values to
      // perform their processing, see for instance file_field_update(), first
      // we need to store the new translations and only after we can remove the
      // old ones. Otherwise we might have data loss, since the removal of the
      // old translations might occur before the new ones are stored.
      if ($translatable && isset($entity->{$field_name}[LANGUAGE_NONE])) {
        // If the field is being switched to translatable and has data for
        // LANGUAGE_NONE then we need to move the data to the right language.
        $entity->{$field_name}[$langcode] = $entity->{$field_name}[LANGUAGE_NONE];
        // Store the original value.
        _entity_translation_update_field($entity_type, $entity, $field_name);
        $entity->{$field_name}[LANGUAGE_NONE] = array();
        // Remove the language neutral value.
        _entity_translation_update_field($entity_type, $entity, $field_name);
      }
      elseif (!$translatable && isset($entity->{$field_name}[$langcode])) {
        // The field has been marked untranslatable and has data in the entity
        // language: we need to move it to LANGUAGE_NONE and drop the other
        // translations.
        $entity->{$field_name}[LANGUAGE_NONE] = $entity->{$field_name}[$langcode];
        // Store the original value.
        _entity_translation_update_field($entity_type, $entity, $field_name);
        // Remove translations.
        foreach ($entity->{$field_name} as $langcode => $items) {
          if ($langcode != LANGUAGE_NONE) {
            $entity->{$field_name}[$langcode] = array();
          }
        }
        _entity_translation_update_field($entity_type, $entity, $field_name);
      }
      else {
        // No need to save unchanged entities.
        continue;
      }
    }
  }

  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Stores the given field translations.
 */
function _entity_translation_update_field($entity_type, $entity, $field_name) {
  $empty = 0;
  $field = field_info_field($field_name);

  // Ensure that we are trying to store only valid data.
  foreach ($entity->{$field_name} as $langcode => $items) {
    $entity->{$field_name}[$langcode] = _field_filter_items($field, $entity->{$field_name}[$langcode]);
    $empty += empty($entity->{$field_name}[$langcode]);
  }

  // Save the field value only if there is at least one item available,
  // otherwise any stored empty field value would be deleted. If this happens
  // the range queries would be messed up.
  if ($empty < count($entity->{$field_name})) {
    field_attach_presave($entity_type, $entity);
    field_attach_update($entity_type, $entity);
  }
}

/**
 * Check the exit status of the batch operation.
 */
function entity_translation_translatable_batch_done($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t("Data successfully processed."));
  }
  else {
    // @todo: Do something about this case.
    drupal_set_message(t("Something went wrong while processing data. Some nodes may appear to have lost fields."));
  }
}
