<?php

/**
 * @file
 * API documentation for the Entity translation module.
 */

/**
 * Allows modules to define their own translation info.
 *
 * @param $types
 *   The available entity types.
 *
 * @return
 *   An array of entity translation info to be merged into the entity info.
 *   The translation info is an associative array that has to match the
 *   following structure. Three nested sub-arrays keyed respectively by entity
 *   type, the 'translation' key and the 'entity_translation' key: the second
 *   one is the key defined by the core entity system while the third one
 *   registers Entity translation as a field translation handler. Elements:
 *   - class: The name of the translation handler class, which is used to handle
 *     the translation process. Defaults to 'EntityTranslationDefaultHandler'.
 *   - base path: The base menu router path to which attach the administration
 *     user interface. Defaults to "$entity_type/%$entity_type".
 *   - access callback: The access callback for the translation pages. Defaults
 *     to 'entity_translation_tab_access'.
 *   - access arguments: The access arguments for the translation pages.
 *     Defaults to array($entity_type).
 *   - view path: The menu router path to be used to view the entity. Defaults
 *     to the base path.
 *   - edit path: The menu router path to be used to edit the entity. Defaults
 *     to "$base_path/edit".
 *   - path wildcard: The menu router path wildcard identifying the entity.
 *     Defaults to "%$entity_type".
 *   - theme callback: The callback to be used to determine the translation
 *     theme. Defaults to 'variable_get'.
 *   - theme arguments: The arguments to be used to determine the translation
 *     theme. Defaults to array('admin_theme').
 *   - edit form: The key to be used to retrieve the entity object from the form
 *     state array. An empty value prevents Entity translation from performing
 *     alterations to the entity form. Defaults to $entity_type.
 */
function hook_translation_info($types = NULL) {
  $info['custom_entity'] = array(
    'translation' => array(
      'entity_translation' => array(
        'class' => 'EntityTranslationCustomEntityHandler',
        'base path' => 'custom_entity/%custom_entity',
        'access callback' => 'custom_entity_tab_access',
        'access arguments' => array(1),
        'edit form' => 'custom_entity_form_key',
      ),
    ),
  );

  return $info;
}

/**
 * Allows modules to act when a new translation is added.
 *
 * @param $entity_type
 *   The entity type.
 * @param $entity
 *   The entity.
 * @param $translation
 *   The inserted translation array.
 * @param $values
 *   The translated set of values, if any.
 */
function hook_entity_translation_insert($entity_type, $entity, $translation, $values = array()) {
}

/**
 * Allows modules to act when a translation is updated.
 *
 * @param $entity_type
 *   The entity type.
 * @param $entity
 *   The entity.
 * @param $translation
 *   The updated translation array.
 * @param $values
 *   The translated set of values, if any.
 */
function hook_entity_translation_update($entity_type, $entity, $translation, $values = array()) {
}

/**
 * Allows modules to act when a translation is deleted.
 *
 * @param $entity_type
 *   The entity type.
 * @param $entity
 *   The entity.
 * @param $langcode
 *   The langcode of the translation which was deleted.
 */
function hook_entity_translation_delete($entity_type, $entity, $langcode) {
}
