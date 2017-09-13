<?php
/**
 * @file
 * Renders the drop downs for the date range.
 */
?>
<?php print drupal_render($element['year']); ?>
<span>or</span>
<?php print drupal_render($element['from']); ?>
<?php print drupal_render($element['to']); ?>
