<?php

/**
 * @file
 * Taxonomy term translation handler for the entity translation module.
 */


/**
 * Taxonomy term translation handler.
 */
class EntityTranslationTaxonomyTermHandler extends EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity, $entity_id) {
    parent::__construct('taxonomy_term', $entity_info, $entity, $entity_id);
  }

  /**
   * @see EntityTranslationDefaultHandler::entityForm()
   */
  public function entityForm(&$form, &$form_state) {
    parent::entityForm($form, $form_state);

    // Remove the translation fieldset when the deletion confirm form is being
    // displayed.
    if (isset($form_state['confirm_delete'])) {
      unset($form['source_language']);
      unset($form['translation']);
      unset($form['actions']['delete_translation']);
    }
  }
}
