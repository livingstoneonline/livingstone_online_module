<?php

/**
 * @remote_file_path
 */

define('LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE', 'livingstone_fedora_remote_files');
define('LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE', 'livingstone_fedora_local_files');
define('LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS', 'r');
define('LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS', 'l');
define('LIVINGSTONE_FEDORA_IMPORT_ERROR', 'livingstone_fedora_import');

/**
 * Returns the types of content which can be imported into Fedora from FTP.
 *
 * @return array
 *   An associative array where the key is the import type, and it's value is an
 *   associative array like so:
 *   - content_model: The content model to use when creating this type.
 *   - datastreams: The datastreams which come from the FTP server, this does
 *     not include derivatives.
 */
function livingstone_fedora_import_types() {
  return array(
    'illustrative' => array(
      'title' => t('Illustrative Image(s)'),
      'content_model' => 'islandora:sp_large_image_cmodel',
      'required_datastreams' => array('MODS', 'OBJ', 'TXT', 'XMP'),
    ),
    'no_crop' => array(
      'title' => t('No Crop Image(s)'),
      'content_model' => 'islandora:sp_large_image_cmodel',
      'required_datastreams' => array('OBJ', 'TXT', 'XMP'),
    ),
    'manuscript' => array(
      'title' => t('Manuscript(s)'),
      'content_model' => 'islandora:manuscriptCModel',
      'required_datastreams' => array('MODS'),
      'optional_datastreams' => array('TEI', 'TN', 'ZIP'),
    ),
    'manuscript_page' => array(
      'title' => t('Manuscript Page(s)'),
      'content_model' => 'islandora:manuscriptPageCModel',
      'required_datastreams' => array('OBJ', 'TXT', 'XMP'),
    ),
    'manuscript_additional_pdf' => array(
      'title' => t('Manuscript Additional PDF(s)'),
      'content_model' => 'islandora:sp_pdf',
      'required_datastreams' => array('OBJ'),
    ),
  );
}

/**
 * Maps Content models to datastream related info for convenience.
 *
 * @return array
 */
function livingstone_fedora_import_datastream_info() {
  return array(
    'islandora:manuscriptCModel' => array(
      'DC' => array(
        'mime_type' => 'application/xml',
      ),
      'MODS' => array(
        'mime_type' => 'application/xml',
      ),
      'TN' => array(
        'mime_type' => 'image/jpeg',
      ),
      'TEI' => array(
        'mime_type' => 'application/xml',
      ),
      'ZIP' => array(
        'mime_type' => 'application/zip',
      ),
    ),
    'islandora:manuscriptPageCModel' => array(
      'OBJ' => array(
        'mime_type' => 'image/tiff',
      ),
      'JP2' => array(
        'mime_type' => 'image/jp2',
      ),
      'TXT' => array(
        'mime_type' => 'text/plain',
      ),
      'XMP' => array(
        'mime_type' => 'application/xml',
      ),
      'POLICY' => array(
        'mime_type' => 'application/xml',
      ),
    ),
    'islandora:sp_large_image_cmodel' => array(
      'DC' => array(
        'mime_type' => 'application/xml',
      ),
      'MODS' => array(
        'mime_type' => 'application/xml',
      ),
      'OBJ' => array(
        'mime_type' => 'image/tiff',
      ),
      'JP2' => array(
        'mime_type' => 'image/jp2',
      ),
      'TXT' => array(
        'mime_type' => 'text/plain',
      ),
      'XMP' => array(
        'mime_type' => 'application/xml',
      ),
      'POLICY' => array(
        'mime_type' => 'application/xml',
      ),
    ),
    'islandora:sp_pdf' => array(
      'OBJ' => array(
        'mime_type' => 'application/pdf',
      ),
      'POLICY' => array(
        'mime_type' => 'application/xml',
      ),
    ),
  );
}

/**
 * Gets all the human readable title of supported Fedora Import types.
 *
 * @return array
 *   Returns an associative array where the keys are the types of objects
 *   supported by the import, and the values are the titles to display for those
 *   types to the end user.
 */
function livingstone_fedora_import_titles() {
  $titles = array();
  foreach (livingstone_fedora_import_types() as $type => $info) {
    $titles[$type] = $info['title'];
  }
  ksort($titles);
  return array_unique($titles);
}

/**
 * Gets all the Content Models supported by Fedora Import types.
 *
 * @return array
 *   An array of all the Content Models supported by the import types.
 */
function livingstone_fedora_import_content_models() {
  $content_models = array();
  foreach (livingstone_fedora_import_types() as $info) {
    $content_models[] = $info['content_model'];
  }
  sort($content_models);
  return array_unique($content_models);
}

/**
 * Gets all the datastreams DSID's supported by the Fedora Import types.
 *
 * @return array
 *   An array of all the DSID's supported by the import types.
 */
function livingstone_fedora_import_datastreams() {
  $dsids = array();
  foreach (livingstone_fedora_import_types() as $info) {
    $dsids = array_merge($dsids, $info['required_datastreams'], isset($info['optional_datastreams']) ? $info['optional_datastreams'] : array());
  }
  sort($dsids);
  return array_unique($dsids);
}

/**
 * Updates the import tables both remote and local.
 */
function livingstone_fedora_import_update_tables() {
  $module_path = drupal_get_path('module', 'livingstone');
  shell_exec("$module_path/scripts/import/update_tables.sh");
}

/**
 * Attempts to get an FTP connection.
 *
 * Only used for testing the connection, we don't do any downloads though the
 * PHP FTP client, we use cURL instead.
 *
 * @param string $server
 *   The server to attempt to connect to, defaults used if none provided.
 * @param string $user
 *   The user to attempt to connect with, defaults used if none provided.
 * @param string $password
 *   The password to attempt to connect with, defaults used if none provided.
 *
 * @return bool|resource
 *   A connection to the FTP server or FALSE if no connection could be made.
 */
function livingstone_fedora_import_get_ftp_connection($server = NULL, $user = NULL, $password = NULL) {
  $server = isset($server) ? $server : variable_get('livingstone_ftp_server', 'agnes.unl.edu');
  $user = isset($user) ? $user : variable_get('livingstone_ftp_user', 'nbanks');
  $password = isset($password) ? $password : variable_get('livingstone_ftp_password', '');
  // Set up a connection.
  $connection = ftp_connect($server);
  $result = ftp_login($connection, $user, $password);
  if ($result) {
    ftp_pasv($connection, TRUE);
    return $connection;
  }
  return FALSE;
}

/**
 * Checks if the user can in fact connect to the FTP with given credentials.
 *
 * @param string $server
 *   The server to attempt to connect to, defaults used if none provided.
 * @param string $user
 *   The user to attempt to connect with, defaults used if none provided.
 * @param string $password
 *   The password to attempt to connect with, defaults used if none provided.
 *
 * @return bool
 *   TRUE if the credentials can be used to connect to the FTP server.
 */
function livingstone_fedora_import_valid_ftp_connection($server = NULL, $user = NULL, $password = NULL) {
  $connection = livingstone_fedora_import_get_ftp_connection($server, $user, $password);
  if (!$connection) {
    return FALSE;
  }
  ftp_close($connection);
  return TRUE;
}

/**
 * Triggers a background process to download the given file.
 *
 * Caller is responsible for deleting the file when done.
 *
 * @param string $remote_file_path
 *   The path to the remote file on the FTP server.
 *
 * @return array
 */
function livingstone_fedora_import_start_ftp_download($remote_file_path) {
  global $user;
  $basename = basename($remote_file_path);
  $local_file_uri = drupal_tempnam('temporary://', "$basename.");
  $local_file_path = drupal_realpath($local_file_uri);
  $output_file_uri = drupal_tempnam('temporary://', "$basename.progress.");
  $output_file_path = drupal_realpath($output_file_uri);
  $ftp_server = variable_get('livingstone_ftp_server', 'agnes.unl.edu');
  $ftp_user = variable_get('livingstone_ftp_user', 'nbanks');
  $ftp_password = variable_get('livingstone_ftp_password', '');
  $process_id = exec("curl -u '{$ftp_user}:{$ftp_password}' 'ftp://{$ftp_server}{$remote_file_path}' -o '$local_file_path' -# > '$output_file_path' 2>&1 & echo $!", $output);

  $local_file = new stdClass;
  $local_file->uid = $user->uid;
  $local_file->filename = $basename;
  $local_file->uri = $local_file_uri;
  $local_file->status = 0; // Temporary remote_file_path.
  $local_file->filemime = file_get_mimetype($basename);
  $local_file = file_save($local_file);

  $output_file = new stdClass;
  $output_file->uid = $user->uid;
  $output_file->filename = $basename;
  $output_file->uri = $output_file_uri;
  $output_file->status = 0; // Temporary remote_file_path.
  $output_file->filemime = file_get_mimetype($basename);
  $output_file = file_save($output_file);

  return array($local_file, $output_file, $process_id);
}

/**
 * Gets the download progress from the output file.
 *
 * @param stdClass $output_file
 *   The output file populated by cURL.
 *
 * @return float
 *   The progress of the download, as a value between 0 and 100.
 */
function livingstone_fedora_import_ftp_download_progress(stdClass $output_file) {
  $output_file_path = drupal_realpath($output_file->uri);
  $progress = exec("cat {$output_file_path} | stdbuf -oL tr '\r' '\n' | grep -o '[0-9]*\\.[0-9]'");
  if (filter_var($progress, FILTER_VALIDATE_FLOAT)) {
    return $progress;
  }
  return 0.0;
}

/**
 * Checks if the background download process has finished executing.
 *
 * @param int $process_id
 *   The process ID of the download script.
 *
 * @return bool
 *   TRUE when the process has finished, FALSE otherwise.
 */
function livingstone_fedora_import_finished_ftp_download($process_id) {
  return !posix_getpgid($process_id);
}

/**
 * Checks if the download was successful.
 *
 * @param stdClass $local_file
 *   The Drupal file object representing the local copy of the file.
 * @param $remote_file_path
 *   The remote path to the file on the FTP server.
 * @param $md5
 *   The expected MD5 checksum for the file.
 *
 * @return bool
 *   TRUE if successful, FALSE otherwise.
 */
function livingstone_fedora_import_successful_ftp_download(stdClass $local_file, $remote_file_path, $md5) {
  $local_file_path = drupal_realpath($local_file->uri);
  $downloaded_md5 = md5_file($local_file_path);
  if ($downloaded_md5 != $md5) {
    watchdog(LIVINGSTONE_FEDORA_IMPORT_ERROR, 'Downloaded @file MD5 (@downloaded_md5) does not match given MD5 (@md5)', array(
      '@file' => $remote_file_path,
      '@downloaded_md5' => $downloaded_md5,
      '@md5' => $md5,
    ));
    return FALSE;
  }
  return TRUE;
}

/**
 * Gets a list of all the objects which are missing from Fedora.
 *
 * @param array $fields.
 *   The columns to return.
 *
 * @return SelectQuery
 *   A SelectQuery used to fetch the missing objects.
 */
function livingstone_fedora_import_add_objects_query(array $fields = array()) {
  $local_table_alias = LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS;
  $remote_table_alias = LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS;

  // Require PID as a field.
  if (!empty($fields)) {
    array_push($fields, 'PID');
    $fields = array_unique($fields);
  }

  $sub_query = db_select(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, $local_table_alias);
  $sub_query->fields($local_table_alias, array('PID'));

  $query = db_select(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE, $remote_table_alias);
  $query->fields($remote_table_alias, $fields);
  $query->condition("{$remote_table_alias}.PID", $sub_query, 'NOT IN');
  return $query;
}

/**
 * Gets a list of all the objects which are missing from Fedora.
 *
 * @param array $fields.
 *   The columns to return.
 *
 * @return SelectQuery
 *   A SelectQuery used to fetch the missing objects.
 */
function livingstone_fedora_import_remove_objects_query(array $fields = array()) {
  $local_table_alias = LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS;
  $remote_table_alias = LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS;

  // Require PID as a field.
  if (!empty($fields)) {
    array_push($fields, 'PID');
    $fields = array_unique($fields);
  }

  $sub_query = db_select(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE, $remote_table_alias);
  $sub_query->fields($remote_table_alias, array('PID'));

  $query = db_select(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, $local_table_alias);
  $query->fields($local_table_alias, $fields);
  $query->condition("$local_table_alias.PID", $sub_query, 'NOT IN');

  return $query;
}

/**
 * Gets a list of all the objects which are missing from Fedora.
 *
 * @param array $fields.
 *   The columns to return.
 *
 * @return SelectQuery
 *   A SelectQuery used to fetch the missing objects.
 */
function livingstone_fedora_import_update_objects_query(array $fields = array()) {
  $local_table_alias = LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS;
  $remote_table_alias = LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS;

  // Require PID as a field.
  if (!empty($fields)) {
    array_push($fields, 'PID');
    $fields = array_unique($fields);
  }

  $query = db_select(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, $local_table_alias);
  $query->leftJoin(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE, $remote_table_alias, "$local_table_alias.PID = $remote_table_alias.PID");
  $query->fields($remote_table_alias, $fields);
  $query->where('NOT l.MODS_MD5 <=> r.MODS_MD5 OR NOT l.OBJ_MD5 <=> r.OBJ_MD5 OR NOT l.PDF_MD5 <=> r.PDF_MD5 OR NOT l.TEI_MD5 <=> r.TEI_MD5 OR NOT l.TN_MD5 <=> r.TN_MD5 OR NOT l.TXT_MD5 <=> r.TXT_MD5 OR NOT l.XMP_MD5 <=> r.XMP_MD5 OR NOT l.ZIP_MD5 <=> r.ZIP_MD5');
  return $query;
}

/**
 * Gets a list of all the objects which are missing from Fedora.
 *
 * @param array $fields.
 *   The columns to return.
 *
 * @return SelectQuery
 *   A SelectQuery used to fetch the missing objects.
 */
function livingstone_fedora_import_publish_objects_query(array $fields = array()) {
  $local_table_alias = LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS;
  $remote_table_alias = LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS;

  // Require PID as a field.
  if (!empty($fields)) {
    array_push($fields, 'PID');
    $fields = array_unique($fields);
  }
  $query = db_select(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, $local_table_alias);
  $query->leftJoin(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE, $remote_table_alias, "$local_table_alias.PID = $remote_table_alias.PID");
  $query->fields($remote_table_alias, $fields);
  $query->where("$local_table_alias.PRIVATE != $remote_table_alias.PRIVATE");
  return $query;
}

/**
 * Checks if the given object does not exist.
 *
 * @param string $pid
 *   The object to check for.
 *
 * @return bool
 *   TRUE if the object does not exist FALSE otherwise.
 */
function livingstone_fedora_import_guard_add_object_does_not_exist($pid) {
  $object = islandora_object_load($pid);
  if ($object) {
    watchdog(LIVINGSTONE_FEDORA_IMPORT_ERROR, 'Object: @pid already exists.', array(
      '@pid' => $pid,
    ));
    return FALSE;
  }
  return TRUE;
}

/**
 * Checks if the given files meet the types requirements.
 *
 * @param string $type
 *   The type to check against.
 * @param array $files
 *   An associative array where the keys represent the DSID's of the files.
 *
 * @return bool
 *   TRUE if the object does not exist FALSE otherwise.
 */
function livingstone_fedora_import_guard_add_object_has_required_files($type, array $files) {
  $types = livingstone_fedora_import_types();
  $required_dsids = drupal_map_assoc($types[$type]['required_datastreams']);
  $matching_dsids = array_intersect_key($required_dsids, $files);
  if (count($matching_dsids) != count($required_dsids)) {
    watchdog(LIVINGSTONE_FEDORA_IMPORT_ERROR, 'Missing files for adding type: @type (Required: @required) (Provided: @provided).', array(
      '@type' => $type,
      '@required' => implode(', ', $types[$type]['required_datastreams']),
      '@provided' => implode(', ', array_keys($files)),
    ));
    // Missing files.
    return FALSE;
  }
  return TRUE;
}

/**
 * Add's or updates the given datastream with the given file.
 *
 * @param AbstractObject $object
 *   The object to add / update.
 * @param string $dsid
 *   The datastream to add / update.
 * @param mixed $file
 *   The file whose contents will used for the datastream.
 * @param string $md5
 *   The MD5 to compare against when updating an existing datastream, if they
 *   are equal no update occurs.
 *
 * @return bool
 *   TRUE if successful, FALSE otherwise.
 */
function livingstone_fedora_import_add_update_datastream_from_file(AbstractObject $object, $dsid, $file, $md5 = NULL) {
  $file_path = is_object($file) ? drupal_realpath($file->uri) : $file;
  $filename = is_object($file) ? $file->filename : basename($file);
  $datastream_info = livingstone_fedora_import_datastream_info();
  $supported_models = array_intersect($object->models, array_keys($datastream_info));
  $content_model = reset($supported_models);
  $datastream_info = $datastream_info[$content_model];
  try {
    if (empty($object[$dsid])) {
      $datastream = $object->constructDatastream($dsid, 'M');
      $datastream->label = $filename;
      $datastream->mimetype = $datastream_info[$dsid]['mime_type'];
      $datastream->checksumType = 'MD5';
      $datastream->versionable = TRUE;
      $datastream->setContentFromFile($file_path, FALSE);
      $object->ingestDatastream($datastream);
    }
    elseif ($object[$dsid]->checksum != $md5) {
      $object[$dsid]->setContentFromFile($file_path, FALSE);
    }
  } catch (Exception $e){
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
  return TRUE;
}

/**
 * Fetches the title from the MODS document if possible.
 *
 * @param mixed $mods
 *   The file object to the MODS document.
 *
 * @return mixed
 */
function livingstone_fedora_import_get_label($mods) {
  $file_path = is_object($mods) ? drupal_realpath($mods->uri) : $mods;
  $dom = new DOMDocument();
  $dom->load($file_path);
  $xpath = new DOMXPath($dom);
  return $xpath->evaluate('string(//mods:titleInfo/mods:title[1]/text())');
}

/**
 * Crosswalks the given MODS to DC.
 *
 * @param mixed $mods
 *   The file object to the MODS document.
 *
 * @return mixed
 */
function livingstone_fedora_import_crosswalk_mods_to_dc($mods) {
  $file_path = is_object($mods) ? drupal_realpath($mods->uri) : $mods;
  $module_path = drupal_get_path('module', 'livingstone');
  $xsl = new DOMDocument();
  $xsl->load("$module_path/xsl/mods_to_dc.xsl");
  $xslt = new XSLTProcessor();
  $xslt->importStyleSheet($xsl);
  $src = new DOMDocument();
  $src->load($file_path);
  $result = $xslt->transformToDoc($src);
  return $result->saveXML();
}

/**
 * Update the Dublin Core from the MODS.
 * 
 * @param AbstractObject $object
 *   The object to update.
 * @param mixed $mods
 *   The MODS file.
 */
function livingstone_fedora_import_add_update_dublin_core($object, $mods) {
  if (empty($object['DC'])) {
    $datastream = $object->constructDatastream('DC', 'M');
    $datastream->label = 'Dublin Core Descriptive Metadata';
    $datastream->mimetype = 'application/xml';
    $datastream->checksumType = 'MD5';
    $datastream->versionable = TRUE;
    $datastream->setContentFromString(livingstone_fedora_import_crosswalk_mods_to_dc($mods));
    $object->ingestDatastream($datastream);
  }
  else {
    $object['DC']->setContentFromString(livingstone_fedora_import_crosswalk_mods_to_dc($mods));
  }
}

/**
 * Add's the given object if possible.
 *
 * @param string $pid
 *   The identifier of the new object to add.
 * @param string $type
 *   The type of object to create.
 * @param bool $private
 *   Make the object private or public.
 * @param array $files
 *   An associative array of files where the keys are DSID'S.
 * @return bool
 *   TRUE if successful FALSE otherwise.
 */
function livingstone_fedora_import_add_object($pid, $type, $private, array $files) {
  switch($type) {
    case 'manuscript':
      return livingstone_fedora_import_add_manuscript($pid, $private, $files);

    case 'manuscript_page':
      return livingstone_fedora_import_add_manuscript_page($pid, $private, $files);

    case 'manuscript_additional_pdf':
      return livingstone_fedora_import_add_manuscript_pdf($pid, $private, $files);

    case 'illustrative':
      return livingstone_fedora_import_add_illustrative($pid, $private, $files);

    case 'no_crop':
      return livingstone_fedora_import_add_no_crop($pid, $private, $files);
  }
  return FALSE;
}

/**
 * Adds a new manuscript object if possible.
 *
 * @param string $pid
 *   The PID of the new object to create.
 * @param $private
 *   TRUE if the new object should be private or not.
 * @param $files
 *   An associative array where the keys are DSID's and the files are the
 *   datastream content.
 *
 * @return mixed
 *   The newly created object if successful, FALSE otherwise.
 */
function livingstone_fedora_import_add_manuscript($pid, $private, $files) {
  $type = 'manuscript';
  if (!livingstone_fedora_import_guard_add_object_does_not_exist($pid)) {
    return FALSE;
  }
  if (!livingstone_fedora_import_guard_add_object_has_required_files('manuscript', $files)) {
    return FALSE;
  }
  $types = livingstone_fedora_import_types();
  $type_info = $types[$type];
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models = $type_info['content_model'];
  $object->label = livingstone_fedora_import_get_label($files['MODS']);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', 'liv:root');
  livingstone_fedora_import_add_update_dublin_core($object, $files['MODS']);
  foreach ($files as $dsid => $file) {
    livingstone_fedora_import_add_update_datastream_from_file($object, $dsid, $file);
  }
  try {
    return $connection->repository->ingestObject($object);
  } catch (Exception $e) {
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
}

/**
 * Adds a new manuscript_page object if possible.
 *
 * @param string $pid
 *   The PID of the new object to create.
 * @param $private
 *   TRUE if the new object should be private or not.
 * @param $files
 *   An associative array where the keys are DSID's and the files are the
 *   datastream content.
 *
 * @return mixed
 *   The newly created object if successful, FALSE otherwise.
 */
function livingstone_fedora_import_add_manuscript_page($pid, $private, $files) {
  $type = 'manuscript_page';
  if (!livingstone_fedora_import_guard_add_object_does_not_exist($pid)) {
    return FALSE;
  }
  if (!livingstone_fedora_import_guard_add_object_has_required_files($type, $files)) {
    return FALSE;
  }
  $types = livingstone_fedora_import_types();
  $type_info = $types[$type];
  $parent_pid = preg_replace('/^(liv:[0-9]{6})_[0-9]{4}$/', '\1', $pid);
  $page = (int) preg_replace('/^liv:[0-9]{6}_([0-9]{4})$/', '\1', $pid);
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models = $type_info['content_model'];
  $object->label = $pid;
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isPageOf', $parent_pid);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isSequenceNumber', $page, TRUE);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isPageNumber', $page, TRUE);
  $object->relationships->add(ISLANDORA_RELS_EXT_URI, 'isSection', '1', TRUE);
  if ($private) {
    $policy = drupal_get_path('module', 'livingstone') . '/xacml/page_policy.xml';
    livingstone_fedora_import_add_update_datastream_from_file($object, 'POLICY', $policy);
  }
  foreach ($files as $dsid => $file) {
    livingstone_fedora_import_add_update_datastream_from_file($object, $dsid, $file);
  }
  try {
    return $connection->repository->ingestObject($object);
  } catch (Exception $e) {
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
}

/**
 * Adds a new manuscript_additional_pdf object if possible.
 *
 * @param string $pid
 *   The PID of the new object to create.
 * @param $private
 *   TRUE if the new object should be private or not.
 * @param $files
 *   An associative array where the keys are DSID's and the files are the
 *   datastream content.
 *
 * @return mixed
 *   The newly created object if successful, FALSE otherwise.
 */
function livingstone_fedora_import_add_manuscript_pdf($pid, $private, array $files) {
  $type = 'manuscript_additional_pdf';
  if (!livingstone_fedora_import_guard_add_object_does_not_exist($pid)) {
    return FALSE;
  }
  if (!livingstone_fedora_import_guard_add_object_has_required_files($type, $files)) {
    return FALSE;
  }
  $types = livingstone_fedora_import_types();
  $type_info = $types[$type];
  $parent_pid = preg_replace('/^(liv:[0-9]{6})_[0-9]{4}$/', '\1', $pid);
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models = $type_info['content_model'];
  $object->label = basename($files['OBJ']->filename);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  if ($private) {
    $policy = drupal_get_path('module', 'livingstone') . '/xacml/pdf_policy.xml';
    livingstone_fedora_import_add_update_datastream_from_file($object, 'POLICY', $policy);
  }
  foreach ($files as $dsid => $file) {
    livingstone_fedora_import_add_update_datastream_from_file($object, $dsid, $file);
  }
  try {
    return $connection->repository->ingestObject($object);
  } catch (Exception $e) {
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
}

/**
 * Adds a new illustrative object if possible.
 *
 * @param string $pid
 *   The PID of the new object to create.
 * @param $private
 *   TRUE if the new object should be private or not.
 * @param $files
 *   An associative array where the keys are DSID's and the files are the
 *   datastream content.
 *
 * @return mixed
 *   The newly created object if successful, FALSE otherwise.
 */
function livingstone_fedora_import_add_illustrative($pid, $private, array $files) {
  $type = 'illustrative';
  if (!livingstone_fedora_import_guard_add_object_does_not_exist($pid)) {
    return FALSE;
  }
  if (!livingstone_fedora_import_guard_add_object_has_required_files($type, $files)) {
    return FALSE;
  }
  $types = livingstone_fedora_import_types();
  $type_info = $types[$type];
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models = $type_info['content_model'];
  $object->label = livingstone_fedora_import_get_label($files['MODS']);
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', 'liv:illustrative');
  if ($private) {
    $policy = drupal_get_path('module', 'livingstone') . '/xacml/image_policy.xml';
    livingstone_fedora_import_add_update_datastream_from_file($object, 'POLICY', $policy);
  }
  livingstone_fedora_import_add_update_dublin_core($object, $files['MODS']);
  foreach ($files as $dsid => $file) {
    livingstone_fedora_import_add_update_datastream_from_file($object, $dsid, $file);
  }
  try {
    return $connection->repository->ingestObject($object);
  } catch (Exception $e) {
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
}

/**
 * Adds a new illustrative object if possible.
 *
 * @param string $pid
 *   The PID of the new object to create.
 * @param $private
 *   TRUE if the new object should be private or not.
 * @param $files
 *   An associative array where the keys are DSID's and the files are the
 *   datastream content.
 *
 * @return mixed
 *   The newly created object if successful, FALSE otherwise.
 */
function livingstone_fedora_import_add_no_crop($pid, $private, array $files) {
  $type = 'no_crop';
  if (!livingstone_fedora_import_guard_add_object_does_not_exist($pid)) {
    return FALSE;
  }
  if (!livingstone_fedora_import_guard_add_object_has_required_files($type, $files)) {
    return FALSE;
  }
  $types = livingstone_fedora_import_types();
  $type_info = $types[$type];
  $parent_pid = preg_replace('/^(liv:[0-9]{6}_[0-9]{4})_noCrop$/', '\1', $pid);
  $connection = islandora_get_tuque_connection();
  $object = $connection->repository->constructObject($pid);
  $object->owner = 'fedoraAdmin';
  $object->models = $type_info['content_model'];
  $object->label = $pid;
  $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $parent_pid);
  if ($private) {
    $policy = drupal_get_path('module', 'livingstone') . '/xacml/image_policy.xml';
    livingstone_fedora_import_add_update_datastream_from_file($object, 'POLICY', $policy);
  }
  foreach ($files as $dsid => $file) {
    livingstone_fedora_import_add_update_datastream_from_file($object, $dsid, $file);
  }
  try {
    return $connection->repository->ingestObject($object);
  } catch (Exception $e) {
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
}

/**
 * Makes the given object private if possible.
 *
 * @param AbstractObject $object
 *   The object to make private.
 *
 * @return bool
 *   TRUE if successful FALSE otherwise.
 */
function livingstone_fedora_import_make_private(AbstractObject $object) {
  $xacml_path = drupal_get_path('module', 'livingstone') . '/xacml';
  $policy_info = array(
    'islandora:manuscriptPageCModel' => "$xacml_path/page_policy.xml",
    'islandora:sp_large_image_cmodel' => "$xacml_path/image_policy.xml",
    'islandora:sp_pdf' => "$xacml_path/pdf_policy.xml",
  );
  $supported_models = array_intersect($object->models, array_keys($policy_info));
  $content_model = reset($supported_models);
  if (empty($policy_info[$content_model])) {
    // Not applicable but none the less mark as success.
    return TRUE;
  }
  $policy = $policy_info[$content_model];
  try {
    if (empty($object['POLICY'])) {
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
  } catch(Exception $e) {
    watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
    return FALSE;
  }
  return TRUE;
}

/**
 * Removes the objects policy making it public.
 *
 * @param AbstractObject $object
 *   The object to be made public.
 *
 * @return bool
 *   TRUE if successful FALSE otherwise.
 */
function livingstone_fedora_import_make_public(AbstractObject $object) {
  if (isset($object['POLICY'])) {
    try {
      $object->purgeDatastream('POLICY');
    } catch (Exception $e) {
      watchdog_exception(LIVINGSTONE_FEDORA_IMPORT_ERROR, $e);
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Checks if the import tables are empty so that we don't run with empty data.
 *
 * @return bool
 *   TRUE if tables are not empty FALSE otherwise.
 */
function livingstone_fedora_import_safe_to_run_batch() {
  $local_count = db_select(LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE, LIVINGSTONE_FEDORA_IMPORT_LOCAL_TABLE_ALIAS)
    ->countQuery()
    ->execute()
    ->fetchField();

  $remote_count = db_select(LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE, LIVINGSTONE_FEDORA_IMPORT_REMOTE_TABLE_ALIAS)
    ->countQuery()
    ->execute()
    ->fetchField();

  return $local_count > 0 && $remote_count > 0;
}