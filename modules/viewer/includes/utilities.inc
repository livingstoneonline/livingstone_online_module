<?php

/**
 * @file
 * Helpers for this module.
 */

/**
 * Gets each pages zip datastream size from Solr.
 *
 * @param string $pid
 *   The PID of the manuscript.
 *
 * @return array
 *   An associative array keyed by page pid, with the datastream size as it's
 *   value in bytes.
 */
function livingstone_manuscript_viewer_page_sizes($pid) {
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search(
      "RELS_EXT_isMemberOf_uri_s:\"info:fedora/$pid\"",
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
 * Fetches the labels from the manuscripts TEI document if available.
 *
 * If not TEI document is available it returns a generate list of labels based
 * on page index.
 *
 * @param string $pid
 *   The PID of the manuscript.
 *
 * @return array
 *   An array of associative arrays in order, containing a field for each 'pid'
 *   and 'label'.
 */
function livingstone_manuscript_viewer_page_labels($pid, $pages) {
  $cache = &drupal_static(__FUNCTION__, array());
  if (empty($cache[$pid])) {
    $object = islandora_object_load($pid);
    $cache[$pid] = array();
    if (isset($object['TEI'])) {
      $dom = new DOMDocument();
      $dom->loadxml($object['TEI']->content);
      $xpath = new DOMXPath($dom);
      $xpath->registerNamespace('tei', 'http://www.tei-c.org/ns/1.0');
      $results = $xpath->query('//tei:pb[@facs and @n]');
      foreach ($results as $result) {
        $facs = $result->getAttribute('facs');
        $cache[$pid][] = array(
          'pid' => str_replace('liv_', 'liv:', $facs),
          'label' => $result->getattribute('n'),
        );
      }
    }
    else {
      $index = 0;
      foreach ($pages as $page) {
        $cache[$pid][] = array(
          'pid' => $page['pid'],
          'label' => sprintf('%04d', $index+=1)
        );
      }
    }
  }
  return $cache[$pid];
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
function livingstone_manuscript_viewer_pages($pid) {
  module_load_include('inc', 'islandora', 'includes/authtokens');
  global $user;
  $filter_hidden = '';
  // Prevent non-administrators from accessing hidden pages.
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
  $sizes = livingstone_manuscript_viewer_page_sizes($pid);
  // Add tokens and sizes, for use in Djatoka viewer for administrative access.
  $index = 0;
  foreach ($pages as &$page) {
    $pid = $page['pid'];
    $page['labels'] = array();
    $page['size'] = isset($sizes[$pid]) ? (int) $sizes[$pid] : FALSE;
    foreach ($page['dsid'] as $dsid) {
      $page['token'][$dsid] = islandora_get_object_token($pid, $dsid, 2);
    }
  }
  // Set the labels.
  $labels = livingstone_manuscript_viewer_page_labels($pid, $pages);
  foreach ($labels as $label) {
    $pages[$label['pid']]['labels'][] = $label['label'];
  }
  return $pages;
}

/**
 * Filter only those resources (CSS / JS) which are part of this module.
 *
 * @param mixed $resource
 *   The CSS or JS resource to filter.
 *
 * @return bool
 *   TRUE to keep the resource and FALSE to filter it out.
 */
function livingstone_manuscript_viewer_filter_module_resources($resource) {
  $module_path = drupal_get_path('module', 'livingstone_manuscript_viewer');
  $module_path_length = strlen($module_path);
  $is_setting = $resource['type'] == 'setting';
  $from_module = FALSE;
  if (is_string($resource['data'])) {
    $from_module = strncmp($resource['data'], $module_path, $module_path_length) == 0;
  }
  return $is_setting || $from_module;
}

/**
 * Get the requested CSS resources provided by this module.
 */
function livingstone_manuscript_viewer_css_resources() {
  $css = drupal_add_css();
  $css = array_filter($css, 'livingstone_manuscript_viewer_filter_module_resources');
  return drupal_get_css($css);
}

/**
 * Get the requested JS resources provided by this module.
 */
function livingstone_manuscript_viewer_js_resources() {
  $js = drupal_add_js();
  $js = array_filter($js, 'livingstone_manuscript_viewer_filter_module_resources');
  return drupal_get_js('header', $js);
}