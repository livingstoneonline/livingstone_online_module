<?php

/**
 * @file
 */

define('LIVINGSTONE_FIELD_CARDINALITY_ONE', 1);
define('LIVINGSTONE_FIELD_CARDINALITY_UNLIMITED', -1);
define('LIVINGSTONE_NODE_IMPORT_SOLR_TITLE_FIELD', 'title_s');
define('LIVINGSTONE_NODE_IMPORT_SOLR_TIMESTAMP_FIELD', 'timestamp');

/**
 * Works like node_load(), but takes a PID.
 *
 * @param string $pid
 *   The Manuscript object's PID from which to load the node object.
 *
 * @return stdClass|bool
 *   The node object if found, FALSE otherwise.
 */
function livingstone_node_import_node_load($pid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('pid', 'value', $pid, '=');
  $results = $query->execute();
  if (!empty($results['node'])) {
    $result = reset($results['node']);
    return node_load($result->nid);
  }
  return FALSE;
}

/**
 * Works like node_load(), but takes a PID.
 *
 * @param string $pid
 *   The Manuscript object's PID from which to load the node object.
 *
 * @return stdClass|bool
 *   The node object if found, FALSE otherwise.
 */
function livingstone_node_import_node_delete($pid) {
  $node = livingstone_node_import_node_load($pid);
  if ($node) {
    return node_delete($node->nid);
  }
  return FALSE;
}

/**
 * Checks if the given $pid has already been imported.
 *
 * @param string $pid
 *   The Manuscript object's PID from which to load the node object.
 *
 * @return bool
 *   TRUE if the node identified by PID exists, FALSE otherwise.
 */
function livingstone_node_import_node_imported($pid) {
  return livingstone_node_import_node_load($pid) != FALSE;
}

/**
 * Creates a new node for the given attributes.
 *
 * @param string $type
 *   The type of node to create.
 * @param string $title
 *   The title of the new node.
 * @param array $fields
 *   The properties to assign to the newly created node.
 *
 * @return stdClass|bool
 *   The newly created node if successful, FALSE otherwise.
 */
function livingstone_node_import_create_node($type, $title, array $fields) {
  $values = array(
    'type' => $type,
    'uid' => 1,
    'language' => LANGUAGE_NONE,
    'status' => 1,
    'promote' => 0,
    'comment' => 0,
  );
  $node = entity_create('node', $values);
  return livingstone_node_import_update_node($node, $title, $fields);
}

/**
 * Updates the given node with the given title and fields.
 *
 * @param stdClass $node
 *   The node to update.
 * @param string $title
 *   The new title of the node.
 * @param array $fields
 *   The properties to update on the node.
 *
 * @return stdClass|bool
 *   The updated node if successful, FALSE otherwise.
 */
function livingstone_node_import_update_node($node, $title, array $fields) {
  $save = FALSE;
  $wrapper = entity_metadata_wrapper('node', $node);
  if ($wrapper->title->value() != $title) {
    $save = TRUE;
    $wrapper->title->set($title);
  }
  $field_settings = livingstone_node_import_field_settings();
  try {
    foreach ($fields as $field_name => $value) {
      $type = $field_settings[$field_name]['type'];
      switch ($field_settings[$field_name]['type']) {
        case 'image':
          $md5 = isset($value[0]) ? $value[0] : NULL;
          $file = $wrapper->image->value();
          if (!$file || md5_file($file['uri']) != $md5) {
            $save = TRUE;
            $object = islandora_object_load($fields['pid']);
            if (isset($object['TN'])) {
              $uri = file_create_filename($object['TN']->label, 'public://');
              $object['TN']->getContent(drupal_realpath($uri));
              $file = new stdClass();
              $file->uid = 1;
              $file->filename = $object['TN']->label;
              $file->uri = $uri;
              $file->filemime = $object['TN']->mimetype;
              $file->filesize = filesize($uri);
              $file->status = 1;
              file_save($file);
              $wrapper->image->file->set($file);
            }
          }
          break;
        case 'date':
          $date = new DateTime($value);
          $current_value = $wrapper->raw()->{$field_name}[LANGUAGE_NONE][0]['value'];
          $new_value = $date->format('Y-m-d\TH:i:s');
          if ($current_value != $new_value) {
            $save = TRUE;
            $wrapper->raw()->{$field_name}[LANGUAGE_NONE][0] = array(
              'value' => $new_value,
              'timezone' => 'UTC',
              'timezone_db' => 'UTC',
            );
          }
          break;
        case 'text':
        case 'text_long':
        default:
          if (is_array($value)) {
            $current_value = $wrapper->{$field_name}->raw();
            if ($current_value != $value) {
              $save = TRUE;
              $wrapper->{$field_name}->set($value);
            }
          }
          else {
            $current_value = $wrapper->{$field_name}->value();
            if ($current_value != $value) {
              $save = TRUE;
              $wrapper->{$field_name}->set($value);
            }
          }
          break;
      }
    }
    // Return TRUE if saving was not needed.
    return ($save) ? $wrapper->save()->raw() : $node;
  }
  catch(Exception $e) {
    watchdog_exception('livingstone', $e);
    drupal_set_message($e->getMessage(), 'error');
  }
  return FALSE;
}

/**
 * Deletes the node identified by the given PID.
 *
 * @param string $pid
 *   The Manuscript object's PID from which to identifier the node to delete.
 */
function livingstone_node_import_delete_node($pid) {
  $node = livingstone_node_import_node_load($pid);
  if ($node) {
    node_delete($node->nid);
  }
}

/**
 * Gets an list of PID's which have nodes of the given type.
 *
 * @param string $type
 *   The type of nodes to fetch the PID's from.
 *
 * @return array
 *   An associative list of nodes where the keys are NID's and the values are
 *   PID'S.
 */
function livingstone_node_import_list_nodes($type = 'manuscript') {
  $results = db_query(
    'SELECT node.nid, field.pid_value ' .
    'FROM {node} AS node ' .
    'JOIN {field_data_pid} AS field ' .
    'ON field.entity_id = node.nid AND field.entity_type = :node ' .
    'WHERE node.type = :type',
    array(
      ':node' => 'node',
      ':type' => $type,
    )
  );
  // Key nid, value is PID.
  return $results->fetchAllKeyed(0, 1);
}

/**
 * Gets an associative list of nodes keyed by PID.
 *
 * @return array
 *   A list of PID tha
 *   PID'S.
 */
function livingstone_node_import_list_pids() {
  $query = '*:*';
  $params = livingstone_node_import_query_solr_parameters();
  $params['fl'] = array('PID');
  $response = livingstone_node_import_query_solr($query, $params);
  $docs = isset($response['response']['docs']) ? $response['response']['docs'] : array();
  $pids = array();
  foreach($docs as $doc) {
    $pids[] = $doc['PID'];
  }
  return $pids;
}

/**
 * Imports the given PID as a manuscript node.
 *
 * @param string $pid
 *   The Manuscript object's PID.
 *
 * @return stdClass|bool
 *   The node object if created, FALSE otherwise.
 */
function livingstone_node_import($pid) {
  if (!islandora_object_load($pid)) {
    return FALSE;
  }
  list($title, $fields) = livingstone_node_import_solr_fetch_data($pid);
  if ($title == FALSE) {
    return FALSE;
  }
  return livingstone_node_import_create_node('manuscript', $title, $fields);
}

/**
 * Update an existing node.
 *
 * @param string $pid
 *   The Manuscript object's PID.
 *
 * @return stdClass|bool
 *   The node object if created, FALSE otherwise.
 */
function livingstone_node_import_update($pid) {
  if (!islandora_object_load($pid)) {
    return FALSE;
  }
  $node = livingstone_node_import_node_load($pid);
  if (!$node) {
    return FALSE;
  }
  list($title, $fields) = livingstone_node_import_solr_fetch_data($pid);
  if ($title == FALSE) {
    return FALSE;
  }
  return livingstone_node_import_update_node($node, $title, $fields);
}

/**
 * Queries Solr for import data and maps it to format in which can be imported.
 *
 * @param string $pid
 *   The Manuscript object's PID.
 *
 * @return array|bool
 *   The solr data prepared for import if successful, FALSE otherwise.
 */
function livingstone_node_import_solr_fetch_data($pid) {
  $query = isset($pid) ? "PID:\"$pid\"" : '*:*';
  $params = livingstone_node_import_query_solr_parameters();
  $response = livingstone_node_import_query_solr($query, $params);
  $docs = isset($response['response']['docs']) ? $response['response']['docs'] : array();
  $doc = reset($docs);
  if (!empty($doc)) {
    $title = livingstone_node_import_map_solr_doc_to_node_title($doc);
    $fields = livingstone_node_import_map_solr_doc_to_node_fields($doc);
    return array($title, $fields);
  }
  return FALSE;
}

/**
 * Gets the title for a node from the given Solr result doc.
 *
 * @param array $doc
 *   A solr result document.
 *
 * @return string
 *   The title of object.
 */
function livingstone_node_import_map_solr_doc_to_node_title(array $doc) {
  return isset($doc[LIVINGSTONE_NODE_IMPORT_SOLR_TITLE_FIELD]) ?
    $doc[LIVINGSTONE_NODE_IMPORT_SOLR_TITLE_FIELD] : '';
}

/**
 * Maps the given solr results to node fields.
 *
 * @param array $doc
 *   A solr result document.
 *
 * @return array
 *   The solr result values mapped to node fields.
 */
function livingstone_node_import_map_solr_doc_to_node_fields(array $doc) {
  $fields = array();
  $field_settings = livingstone_node_import_field_settings();
  foreach ($field_settings as $field_name => $settings) {
    if (isset($settings['solr'])) {
      $solr = $settings['solr'];
      $solr_field = $solr['field'];
      if (isset($doc[$solr_field])) {
        $value = $doc[$solr['field']];
        $fields[$field_name] = (isset($solr['map'])) ?
          call_user_func($settings['solr']['map'], $value) :
          $value;
      }
    }
  }
  return $fields;
}

/**
 * Query solr for import data.
 *
 * @param string $query
 *   The search query.
 * @param array $params
 *   The solr search parameters.
 *
 * @return array
 *   The solr search results.
 */
function livingstone_node_import_query_solr($query, $params) {
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);

  try {
    $results = $solr->search($query, $params['start'], $params['rows'], $params, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  return isset($results) ? json_decode($results->getRawResponse(), TRUE) : array();
}

/**
 * The solr search parameters to be used to fetch import data.
 *
 * @param int $start
 *   The offset from which to return results.
 * @param int $rows
 *   The number of rows to return in the query.
 *
 * @return array
 *   The solr search parameters.
 */
function livingstone_node_import_query_solr_parameters($start = 0, $rows = 10000) {
  $fl = livingstone_node_import_solr_params_fl();
  return array(
    'fl' => $fl,
    'fq' => array(
      'RELS_EXT_hasModel_uri_s:"info:fedora/islandora:manuscriptCModel"',
    ),
    'start' => $start,
    'rows' => $rows,
    'sort' => 'PID asc',
  );
}

/**
 * Gets the 'fl' parameter for solr searches when importing.
 *
 * @return string
 *   The 'fl' parameter for solr searches used to import content into Drupal.
 */
function livingstone_node_import_solr_params_fl() {
  $fl = array(LIVINGSTONE_NODE_IMPORT_SOLR_TITLE_FIELD);
  $field_settings = livingstone_node_import_field_settings();
  foreach ($field_settings as $field_name => $settings) {
    if (isset($settings['solr']['field'])) {
      $fl[] = $settings['solr']['field'];
    }
  }
  return $fl;
}

/**
 * Settings for importing data, maps solr content to node fields.
 *
 * @return array
 *   An associative array where the keys correspond to fields and the values,
 *   are settings for creating / populating that field.
 */
function livingstone_node_import_field_settings() {
  return array(
    'pid' => array(
      'type' => 'text',
      'title' => t('PID'),
      'description' => t('PID'),
      'required' => TRUE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'PID',
      ),
    ),
    'alt_title' => array(
      'type' => 'text',
      'title' => t('Alternative Title'),
      'description' => t('Alternative Title'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'alt_title_s',
      ),
    ),
    'image' => array(
      'type' => 'image',
      'title' => t('Image'),
      'description' => t('Image'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'fedora_datastream_version_TN_MD5_ms',
      ),
    ),
    'viewable' => array(
      'type' => 'list_boolean',
      'title' => t('Viewable'),
      'description' => t('Viewable'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'viewable_b',
      ),
    ),
    'hidden' => array(
      'type' => 'list_boolean',
      'title' => t('Hidden'),
      'description' => t('Hidden'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'hidden_b',
      ),
    ),
    'downloadable' => array(
      'type' => 'list_boolean',
      'title' => t('Downloadable'),
      'description' => t('Downloadable'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'downloadable_b',
      ),
    ),
    'dates' => array(
      'type' => 'text',
      'title' => t('Date(s)'),
      'description' => t('Date(s)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'date_s',
      ),
    ),
    'creators' => array(
      'type' => 'text',
      'title' => t('Creator(s)'),
      'description' => t('Creator(s)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'creator_s',
      ),
    ),
    'addressees' => array(
      'type' => 'text',
      'title' => t('Addressee(s)'),
      'description' => t('Addressee(s)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'addressee_s',
      ),
    ),
    'places_created' => array(
      'type' => 'text',
      'title' => t('Place(s) Created'),
      'description' => t('Place(s) Created'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'place_s',
      ),
    ),
    'extent_pages' => array(
      'type' => 'text',
      'title' => t('Extent (pages)'),
      'description' => t('Extent (pages)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'extent_pages_s',
      ),
    ),
    'extent_size' => array(
      'type' => 'text',
      'title' => t('Extent (size)'),
      'description' => t('Extent (size)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'extent_size_s',
      ),
    ),
    'genres' => array(
      'type' => 'text',
      'title' => t('Genre(s)'),
      'description' => t('Genres(s)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'genre_s',
      ),
    ),
    'repository_shelfmark' => array(
      'type' => 'text_long',
      'title' => t('Repository / Shelfmark'),
      'description' => t('Repository / Shelfmark'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'repository_s',
      ),
    ),
    'copy_of_item' => array(
      'type' => 'text',
      'title' => t('Copy of Item'),
      'description' => t('Copy of Item'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'copy_identifier_s',
      ),
    ),
    'other_versions' => array(
      'type' => 'text_long',
      'title' => t('Other Version(s)'),
      'description' => t('Other Version(s)'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'otherVersion_s',
      ),
    ),
    'catalogue_number' => array(
      'type' => 'text',
      'title' => t('C&C Catalogue Number'),
      'description' => t('C&C Catalogue Number'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'catalog_identifier_s',
      ),
    ),
    'project_id' => array(
      'type' => 'text',
      'title' => t('Project ID'),
      'description' => t('Project ID'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'master_id_s',
      ),
    ),
    'coordinates' => array(
      'type' => 'text',
      'title' => t('Coordinates'),
      'description' => t('Coordinates'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_UNLIMITED,
      'solr' => array(
        'field' => 'coordinates_ms',
      ),
    ),
    'tei' => array(
      'type' => 'text_long',
      'title' => t('TEI'),
      'description' => t('TEI'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'tei',
          'map' => 'livingstone_node_import_map_xml_to_text'
      ),
    ),
    'date_range_start' => array(
      'type' => 'date',
      'title' => t('Date Range Start'),
      'description' => t('Date Range Start'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'dateRangeStart_dt',
      ),
    ),
    'date_range_end' => array(
      'type' => 'date',
      'title' => t('Date Range End'),
      'description' => t('Date Range End'),
      'required' => FALSE,
      'cardinality' => LIVINGSTONE_FIELD_CARDINALITY_ONE,
      'solr' => array(
        'field' => 'dateRangeEnd_dt',
      ),
    ),
  );
}

/**
 * Converts the given XML string to a plain string of only the XML text content.
 *
 * @param string $value
 *   An XML document as a string.
 *
 * @return string
 *   The extracted text from given XML document.
 */
function livingstone_node_import_map_xml_to_text($value) {
  $value = is_array($value) ? reset($value) : $value;
  $module_path = drupal_get_path('module', 'livingstone');
  $dom = new DOMDocument();
  $dom->loadXML($value);
  $xsl = new DOMDocument();
  $xsl->load("$module_path/xsl/extract-text.xsl");
  $xslt = new XSLTProcessor();
  $xslt->importStylesheet($xsl);
  $result = $xslt->transformToXml($dom);
  return $result;
}
