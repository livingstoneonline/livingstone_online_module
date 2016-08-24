<?php

/**
 * @file
 * Utility functions for running batches.
 */

/**
 * Initializes the context data structure for use in the batch operation.
 *
 * @param array $context
 *   The context of this batch operation.
 * @param int $total
 *   The number of times that this batch operation will iterate.
 */
function livingstone_initialize_batch_operation(&$context, $total = 1) {
  if (empty($context['results'])) {
    $results =& $context['results'];
    if (empty($results)) {
      // "files" will be deleted upon failure or success of the batch.
      // "successful" is a count of the number of successful operations.
      // "failed" is a count of the number of failed operations.
      // "messages" array of messages to display on finishing the batch
      // values are used as parameters to t() and drupal_set_message().
      $results = array(
        'files' => array(),
        'messages' => array(),
        'successful' => 0,
        'failed' => 0,
      );
    }
  }
  if (empty($context['sandbox'])) {
    // Local storage for a single operation.
    $context['sandbox']['cache'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['total'] = $total;
  }
}

/**
 * Sets up a batch operation which has clearly defined number of operands.
 *
 * @param $operands
 *   All the items to operate on, if an array each item in the array will be
 *   returned by this function, if an integer it will set the number of
 *   times the operation iterates.
 * @param array $context
 *   The context of this batch operation.
 *
 * @return mixed
 *   The current operand the operation will process which is the item given in
 *   the operands array or if no array given the current progress integer.
 */
function livingstone_start_batch_operation_iteration($operands, &$context) {
  $num_operands = is_array($operands) ? count($operands) : $operands;
  livingstone_initialize_batch_operation($context, $num_operands);
  $operand_index = $context['sandbox']['progress'];
  if (is_array($operands) && $operand_index < $num_operands) {
    $operator = array_slice($operands, $operand_index, 1, TRUE);
    return array(key($operator), reset($operator));
  }
  return $operand_index;
}

/**
 * Ends the batch operation iteration assumes success.
 *
 * @param array $context
 *   The context of this batch operation.
 * @param int $count
 *   The number of iterations completed, typically 1.
 * @param string $message
 *   The message to display to the user when the operation is finished.
 * @param array $params
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed when the batch is finished.
 *
 * @return bool
 *   TRUE if the batch operation is complete, FALSE otherwise.
 */
function livingstone_end_batch_operation_iteration(&$context, $count = 1, $message = "", $params = array()) {
  $context['sandbox']['progress'] += $count;
  if ($context['sandbox']['progress'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['total'];
    return FALSE;
  }
  livingstone_exit_batch_operation($context, TRUE, $message, $params);
  return TRUE;
}

/**
 * Skips the batch operation iteration, assumes failure.
 *
 * @param array $context
 *   The context of this batch operation.
 * @param int $count
 *   The number of iterations completed, typically 1.
 * @param string $message
 *   The message to display to the user when the operation is finished.
 * @param array $params
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed when the batch is finished.
 *
 * @return bool
 *   TRUE if the batch operation is complete, FALSE otherwise.
 */
function livingstone_skip_batch_operation_iteration(&$context, $count = 1, $message = "", $params = array()) {
  $context['sandbox']['progress'] += $count;
  if ($context['sandbox']['progress'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['total'];
    return FALSE;
  }
  livingstone_exit_batch_operation($context, FALSE, $message, $params);
  return TRUE;
}

/**
 * Continue working the current operation, do no increment progress indicator.
 *
 * @param array &$context
 *   The context of this batch operation.
 * @param string $message
 *   The message to display to the user.
 * @param array $params
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed immediately.
 */
function livingstone_continue_batch_operation(array &$context, $message = "", array $params = array()) {
  if (!empty($message)) {
    livingstone_set_progress_message($context, $message, $params);
  }
  livingstone_end_batch_operation_iteration($context, 0);
}

/**
 * Quit the batch operation.
 *
 * @param array &$context
 *   The context of this batch operation.
 * @param bool $success
 *   TRUE if the operation as a whole was successful, FALSE otherwise.
 * @param string $message
 *   The message to display to the user.
 * @param array $params
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed when the batch is finished.
 */
function livingstone_exit_batch_operation(array &$context, $success = FALSE, $message = "", $params = array()) {
  $context['finished'] = 1;
  $success ?
    livingstone_log_batch_operation_success($context) :
    livingstone_log_batch_operation_failed($context);
  if (!empty($message)) {
    livingstone_append_result_message($context, $message, $params);
  }
}

/**
 * Logs that the current batch operation was successful.
 *
 * @param array &$context
 *   The context of this batch operation.
 */
function livingstone_log_batch_operation_success(array &$context) {
  $context['results']['successful'] += 1;
}

/**
 * Logs that the current batch operation failed.
 *
 * @param array &$context
 *   The context of this batch operation.
 */
function livingstone_log_batch_operation_failed(array &$context) {
  $context['results']['failed'] += 1;
}

/**
 * Fetches a reference to the operation cache.
 *
 * To be used for a single operation that iterates multiple times, not to be
 * used to pass info between operations.
 *
 * @param array $context
 *   The batch context.
 */
function &livingstone_batch_operation_cache(array &$context) {
  return $context['sandbox']['cache'];
}

/**
 * Tracks files so they are cleaned up upon exit.
 *
 * @param stdClass $file
 *   The file to track.
 * @param array $context
 *   The context of this batch operation.
 */
function livingstone_batch_track_file(stdClass $file, array &$context) {
  $context['results']['files'][$file->fid] = $file;
}

/**
 * Set the progress message to display to the user.
 *
 * @param array &$context
 *   The context of this batch operation.
 * @param string $message
 *   The message to display to the user.
 * @param array $params
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed immediately.
 */
function livingstone_set_progress_message(array &$context, $message, array $params = array()) {
  $place_holders = array(
    '@progress' => $context['sandbox']['progress'],
    '@total' => $context['sandbox']['total'],
  );
  $params = array_merge($params, $place_holders);
  $context['message'] = format_string($message, $params);
}

/**
 * Appends a message to be displayed when the batch process finishes.
 *
 * @param string $message
 *   The message to display to the user.
 * @param array $params
 *   Values are used as parameters to t() and drupal_set_message() that will be
 *   displayed when the batch is finished.
 * @param array $context
 *   The context of this batch operation.
 */
function livingstone_append_result_message(array &$context, $message, array $params = array()) {
  $context['results']['messages'][] = array($message, $params);
}

/**
 * The batch 'finished' callback.
 *
 * @param bool $success
 *   True if the process finished successfully, FALSE otherwise.
 * @param array $results
 *   An associative array which contains the following:
 *   - files: An array of temporary un-managed files for deletion.
 *   - successful: An array of booleans indicating success or failure for each
 *     operation.
 *   - messages: Any messages / errors / warnings generated by the operations.
 * @param array $operations
 *   The operations that remain unprocessed.
 */
function livingstone_batch_finished($success, $results, $operations) {
  if (!$success) {
    // Generic Error Message.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
  // Delete any lingering files.
  array_walk($results['files'], 'file_delete');
  // Build generic place holders for the message. These keep track of operations
  // which may not be useful to operations that perform multiple actions per
  // operation.
  $place_holders = array(
    '@successful_operations' => $results['successful'],
    '@failed_operations' => $results['failed'],
    '@total_operations' => count($operations),
  );
  // Display all messages/errors/warnings.
  $messages = array_filter($results['messages']);
  foreach ($messages as $message) {
    $vars = isset($message[1]) ? array_merge($message[1], $place_holders) : $place_holders;
    $status = isset($message[2]) ? $message[2] : 'status';
    $message = format_string($message[0], $vars);
    drupal_set_message(check_plain($message), $status);
  }
}
