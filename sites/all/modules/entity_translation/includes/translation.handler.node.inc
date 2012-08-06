<?php

/**
 * @file
 * Node translation handler for the entity translation module.
 */


/**
 * Node translation handler.
 *
 * Overrides default behaviours for Node properties.
 */
class EntityTranslationNodeHandler extends EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity, $entity_id) {
    parent::__construct('node', $entity_info, $entity, $entity_id);
  }

  /**
   * @see EntityTranslationDefaultHandler::isRevision()
   */
  public function isRevision() {
    return !empty($this->entity->revision);
  }

  /**
   * @see EntityTranslationDefaultHandler::getAccess()
   */
  public function getAccess($op) {
    return node_access($op, $this->entity);
  }

  /**
   * Convert the translation update status fieldset into a vartical tab.
   */
  public function entityForm(&$form, &$form_state) {
    parent::entityForm($form, $form_state);

    // Move the translation fieldset to a vertical tab.
    if (isset($form['translation'])) {
      $form['translation'] += array(
        '#group' => 'additional_settings',
        '#weight' => 100,
        '#attached' => array(
          'js' => array(drupal_get_path('module', 'entity_translation') . '/entity_translation.node-form.js'),
        ),
      );

      if (!$this->isTranslationForm()) {
        $form['translation']['name']['#access'] = FALSE;
        $form['translation']['created']['#access'] = FALSE;
      }
    }
  }

  /**
   * @see EntityTranslationDefaultHandler::menuForm()
   */
  protected function menuForm(&$form, &$form_state) {
    module_load_include('module', 'entity_translation_i18n_menu');
    entity_translation_i18n_menu_form($form, $form_state);
  }

  /**
   * @see EntityTranslationDefaultHandler::entityFormSubmit()
   */
  public function entityFormSubmit($form, &$form_state) {
    if (!isset($form_state['values']['translation'])) {
      $form_state['values']['translation'] = array('status' => $form_state['values']['status']);
    }
    $values = &$form_state['values']['translation'];

    if (!$this->isTranslationForm()) {
      // Inherit entity authoring information for the original values.
      $values['name'] = $form_state['values']['name'];
      if (!empty($form_state['values']['date'])) {
        $values['created'] = $form_state['values']['date'];
      }
    }

    parent::entityFormSubmit($form, $form_state);
  }

  /**
   * @see EntityTranslationDefaultHandler::menuFormSubmit()
   */
  protected function menuFormSubmit($form, &$form_state) {
    // Ensure that the menu property has the 'menu_name' and 'plid' keys.
    // @todo Remove this once hook implementation calling order is fixed.
    menu_node_submit($this->entity, $form, $form_state);
  }

  /**
   * @see EntityTranslationDefaultHandler::entityFormTitle()
   */
  protected function entityFormTitle() {
    $type_name = node_type_get_name($this->entity);
    return t('<em>Edit @type</em> @title', array('@type' => $type_name, '@title' => $this->getLabel()));
  }

  /**
   * @see EntityTranslationDefaultHandler::getStatus()
   */
  protected function getStatus() {
    return (boolean) $this->entity->status;
  }
}
