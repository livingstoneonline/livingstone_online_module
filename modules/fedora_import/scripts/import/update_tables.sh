#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

${PROGDIR}/update_local_table.sh &
${PROGDIR}/update_remote_table.sh &
wait
/usr/local/bin/drush -r ${DRUPAL_ROOT} php-eval "variable_set('livingstone_import_table_updated', date('Y-m-d H:i:s'));";
