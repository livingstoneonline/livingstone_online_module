<?php

/**
 * @file
 * Helper functions related to transcriptions.
 */

/**
 * Gets the URL to the Saxon service.
 *
 * @return string
 *   The URL to the Saxon service.
 */
function livingstone_transcript_saxon_url() {
  return "http://tomcat:8080/saxon/SaxonServlet";
}

/**
 * Generates the URL to to the Saxon service to transform the given source file.
 *
 * @param stdClass $source
 *   Drupal file object, the source file to transform.
 *
 * @return string
 *   The URL that will perform the transform.
 */
function livingstone_transcript_saxon_transform_url(stdClass $source, $style, $params = array()) {
  $default_query = array(
    'source' => livingstone_transcript_get_source_url($source),
    'style' => livingstone_transcript_get_style_url($style),
    'clear-stylesheet-cache' => 'yes',
  );
  $query = array_merge($default_query, $params);
  return url(livingstone_transcript_saxon_url(), array(
    'absolute' => TRUE,
    'external' => TRUE,
    'query' => $query,
  ));
}

/**
 * Gets the docker container relative url of the source file.
 *
 * @param stdClass $source
 *   Drupal file object.
 *
 * @return string
 *   The URL which can be used to access the file.
 */
function livingstone_transcript_get_style_url($style) {
  return url("http://livingstone/{$style}", array('absolute' => true));
}

/**
 * Gets the docker container relative url of the source file.
 *
 * @param stdClass $source
 *   Drupal file object.
 *
 * @return string
 *   The URL which can be used to access the file.
 */
function livingstone_transcript_get_source_url(stdClass $source) {
  global $base_path;
  $uri = $source->uri;
  $scheme = file_uri_scheme($uri);
  $wrapper = file_stream_wrapper_get_instance_by_scheme($scheme);
  // Get the file's path
  $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
  // Set the URL to the (relative) base path plus the file's path
  return url("http://livingstone/{$base_path}{$path}", array('absolute' => true));
}

/**
 * Fetches the style XSLT's given style if possible otherwise a default is used.
 *
 * @param string $tei
 *   The TEI to transform.
 *
 * @return string
 *   The full path to the XSLT used to style the TEI.
 */
function livingstone_transcript_transform_get_xslt($tei) {
  $leap_path = drupal_get_path('module', 'leap_xslt');
  $dom = new DOMDocument();
  $dom->loadXML($tei);
  $xpath = new DOMXpath($dom);
  $results = $xpath->query('//processing-instruction()[name() = "xml-stylesheet"]');
  foreach ($results as $result) {
    if (preg_match('/type="text\/xsl"/', $result->nodeValue)) {
      $stylesheet = preg_replace('/.*href="http:\/\/livingstoneonline.github.io\/LEAP-XSLT\/(.*)".*$/U', '$1', $result->nodeValue);
      $full_path = "$leap_path/$stylesheet";
      if (file_exists($full_path)) {
        return $full_path;
      }
    }
  }
  return drupal_get_path('module', 'livingstone_transcript') . "/xsl/transcription.xsl";
}

/**
 * Fetches the CSS link's in the given HTML document.
 *
 * @param DOMXPath $xpath
 *   DOMXPath object used to extract the css file paths.
 *
 * @return array
 *   An list of paths to the css files used by the HTML document.
 */
function livingstone_transcript_transform_get_css(DOMXPath $xpath) {
  $leap_path = drupal_get_path('module', 'leap_xslt');
  $results = $xpath->query('/html/head/link[@type="text/css"]');
  $files = array();
  foreach ($results as $result) {
    $url = $result->getAttribute('href');
    $stylesheet = preg_replace('/^http:\/\/livingstoneonline.github.io\/LEAP-XSLT\/(.*)$/U', '$1', $url);
    $full_path = "$leap_path/$stylesheet";
    if (file_exists($full_path)) {
      $files[] = $full_path;
    }
  }
  return !empty($files) ? $files : array(
    drupal_get_path('module', 'livingstone_transcript') . "/css/livingstone-default-transcript.css",
  );
}

/**
 * Pre-process the TEI prior to transformation.
 *
 * @param string $tei
 *   The TEI Document to be transformed into HTML.
 *
 * @return string
 *   The preprocessed TEI.
 */
function livingstone_transcript_transform_preprocess_tei($tei) {
  $content = preg_replace('/<\?xml-model .*\?>/', '', $tei);
  return $content;
}

/**
 * Attempts to transform the given TEI to HTML using Saxon.
 *
 * @param string $tei
 *   The TEI Document to be transformed into HTML.
 *
 * @return string|bool
 *   The transformed TEI as HTML if successful FALSE otherwise.
 */
function livingstone_transcript_saxon_transform($tei) {
  $transform = livingstone_transcript_transform_get_xslt($tei);
  $tei = livingstone_transcript_transform_preprocess_tei($tei);
  $source = file_save_data($tei, file_default_scheme() . '://');
  // File is temporary and will linger if the transform fails for debug
  // purposes, otherwise it's removed immediately.
  $source->status = 0;
  file_save($source);
  $url = livingstone_transcript_saxon_transform_url($source, $transform);
  $result = drupal_http_request($url);
  if (isset($result->error) || !isset($result->data)) {
    $message = "Saxon Transform failed to transform <a href='!tei'>TEI</a>: !url.";
    $variables = array(
      '!tei' => file_create_url($source->uri),
      '!url' => $url,
    );
    watchdog('livingstone-manuscript-viewer', $message, $variables, WATCHDOG_ERROR);
    return FALSE;
  }
  file_delete($source);
  // Write the result to the cached file.
  return $result->data;
}


/**
 * Attempts to transform the given TEI to HTML using Saxon.
 *
 * Extracts the body of the document and adds the appropriate CSS files so that
 * The document can be displayed embedded in content rather than in an iframe.
 *
 * @param AbstractDatastream $datastream
 *   The datastream TEI Document to be transformed into HTML.
 *
 * @return string|bool
 *   The transformed TEI as HTML if successful FALSE otherwise.
 */
function livingstone_transcript_saxon_transform_embedded($datastream) {
  module_load_include('inc', 'livingstone', 'includes/utilities');
  $content = livingstone_transcript_saxon_transform($datastream->content);
  if ($content == FALSE) {
    return FALSE;
  }
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->loadXML($content);
  $xpath = new DOMXPath($doc);
  $results = $xpath->query('/html/body/*[1]');
  $transcript = $results->item(0);
  $class = $transcript->getAttribute('class');
  $project_id = livingstone_pid_to_project_id($datastream->parent->id);
  $class = "{$class} transcription-viewer-content {$project_id}";
  $transcript->setAttribute('class', $class);
  $element = array(
    '#attached' => array(
      'css' => livingstone_transcript_transform_get_css($xpath),
    ),
    '#markup' => $doc->saveXML($transcript),
  );
  return drupal_render($element);
}