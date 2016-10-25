#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

readonly INFILE_DIR=/var/lib/mysql-files

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
function download_import_objects_csv() {
  local output="${INFILE_DIR}/import.objects.csv"
  rm ${output}
  lftp ftp://${HOST} -u ${USER},${PASS} -e "pget -n 2 /Livingstone-Directors/0_Core-Data/import.objects.csv -o ${output}; bye" 1>&2
  sed -i -e ':a; s/NULL/\\N/g; ta' ${output}
  echo ${output}
}

# Down load the given file from the FTP server.
function download_import_datastreams_csv() {
  local output="${INFILE_DIR}/import.datastreams.csv"
  rm ${output}
  lftp ftp://${HOST} -u ${USER},${PASS} -e "pget -n 2 /Livingstone-Directors/0_Core-Data/import.datastreams.csv -o ${output}; bye" 1>&2
  sed -i -e ':a; s/NULL/\\N/g; ta' ${output}
  echo ${output}
}

# Updates the remote table.
function update_remote_tables() {
  local objects_file=$(download_import_objects_csv)
  local objects_headers=$(head -n 1 ${objects_file})
  local datastreams_file=$(download_import_datastreams_csv)
  local datastreams_headers=$(head -n 1 ${datastreams_file})
  # Empty the table first.
  mysql -e "TRUNCATE TABLE livingstone.livingstone_fedora_remote_objects;"
  mysql -e "TRUNCATE TABLE livingstone.livingstone_fedora_remote_datastreams;"
  # Import the objects CSV file.
  mysql --local-infile=1 -e "LOAD DATA INFILE '${objects_file}' INTO TABLE livingstone.livingstone_fedora_remote_objects FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES (${objects_headers});"
  # Import the datastreams CSV file.
  mysql --local-infile=1 -e "LOAD DATA INFILE '${datastreams_file}' INTO TABLE livingstone.livingstone_fedora_remote_datastreams FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES (${datastreams_headers});"
  # Update the checksums in the table.
  mysql livingstone  -e "UPDATE livingstone_fedora_remote_objects o SET MD5 = (SELECT MD5(GROUP_CONCAT(MD5 SEPARATOR '')) FROM livingstone_fedora_remote_datastreams d WHERE d.PID = o.PID ORDER BY DSID)";
}

# Entry Point.
function main() {
  cmdline ${ARGS}
  mkdir -p ${INFILE_DIR}
  update_remote_tables
}
main
