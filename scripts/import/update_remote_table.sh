#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME options server user password

    Updates the import database manifest table with data from manifest.csv
    files contained in the given directory.

    OPTIONS:
       -x --debug               debug
       -h --help                show this help

    Examples:
       Run:
       $PROGNAME
EOF
}

# Validate arguments and set global variables.
function cmdline() {
  local arg=
  for arg
  do
    local delim=""
    case "$arg" in
      # Translate --gnu-long-options to -g (short options)
      --help)           args="${args}-h ";;
      --debug)          args="${args}-x ";;
      # Pass through anything else
      *) [[ "${arg:0:1}" == "-" ]] || delim="\""
         args="${args}${delim}${arg}${delim} ";;
    esac
  done

  # Reset the positional parameters to the short options
  eval set -- $args

  while getopts "hx" OPTION
  do
    case $OPTION in
      h)
        usage
        exit 0
        ;;
      x)
        readonly DEBUG='-x'
        set -x
        ;;
    esac
  done
  shift $((OPTIND-1))

  readonly HOST=$(/usr/local/bin/drush -r /var/www/html vget --format=string --exact 'livingstone_ftp_server')
  readonly USER=$(/usr/local/bin/drush -r /var/www/html vget --format=string --exact 'livingstone_ftp_user')
  readonly PASS=$(/usr/local/bin/drush -r /var/www/html vget --format=string --exact 'livingstone_ftp_password')
  return 0
}

# Down load the given file from the FTP server.
function download_import_csv() {
  local output="${SCRATCH}/import.csv"
  lftp ftp://${HOST} -u ${USER},${PASS} -e "pget -n 2 /Livingstone-Directors/0_Core-Data/import.csv -o ${output}; bye" 1>&2
  sed -i -e ':a; s/NULL/\\N/g; ta' ${output}
  echo ${output}
}

# Updates the remote table.
function update_remote_table() {
  local file=$(download_import_csv)
  local headers=$(head -n 1 ${file})
  # Empty the table first.
  mysql -e "TRUNCATE TABLE livingstone.livingstone_fedora_remote_files;"
  # Import the CSV file.
  mysql --local-infile=1 -e "LOAD DATA INFILE '${file}' INTO TABLE livingstone.livingstone_fedora_remote_files FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES (${headers});"
}

# Entry Point.
function main() {
  cmdline ${ARGS}
  update_remote_table
}
main
