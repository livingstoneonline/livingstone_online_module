<?php

/**
 * @file
 * Forms for managing the import of content from the FTP into Fedora.
 */


require_once dirname(__FILE__) . '/fedora.import.inc';
require_once dirname(__FILE__) . '/fedora.import.batch.inc';

/**
 * Menu callback for various forms for importing / managing Fedora content.
 *
 * @return array
 *   Renderable array.
 */
function livingstone_fedora_import_overview_menu_task() {
  $module_path = drupal_get_path('module', 'livingstone_fedora_import');
  return array(
    '#attached' => array(
      'css' => array(
        "$module_path/css/fedora.import.form.css",
      ),
    ),
    'ftp_settings_form' => drupal_get_form('livingstone_fedora_import_ftp_settings_form'),
    'update_tables_form' => drupal_get_form('livingstone_fedora_import_update_tables_form'),
    'solr_reindex_form' => drupal_get_form('livingstone_fedora_import_solr_reindex_form'),
    'missing_derivatives_form' => drupal_get_form('livingstone_fedora_import_missing_derivatives_form'),
    'sync_form' => drupal_get_form('livingstone_fedora_import_sync_form'),
    'tables' => array(
      '#prefix' => '<div class="livingstone-import-fedora-tables">',
      '#suffix' => '</div>',
      array(
        '#prefix' => '<div class="livingstone-import-fedora-table-group">',
        '#suffix' => '</div>',
        'local_stats' => livingstone_fedora_import_local_stats_table(),
        'remote_stats' => livingstone_fedora_import_remote_stats_table(),
      ),
      array(
        '#prefix' => '<div class="livingstone-import-fedora-table-group">',
        '#suffix' => '</div>',
        'up_to_date_stats' => livingstone_fedora_import_up_to_date_stats_table(),
        'out_of_date_stats' => livingstone_fedora_import_out_of_date_stats_table(),
      ),
      array(
        '#prefix' => '<div class="livingstone-import-fedora-table-group">',
        '#suffix' => '</div>',
        'add_stats_table' => livingstone_fedora_import_add_stats_table(),
        'remove_stats_table' => livingstone_fedora_import_remove_stats_table(),
      ),
      array(
        '#prefix' => '<div class="livingstone-import-fedora-table-group">',
        '#suffix' => '</div>',
        'private_stats_table' => livingstone_fedora_import_private_stats_table(),
        'public_stats_table' => livingstone_fedora_import_public_stats_table(),
      ),
      array(
        '#prefix' => '<div class="livingstone-import-fedora-table-group">',
        '#suffix' => '</div>',
        'datastream_stats_table' => livingstone_fedora_import_derivatives_stats_table(),
      ),
    ),
  );
}

/**
 * Gets a reference to the settings for the given form.
 *
 * We store the settings in the $_SESSION for the given user.
 *
 * @param string $settings
 *   The settings to get.
 *
 * @return array
 *   A reference to the settings storage.
 */
function &livingstone_fedora_import_form_settings($settings) {
  if (!isset($_SESSION[$settings])) {
    $_SESSION[$settings] = array();
  }
  return $_SESSION[$settings];
}

/**
 * Clears the given form settings.
 *
 * @param string $settings
 *   The settings to reset.
 */
function &livingstone_fedora_import_reset_form_settings($settings) {
  unset($_SESSION[$settings]);
}

/**
 * Creates a form for updating Fedora content from the FTP.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_ftp_settings_form(array $form, array &$form_state) {
  $server = livingstone_system_settings_form_default_value('livingstone_ftp_server', 'agnes.unl.edu', $form_state);
  $user = livingstone_system_settings_form_default_value('livingstone_ftp_user', 'nbanks', $form_state);
  $password = livingstone_system_settings_form_default_value('livingstone_ftp_password', '', $form_state);
  $access_message = livingstone_fedora_import_ftp_settings_form_access_message($server, $user, $password);
  return array(
    'ftp' => array(
      '#type' => 'fieldset',
      '#title' => t('FTP Server Settings'),
      'livingstone_ftp_server' => array(
        '#type' => 'textfield',
        '#title' => t('URL'),
        '#required' => TRUE,
        '#default_value' => $server,
        '#description' => filter_xss(t('!message', array('!message' => $access_message)), array('a', 'img')),
      ),
      'livingstone_ftp_user' => array(
        '#type' => 'textfield',
        '#title' => t('User'),
        '#required' => TRUE,
        '#default_value' => $user,
      ),
      'livingstone_ftp_password' => array(
        '#type' => 'password',
        '#title' => t('Password'),
        '#required' => TRUE,
        '#default_value' => $password,
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Update'),
      ),
    ),
  );
}

/**
 * Gets the default value for the given system_settings_form() element.
 *
 * Checks the $form_state for the default value if not it checks
 * variable_get(). Assumes #tree is FALSE. This is only really required
 * for elements that utilize AJAX, as their value can change before the
 * submit actually takes place.
 *
 * @param string $name
 *   The name of the system settings form element.
 * @param mixed $default_value
 *   The default value for the system settings form element.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return mixed
 *   The default value for use in a the system_settings_form().
 */
function livingstone_system_settings_form_default_value($name, $default_value, array &$form_state) {
  return isset($form_state['values'][$name]) ? $form_state['values'][$name] : variable_get($name, $default_value);
}

/**
 * Get a message of success or failure in attempting to connect to the server.
 *
 * @param string $server
 *   The server to attempt to authenticate against.
 * @param string $user
 *   The user to attempt to authenticate with.
 * @param string $password
 *   The password to attempt to authenticate with.
 *
 * @return string
 *   The access message to be displayed to the user.
 */
function livingstone_fedora_import_ftp_settings_form_access_message($server, $user, $password) {
  if (livingstone_fedora_import_valid_ftp_connection($server, $user, $password)) {
    $message = theme_image(array('path' => 'misc/watchdog-ok.png', 'attributes' => array()));
    $message .= t('Successfully connected to FTP Server!');
  }
  else {
    $message = theme_image(array('path' => 'misc/watchdog-error.png', 'attributes' => array()));
    $message .= t('Unable to connect to FTP server!');
  }
  return $message;
}

/**
 * Updates the FTP settings.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_ftp_settings_form_submit(array $form, array &$form_state) {
  $variables = array(
    'livingstone_ftp_server',
    'livingstone_ftp_user',
    'livingstone_ftp_password',
  );
  foreach ($variables as $variable) {
    variable_set($variable, $form_state['values'][$variable]);
  }
}

/**
 * Creates a form for updating the import tables.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_update_tables_form(array $form, array &$form_state) {
  $last_modified_date = variable_get('livingstone_import_table_updated', t('Never'));
  $symbols = array('B', 'KiB', 'MiB', 'GiB', 'TiB', 'PiB', 'EiB', 'ZiB', 'YiB');
  $bytes = disk_total_space("/opt/fedora/data");
  $exp = floor(log($bytes)/log(1024));
  $total_disk_space = sprintf('%.2f ' . $symbols[$exp], ($bytes/pow(1024, floor($exp))));
  $bytes = disk_free_space("/opt/fedora/data");
  $exp = floor(log($bytes)/log(1024));
  $disk_free_space = sprintf('%.2f ' . $symbols[$exp], ($bytes/pow(1024, floor($exp))));
  return array(
    'import' => array(
      '#type' => 'fieldset',
      '#title' => t('Import Table Settings'),
      'last_modified' => array(
        '#markup' => t('<p>The import table stores information used to determine what files need to copied from the FTP server to Fedora. <br/> To do this it compares the MD5 checksums provided by import.csv on the FTP server against the MD5 checksums stored in Fedora. </p> <p> Import table was last updated: <strong>@date</strong></p><p>Total Disk Space: <strong>@total</strong></p><p>Free Disk Space: <strong>@free</strong></p>', array(
          '@date' => $last_modified_date,
          '@total' => $total_disk_space,
          '@free' => $disk_free_space,
        )),
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Update'),
      ),
    ),
  );
}

/**
 * Submit the form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_update_tables_form_submit(array $form, array &$form_state) {
  livingstone_fedora_import_update_tables();
}

/**
 * Creates a form for updating the import tables.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_solr_reindex_form(array $form, array &$form_state) {
  return array(
    'index' => array(
      '#type' => 'fieldset',
      '#title' => t('Re-Index Manuscripts in Solr'),
      'last_modified' => array(
        '#markup' => t('<p>The re-indexes manuscript objects in solr, needed for when pages get added to existing manuscripts.</p>'),
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Re-Index'),
      ),
    ),
  );
}

/**
 * Submit the form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_solr_reindex_form_submit(array $form, array &$form_state) {
  $batch = livingstone_fedora_import_reindex_manuscripts_batch(TRUE);
  batch_set($batch);
}

/**
 * Creates a form for generating missing derivatives.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_missing_derivatives_form(array $form, array &$form_state) {
  return array(
    'index' => array(
      '#type' => 'fieldset',
      '#title' => t('Generate Missing Derivatives'),
      'last_modified' => array(
        '#markup' => t('<p>Generates missing derivatives. Depending on the number of missing derivatives this can take some time.</p>'),
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Generate'),
      ),
    ),
  );
}

/**
 * Submit the form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_missing_derivatives_form_submit(array $form, array &$form_state) {
  $batch = livingstone_fedora_import_missing_derivatives_batch();
  batch_set($batch);
}

/**
 * Update the sync form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 *
 * @return array
 *   Drupal form definition.
 */
function livingstone_fedora_import_sync_form(array $form, array &$form_state) {
  return array(
    'import' => array(
      '#type' => 'fieldset',
      '#title' => t('Import Content From FTP Server'),
      'description' => array(
        '#markup' => t('<p>This will run all the required steps to bring the Fedora in-sync with the FTP server.</p>'),
      ),
      'update' => array(
        '#type' => 'submit',
        '#value' => t('Import All Content'),
      ),
    ),
  );
}

/**
 * Submit the form.
 *
 * @param array $form
 *   Drupal Form.
 * @param array $form_state
 *   Drupal Form state.
 */
function livingstone_fedora_import_sync_form_submit(array $form, array &$form_state) {
  livingstone_fedora_import_update_tables();
  $batch = livingstone_fedora_import_add_objects_batch();
  batch_set($batch);
  $batch = livingstone_fedora_import_remove_objects_batch();
  batch_set($batch);
  $batch = livingstone_fedora_import_update_objects_batch();
  batch_set($batch);
  $batch = livingstone_fedora_import_publish_objects_batch();
  batch_set($batch);
  $batch = livingstone_fedora_import_reindex_manuscripts_batch();
  batch_set($batch);
}

/**
 * Gets the remote stats table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_remote_stats_table() {
  $header = array('Remote Objects (<strong>On FTP Server</strong>)', 'Count');
  $results = db_query("SELECT DISTINCT type, count(type) as count FROM {livingstone_fedora_remote_objects} GROUP by type ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No remote files (<strong>Something is wrong</strong>).'));
}

/**
 * Gets the missing types table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_local_stats_table() {
  $header = array('Local Objects (<strong>In Fedora</strong>)', 'Count');
  $results = db_query("SELECT DISTINCT type, count(type) as count FROM {livingstone_fedora_local_objects} GROUP by type ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No local files (<strong>Something is wrong</strong>).'));
}

/**
 * Gets the remote stats table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_up_to_date_stats_table() {
  $header = array('Local Objects that are <strong>up to date</strong>', 'Count');
  $results = db_query("SELECT DISTINCT l.TYPE, count(l.TYPE) as count FROM {livingstone_fedora_local_objects} as l LEFT OUTER JOIN {livingstone_fedora_remote_objects} as r on l.PID = r.PID WHERE (l.MD5 <=> r.MD5) GROUP by l.TYPE ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No objects are up to date (<strong>Something is wrong</strong>).'));
}

/**
 * Gets the missing types table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_out_of_date_stats_table() {
  $header = array('Local Objects that are <strong>out to date</strong>', 'Count');
  $results = db_query("SELECT DISTINCT l.TYPE, count(l.TYPE) as count FROM {livingstone_fedora_local_objects} as l LEFT OUTER JOIN {livingstone_fedora_remote_objects} as r on l.PID = r.PID WHERE (NOT l.MD5 <=> r.MD5) GROUP by l.TYPE ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No objects are out of date.'));
}

/**
 * Gets the missing types table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_add_stats_table() {
  $header = array('Missing Objects (<strong>To be Added</strong>)', 'Count');
  $results = db_query("SELECT DISTINCT r.type, count(r.type) as count FROM {livingstone_fedora_remote_objects} as r WHERE PID NOT IN (SELECT DISTINCT PID from {livingstone_fedora_local_objects}) GROUP by r.type ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No objects to add.'));
}

/**
 * Gets the missing types table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_public_stats_table() {
  $header = array('Local Objects to be <strong>made public</strong>', 'Count');
  $results = db_query("SELECT DISTINCT l.TYPE, count(l.TYPE) as count FROM {livingstone_fedora_local_objects} as l LEFT OUTER JOIN {livingstone_fedora_local_objects} as r on l.PID = r.PID WHERE (l.PRIVATE <> r.PRIVATE AND l.PRIVATE=true) GROUP by l.TYPE ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No local files are to be made public.'));
}

/**
 * Gets the missing types table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_private_stats_table() {
  $header = array('Local Objects to be <strong>made private</strong>', 'Count');
  $results = db_query("SELECT DISTINCT l.TYPE, count(l.TYPE) as count FROM {livingstone_fedora_local_objects} as l LEFT OUTER JOIN {livingstone_fedora_remote_objects} as r on l.PID = r.PID WHERE (l.PRIVATE <> r.PRIVATE AND l.PRIVATE=false) GROUP by l.TYPE ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No local files are to be made private.'));
}

/**
 * Gets the missing types table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_remove_stats_table() {
  $header = array('Stale Objects (<strong>To be Removed</strong>)', 'Count');
  $results = db_query("SELECT DISTINCT l.type, count(l.type) as count FROM {livingstone_fedora_local_objects} as l WHERE PID NOT IN (SELECT DISTINCT PID from {livingstone_fedora_remote_objects}) GROUP by l.type ORDER BY count DESC;");
  return livingstone_fedora_import_count_table($results, $header, t('No objects to be removed.'));
}

/**
 * Gets the datastream table.
 *
 * @return array
 *   A renderable array.
 */
function livingstone_fedora_import_derivatives_stats_table() {
  $types = livingstone_fedora_import_types();
  $total = 0;
  $rows = array();
  foreach ($types as $key => $type) {
    if ($key == 'spectral_manuscript_page') {
      $count = livingstone_fedora_import_spectral_page_derivatives_missing_count();
    }
    else {
      $count = livingstone_fedora_import_derivatives_missing_count($type['content_model'], $type['derived_datastreams']);
    }
    $rows[] = array($type['title'], $count);
    $total += $count;
  }
  if ($total) {
    $rows[] = array(
      t('<strong>Total</strong>'),
      t('<strong>@total</strong>', array('@total' => $total))
    );
  }
  return array(
    '#prefix' => '<div class="livingstone-import-fedora-table">',
    '#suffix' => '</div>',
    '#theme' => 'table',
    '#header' => array('Objects Missing Derivatives (<strong>In Fedora</strong>)', 'Count'),
    '#rows' => $rows,
    '#empty' => t('No derivatives missing.'),
  );
}

/**
 * Gets PIDs with missing datastreams for the given content model.
 */
function livingstone_fedora_import_derivatives_missing_count($content_model, array $datastreams) {
  if (empty($datastreams)) {
    return 0;
  }
  $filter_queries = array();
  foreach ($datastreams as $datastream) {
    $filter_queries[] = "(fedora_datastreams_ms:[* TO *] -fedora_datastreams_ms:$datastream)";
  }
  $params = array(
    'fl' => 'PID',
    'fq' => implode(' OR ', $filter_queries),
    'defType' => 'edismax',
  );
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search("RELS_EXT_hasModel_uri_s:\"info:fedora/$content_model\"", 0, 0, $params, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  $response = isset($results) ? json_decode($results->getRawResponse(), TRUE) : array(
    'response' => array(
      'numFound' => 0,
    ),
  );
  return $response['response']['numFound'];
}

/**
 * Spectral pages are a special case since there derivatives are unique to each.
 */
function livingstone_fedora_import_spectral_page_derivatives_missing_count() {
  $params = array(
    'fl' => 'PID,fedora_datastreams_ms',
  );
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search('RELS_EXT_hasModel_uri_s:"info:fedora/livingstone:spectralManuscriptPageCModel"', 0, 10000, $params, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  $response = isset($results) ? json_decode($results->getRawResponse(), TRUE) : array(
    'response' => array(
      'docs' => array(
      ),
    ),
  );
  $count = 0;
  foreach ($response['response']['docs'] as $doc) {
    // The number of datastreams should be divisible by 4.
    $datastreams = array_diff($doc['fedora_datastreams_ms'], array('AUDIT', 'DC', 'RELS-EXT', 'ZIP', 'GIF'));
    $sources = array_filter($datastreams, function($datastream) { return strpos($datastream, '_JP2') !== FALSE; });
    $derivatives = array_filter($datastreams, function($datastream) { return strpos($datastream, '_JP2') !== FALSE; });
    if (count($sources) !== count($derivatives)) {
      $count += 1;
    }
  }
  return $count;
}

/**
 * Renders a two column table of information of counts and their sum.
 *
 * @param DatabaseStatementInterface $results
 *   The results to populate the count table with.
 * @param array $header
 *   The header of the count table.
 * @param $empty_message
 *   The message to display if the count table is empty.
 *
 * @return array
 *   A renderable array describing the count table.
 */
function livingstone_fedora_import_count_table(DatabaseStatementInterface $results, array $header, $empty_message) {
  $type_titles =livingstone_fedora_import_titles();
  $total = 0;
  $rows = array();
  foreach ($results->fetchAllKeyed() as $type => $count) {
    $rows[] = array($type_titles[$type], $count);
    $total += $count;
  }
  if ($total) {
    $rows[] = array(
      t('<strong>Total</strong>'),
      t('<strong>@total</strong>', array('@total' => $total))
    );
  }
  return array(
    '#prefix' => '<div class="livingstone-import-fedora-table">',
    '#suffix' => '</div>',
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => $empty_message,
  );
}