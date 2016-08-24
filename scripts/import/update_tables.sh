#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

${PROGDIR}/update_remote_table.sh &
${PROGDIR}/update_local_table.sh &
/usr/local/bin/drush -r /var/www/html php-eval "variable_set('livingstone_import_table_updated', date('Y-m-d H:i:s'));";
