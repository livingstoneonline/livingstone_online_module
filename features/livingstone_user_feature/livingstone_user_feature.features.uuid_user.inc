<?php
/**
 * @file
 * livingstone_user_feature.features.uuid_user.inc
 */

/**
 * Implements hook_uuid_features_default_users().
 */
function livingstone_user_feature_uuid_features_default_users() {
  $users = array();

  $users[] = array(
  'name' => 'admin',
  'mail' => 'nigel.g.banks@gmail.com',
  'theme' => '',
  'signature' => '',
  'signature_format' => NULL,
  'created' => 1491933389,
  'status' => 1,
  'timezone' => 'UTC',
  'language' => '',
  'picture' => 0,
  'init' => 'nigel.g.banks@gmail.com',
  'data' => FALSE,
  'uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
  'roles' => array(
    2 => 'authenticated user',
  ),
  'date' => '2017-04-11 17:56:29 +0000',
);
  return $users;
}
