<?php

/**
 * @file
 * Helpers for this module.
 */

/**
 * Gets an orderd list of all pages in the given manuscript.
 *
 * @param string $pid
 *   The PID of the manuscript.
 *
 * @return array
 *   An associative array containing all the relevant information about the
 *   given manuscripts pages.
 */
function livingstone_manuscript_pages($pid) {
  global $user;
  $filter_hidden = '';
  if (!in_array('administrator', $user->roles)){
    $filter_hidden = <<<EOT
    OPTIONAL {
      ?pid <fedora-view:disseminates> ?policy .
      ?policy <fedora-view:disseminationType> <info:fedora/*/POLICY> .
    }
    FILTER (!BOUND(?policy))
EOT;
  }
  $query = <<<EOQ
  PREFIX islandora-rels-ext: <http://islandora.ca/ontology/relsext#>
  SELECT ?pid ?page ?width ?height ?levels
  FROM <#ri>
  WHERE {
    ?pid <fedora-rels-ext:isMemberOf> <info:fedora/{$pid}> ;
         <islandora-rels-ext:isSequenceNumber> ?page ;
         <fedora-model:state> <fedora-model:Active> .
    OPTIONAL {
      ?pid <fedora-view:disseminates> ?dss .
      ?dss <fedora-view:disseminationType> <info:fedora/*/JP2> .
      ?pid  <islandora-rels-ext:width> ?width ;
               <islandora-rels-ext:height> ?height ;
               <islandora-rels-ext:levels> ?levels .
    }
    $filter_hidden
  }
  ORDER BY ?page
EOQ;
  $tuque = islandora_get_tuque_connection();
  $results = $tuque->repository->ri->sparqlQuery($query);
  // Get rid of the "extra" info...
  $map = function($o) {
    foreach ($o as $key => &$info) {
      $info = $info['value'];
    }
    $o = array_filter($o);
    return $o;
  };
  return array_map($map, $results);
}

/**
 * Gets the URL to the Saxon service.
 *
 * @return string
 *   The URL to the Saxon service.
 */
function livingstone_saxon_url() {
  return "http://localhost:8080/saxon/SaxonServlet";
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
function livingstone_saxon_transform_url(stdClass $source, $style, $params = array()) {
  $module_path = drupal_get_path('module', 'livingstone');
  $default_query = array(
    'style' => file_create_url("$module_path/xsl/$style"),
    'source' => file_create_url($source->uri),
    'clear-stylesheet-cache' => 'yes',
  );
  $query = array_merge($default_query, $params);
  return url(livingstone_saxon_url(), array(
      'absolute' => TRUE,
      'external' => TRUE,
      'query' => $query,
    ));
}

/**
 * Pre-process the TEI prior to transformation.
 */
function livingstone_transform_preprocess_tei($tei) {
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
function livingstone_saxon_transform($tei) {
  $tei = livingstone_transform_preprocess_tei($tei);
  $source = file_save_data($tei, file_default_scheme() . '://');
  // File is temporary and will linger if the transform fails for debug
  // purposes, otherwise it's removed immediately.
  $source->status = 0;
  $url = livingstone_saxon_transform_url($source, 'transcription.xsl');
  $result = drupal_http_request($url);
  if (isset($result->error) || !isset($result->data)) {
    $message = "Saxon Transform failed to transform <a href='!tei'>TEI</a>: !url.";
    $variables = array(
      '!tei' => file_create_url($source->uri),
      '!url' => $url,
    );
	watchdog('livingstone-viewer', $message, $variables, WATCHDOG_ERROR);
    return FALSE;
  }
  file_delete($source);
  return $result->data;
}
