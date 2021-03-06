<?php

/**
 * @file
 * Default template implementation to display the value of a fieldset.
 *
 * @see nucleus_preprocess_fieldset()
 */
?>
<fieldset <?php print drupal_attributes($attributes); ?>>
  <?php if (!empty($title)): ?>
    <legend>
      <span class="<?php print $hook; ?>-title fieldset-legend">
        <?php print $title; ?>
      </span>
    </legend>
  <?php endif; ?>

  <?php if (!empty($content)): ?>
    <div class="<?php print $hook; ?>-constent fieldset-wrapper clearfix"<?php print drupal_attributes($attributes); ?>>
      <?php print $content; ?>
    </div>
  <?php endif; ?>
</fieldset>
