<?php
/**
 * @file
 * livingstone_backup_feature.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function livingstone_backup_feature_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'agnes';
  $item->name = 'Agnes';
  $item->subtype = 'ftp';
  $item->location = 'ftp://Production-Backup:marymo%24%24%40t62@agnes.unl.edu:21/Production-Site-Backup/database';
  $item->settings = array(
    'pasv' => TRUE,
  );
  $export['agnes'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function livingstone_backup_feature_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'agnes';
  $item->name = 'Agnes';
  $item->source_id = 'db';
  $item->destination_id = 'agnes';
  $item->copy_destination_id = '';
  $item->profile_id = 'default';
  $item->keep = 90;
  $item->period = 86400;
  $item->enabled = TRUE;
  $item->cron = 'builtin';
  $item->cron_schedule = '0 4 * * *';
  $export['agnes'] = $item;

  return $export;
}
