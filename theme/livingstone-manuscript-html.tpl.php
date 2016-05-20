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
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <meta http-equiv="Content-type" content="text/html;charset=UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=Edge" />
    <?php print $scripts; ?>
    <?php print $styles; ?>
    <link href="//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css" rel="stylesheet">
  </head>
  <body class="loading">
    <div class="modal"></div>
    <?php print $content; ?>
    <div class="slideout-menu">
      <h3>Sections <a class="slideout-menu-toggle">&times;</a></h3>
      <ul><?php print render($page['section']); ?></ul>
    </div>
  </body>
</html>
