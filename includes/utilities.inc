<?php

/**
 * @file
 * Helpers for this module.
 */

/**
 * Gets an all the manuscript pids.
 *
 * @return array
 *   An array of all manuscript pids.
 */
function livingstone_manuscripts() {
  $query = <<<EOQ
  PREFIX islandora-rels-ext: <http://islandora.ca/ontology/relsext#>
  SELECT ?pid
  FROM <#ri>
  WHERE {
    {
      ?pid <fedora-model:state> <fedora-model:Active> ;
           <fedora-model:hasModel> <info:fedora/islandora:manuscriptCModel> .
    }
    UNION {
      ?pid <fedora-model:state> <fedora-model:Active> ;
           <fedora-model:hasModel> <info:fedora/livingstone:spectralManuscriptCModel> .
    }
  }
  ORDER BY ?pid
EOQ;
  $tuque = islandora_get_tuque_connection();
  $results = $tuque->repository->ri->sparqlQuery($query);
  // Get rid of the "extra" info...
  $map = function($result) {
    return $result['pid']['value'];
  };
  $pids = array_map($map, $results);
  return $pids;
}

/**
 * Gets the zip datastream sizes from Solr.
 */
function livingstone_datastream_sizes($manuscript) {
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search(
      "RELS_EXT_isMemberOf_uri_s:\"info:fedora/$manuscript\"",
      0,
      10000,
      array(
        'fl' => 'PID,fedora_datastream_latest_ZIP_SIZE_ms',
      ),
      'GET'
    );
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  $results = isset($results) ? json_decode($results->getRawResponse(), TRUE) : array();
  $docs = $results['response']['docs'];
  $objects = array();
  foreach ($docs as $doc) {
    $pid = $doc['PID'];
    $size = isset($doc['fedora_datastream_latest_ZIP_SIZE_ms']) ?
      reset($doc['fedora_datastream_latest_ZIP_SIZE_ms']) :
      FALSE;
    $objects[$pid] = $size;
  }
  return $objects;
}

/**
 * Gets an ordered list of all pages in the given manuscript.
 *
 * @param string $pid
 *   The PID of the manuscript.
 *
 * @return array
 *   An associative array containing all the relevant information about the
 *   given manuscripts pages.
 */
function livingstone_manuscript_pages($pid) {
  module_load_include('inc', 'islandora', 'includes/authtokens');
  global $user;
  $filter_hidden = '';
  if (!in_array('administrator', $user->roles)) {
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
  SELECT ?pid ?page ?dsid 
  FROM <#ri>
  WHERE {
    {
      ?pid <fedora-rels-ext:isMemberOf> <info:fedora/{$pid}> ;
         <islandora-rels-ext:isSequenceNumber> ?page ;
         <fedora-model:state> <fedora-model:Active> ;
         <fedora-model:hasModel> <info:fedora/islandora:manuscriptPageCModel> ;
         <fedora-view:disseminates> ?dsid .
      ?dsid <fedora-view:mimeType> "image/jp2" .
    } 
    UNION {
      ?pid <fedora-rels-ext:isMemberOf> <info:fedora/{$pid}> ;
         <islandora-rels-ext:isSequenceNumber> ?page ;
         <fedora-model:state> <fedora-model:Active> ;
         <fedora-model:hasModel> <info:fedora/livingstone:spectralManuscriptPageCModel> ;
         <fedora-view:disseminates> ?dsid .
      ?dsid <fedora-view:mimeType> "image/jp2" .
    }
    $filter_hidden
  }
  ORDER BY ?page ?dsid
EOQ;
  $tuque = islandora_get_tuque_connection();
  $results = $tuque->repository->ri->sparqlQuery($query);
  // Get rid of the "extra" info...
  $map = function($o) {
    foreach ($o as $key => &$info) {
      $info = ($key == 'dsid') ?
        preg_replace('/^.*\/([^\/]*)$/u', '$1', $info['value']) :
        $info['value'];
    }
    $o = array_filter($o);
    return $o;
  };
  $results = array_map($map, $results);
  // Collapse dsid field into an array.
  $pages = array();
  foreach ($results as $result) {
    $page_pid = $result['pid'];
    $pages[$page_pid]['pid'] = $page_pid;
    $pages[$page_pid]['page'] = $result['page'];
    $pages[$page_pid]['dsid'][] = $result['dsid'];
  }
  $sizes = livingstone_datastream_sizes($pid);
  // Add tokens and sizes, for use in Djatoka viewer for administrative access.
  foreach ($pages as &$page) {
    $pid = $page['pid'];
    $page['size'] = isset($sizes[$pid]) ? (int) $sizes[$pid] : FALSE;
    foreach ($page['dsid'] as $dsid) {
      $page['token'][$dsid] = islandora_get_object_token($pid, $dsid, 2);
    }
  }
  return $pages;
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
    'style' => file_create_url($style),
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
 * Fetches the style XSLT's given style if possible otherwise a default is used.
 *
 * @param string $tei
 *   The TEI to transform.
 *
 * @return string
 *   The full path to the XSLT used to style the TEI.
 */
function livingstone_transform_get_xslt($tei) {
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
  return drupal_get_path('module', 'livingstone') . "/xsl/transcription.xsl";
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
function livingstone_transform_get_css($tei) {
  $leap_path = drupal_get_path('module', 'leap_xslt');
  $dom = new DOMDocument();
  $dom->loadXML($tei);
  $xpath = new DOMXpath($dom);
  $results = $xpath->query('//processing-instruction()[name() = "xml-stylesheet"]');
  foreach ($results as $result) {
    if (preg_match('/type="text\/css"/', $result->nodeValue)) {
      $stylesheet = preg_replace('/.*href="http:\/\/livingstoneonline.github.io\/LEAP-XSLT\/(.*)".*$/U', '$1', $result->nodeValue);
      $full_path = "$leap_path/$stylesheet";
      if (file_exists($full_path)) {
        return $full_path;
      }
    }
  }
  return drupal_get_path('module', 'livingstone') . "/css/transcript/style.css";
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
  $transform = livingstone_transform_get_xslt($tei);
  $tei = livingstone_transform_preprocess_tei($tei);
  $source = file_save_data($tei, file_default_scheme() . '://');
  // File is temporary and will linger if the transform fails for debug
  // purposes, otherwise it's removed immediately.
  $source->status = 0;
  $url = livingstone_saxon_transform_url($source, $transform);
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
