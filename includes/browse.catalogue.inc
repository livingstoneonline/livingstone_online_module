<?php

/**
 * @file
 * Browse by catalog page.
 */

const LIVINGSTONE_BROWSE_CATALOGUE_LIMIT_RESULTS = 100;

/**
 * Search form.
 *
 * @param array $form
 *   Drupal form.
 * @param array $form_state
 *   Drupal form state.
 * @param $query
 *   The search query.
 *
 * @return array
 *   The search form and results.
 */
function livingstone_browse_catalogue_form(array $form, array &$form_state, $query) {
  form_load_include($form_state, 'inc', 'livingstone', 'includes/browse.catalogue');
  $query = livingstone_browse_catalogue_default_value('query', $query, $form_state);
  livingstone_browse_catalogue_form_ajax_hacks($form_state, $query);
  $full_record = livingstone_browse_catalogue_default_value('full_record', 0, $form_state);
  $results = livingstone_browse_catalogue_search($query, $form_state);
  list($access, $limit, $creator, $addressee, $repository, $genre) = livingstone_browse_catalogue_facet_elements($results, $form_state);
  $table = livingstone_browse_catalogue_table($results, !$full_record);
  list($year, $from, $to) = livingstone_browse_catalogue_facet_range_elements($query, $form_state);
  $pager = livingstone_browse_catalogue_pager($results);
  $path = drupal_get_path('module', 'livingstone');
  return array(
    '#prefix' => '<div id="form_wrapper">',
    '#suffix' => '</div>',
    '#attached' => array(
      'js' => array(
        "$path/lib/URI.js",
        "$path/js/browse.catalogue.js",
        "$path/js/livingstone-manuscript-launcher.js",
        array(
          'type' => 'setting',
          'data' => array(
            'livingstoneBrowseCatalogue' => array(
              'facets' => livingstone_browse_catalogue_facet_fields(),
            ),
          )
        ),
      ),
      'css' => array(
        "$path/css/browse.catalogue.css",
        "$path/css/manuscript-launcher.css",
      ),
    ),
    'ajax-wrapper' => array(
      '#type' => 'container',
      '#prefix' => '<div id="ajax-wrapper">',
      '#suffix' => '</div>',
      '#attributes' => array(
        'class' => array(
          'browse-catalogue-base',
        ),
      ),
      'controls' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'col-sm-4',
            'col-lg-3',
            'search-fields',
          ),
        ),
        'search-block' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'search-block',
            ),
          ),
          '#theme' => 'livingstone_browse_catalogue_search',
          'query' => array(
            '#type' => 'textfield',
            '#size' => NULL,
            '#default_value' => $query,
            '#attributes' => array(
              'class' => array(
                'img-rounded',
              ),
            ),
          ),
          'search' => array(
            '#type' => 'submit',
            '#value' => t('Search'),
            '#attributes' => array(
              'class' => array(
                'search-button',
                'img-rounded',
                'btn',
                'btn-small',
                'btn-secondary',
              ),
            ),
          ),
        ),
        'limit' => $limit,
        'full_record' => array(
          '#prefix' => '<div class="full-record">',
          '#suffix' => '</div>',
          '#type' => 'checkbox',
          '#title' => t('Full Record'),
          '#default_value' => $full_record,
        ),
        'date-container' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'date-container',
            ),
          ),
          'range' => array(
            '#theme' => 'livingstone_browse_catalogue_date_range',
            '#attributes' => array(
              'class' => array(
                'range',
              ),
            ),
            'year' => $year,
            'from' => $from,
            'to' => $to,
          ),
          'clearfix' => array(
            '#markup' => '<div class="clearfix"></div>',
          ),
        ),
        'creator' => $creator,
        'addressee' => $addressee,
        'repository' => $repository,
        'genre' => $genre,
        'access' => $access,
        'page' => array(
          '#type' => 'hidden',
          '#default_value' => livingstone_browse_catalogue_default_value('page', 0, $form_state),
        ),
        'sort' => array(
          '#type' => 'hidden',
          '#default_value' => livingstone_browse_catalogue_default_value('sort', 'asc', $form_state),
        ),
        'order' => array(
          '#type' => 'hidden',
          '#default_value' => livingstone_browse_catalogue_default_value('order', 'Date(s)', $form_state),
        ),
        'clear' => array(
          '#type' => 'submit',
          '#value' => t('Clear search / browse choices'),
          '#submit' => array('livingstone_browse_catalogue_form_clear_submit'),
          '#attributes' => array(
            'class' => array(
              'clear-button',
              'img-rounded',
              'btn',
              'btn-small',
              'btn-secondary',
            ),
          ),
        ),
        'rebuild' => array(
          '#name' => 'rebuild',
          '#type' => 'submit',
          '#value' => t('Rebuild'),
          '#prefix' => '<div style="display:none">',
          '#suffix' => '</div>',
          '#submit' => array('livingstone_browse_catalogue_form_rebuild_submit'),
          '#ajax' => array(
            'wrapper' => 'ajax-wrapper',
            'callback' => 'livingstone_browse_catalogue_form_ajax_callback',
          ),
        ),
        'download_links' => array(
          '#markup' => livingstone_browse_catalogue_form_download_markup(),
        ),
      ),
      'results' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'col-sm-8',
            'col-lg-9',
          ),
        ),
        'top_pager' => array(
          '#markup' => $pager,
        ),
        'table' => $table,
        'bottom_pager' => array(
          '#markup' => $pager,
        ),
      ),
    )) + $form;
}

function livingstone_browse_catalogue_form_download_markup() {
  $pdf_files = file_create_url(file_build_uri('/Livingstone-Online-Complete-PDF-transcriptions.zip'));
  $tei_files = file_create_url(file_build_uri('/Livingstone-Online-Complete-TEI-transcriptions.zip'));
  $mods_files = file_create_url(file_build_uri('/Livingstone-Online-Complete-MODS-records.zip'));
  return <<<EOT
<div class="catalogue-download-links">
  <div>Download complete:</div>
  <div><a href="$pdf_files">PDF transcriptions</a>(all users)</div>
  <div><a href="$tei_files">TEI transcriptions</a>(specialists)</div>
  <div><a href="$mods_files">MODS Records</a>(specialists)</div>
</div>
EOT;
}

/**
 * Hacks to allow for Ajax based paging and sorting.
 *
 * Drupal functions for paging and sorting assume the will always be called from
 * the context of the page they are rendering in a non-ajax context.
 *
 * @param array $form_state
 *   The Drupal form state.
 * @param $query
 *   The search query.
 */
function livingstone_browse_catalogue_form_ajax_hacks(array &$form_state, $query) {
  $_GET['page'] = livingstone_browse_catalogue_default_value('page', 0, $form_state);
  $_GET['sort'] = livingstone_browse_catalogue_default_value('sort', 'asc', $form_state);
  $_GET['order'] = livingstone_browse_catalogue_default_value('order', 'Date(s)', $form_state);
  $form_state['build_info']['args'][0] = $query;
}

/**
 * The AJAX callback for action selected.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   A Drupal form definition.
 */
function livingstone_browse_catalogue_form_ajax_callback(array $form, array &$form_state) {
  $form_state['rebuild'] = TRUE;
  return $form['ajax-wrapper'];
}

/**
 * Causes form to be rebuild, potentially dropping other form steps.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 */
function livingstone_browse_catalogue_form_rebuild_submit(array $form, array &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * Clear the form.
 *
 * @param array $form
 *   Drupal form.
 * @param array $form_state
 *   Drupal form state.
 */
function livingstone_browse_catalogue_form_clear_submit(array $form, array &$form_state) {
  $form_state['redirect'] = "islandora/search";
}

/**
 * Execute the search, by redirecting to this form with different settings.
 *
 * @param array $form
 *   Drupal form.
 * @param array $form_state
 *   Drupal form state.
 */
function livingstone_browse_catalogue_form_submit(array $form, array &$form_state) {
  $values = $form_state['values'];
  $form_state['redirect'] = array(
    "islandora/search/{$values['query']}",
    array(
      'query' => livingstone_browse_catalogue_build_query($values),
    ),
  );
}

/**
 * Builds the redirect query for searching.
 *
 * @param array $values
 *   The submitted values to build the query from.
 *
 * @return array
 *   The URL query for use in the form redirect.
 */
function livingstone_browse_catalogue_build_query(array $values) {
  $query = array();
  if ($values['full_record']) {
    $query['full_record'] = 1;
  }
  if (isset($values['access'])) {
    $query['access'] = $values['access'];
  }
  if (isset($values['limit'])) {
    $query['limit'] = $values['limit'];
  }
  $filter_query = livingstone_browse_catalogue_build_filter_query($values);
  if (!empty($filter_query)) {
    $query['f'] = $filter_query;
  }
  return $query;
}

/**
 * Builds the filter query from the given values.
 *
 * @param array $values
 *   The submitted values to build the filter query from.
 *
 * @return array
 *   The filter query to apply to the URL query.
 */
function livingstone_browse_catalogue_build_filter_query(array $values) {
  $filter_query = array();
  $value = function($name) use ($values) {
    return isset($values[$name]) ? $values[$name] : NULL;
  };
  $filter_query[] = livingstone_browse_catalogue_build_facet_field_filter_query('creator', $value('creator'));
  $filter_query[] = livingstone_browse_catalogue_build_facet_field_filter_query('addressee', $value('addressee'));
  $filter_query[] = livingstone_browse_catalogue_build_facet_field_filter_query('repository', $value('repository'));
  $filter_query[] = livingstone_browse_catalogue_build_facet_field_filter_query('genre', $value('genre'));
  $date_values = $value('year') ? $value('year') : array($value('from'), $value('to'));
  $filter_query[] = livingstone_browse_catalogue_build_facet_range_filter_query('date', $date_values);
  return array_filter($filter_query);
}

/**
 * Builds a filter query for the given facet, for use in the redirect URL.
 *
 * @param string $facet
 *   The type of facet to filter by.
 * @param string $value
 *   The value to filter by.
 *
 * @return null|string
 *   The filter query for the given facet if one was build, NULL otherwise.
 */
function livingstone_browse_catalogue_build_facet_field_filter_query($facet, $value) {
  if ($value) {
    $facet_fields = livingstone_browse_catalogue_facet_fields();
    $facet_field = $facet_fields[$facet];
    return "{$facet_field}:\"{$value}\"";
  }
  return NULL;
}

/**
 * Builds a filter query for the given range facet, for use in the redirect URL.
 *
 * @param string $facet
 *   The type of facet to filter by.
 * @param mixed $values
 *   The value to filter by.
 *
 * @return null|string
 *   The filter query for the given ranged facet if one was build, NULL
 *   otherwise.
 */
function livingstone_browse_catalogue_build_facet_range_filter_query($facet, $values) {
  $facet_range_fields = livingstone_browse_catalogue_facet_range_fields();
  $facet_range_field = $facet_range_fields[$facet];

  if (!is_array($values) && $values != 0) {
    return "{$facet_range_field}:{$values}";
  }
  if (is_array($values)) {
    list($from, $to) = $values;
    if ($from || $to) {
      $from = $from != 0 ? $from : '*';
      $to = $to != 0 ? $to : '*';
      return "{$facet_range_field}:[{$from} TO {$to}]";
    }
  }
  return NULL;
}

/**
 * Creates a select field for every facet field.
 *
 * @param array $results
 *   An associative array of search results returned from Solr.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   An array of form elements.
 */
function livingstone_browse_catalogue_facet_elements(array $results, array &$form_state) {
  $elements = array();
  // Exceptional case for View / Download.
  $elements[] = array(
    '#type' => 'select',
    '#default_value' => livingstone_browse_catalogue_default_value('access', 'all', $form_state),
    '#options' => array(
      'all' => t('Access options'),
      'view' => t('View (any)'),
      'view_transcription' => t('View (w/ transcriptions)'),
      'view_wo_transcription' => t('View (w/o transcriptions)'),
      'download' => t('Download (any)'),
      'download_transcription' => t('Download (w/ transcriptions)'),
      'download_wo_transcription' => t('Download (w/o transcriptions)'),
      'both' => t('View & download (any)'),
      'both_transcription' => t('View & download (w/ transcriptions)'),
      'both_wo_transcription' => t('View & download (w/o transcriptions)'),
      'restricted' => t('Restricted'),
      'neither' => t('No access available'),
    ),
    '#attributes' => array(
      'class' => array(
        'img-rounded'
      ),
    ),
  );
  $elements[] = array(
    '#type' => 'select',
    '#default_value' => livingstone_browse_catalogue_default_value('limit', 'catalogue', $form_state),
    '#options' => array(
      'catalogue' => t('Search catalogue only'),
      'transcriptions' => t('Search transcriptions only'),
      'both' => t('Search catalogue & transcriptions'),
    ),
    '#attributes' => array(
      'class' => array(
        'img-rounded'
      ),
    ),
  );
  foreach (livingstone_browse_catalogue_facet_fields() as $facet => $facet_field) {
    $label = t(ucfirst($facet));
    $default = livingstone_browse_catalogue_facet_default($facet, $form_state);
    $results = livingstone_browse_catalogue_solr_search_without_facet($facet_field, $form_state);
    $options = livingstone_browse_catalogue_facet_options($facet, $results);
    $elements[] = array(
      '#type' => 'select',
      '#default_value' => $default,
      '#options' => array_merge(array($label), $options),
      '#attributes' => array(
        'class' => array(
          'img-rounded'
        ),
      ),
    );
  }
  return $elements;
}

/**
 * Builds the results pager.
 *
 * @param array $results
 *   An associative array of search results returned from Solr.
 *
 * @return string
 *   The HTML representation of the pager.
 */
function livingstone_browse_catalogue_pager(array $results) {
  $mock_pager = '<div class="mock-pager"></div>';
  pager_default_initialize($results['response']['numFound'], LIVINGSTONE_BROWSE_CATALOGUE_LIMIT_RESULTS);
  $pager = theme('pager', array('quantity' => 5));
  return empty($pager) ? $mock_pager :  $pager;
}

/**
 * Builds a table to display the search results.
 *
 * @param array $results
 *   An associative array of search results returned from Solr.
 * @param bool $collapsed
 *   If we are to results should be collapsed.
 *
 * @return array
 *   A renderable array defining the search result table display.
 */
function livingstone_browse_catalogue_table(array $results, $collapsed = TRUE) {
  $fields = livingstone_browse_catalogue_display_fields();
  $headers = array();
  foreach($fields as $field) {
    $collapsible = in_array('collapsible-column', $field['classes']);
    $collapse = $collapsible && $collapsed;
    $headers[] = array(
      'data' => $field['label'],
      'field' => $field['sort'],
      'sort' => isset($field['default_sort']) ? 'asc' : NULL,
      'class' => $field['classes'],
      'style' => $collapse ? 'display:none;' : NULL,
    );
  }
  $rows = array();
  $docs = isset($results['response']['docs']) && is_array($results['response']['docs']) ? $results['response']['docs'] : array();
  foreach ($docs as $doc) {
    $row = array();
    foreach($fields as $field) {
      $solr_field = $field['field'];
      $collapsible = in_array('collapsible-column', $field['classes']);
      $collapse = $collapsible && $collapsed;
      $data = '&nbsp;';
      if ($solr_field == 'PID') {
        $data = livingstone_browse_catalogue_view_link($doc);
        $data .= livingstone_browse_catalogue_download_link($doc);
      }
      else if (isset($doc[$solr_field]) && is_array($doc[$solr_field])) {
        $delimiter = isset($field['delimiter']) ? $field['delimiter'] : ';<br/>';
        $data = implode($delimiter, array_unique($doc[$solr_field]));
      }
      else if (isset($doc[$solr_field]) && is_string($doc[$solr_field])) {
        if (isset($field['split'])) {
          $split = $field['split'];
          $data = preg_replace("($split)", "$split<br/>", $doc[$solr_field]);
        }
        else {
          $data = $doc[$solr_field];
        }
      }
      if ($solr_field != 'PID') {
        // Setup dummy filter object.
        $filter = new stdClass();
        $filter->callback = '_filter_url';
        $filter->settings = array(
          'filter_url_length' => 496,
        );
        $data = _filter_url($data, $filter);
        $data = preg_replace('/>.*<\/a/', ' target="_blank">link</a', $data);
      }
      $row[] = array(
        'data' => $data,
        'class' => $field['classes'],
        'style' => $collapse ? 'display:none;' : NULL,
      );
    }
    $rows[] = $row;
  }
  return array(
    '#prefix' => '<div class="search-results">',
    '#suffix' => '</div>',
    '#theme' => 'table',
    '#sticky' => FALSE,
    '#header' => $headers,
    '#rows' => $rows,
    '#empty' => t('No results found.'),
  );
}

/**
 * Gets a link to view the given object.
 *
 * @param array $doc
 *   A single Solr result doc.
 *
 * @return string
 *   The link if one is generated.
 */
function livingstone_browse_catalogue_view_link($doc) {
  global $user;
  $pid = $doc['PID'];
  $viewable = isset($doc['viewable_b']) ? $doc['viewable_b'] : FALSE;
  $hidden = isset($doc['hidden_b']) ? $doc['hidden_b'] : TRUE;
  $hidden = $hidden && !in_array('administrator', $user->roles);
  $attributes = array(
    'external' => FALSE,
    'query' => drupal_get_query_parameters() +
      array(
        'view_pid' => $pid,
        'view_page' => 1,
      ),
    'attributes' => array(
      'data-pid' => $pid,
    ),
  );
  if ($viewable && !$hidden) {
    $attributes['attributes']['title'] = 'View';
    $attributes['attributes']['class'] = array(
      'livingstone-manuscript-launcher fa fa-camera'
    );
    return l((''), current_path(), $attributes);
  }
  else if ($viewable && $hidden) {
    $attributes['attributes']['title'] = 'Restricted';
    $attributes['attributes']['class'] = array(
      'livingstone-manuscript-launcher fa fa-ban'
    );
    return l((''), '#', $attributes);
  }
  return '&nbsp;';
}

/**
 * Gets a link to download the given objects ZIP datastream.
 *
 * @param $pid
 *   The object ID in which to potentially view.
 *
 * @return string
 *   The link if one is generated.
 */
function livingstone_browse_catalogue_download_link($doc) {
  $pid = $doc['PID'];
  $downloadable = isset($doc['downloadable_b']) ? $doc['downloadable_b'] : FALSE;
  $path = "islandora/object/$pid/datastream/ZIP/download";
  $attributes = array(
    'external' => FALSE,
    'attributes' => array(
      'title' => 'Download',
      'class' => array('fa fa-arrow-down'),
    ),
  );
  if ($downloadable) {
    $size = reset($doc['fedora_datastream_version_ZIP_SIZE_ms']);
    $size = number_format($size / 1024 / 1024, 1);
    return l((''), $path, $attributes) . "<span class='download-size'>($size MB)<span>";
  }
  return '&nbsp;';
}

/**
 * Performs a search.
 *
 * @param string $query
 *   The search query.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   The search results.
 */
function livingstone_browse_catalogue_search($query, array &$form_state) {
  $start = livingstone_browse_catalogue_start_search_parameter($form_state);
  $params = livingstone_browse_catalogue_search_parameters($form_state);
  return livingstone_browse_catalogue_solr_search($query, $start, $params);
}

/**
 * Performs a solr search
 *
 * @param string $query
 *   The search query.
 * @param int $start
 *   The start point in the returned results.
 * @param array $params
 *   The search parameters for Solr.
 *
 * @return array
 *   The search results.
 */
function livingstone_browse_catalogue_solr_search($query, $start, array $params) {
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search($query, $start, LIVINGSTONE_BROWSE_CATALOGUE_LIMIT_RESULTS, $params, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage());
  }
  return isset($results) ? json_decode($results->getRawResponse(), TRUE) : array();

}

/**
 * Search without the given facet.
 *
 * @param string $facet_field
 *   The facet to remove from the search.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 */
function livingstone_browse_catalogue_solr_search_without_facet($facet_field, array &$form_state) {
  $query = $form_state['build_info']['args'][0];
  // We perform an additional query with no date(s) set so we can appropriately
  // populate the date ranges and single value date fields.
  $params = livingstone_browse_catalogue_search_parameters($form_state);
  foreach($params['fq'] as $key => $filter_query) {
    if (strpos($filter_query, $facet_field) !== FALSE) {
      unset($params['fq'][$key]);
    }
  }
  return livingstone_browse_catalogue_solr_search($query, 0, $params);
}

/**
 * Generates the search parameters from the query parameters and defaults.
 *
 * @return array
 *   The search parameters for Solr.
 */
function livingstone_browse_catalogue_search_parameters(array &$form_state) {
  global $user;
  $values = isset($form_state['values']) ? $form_state['values'] : array();
  $filter_query = livingstone_browse_catalogue_build_filter_query($values);
  if (empty($filter_query)) {
    $filter_query = isset($_GET['f']) ? $_GET['f'] : NULL;
  }
  $access = isset($values['access']) ? $values['access'] : (isset($_GET['access']) ? $_GET['access'] : 'all');
  $hide = !in_array('administrator', $user->roles);
  switch($access) {
    case 'view':
      $filter_query[] = "viewable_b:true";
      if ($hide) {
        $filter_query[] = "hidden_b:false";
      }
      break;
    case 'view_transcription':
      $filter_query[] = "viewable_b:true";
      if ($hide) {
        $filter_query[] = "hidden_b:false";
      }
      $filter_query[] = "fedora_datastreams_ms:TEI";
      break;
    case 'view_wo_transcription':
      $filter_query[] = "viewable_b:true";
      if ($hide) {
        $filter_query[] = "hidden_b:false";
      }
      $filter_query[] = "-fedora_datastreams_ms:TEI";
      break;
    case 'restricted':
      $filter_query[] = "hidden_b:true";
      break;
    case 'download':
      $filter_query[] = "downloadable_b:true";
      break;
    case 'download_transcription':
      $filter_query[] = "downloadable_b:true";
      $filter_query[] = "fedora_datastreams_ms:TEI";
      break;
    case 'download_wo_transcription':
      $filter_query[] = "downloadable_b:true";
      $filter_query[] = "-fedora_datastreams_ms:TEI";
      break;
    case 'both':
      $filter_query[] = "viewable_b:true";
      $filter_query[] = "downloadable_b:true";
      if ($hide) {
        $filter_query[] = "hidden_b:false";
      }
      break;
    case 'both_transcription':
      $filter_query[] = "viewable_b:true";
      $filter_query[] = "downloadable_b:true";
      if ($hide) {
        $filter_query[] = "hidden_b:false";
      }
      $filter_query[] = "fedora_datastreams_ms:TEI";
      break;
    case 'both_wo_transcription':
      $filter_query[] = "viewable_b:true";
      $filter_query[] = "downloadable_b:true";
      if ($hide) {
        $filter_query[] = "hidden_b:false";
      }
      $filter_query[] = "-fedora_datastreams_ms:TEI";
      break;
    case 'neither':
      $filter_query[] = "viewable_b:false";
      break;
    default:
      break;
  }
  $filter_query[] = "RELS_EXT_hasModel_uri_s:\"info:fedora/islandora:manuscriptCModel\"";
  $limit = isset($values['limit']) ? $values['limit'] : (isset($_GET['limit']) ? $_GET['limit'] : 'catalogue');
  switch($limit) {
    case 'transcriptions':
      $qf = 'tei^1.0';
      break;
    case 'both':
      $qf = 'PID^1.0 title_t^1.0 date_mt creator_t addressee_t place_t genre_t repository_t copy_identifier_t otherVersion_t catalog_identifier_t master_id_t tei';
      break;
    case 'catalogue':
    default:
      $qf = 'PID^1.0 title_t^1.0 date_mt creator_t addressee_t place_t genre_t repository_t copy_identifier_t otherVersion_t catalog_identifier_t master_id_t';
      break;
  }
  return array(
    'fl' => livingstone_browse_catalogue_fl_search_parameter(),
    'fq' => $filter_query,
    'defType' => 'edismax',
    'qf' => $qf,
    'start' => livingstone_browse_catalogue_start_search_parameter($form_state),
    'rows' => LIVINGSTONE_BROWSE_CATALOGUE_LIMIT_RESULTS,
    'sort' => livingstone_browse_catalogue_sort_search_parameter($form_state),
    'facet' => 'true',
    'facet.mincount' => variable_get('islandora_solr_facet_min_limit', '2'),
    'facet.limit' => variable_get('islandora_solr_facet_max_limit', '20'),
    'facet.field' => array_values(livingstone_browse_catalogue_facet_fields()),
    'facet.range' => array_values(livingstone_browse_catalogue_facet_range_fields()),
    // Shouldn't be any dates before 1700's or after the current year.
    'facet.range.start' => 1700,
    'facet.range.end' => date("Y"),
    'facet.range.gap' => 1,
  );
}

/**
 * Gets the fl parameter.
 *
 * @return array
 */
function livingstone_browse_catalogue_fl_search_parameter() {
  $fl = array(
    'PID',
    'viewable_b',
    'downloadable_b',
    'hidden_b',
    'fedora_datastream_version_ZIP_SIZE_ms'
  );
  $fields = livingstone_browse_catalogue_display_fields();
  foreach($fields as $field) {
    $fl[] = $field['field'];
  }
  return $fl;
}

/**
 * Gets the start search parameter.
 *
 * @return int
 *   The document to start returning results from.
 */
function livingstone_browse_catalogue_start_search_parameter(array $form_state) {
  $page = livingstone_browse_catalogue_default_value('page', 0, $form_state);
  return LIVINGSTONE_BROWSE_CATALOGUE_LIMIT_RESULTS * $page;
}

/**
 * Gets the sort search parameter.
 *
 * @return null|string
 *   The search parameter if given in the URL, otherwise NULL.
 */
function livingstone_browse_catalogue_sort_search_parameter(array $form_state) {
  $direction = livingstone_browse_catalogue_default_value('sort', 'asc', $form_state);
  $order = livingstone_browse_catalogue_default_value('order', 'Date(s)', $form_state);
  if ($order != NULL) {
    $fields = livingstone_browse_catalogue_display_fields();
    foreach ($fields as $field) {
      if ($field['label'] == $order) {
        return "{$field['sort']} $direction, date_s asc, creator_s asc, title_s asc";
      }
    }
  }
  return NULL;
}

/**
 * Gets the catalog search results fields to display.
 *
 * @return array
 *   The search result display fields.
 */
function livingstone_browse_catalogue_display_fields() {
  return array(
    array(
      'label' => t('Access'),
      'field' => 'PID',
      'sort' => 'PID',
      'classes' => array('access-column'),
    ),
    array(
      'label' => t('Title'),
      'field' => 'title_s',
      'sort' => 'title_s',
      'classes' => array('title-column'),
    ),
    array(
      'label' => t('Date(s)'),
      'field' => 'date_ms',
      'sort' => 'dateRangeStart_dt',
      'default_sort' => TRUE,
      'classes' => array('date-column'),
    ),
    array(
      'label' => t('Creator(s)'),
      'field' => 'creator_ms',
      'sort' => 'creator_s',
      'classes' => array('creator-column'),
    ),
    array(
      'label' => t('Addressee(s)'),
      'field' => 'addressee_ms',
      'sort' => 'addressee_s',
      'classes' => array('addressee-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Place(s) Created'),
      'field' => 'place_s',
      'sort' => 'place_s',
      'classes' => array('place-created-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Extent (pages)'),
      'field' => 'extent_pages_s',
      'sort' => 'extent_pages_s',
      'classes' => array('pages-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Extent (size)'),
      'field' => 'extent_size_s',
      'sort' => 'extent_size_s',
      'classes' => array('size-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Genre(s)'),
      'field' => 'genre_s',
      'sort' => 'genre_s',
      'split' => ';',
      'classes' => array('genre-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Repository / Shelfmark'),
      'field' => 'repository_s',
      'sort' => 'repository_s',
      'classes' => array('repository-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Copy of Item'),
      'field' => 'copy_identifier_s',
      'sort' => 'copy_identifier_s',
      'classes' => array('copy-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Other Version(s)'),
      'field' => 'otherVersion_ms',
      'sort' => 'otherVersion_s',
      'delimiter' => '</br>',
      'classes' => array('other-versions-column', 'collapsible-column'),
    ),
    array(
      'label' => t('C&C Catalogue Number'),
      'field' => 'catalog_identifier_s',
      'sort' => 'catalog_identifier_s',
      'classes' => array('catalogue-number-column', 'collapsible-column'),
    ),
    array(
      'label' => t('Project ID'),
      'field' => 'master_id_s',
      'sort' => 'master_id_s',
      'classes' => array('master-id-column', 'collapsible-column'),
    ),
  );
}

/**
 * Gets the facet fields.
 *
 * @return array
 *   An associative array where the key identifies the fields purpose and the
 *   value is the actual Solr field.
 */
function livingstone_browse_catalogue_facet_fields() {
  return array(
    'creator' => 'creator_ms',
    'addressee' => 'addressee_ms',
    'repository' => 'repository_ms',
    'genre' => 'genre_ms',
    'date' => 'dateRangeYear_mi',
  );
}

/**
 * Get the ranged facet fields.
 *
 * @return array
 *   An associative array where the key identifies the fields purpose and the
 *   value is the actual Solr field.
 */
function livingstone_browse_catalogue_facet_range_fields() {
  return array(
    'date' => 'dateRangeYear_mi',
  );
}

/**
 * Gets the options for the given facet.
 *
 * @param string $facet
 *   The facet to fetch the options from the results for.
 * @param array $results
 *   The search results.
 *
 * @return array
 *   An associative array where the keys are the option values and the values,
 *   are what is to be displayed to the users.
 */
function livingstone_browse_catalogue_facet_options($facet, array $results) {
  $facet_fields = livingstone_browse_catalogue_facet_fields();
  $facet_field = $facet_fields[$facet];
  if (isset($results['facet_counts']['facet_fields'][$facet_field])) {
    $options = $results['facet_counts']['facet_fields'][$facet_field];
    $options = array_filter($options);
    ksort($options, SORT_NATURAL);
    foreach ($options as $value => &$count) {
      $value = html_entity_decode($value);
      $count = "$value ($count)";
    }
    return $options;
  }
  return array();
}

/**
 * Gets the options for the given range facet.
 *
 * @param string $facet
 *   The facet to fetch the options from the results for.
 * @param array $results
 *   The search results.
 *
 * @return array
 *   An associative array where the keys are the option values and the values,
 *   are what is to be displayed to the users.
 */
function livingstone_browse_catalogue_facet_range_options($facet, array $results) {
  $facet_fields = livingstone_browse_catalogue_facet_range_fields();
  $facet_field = $facet_fields[$facet];
  if (isset($results['facet_counts']['facet_ranges'][$facet_field]['counts'])) {
    $options = $results['facet_counts']['facet_ranges'][$facet_field]['counts'];
    $options = array_filter($options);
    ksort($options, SORT_NUMERIC);
    foreach ($options as $value => &$count) {
      $count = "$value ($count)";
    }
    return $options;
  }
  return array();
}

/**
 * Creates a fields for ranged facet fields.
 *
 * @param array $results
 *   An associative array of search results returned from Solr.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   An array of form elements.
 */
function livingstone_browse_catalogue_facet_range_elements($query, array &$form_state) {
  $facet_fields = livingstone_browse_catalogue_facet_range_fields();
  $facet_field = $facet_fields['date'];
  $results = livingstone_browse_catalogue_solr_search_without_facet($facet_field, $form_state);
  list($year, $from, $to) = livingstone_browse_catalogue_facet_range_defaults($form_state);
  $years = livingstone_browse_catalogue_facet_range_options('date', $results);
  $range_years = array_combine(array_keys($years), array_keys($years));
  $from_years = array_filter($range_years, function ($year) use ($to) {
    return $year <= $to || !$to;
  });
  $to_years = array_filter($from_years, function ($year) use ($from) {
    return $year >= $from || !$from;
  });
  if (isset($years[$year])) {
    // Remove facet count on the selected value.
    $years[$year] = $year;
  }
  // Set default based on what's currently selected.
  $default_value = function ($default, $options) {
    return in_array($default, $options) ? preg_replace('/^([1-9]{4}).*/', '\1', $default) : 0;
  };
  $classes = array(
    'img-rounded'
  );
  return array(
    array(
      '#type' => 'select',
      '#default_value' => $year,
      '#options' => array(t('Year')) + $years,
      '#attributes' => array(
        'class' => $classes + array(
          'year',
        ),
      ),
    ),
    array(
      '#type' => 'select',
      '#default_value' => $default_value($from, $from_years),
      '#options' => array(t('From')) + $from_years,
      '#attributes' => array(
        'class' => $classes + array(
          'from',
        ),
      ),
    ),
    array(
      '#type' => 'select',
      '#default_value' => $default_value($to, $to_years),
      '#options' => array(t('To')) + $to_years,
      '#attributes' => array(
        'class' => $classes + array(
          'to',
        ),
      ),
    ),
  );
}

/**
 * Gets the default values for range facet related fields.
 *
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   A list of default values for the fields 'year', 'from', and 'to'.
 */
function livingstone_browse_catalogue_facet_range_defaults(array $form_state) {
  $year = $from = $to = 0;
  $range_fields = livingstone_browse_catalogue_facet_range_fields();
  $date_range_field = $range_fields['date'];
  $value = livingstone_browse_catalogue_get_facet_value($date_range_field);
  $values = isset($form_state['values']) ? $form_state['values'] : array();
  if (isset($values['year']) || isset($values['from']) || isset($values['to'])) {
    $year = $values['year'];
    $from = $values['from'];
    $to = $values['to'];
  }
  else if ($value) {
    $matches = array();
    preg_match_all("/[0-9]{4}|\*/", $value, $matches);
    $num_matches = isset($matches[0]) ? count($matches[0]) : 0;
    if ($num_matches > 0) {
      $date = ($num_matches == 2) ? 'range' : 'year';
      if ($date == 'year') {
        $year = $matches[0][0];
      }
      else {
        $from = $matches[0][0] != '*' ? $matches[0][0] : $from;
        $to = $matches[0][1] != '*' ? $matches[0][1] : $to;
      }
    }
  }
  return array($year, $from, $to);
}

/**
 * Gets the given facet value from the filter query in the URL.
 *
 * @param string $facet_field
 *   The facet field to search the filter query for.
 *
 * @return mixed|null
 *   The value used by the facet in the filter query if one was defined.
 */
function livingstone_browse_catalogue_get_facet_value($facet_field) {
  $filter_queries = isset($_GET['f']) ? $_GET['f'] : array();
  foreach ($filter_queries as $filter_query) {
    list($field, $value) = explode(':', $filter_query);
    if ($field == $facet_field) {
      return $value;
    }
  }
  return NULL;
}

/**
 * Get the default value.
 *
 * @param $element
 * @param array $form_state
 * @param null $default
 * @return mixed|null
 */
function livingstone_browse_catalogue_default_value($element, $default, array $form_state) {
  $values = isset($form_state['values']) ? $form_state['values'] : array();
  if (isset($values[$element])) {
    return $values[$element];
  }
  else if (isset($_GET[$element])) {
    return $_GET[$element];
  }
  return $default;
};

/**
 * Gets the default facet value for the given facet.
 *
 * @param string $facet
 *   The facet to get the default for.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return int|string
 *   The default index for the given facet's options.
 */
function livingstone_browse_catalogue_facet_default($facet, array $form_state) {
  $facet_fields = livingstone_browse_catalogue_facet_fields();
  $facet_field = $facet_fields[$facet];
  if (isset($form_state['values'][$facet])) {
    return $form_state['values'][$facet];
  }
  else if (isset($_GET['f'])) {
    foreach($_GET['f'] as $facet) {
      list($field, $value) = explode(':', $facet);
      if ($field == $facet_field) {
        return trim(stripslashes($value), " \t\n\r\0\x0B\'\"");
      }
    }
  }
  return 0;
}
