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
  $query = <<<EOQ
  PREFIX islandora-rels-ext: <http://islandora.ca/ontology/relsext#>
  SELECT ?pid ?page ?width ?height ?levels
  FROM <#ri>
  WHERE {
    ?pid <fedora-rels-ext:isMemberOf> <info:fedora/{$pid}> ;
         islandora-rels-ext:isSequenceNumber ?page ;
         <fedora-model:state> <fedora-model:Active> .
    OPTIONAL {
      ?pid <fedora-view:disseminates> ?dss .
      ?dss <fedora-view:disseminationType> <info:fedora/*/JP2> ;
           islandora-rels-ext:width ?width ;
           islandora-rels-ext:height ?height ;
           islandora-rels-ext:levels ?levels .
    }
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
  dd($result->data);
  return $result->data;
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
function livingstone_saxon_transform_page($tei, $page) {
  $markup = livingstone_saxon_transform($tei);
  if ($markup === FALSE) {
    return FALSE;
  }
  $source = file_save_data($markup, file_default_scheme() . '://');
  // File is temporary and will linger if the transform fails for debug
  // purposes, otherwise it's removed immediately.
  $source->status = 0;
  $url = livingstone_saxon_transform_url($source, 'extract-page.xsl', array('page' => $page));
  $result = drupal_http_request($url);
  if (isset($result->error) || !isset($result->data)) {
    $message = "Saxon Transform failed to transform <a href='!file'>file</a>: !url.";
    $variables = array(
      '!file' => file_create_url($source->uri),
      '!url' => $url,
    );
    watchdog('livingstone-viewer', $message, $variables, WATCHDOG_ERROR);
    return FALSE;
  }
  file_delete($source);
  return $result->data;
}
//   $doc = new DOMDocument();
//   $doc->loadHTML($markup);
//   $xpath = new DOMXPath($doc);
//   $results = $xpath->query("//div[@class = 'transcription']");
//   if ($results->length == 1) {
//     $transcript = $results->item(0);
//     $results = $xpath->query("//following-sibling::span[@class = 'pb-title'][$page] | precd", $transcript);
//     if ($results->length == 1) {
//       $page = $results->item(0);
//       dsm($page);
//       $results = $xpath->query("following-sibling::node()[@class != 'pb-title']", $page);
//       dsm($results->length);
//       foreach($results as $result) {
//         dsm($result->tagName);
//       }
//       dsm($results->length);
//     }

//   }
// }

/**
module_load_include('inc', 'livingstone', 'includes/utilities');
$manuscript = 'liv:000490';
$manuscript = islandora_object_load($manuscript);
$markup = livingstone_saxon_transform_page($manuscript['TEI']->content, 0);
*/

/**
 * Gets a list of public viewable manuscripts.
 *
 * @return array
 *   An array containing viewable manuscripts which are available to the public.
 */
function livingstone_public_viewable_manuscripts() {
  $manuscripts = &drupal_static(__FUNCTION__);
  if (!isset($manuscripts)) {
    if ($cache = cache_get('livingstone_public_viewable_manuscripts')) {
      $manuscripts = $cache->data;
    }
    else {
      // Select all manuscripts which have pages, that lack POLCY datastreams.
      $query = <<<EOT
PREFIX fedora-model: <info:fedora/fedora-system:def/model#>
PREFIX fedora-view: <info:fedora/fedora-system:def/view#>
PREFIX islandora: <http://islandora.ca/ontology/relsext#>
SELECT DISTINCT ?manuscript FROM <#ri>
WHERE {
    ?object <islandora:isPageOf> ?manuscript  .
    ?object <fedora-model:state> <fedora-model:Active> .
    ?manuscript <fedora-model:state> <fedora-model:Active> .
    OPTIONAL {
       ?object <fedora-view:disseminates> ?disseminates .
       ?disseminates <fedora-view:disseminationType>  <info:fedora/*/POLICY> .
    }
    FILTER (!BOUND(?disseminates))
}
EOT;
      $tuque = islandora_get_tuque_connection();
      $results = $tuque->repository->ri->sparqlQuery($query);
      $map = function($o) {
        return $o['manuscript']['value'];
      };
      $manuscripts = array_map($map, $results);
      cache_set('livingstone_public_viewable_manuscripts', $manuscripts, 'cache');
    }
  }
  return $manuscripts;
}

/**
 * Gets a list of hidden viewable manuscripts.
 *
 * @return array
 *   An array containing viewable manuscripts which are hidden from the public.
 */
function livingstone_private_viewable_manuscripts() {
  $manuscripts = &drupal_static(__FUNCTION__);
  if (!isset($manuscripts)) {
    if ($cache = cache_get(__FUNCTION__)) {
      $manuscripts = $cache->data;
    }
    else {
      // Select all manuscripts which have pages, that lack POLCY datastreams.
      $query = <<<EOT
PREFIX fedora-model: <info:fedora/fedora-system:def/model#>
PREFIX fedora-view: <info:fedora/fedora-system:def/view#>
PREFIX islandora: <http://islandora.ca/ontology/relsext#>
SELECT DISTINCT ?manuscript FROM <#ri>
WHERE {
    ?object <islandora:isPageOf> ?manuscript  .
    ?object <fedora-model:state> <fedora-model:Active> .
    ?manuscript <fedora-model:state> <fedora-model:Active> .
    OPTIONAL {
       ?object <fedora-view:disseminates> ?disseminates .
       ?disseminates <fedora-view:disseminationType>  <info:fedora/*/POLICY> .
    }
    FILTER (BOUND(?disseminates))
}
EOT;
      $tuque = islandora_get_tuque_connection();
      $results = $tuque->repository->ri->sparqlQuery($query);
      $map = function($o) {
        return $o['manuscript']['value'];
      };
      $manuscripts = array_map($map, $results);
      cache_set(__FUNCTION__, $manuscripts, 'cache');
    }
  }
  return $manuscripts;
}

/**
 * Gets a list of all viewable manuscripts.
 *
 * @return array
 *   An array containing manuscripts which can be viewed (assuming permission).
 */
function livingstone_all_viewable_manuscripts() {
  $manuscripts = &drupal_static(__FUNCTION__);
  if (!isset($manuscripts)) {
    if ($cache = cache_get(__FUNCTION__)) {
      $manuscripts = $cache->data;
    }
    else {
      // Select all manuscripts which have pages, that lack POLCY datastreams.
      $query = <<<EOT
PREFIX fedora-model: <info:fedora/fedora-system:def/model#>
PREFIX fedora-view: <info:fedora/fedora-system:def/view#>
PREFIX islandora: <http://islandora.ca/ontology/relsext#>
SELECT DISTINCT ?manuscript FROM <#ri>
WHERE {
    ?object <islandora:isPageOf> ?manuscript  .
    ?object <fedora-model:state> <fedora-model:Active> .
    ?manuscript <fedora-model:state> <fedora-model:Active> .
}
EOT;
      $tuque = islandora_get_tuque_connection();
      $results = $tuque->repository->ri->sparqlQuery($query);
      $map = function($o) {
        return $o['manuscript']['value'];
      };
      $manuscripts = array_map($map, $results);
      cache_set(__FUNCTION__, $manuscripts, 'cache');
    }
  }
  return $manuscripts;
}


/**
 * Gets a list of public viewable manuscripts.
 *
 * @return array
 *   An array containing viewable manuscripts which are available to the public.
 */
function livingstone_public_downloadable_manuscripts() {
  $manuscripts = &drupal_static(__FUNCTION__);
  if (!isset($manuscripts)) {
    if ($cache = cache_get('livingstone_public_viewable_manuscripts')) {
      $manuscripts = $cache->data;
    }
    else {
      // Select all manuscripts which have pages, that lack POLCY datastreams.
      $query = <<<EOT
PREFIX fedora-model: <info:fedora/fedora-system:def/model#>
PREFIX fedora-view: <info:fedora/fedora-system:def/view#>
PREFIX islandora: <http://islandora.ca/ontology/relsext#>
SELECT DISTINCT ?manuscript FROM <#ri>
WHERE {
    ?manuscript <fedora-model:state> <fedora-model:Active> .
    OPTIONAL {
      ?manuscript <fedora-view:disseminates> ?disseminates .
      ?disseminates <fedora-view:disseminationType>  <info:fedora/*/ZIP> .
    }
    FILTER (BOUND(?disseminates))
}
EOT;
      $tuque = islandora_get_tuque_connection();
      $results = $tuque->repository->ri->sparqlQuery($query);
      $map = function($o) {
        return $o['manuscript']['value'];
      };
      $manuscripts = array_map($map, $results);
      cache_set('livingstone_public_viewable_manuscripts', $manuscripts, 'cache');
    }
  }
  return $manuscripts;
}

/**
 * Gets a list of hidden viewable manuscripts.
 *
 * @return array
 *   An array containing viewable manuscripts which are hidden from the public.
 */
function livingstone_private_downloadable_manuscripts() {
  return livingstone_public_downloadable_manuscripts();
}

/**
 * Gets a list of all viewable manuscripts.
 *
 * @return array
 *   An array containing manuscripts which can be viewed (assuming permission).
 */
function livingstone_all_downloadable_manuscripts() {
  return livingstone_public_downloadable_manuscripts();
}
