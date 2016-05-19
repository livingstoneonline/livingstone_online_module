<?php

/**
 * @file
 * Theme functions for livingstone_manuscript.
 */

/**
 * Implements template_process_livingstone_manuscript_html().
 */
function template_process_livingstone_manuscript_html(array &$variables) {
  // Render out only those resources which are required for the transcript. Note
  // that only specific CSS / JS files will get loaded. Note that this must be
  // last as the other renders above may include some scripts.
  $filter = function($data) {
    $is_setting = $data['type'] == 'setting';
    $is_needed = is_string($data['data']) &&  strpos($data['data'], "livingstone") !== FALSE;
    return $is_setting || $is_needed;
  };
  $css = drupal_add_css();
  $css = array_filter($css, $filter);
  $variables['styles']  = drupal_get_css($css);
  $js = drupal_add_js();
  $js = array_filter($js, $filter);
  $variables['scripts'] = drupal_get_js('header', $js);
  $variables['content'] = drupal_render($variables['page']['content']);
}

/**
 * Implements template_preprocess_livingstone_manuscript_transcript_iframe().
 */
function template_preprocess_livingstone_manuscript_viewer(array &$variables) {
  module_load_include('inc', 'livingstone', 'includes/utilities');
  $module_path = drupal_get_path('module', 'livingstone');
  $js_path = "$module_path/js";
  $css_path = "$module_path/css";
  drupal_add_js("$js_path/jquery-1.12.2.min.js");
  drupal_add_js("$js_path/jquery.once.js");
  drupal_add_js("$js_path/jquery-ui/jquery-ui.js");
  drupal_add_css("$js_path/jquery-ui/jquery-ui.css");
  drupal_add_js("$js_path/drupal.js");
  drupal_add_js("$js_path/openseadragon.js");
  drupal_add_js("$js_path/djatoka-tile-source.js");
  //drupal_add_js("$js_path/jquery.history.js");
  drupal_add_js("$js_path/jquery.mCustomScrollbar.concat.min.js");
  drupal_add_css("$css_path/jquery.mCustomScrollbar.min.css");
  drupal_add_js("$js_path/jquery.query-object.js");
  drupal_add_js("$js_path/URI.js");
  drupal_add_js("$js_path/livingstone-manuscript-viewer.js");
  drupal_add_css("$css_path/reset.css");
  drupal_add_css("$css_path/manuscript-viewer.css");
  drupal_add_css("$css_path/slideout-menu.css");
  drupal_add_css("$css_path/transcript/style.css");
  drupal_add_js("$js_path/slideout-menu.js");

  $manuscript = $variables['manuscript'];
  $manuscript_object = islandora_object_load($manuscript);
  $display_page = $variables['display_page'];
  $pages = livingstone_manuscript_pages($manuscript);
  $variables['pages'] = $pages;
  $variables['search_form'] = drupal_get_form('search_block_form');
  $variables['search_form']['#attributes'] = array('target' => '_top');
  $variables['item_details'] = array(
    '#theme' => 'livingstone_manuscript_item_details',
    '#manuscript' => $manuscript,
  );
  $variables['transcript'] = array(
    '#theme' => 'livingstone_manuscript_transcript',
    '#manuscript' => $manuscript,
    '#display_page' => $display_page,
  );
  drupal_add_js(
    array(
      'livingstoneManuscriptViewer' => array(
        'pid' => $manuscript,
        'pages' => $pages,
        'initialPage' => $display_page,
        'hasTranscription' => isset($manuscript_object['TEI']),
        'openSeaDragon' => array(
          'options' => array(
            'prefixUrl' => file_create_url("$module_path/images/"),
          ),
        )
      ),
    ),
    'setting'
  );
}

/**
 * Implements template_process_livingstone_manuscript_transcript_iframe().
 */
function template_process_livingstone_manuscript_viewer(array &$variables) {
  $variables['search_form'] = drupal_render($variables['search_form']);
  $variables['item_details'] = drupal_render($variables['item_details']);
  $variables['transcript'] = drupal_render($variables['transcript']);
}

/**
 * Implements template_process_livingstone_manuscript_transcript_item_details().
 */
function template_preprocess_livingstone_manuscript_item_details(array &$variables) {
  $manuscript = islandora_object_load($variables['manuscript']);
  $fields = array(
  );
  // Check the TEI.
  if ($manuscript && isset($manuscript['MODS'])) {
    $dom = new DOMDocument();
    $dom->loadXML($manuscript['MODS']->content);
    $xpath = new DOMXPath($dom);
    $xpath->registerNamespace('mods', 'http://www.loc.gov/mods/v3');
    $results = $xpath->query("/mods:mods/mods:relatedItem[@type='original' and //mods:roleTerm[@type='text' and text()='repository']]");
    $repository = $results->length > 0 ? $results->item(0) : NULL;
    $fields = array(
      'title' => $xpath->evaluate('normalize-space(/mods:mods/mods:titleInfo[@type="alternative"]/mods:title/text())'),
      'authors' => $xpath->evaluate('normalize-space(/mods:mods/mods:name[@type="personal"][mods:role/mods:roleTerm[@type="text" and text() = "creator"]]/mods:namePart)'),
      'repository' => $xpath->evaluate("normalize-space(/mods:mods/mods:relatedItem//mods:namePart/text())", $repository),
      'shelfmark' => $xpath->evaluate("normalize-space(//mods:shelfLocator/text())", $repository),
      'created_date' => $manuscript->createdDate->format('Y'),
    ) + $fields;
  }
  $fields['accessed_date'] = date('d F Y');
  $variables['fields'] = $fields;
}

/**
 * Implements hook_preprocess_theme().
 */
function theme_livingstone_manuscript_transcript(array &$variables) {
  $manuscript = $variables['manuscript'];
  module_load_include('inc', 'livingstone', 'includes/utilities');
  $manuscript = islandora_object_load($manuscript);
  if ($manuscript === FALSE || !isset($manuscript['TEI'])) {
    return '<div>' . t('No Transcript available.') . '</div>';
  }
  $markup = livingstone_saxon_transform($manuscript['TEI']->content);
  if ($markup === FALSE) {
    return '<div>' . t('Failed to generate transcript.') . '</div>';
  }
  return "<div class='viewer-sidebar'>{$markup}</div>";
}
