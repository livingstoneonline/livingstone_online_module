<?php
/**
 * @file
 * Returns the a full HTML document.
 *
 * It's meant only for use within an iFrame. This is meant to be used as a
 * #theme_wrapper for #theme page, it replaces html.tpl.php.
 *
 * Complete documentation of the variables this inherits from html.tpl.php
 * is available online.
 * @see https://drupal.org/node/1728208
 *
 * Variables available:
 * - $scripts: The same as html.tpl.php defines except it may be filtered to only
 *   include CSS known to work with the transcript.
 * - $styles: The same as html.tpl.php defines except it may be filtered to only
 *   include CSS known to work with the transcript.
 * - $content: The rendered page content.

    <span style="display:none">
      <a href="#" class="slideout-menu-toggle"><i class="fa fa-bars"></i></a>
      <ul><?php print render($page['section']); ?><?php print render($page['header']); ?></ul>
    </span>

 */
?>
<?php print $content; ?>
