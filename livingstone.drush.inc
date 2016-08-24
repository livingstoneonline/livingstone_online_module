<?php

/**
 * @file
 * Implementation of Drush hooks.
 */

// Used for updating datastreams.
function livingstone_import_datastream_info() {
  return array(
    'islandora:manuscriptCModel' => array(
      'DC' => array(
        'mimetype' => 'application/xml',
      ),
      'MODS' => array(
        'mimetype' => 'application/xml',
      ),
      'TN' => array(
        'mimetype' => 'image/jpeg',
      ),
      'TEI' => array(
        'mimetype' => 'application/xml',
      ),
      'ZIP' => array(
        'mimetype' => 'application/zip',
      ),
    ),
    'islandora:manuscriptPageCModel' => array(
      'OBJ' => array(
        'mimetype' => 'image/tiff',
      ),
      'JP2' => array(
        'mimetype' => 'image/jp2',
      ),
      'TXT' => array(
        'mimetype' => 'text/plain',
      ),
      'XMP' => array(
        'mimetype' => 'application/xml',
      ),
      'POLICY' => array(
        'mimetype' => 'application/xml',
      ),
    ),
    'islandora:sp_large_image_cmodel' => array(
      'DC' => array(
        'mimetype' => 'application/xml',
      ),
      'MODS' => array(
        'mimetype' => 'application/xml',
      ),
      'OBJ' => array(
        'mimetype' => 'image/tiff',
      ),
      'JP2' => array(
        'mimetype' => 'image/jp2',
      ),
      'TXT' => array(
        'mimetype' => 'text/plain',
      ),
      'XMP' => array(
        'mimetype' => 'application/xml',
      ),
      'POLICY' => array(
        'mimetype' => 'application/xml',
      ),
    ),
    'islandora:sp_pdf' => array(
      'OBJ' => array(
        'mimetype' => 'application/pdf',
      ),
      'POLICY' => array(
        'mimetype' => 'application/xml',
      ),
    ),
  );
}

function livingstone_import_policy_info() {
  $xacml_path = drupal_get_path('module', 'livingstone') . '/xacml';
  return array(
    'islandora:manuscriptPageCModel' => "$xacml_path/page_policy.xml",
    'islandora:sp_large_image_cmodel' => "$xacml_path/image_policy.xml",
    'islandora:sp_pdf' => "$xacml_path/pdf_policy.xml",
  );
}

function livingstone_import_get_label($mods) {
  $dom = new DOMDocument();
  $dom->load($mods);
  $xpath = new DOMXPath($dom);
  return $xpath->evaluate('string(//mods:titleInfo/mods:title[1]/text())');
}

function livingstone_import_crosswalk_mods_to_dc($mods) {
  $module_path = drupal_get_path('module', 'livingstone');
  $xsl = new DOMDocument();
  $xsl->load("$module_path/xsl/mods_to_dc.xsl");
  $xslt = new XSLTProcessor();
  $xslt->importStyleSheet($xsl);
  $src = new DOMDocument();
  $src->load($mods);
  $result = $xslt->transformToDoc($src);
  return $result->saveXML();
}

function livingstone_import_add_update_datastream_from_file($object, $dsid, $file) {
  $datastream_info = livingstone_import_datastream_info();
  $supported_models = array_intersect($object->models, array_keys($datastream_info));
  $content_model = reset($supported_models);
  $datastream_info = $datastream_info[$content_model];
  if (empty($object[$dsid])) {
    $datastream = $object->constructDatastream($dsid, 'M');
    $datastream->label = basename($file);
    $datastream->mimetype = $datastream_info[$dsid]['mimetype'];
    $datastream->checksumType = 'MD5';
    $datastream->versionable = TRUE;
    $datastream->setContentFromFile($file, FALSE);
    $object->ingestDatastream($datastream);
  } else {
    $object[$dsid]->setContentFromFile($file, FALSE);
  }
}

function livingstone_import_add_update_dublin_core($object, $mods) {
  if (empty($object['DC'])) {
    $datastream = $object->constructDatastream('DC', 'M');
    $datastream->label = 'Dublin Core Descriptive Metadata';
    $datastream->mimetype = 'application/xml';
    $datastream->checksumType = 'MD5';
    $datastream->versionable = TRUE;
    $datastream->setContentFromString(livingstone_import_crosswalk_mods_to_dc($mods));
    $object->ingestDatastream($datastream);
  }
  else {
    $object['DC']->setContentFromString(livingstone_import_crosswalk_mods_to_dc($mods));
  }
}

function drush_livingstone_validate_file_exists($file) {
  if (!file_exists($file)) {
    $message = dt('The given file: @file does not exist.', array('@file' => $file));
    return drush_set_error('livingstone', $message);
  }
  return TRUE;
}

function drush_livingstone_validate_file_parameters($params) {
  foreach($params as $param) {
    $file = drush_get_option($param);
    if (!drush_livingstone_validate_file_exists($file)) {
      return FALSE;
    }
  }
  return TRUE;
}

function drush_livingstone_validate_optional_file_parameters($params) {
  foreach($params as $param) {
    $file = drush_get_option($param);
    if ($file && !drush_livingstone_validate_file_exists($file)) {
      return FALSE;
    }
  }
  return TRUE;
}

function drush_livingstone_validate_object_exists() {
  $pid = drush_get_option('pid');
  $object = islandora_object_load($pid);
  if (!$object) {
    $message = dt('The given object (@pid) does not exist.', array(
      '@pid' => $pid
    ));
    return drush_set_error('livingstone', $message);
  }
  return TRUE;
}

function drush_livingstone_validate_object_does_not_exist() {
  $pid = drush_get_option('pid');
  $object = islandora_object_load($pid);
  if ($object) {
    $message = dt('The given object (@pid) already exists.', array(
      '@pid' => $pid
    ));
    return drush_set_error('livingstone', $message);
  }
  return TRUE;
}

/**
 * Implements hook_drush_command().
 */
function livingstone_drush_command() {
  return array(
    'livingstone_import_nodes' => array(
      'description' => 'Imports Fedora content into Drupal Nodes.',
      'drupal dependencies' => array(
        'date',
        'entity',
        'livingstone',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_policy' => array(
      'description' => 'Adds / Updates the XACML policy of the given object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to update.',
          'required' => TRUE,
        ),
        'policy' => array(
          'description' => 'The policy to update the object with.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_remove_policy' => array(
      'description' => 'Updates the XACML policy of the given object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to update.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_update_datastream' => array(
      'description' => 'Updates the datastream of the given object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to update.',
          'required' => TRUE,
        ),
        'dsid' => array(
          'description' => 'The DSID to update.',
          'required' => TRUE,
        ),
        'file' => array(
          'description' => 'The content to update.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_manuscript' => array(
      'description' => 'Creates a manuscript object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
        'mods' => array(
          'description' => 'The MODS file.',
          'required' => TRUE,
        ),
        'tei' => array(
          'description' => 'The TEI file (optional).',
          'required' => FALSE,
        ),
        'zip' => array(
          'description' => 'The ZIP file (optional).',
          'required' => FALSE,
        ),
        'tn' => array(
          'description' => 'The TN file (optional).',
          'required' => FALSE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_manuscript_page' => array(
      'description' => 'Creates a manuscript page object, and adds it to a manuscript.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
        'private' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
        'obj' => array(
          'description' => 'The OBJ file.',
          'required' => TRUE,
        ),
        'jp2' => array(
          'description' => 'The JP2 file.',
          'required' => TRUE,
        ),
        'txt' => array(
          'description' => 'The TXT file.',
          'required' => TRUE,
        ),
        'xmp' => array(
          'description' => 'The XMP file.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_no_crop' => array(
      'description' => 'Creates a no_crop object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
        'obj' => array(
          'description' => 'The OBJ file.',
          'required' => TRUE,
        ),
        'jp2' => array(
          'description' => 'The JP2 file.',
          'required' => TRUE,
        ),
        'txt' => array(
          'description' => 'The TXT file.',
          'required' => TRUE,
        ),
        'xmp' => array(
          'description' => 'The XMP file.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_illustrative' => array(
      'description' => 'Creates a manuscript object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
        'mods' => array(
          'description' => 'The MODS file.',
          'required' => TRUE,
        ),
        'obj' => array(
          'description' => 'The OBJ file.',
          'required' => TRUE,
        ),
        'jp2' => array(
          'description' => 'The JP2 file.',
          'required' => TRUE,
        ),
        'txt' => array(
          'description' => 'The TXT file.',
          'required' => TRUE,
        ),
        'xmp' => array(
          'description' => 'The XMP file.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_additional_compound' => array(
      'description' => 'Creates a compound to house additional objects.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
    'livingstone_add_additional_pdf' => array(
      'description' => 'Creates a additional PDF object.',
      'drupal dependencies' => array(
        'livingstone',
      ),
      'options' => array(
        'pid' => array(
          'description' => 'The object to create.',
          'required' => TRUE,
        ),
        'obj' => array(
          'description' => 'The PDF file.',
          'required' => TRUE,
        ),
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    ),
  );
}

function drush_livingstone_import_nodes() {
  module_load_include('inc', 'livingstone', 'includes/node.import');
  module_load_include('inc', 'livingstone', 'includes/node.import.batch');
  $batch = livingstone_node_import_sync_batch();
  $batch['progressive'] = FALSE;
  batch_set($batch);
  drush_backend_batch_process();
}

function drush_livingstone_add_policy() {
  $pid = drush_get_option('pid');
  $object = islandora_object_load($pid);
  $policy_info = livingstone_import_policy_info();
  $supported_models = array_intersect($object->models, array_keys($policy_info));
  $content_model = reset($supported_models);
  $policy = $policy_info[$content_model];
  if (!isset($object['POLICY'])) {
    $ds = $object->constructDatastream('POLICY', 'M');
    $ds->state = 'A';
    $ds->versionable = TRUE;
    $ds->mimetype = 'application/xml';
    $ds->checksumType = 'MD5';
    $ds->setContentFromFile($policy);
    $object->ingestDatastream($ds);
  }
  elseif (md5_file($policy) != $object['POLICY']->checksum) {
    $object['POLICY']->setContentFromFile($policy);
  }
}

function drush_livingstone_add_policy_validate() {
  drupal_static_reset('islandora_get_tuque_connection');
  $pid = drush_get_option('pid');
  $object = islandora_object_load($pid);
  if (!$object) {
    $message = dt('The given object: @pid does not exist.', array('@pid' => $pid));
    return drush_set_error('livingstone', $message);
  }
  $policy_info = livingstone_import_policy_info();
  $supported_models = array_intersect($object->models, array_keys($policy_info));
  if (count($supported_models) == 0) {
    $message = dt('The given object: @pid does not require a POLICY.', array('@pid' => $pid));
    return drush_set_error('livingstone', $message);
  }
}

function drush_livingstone_remove_policy() {
  $pid = drush_get_option('pid');
  $object = islandora_object_load($pid);
  $object->purgeDatastream('POLICY');
}

function drush_livingstone_remove_policy_validate() {
  drupal_static_reset('islandora_get_tuque_connection');
  $pid = drush_get_option('pid');
  $object = islandora_object_load($pid);
  if (!$object) {
    $message = dt('The given object: @pid does not exist.', array('@pid' => $pid));
    return drush_set_error('livingstone', $message);
  }
}

function drush_livingstone_update_datastream() {
  $pid = drush_get_option('pid');
  $dsid = drush_get_option('dsid');
  $file = drush_get_option('file');
  $object = islandora_object_load($pid);
  livingstone_import_add_update_datastream_from_file($object, $dsid, $file);
}

function drush_livingstone_update_datastream_validate() {
  drupal_static_reset('islandora_get_tuque_connection');
  $pid = drush_get_option('pid');
  $dsid = drush_get_option('dsid');
  $file = drush_get_option('file');
  $object = islandora_object_load($pid);
  if (!$object) {
    $message = dt('The given object: @pid does not exist.', array('@pid' => $pid));
    return drush_set_error('livingstone', $message);
  }
  $datastream_info = livingstone_import_datastream_info();
  $supported_models = array_intersect($object->models, array_keys($datastream_info));
  // Should only ever be one supported.
  $content_model = reset($supported_models);
  if (!isset($datastream_info[$content_model][$dsid])) {
    $message = dt('The dsid: @dsid is not supported by @pid.', array(
      '@pid' => $pid,
      '@dsid' => $dsid,
    ));
    return drush_set_error('livingstone', $message);
  }
  if (!file_exists($file)) {
    $message = dt('The given file: @file does not exist.', array('@file' => $file));
    return drush_set_error('livingstone', $message);
  }
  $md5 = md5_file($file);
  if (isset($object[$dsid]) && $md5 == $object[$dsid]->checksum) {
    $message = dt('@pid[@dsid]: is identical to @file, no update needed.', array(
                 '@pid' => $pid,
                 '@dsid' => $dsid,
                 '@file' => $file,
               ));
    return drush_set_error('livingstone', $message);
  }
}

function drush_livingstone_add_manuscript() {
  $pid = drush_get_option('pid');
  $mods = drush_get_option('mods');
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models ='islandora:sp_large_image_cmodel';
  $object->label = livingstone_import_get_label($mods);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', 'liv:illustrative');
  // Add datastreams, and generate DC.
  $tei = drush_get_option('tei');
  if ($tei) {
    livingstone_import_add_update_datastream_from_file($object, 'TEI', $tei);
  }
  $tn = drush_get_option('tn');
  if ($tn) {
    livingstone_import_add_update_datastream_from_file($object, 'TN', $tn);
  }
  $zip = drush_get_option('zip');
  if ($zip) {
    livingstone_import_add_update_datastream_from_file($object, 'ZIP', $zip);
  }
  livingstone_import_add_update_datastream_from_file($object, 'MODS', $mods);
  livingstone_import_add_update_dublin_core($object, $mods);
  // Ingest the object into Fedora.
  $connection->repository->ingestObject($object);
  drush_print("Ingested: $pid");
}

function drush_livingstone_add_manuscript_validate() {
  $file_parameters = array('mods');
  $optional_file_parameters = array('tei', 'tn', 'zip');
  return drush_livingstone_validate_object_does_not_exist() &&
         drush_livingstone_validate_file_parameters($file_parameters) &&
         drush_livingstone_validate_optional_file_parameters($optional_file_parameters);
}

function drush_livingstone_add_manuscript_page() {
  $pid = drush_get_option('pid');
  $parent_pid = preg_replace('/^(liv:[0-9]{6})_[0-9]{4}$/', '\1', $pid);
  $page = (int) preg_replace('/^liv:[0-9]{6}_([0-9]{4})$/', '\1', $pid);
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models ='islandora:manuscriptPageCModel';
  $object->label = $pid;
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isPageOf', $parent_pid);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isSequenceNumber', $page, TRUE);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isPageNumber', $page, TRUE);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isSection', '1', TRUE);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  if (drush_get_option('private')) {
    livingstone_import_add_update_datastream_from_file($object, 'POLICY', drupal_get_path('module', 'livingstone') . '/xacml/page_policy.xml');
  }
  livingstone_import_add_update_datastream_from_file($object, 'OBJ', drush_get_option('obj'));
  livingstone_import_add_update_datastream_from_file($object, 'JP2', drush_get_option('jp2'));
  livingstone_import_add_update_datastream_from_file($object, 'TXT', drush_get_option('txt'));
  livingstone_import_add_update_datastream_from_file($object, 'XMP', drush_get_option('xmp'));
  // Ingest the object into Fedora.
  $connection->repository->ingestObject($object);
  drush_print("Ingested: $pid");
}

function drush_livingstone_add_manuscript_page_validate() {
  $file_parameters = array('obj', 'jp2', 'txt', 'xmp');
  return drush_livingstone_validate_object_does_not_exist() && drush_livingstone_validate_file_parameters($file_parameters);
}

function drush_livingstone_add_no_crop() {
  $pid = drush_get_option('pid');
  $parent_pid = preg_replace('/^(liv:[0-9]{6}_[0-9]{4})_noCrop$/', '\1', $pid);
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models ='islandora:sp_large_image_cmodel';
  $object->label = $pid;
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  livingstone_import_add_update_datastream_from_file($object, 'POLICY', drupal_get_path('module', 'livingstone') . '/xacml/image_policy.xml');
  livingstone_import_add_update_datastream_from_file($object, 'OBJ', drush_get_option('obj'));
  livingstone_import_add_update_datastream_from_file($object, 'JP2', drush_get_option('jp2'));
  livingstone_import_add_update_datastream_from_file($object, 'TXT', drush_get_option('txt'));
  livingstone_import_add_update_datastream_from_file($object, 'XMP', drush_get_option('xmp'));
  // Ingest the object into Fedora.
  $connection->repository->ingestObject($object);
  drush_print("Ingested: $pid");
}

function drush_livingstone_add_no_crop_validate() {
  $file_parameters = array('obj', 'jp2', 'txt', 'xmp');
  return drush_livingstone_validate_object_does_not_exist() && drush_livingstone_validate_file_parameters($file_parameters);
}

function drush_livingstone_add_illustrative() {
  $pid = drush_get_option('pid');
  $mods = drush_get_option('mods');
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models ='islandora:sp_large_image_cmodel';
  $object->label = livingstone_import_get_label($mods);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', 'liv:illustrative');
  // Add datastreams, and generate DC.
  livingstone_import_add_update_datastream_from_file($object, 'POLICY', drupal_get_path('module', 'livingstone') . '/xacml/image_policy.xml');
  livingstone_import_add_update_datastream_from_file($object, 'OBJ', drush_get_option('obj'));
  livingstone_import_add_update_datastream_from_file($object, 'JP2', drush_get_option('jp2'));
  livingstone_import_add_update_datastream_from_file($object, 'TXT', drush_get_option('txt'));
  livingstone_import_add_update_datastream_from_file($object, 'XMP', drush_get_option('xmp'));
  livingstone_import_add_update_datastream_from_file($object, 'MODS', $mods);
  livingstone_import_add_update_dublin_core($object, $mods);
  // Ingest the object into Fedora.
  $connection->repository->ingestObject($object);
  drush_print("Ingested: $pid");
}

function drush_livingstone_add_illustrative_validate() {
  $file_parameters = array('mods', 'obj', 'jp2', 'txt', 'xmp');
  return drush_livingstone_validate_object_does_not_exist() && drush_livingstone_validate_file_parameters($file_parameters);
}

function drush_livingstone_add_additional_pdf() {
  $pid = drush_get_option('pid');
  $parent_pid = preg_replace('/^(liv:[0-9]{6})_[0-9]{4}$/', '\1', $pid);
  $obj = drush_get_option('obj');
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models ='islandora:sp_pdf';
  $object->label = basename($obj);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  // Add datastreams.
  livingstone_import_add_update_datastream_from_file($object, 'POLICY', drupal_get_path('module', 'livingstone') . '/xacml/pdf_policy.xml');
  livingstone_import_add_update_datastream_from_file($object, 'OBJ', drush_get_option('obj'));
  // Ingest the object into Fedora.
  $connection->repository->ingestObject($object);
  drush_print("Ingested: $pid");
}

function drush_livingstone_add_additional_pdf_validate() {
  $file_parameters = array('obj');
  return drush_livingstone_validate_object_does_not_exist() && drush_livingstone_validate_file_parameters($file_parameters);
}
