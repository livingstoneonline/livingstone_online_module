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
 * Converts the given Project ID to a Fedora PID.
 *
 * @param string $project_id
 *   The Project ID to convert.
 *
 * @return string
 *   The Fedora PID generated from the Project ID.
 */
function livingstone_project_id_to_pid($project_id) {
  return preg_replace('/liv_/', 'liv:', $project_id);
}

/**
 * Converts the given Fedora PID to a Project ID.
 *
 * @param string $pid
 *   The Fedora PID to convert.
 *
 * @return string
 *   The Project ID generated from the Fedora PID.
 */
function livingstone_pid_to_project_id($pid) {
  return preg_replace('/liv:/', 'liv_', $pid);
}
