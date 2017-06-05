<?php
/**
 * @file
 * Renders the drop downs for the date range.
 */
?>
<div class="input-group">
  <span class="input-group-addon">
    <?php print _bootstrap_icon('search', t('Search')); ?>
  </span>
  <?php print theme_textfield(array('element' => $element)); ?>
</div>
