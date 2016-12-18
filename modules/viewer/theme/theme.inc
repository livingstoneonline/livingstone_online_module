<?php

/**
 * @file
 * Theme functions for this module.
 */

/**
 * Helper function to process the variables for HTML theme wrappers.
 */
function _process_livingstone_manuscript_viewer_html(array &$variables) {
  module_load_include('inc', 'livingstone_manuscript_viewer', 'includes/utilities');
  // Render out only those resources which are required. Note that only
  // specific CSS / JS files will get loaded.
  $variables['styles']  = livingstone_manuscript_viewer_css_resources();
  $variables['scripts'] = livingstone_manuscript_viewer_js_resources();

  // Don't render inside a region as this is not a normal page.
  unset($variables['page']['content']['#theme_wrappers']);
  unset($variables['page']['content']['#region']);

  $variables['content'] = drupal_render($variables['page']['content']);
}

/**
 * Implements template_process_livingstone_manuscript_viewer_html().
 */
function template_process_livingstone_manuscript_viewer_html(array &$variables) {
  _process_livingstone_manuscript_viewer_html($variables);
}

/**
 * Implements template_preprocess_livingstone_manuscript_viewer().
 */
function template_preprocess_livingstone_manuscript_viewer(array &$variables) {
  module_load_include('inc', 'livingstone_manuscript_viewer', 'includes/utilities');
  // Include required scripts and stylesheets.
  $module_path = drupal_get_path('module', 'livingstone_manuscript_viewer');
  $js_path = "$module_path/js";
  $css_path = "$module_path/css";
  $lib_path = "$module_path/lib";

  drupal_add_js("$lib_path/jquery/1.12.4/dist/jquery.min.js");
  drupal_add_js("$lib_path/jquery/plugins/jquery.once.js");
  drupal_add_js("$lib_path/jquery-ui/1.11.4/jquery-ui.js");
  drupal_add_css("$lib_path/jquery-ui/1.11.4/jquery-ui.css");
  drupal_add_js("$lib_path/drupal.js");
  drupal_add_js("$lib_path/openseadragon/2.2.0/openseadragon.js");
  drupal_add_js("$js_path/djatoka-tile-source.js");
  drupal_add_js("$lib_path/URI.js");
  drupal_add_js("$js_path/livingstone-manuscript-viewer.js");
  drupal_add_js("$js_path/livingstone-manuscript-viewer-downloads-modal.js");

  // @todo abstract into a theme function for top level module.
  drupal_add_js("$js_path/slideout-menu.js");
  // @todo See if I can include this from the other module.
  drupal_add_js("$js_path/search-form.js");

  drupal_add_css("$css_path/livingstone-manuscript-viewer.css", array(
    'group' => CSS_THEME,
  ));

  // Pass configuration settings to the manuscript viewer.
  $manuscript = $variables['manuscript'];
  $object = islandora_object_load($manuscript);
  $pages = livingstone_manuscript_viewer_pages($manuscript);
  $is_viewable = count($pages) > 0;
  $is_spectral = in_array('livingstone:spectralManuscriptCModel', $object->models);
  $has_transcription = isset($object['TEI']);
  drupal_add_js(
    array(
      'livingstoneManuscriptViewer' => array(
        'pid' => $manuscript,
        'pages' => $pages,
        'initialPage' => 0,//$display_page,
        'hasTranscription' => $has_transcription,
        'openSeaDragon' => array(
          'options' => array(
            'prefixUrl' => file_create_url("$module_path/images/"),
          ),
        )
      ),
    ),
    'setting'
  );
  // Build up display components.
  $variables['toolbar'] = array(
    '#theme' => 'livingstone_manuscript_viewer_toolbar',
    '#manuscript' => $manuscript,
    '#pages' => $pages,
    '#is_viewable' => $is_viewable,
    '#is_spectral' => $is_spectral,
    '#has_transcription' => $has_transcription,
  );
  $variables['panels'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'panels',
    ),
    'item-details' => array(
      '#theme' => 'livingstone_manuscript_viewer_pane_item_details',
      '#theme_wrappers' => array('livingstone_manuscript_viewer_pane'),
      '#attributes' => array(
        'class' => array('item-details'),
      ),
      '#manuscript' => $manuscript,
      '#open' => FALSE,
    ),
    'transcription' => array(
      '#access' => $has_transcription,
      '#theme' => 'livingstone_manuscript_viewer_pane_transcription',
      '#theme_wrappers' => array('livingstone_manuscript_viewer_pane'),
      '#attributes' => array(
        'class' => array('transcription'),
      ),
      '#manuscript' => $manuscript,
      '#open' => FALSE,
    ),
    'main_image' => array(
      '#access' => $is_viewable,
      '#theme' => 'livingstone_manuscript_viewer_pane_image',
      '#theme_wrappers' => array('livingstone_manuscript_viewer_pane'),
      '#attributes' => array(
        'class' => array('main-image'),
      ),
      '#identifier' => 'main-image',
      '#manuscript' => $manuscript,
      '#pages' => $pages,
      '#is_spectral' => $is_spectral,
      '#open' => TRUE,
    ),
    'compare_image' => array(
      '#access' => $is_viewable && $is_spectral,
      '#theme' => 'livingstone_manuscript_viewer_pane_image',
      '#theme_wrappers' => array('livingstone_manuscript_viewer_pane'),
      '#attributes' => array(
        'class' => array('compare-image'),
      ),
      '#identifier' => 'compare-image',
      '#manuscript' => $manuscript,
      '#pages' => $pages,
      '#is_spectral' => $is_spectral,
      '#open' => TRUE,
    ),
    'restricted' => array(
      '#access' => !$is_viewable,
      '#theme' => 'livingstone_manuscript_viewer_pane_restricted',
      '#theme_wrappers' => array('livingstone_manuscript_viewer_pane'),
      '#attributes' => array(
        'class' => array('restricted'),
      ),
      '#manuscript' => $manuscript,
      '#open' => TRUE,
    ),
  );
}

/**
 * Implements template_process_livingstone_manuscript_viewer().
 */
function template_process_livingstone_manuscript_viewer(array &$variables) {
  $variables['toolbar'] = drupal_render($variables['toolbar']);
  $variables['panels'] = drupal_render($variables['panels']);
}

/**
 * Implements template_process_livingstone_manuscript_viewer_toolbar().
 */
function template_preprocess_livingstone_manuscript_viewer_toolbar(array &$variables) {
  module_load_include('inc', 'livingstone_manuscript_viewer', 'includes/utilities');
  //$variables['is_viewable'] = true;
  //$variables['is_spectral'] = in_array('livingstone:spectralManuscriptCModel', $object->models);
  //$variables['has_transcription'] = true;
  $variables['pager_options'] = livingstone_manuscript_viewer_page_labels($variables['manuscript'], $variables['pages']);
  $variables['search'] = drupal_get_form('search_block_form');
  $variables['search']['#attributes'] = array('target' => '_top');
}

/**
 * Implements template_process_livingstone_manuscript_viewer_toolbar().
 */
function template_process_livingstone_manuscript_viewer_toolbar(array &$variables) {
  $variables['search'] = drupal_render($variables['search']);
}

/**
 * Themes a viewer pane.
 */
function theme_livingstone_manuscript_viewer_pane(array $variables) {
  $element = &$variables['element'];
  $attributes = isset($element['#attributes']) ? $element['#attributes'] : array();
  $attributes['class'][] = 'pane';
  if ($element['#open']) {
    $attributes['class'][] = 'pane-open';
  }
  if (isset($element['#side'])) {
    $attributes['class'][] = "pane-{$element['#side']}";
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";
  $output .= $element['#children'];
  $output .= "</div>\n";
  return $output;
}

/**
 * Implements template_process_livingstone_manuscript_viewer_pane_item_details().
 */
function template_preprocess_livingstone_manuscript_viewer_pane_item_details(array &$variables) {
  $pid = $variables['manuscript'];
  $object = islandora_object_load($pid);
  $fields = array();
  // Check the TEI.
  if ($object && isset($object['MODS'])) {
    $dom = new DOMDocument();
    $dom->loadXML($object['MODS']->content);
    $xpath = new DOMXPath($dom);
    $xpath->registerNamespace('mods', 'http://www.loc.gov/mods/v3');
    $results = $xpath->query("/mods:mods/mods:relatedItem[@type='original' and //mods:roleTerm[@type='text' and text()='repository']]");
    $repository = $results->length > 0 ? $results->item(0) : NULL;
    $fetch_fields = function ($query, $context = NULL) use ($xpath) {
      $fields = array();
      $results = $xpath->query($query, $context);
      foreach ($results as $result) {
        $field = trim($result->nodeValue);
        if (!empty($field)) {
          $fields[] = $field;
        }
      }
      return $fields;
    };
    $authors = $fetch_fields('/mods:mods/mods:name[@type="personal"][mods:role/mods:roleTerm[@type="text" and text() = "creator"]]/mods:namePart[normalize-space()]');
    if ($xpath->query('/mods:mods/mods:note[@displayLabel="creator"]')->length > 0) {
      $authors[] = "Unknown creator";
    }
    $credits = $fetch_fields("mods:accessCondition[@type='use and reproduction' and normalize-space()]", $repository);
    // Add hyper links.
    foreach ($credits as &$credit) {
      $credit = preg_replace('(https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*))', '<a href="\0" target="_blank">\0</a>', $credit);
    }
    $download = FALSE;
    if (in_array('livingstone:spectralManuscriptCModel', $object->models)) {
      $download = l('', "livingstone/manuscript/{$pid}/downloads", array(
        'attributes' => array(
          'class' => array(
            'livingstone-manuscript-viewer-download-modal',
            'fa',
            'fa-arrow-down',
          ),
        ),
      ));
    }
    elseif (isset($object['ZIP'])) {
      $path = "islandora/object/{$object->id}/datastream/ZIP/download";
      $attributes = array(
        'external' => FALSE,
        'attributes' => array(
          'title' => 'Download',
          'class' => array('fa fa-arrow-down'),
        ),
      );
      $size = $object['ZIP']->size;
      $size = number_format($size / 1024 / 1024, 1);
      $download = l((''), $path, $attributes) . "<span class='download-size'>($size MB)<span>";
    }
    $fields = array(
        'title' => $fetch_fields('/mods:mods/mods:titleInfo[not(@type)]/mods:title[normalize-space()]'),
        'title-alt' => $fetch_fields('/mods:mods/mods:titleInfo[@type="alternative"]/mods:title[normalize-space()]'),
        'date' => $fetch_fields('/mods:mods/mods:originInfo/mods:dateCreated[not(@encoding)]'),
        'download' => $download,
        'authors' => $authors,
        'repository' => $fetch_fields("mods:name/mods:namePart[normalize-space()]", $repository),
        'shelfmark' => $fetch_fields("mods:location/mods:shelfLocator[normalize-space()]", $repository),
        'credits' => $credits,
        'created_date' => $object->createdDate->format('Y'),
      ) + $fields;
  }
  if ($object && isset($object['TEI'])) {
    $dom = new DOMDocument();
    $dom->loadXML($object['TEI']->content);
    $xpath = new DOMXPath($dom);
    $xpath->registerNamespace('tei', 'http://www.tei-c.org/ns/1.0');
    $fields = array(
        'transcription_team' => array(),
      ) + $fields;
  }
  $fields['accessed_date'] = date('d F Y');
  $variables['fields'] = $fields;
}

/**
 * Implements template_process_livingstone_manuscript_viewer_pane_transcription().
 */
function theme_livingstone_manuscript_viewer_pane_transcription(array &$variables) {
  $pid = $variables['manuscript'];
  $src = url("livingstone/manuscript/{$pid}/transcript");
  return "<iframe id='transcription' src='{$src}' width='100%' height='100%'></iframe>";
}

/**
 * Implements template_preprocess_livingstone_manuscript_viewer_pane_image().
 */
function template_preprocess_livingstone_manuscript_viewer_pane_image(array &$variables) {
  // @todo Get urls.
  $pages = $variables['pages'];
  $page = reset($pages);
  $size = isset($page['size']) ?  number_format($page['size'] / 1024 / 1024, 1) : FALSE;
  $variables['processing_details'] = l(
    'Processing Details',
    'spectral-imaging/notes-processed-spectral-images',
    array(
      'attributes' => array(
        'target' => '_blank',
        'class' => array('processing-details', 'icon', 'button'),
      ),
    )
  );
  $variables['download'] = l(
    "<span class='fa'>&#xf063;</span>&nbsp;($size MB)",
    "islandora/object/{$page['pid']}/datastreams/ZIP/download",
    array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('icon', 'button'),
      ),
    )
  );
}

/**
 * Implements template_process_livingstone_manuscript_viewer_downloads_html().
 */
function template_process_livingstone_manuscript_viewer_downloads_html(array &$variables) {
  _process_livingstone_manuscript_viewer_html($variables);
}

/**
 * Implements template_process_livingstone_manuscript_transcript_item_details().
 */
function template_preprocess_livingstone_manuscript_viewer_downloads(array &$variables) {
  module_load_include('inc', 'livingstone_manuscript_viewer', 'includes/utilities');
  $module_path = drupal_get_path('module', 'livingstone_manuscript_viewer');
  $css_path = "$module_path/css";
  $js_path = "$module_path/js";
  $lib_path = "$module_path/lib";
  drupal_add_css("$css_path/livingstone-manuscript-viewer.css");
  drupal_add_js("$lib_path/jquery/1.12.4/dist/jquery.min.js");
  drupal_add_js("$lib_path/jquery/plugins/jquery.once.js");
  drupal_add_js("$lib_path/drupal.js");
  drupal_add_js("$js_path/livingstone-manuscript-viewer-downloads.js");

  $manuscript = islandora_object_load($variables['manuscript']);
  $variables['title'] = $manuscript->label;
  if (isset($manuscript['MODS'])) {
    $dom = new DOMDocument();
    $dom->loadXML($manuscript['MODS']->content);
    $xpath = new DOMXPath($dom);
    $xpath->registerNamespace('mods', 'http://www.loc.gov/mods/v3');
    $results = $xpath->query('/mods:mods/mods:titleInfo[@type="alternative"]/mods:title[normalize-space()][1]/text()');
    $variables['title'] = ($results->length > 0) ?
      $results->item(0)->textContent :
      $variables['title'];
  }
  $variables['downloads'] = array();
  $pages = livingstone_manuscript_viewer_pages($manuscript);
  foreach ($pages as $page) {
    if (!$page['size']) {
      continue;
    }
    $variables['downloads'][] = array(
      'size' => number_format($page['size'] / 1024 / 1024, 1),
      'label' => str_replace(':', '_', $page['pid']),
      'url' => url("islandora/object/{$page['pid']}/datastream/ZIP/download"),
    );
  }
}

/**
 * Implements template_process_livingstone_manuscript_transcript_html().
 */
function template_process_livingstone_manuscript_viewer_transcript_html(array &$variables) {
  $leap_path = drupal_get_path('module', 'leap_xslt');
  // Don't render into a region.
  unset($variables['page']['content']['#region']);
  unset($variables['page']['content']['#theme_wrappers']);
  $html = drupal_render($variables['page']['content']);
  $dom = new DOMDocument();
  $dom->loadXML($html);
  $xpath = new DOMXPath($dom);
  $results = $xpath->query('/html/head/link');
  // Alter the includes to point to the local copy.
  foreach ($results as $result) {
    $style = str_replace('http://livingstoneonline.github.io/LEAP-XSLT/', '', $result->getAttribute('href'));
    $result->setAttribute('href', url("$leap_path/$style"));
  }
  // Render out only those resources which are required. Note that only
  // specific CSS / JS files will get loaded.
  $css = livingstone_manuscript_viewer_css_resources();
  $js = livingstone_manuscript_viewer_js_resources();
  $scripts = $dom->createDocumentFragment();
  $scripts->appendXML($js);
  $scripts->appendXML($css);
  $head = $xpath->query('/html/head')->item(0);
  $head->appendChild($scripts);
  $variables['content'] = $dom->saveHTML();
}

/**
 * Implements hook_preprocess_theme().
 */
function theme_livingstone_manuscript_viewer_transcript(array &$variables) {
  module_load_include('inc', 'livingstone_manuscript_viewer', 'includes/transcript');
  module_load_include('inc', 'livingstone_manuscript_viewer', 'includes/utilities');
  $module_path = drupal_get_path('module', 'livingstone_manuscript_viewer');
  $js_path = "$module_path/js";
  $lib_path = "$module_path/lib";
  $css_path = "$module_path/css";
  drupal_add_js("$js_path/livingstone-manuscript-viewer-transcript.js");
  drupal_add_js("$lib_path/drupal.js");
  drupal_add_js("$lib_path/jquery/plugins/jquery.once.js");
  drupal_add_js("$lib_path/qtip2/2.2.1/jquery.qtip.min.js");
  drupal_add_js("$lib_path/jquery/1.12.4/dist/jquery.min.js");
  drupal_add_css("$lib_path/qtip2/2.2.1/jquery.qtip.min.css");
  drupal_add_css("$css_path/livingstone-manuscript-viewer-transcript.css");
  $manuscript = $variables['manuscript'];
  $manuscript = islandora_object_load($manuscript);
  if ($manuscript === FALSE || !isset($manuscript['TEI'])) {
    $error = t('No Transcript available.');
    return <<<EOT
<html>
  <head></head>
  <body>
    <div>$error</div>
  </body>
</html>
EOT;
  }
  $markup = livingstone_manuscript_viewer_saxon_transform($manuscript['TEI']->content);
  if ($markup === FALSE) {
    $error = t('Failed to generate transcript.') ;
    return <<<EOT
<html>
  <head></head>
  <body>
    <div>$error</div>
  </body>
</html>
EOT;
  }
  return $markup;
}
