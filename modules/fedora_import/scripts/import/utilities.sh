#!/usr/bin/env bash

readonly DATASTREAMS=(MODS OBJ PDF TEI TN TXT XMP ZIP)
readonly DRUPAL_ROOT=${DRUPAL_ROOT:-$PWD}

function sql_query() {
  local query="${1}"
  /usr/local/bin/drush -r "${DRUPAL_ROOT}" sql-query "${query}"
}

function vget() {
  local variable=${1}
  /usr/local/bin/drush -r "${DRUPAL_ROOT}" vget --format=string --exact "${variable}"
}

# Print error message before exiting.
function eexit() {
  echo "$@"
  exit 1
}

# Down load the given file from the FTP server.
function download_file() {
  local file="${1}"
  local dest="${2}"
  lftp ftp://${HOST} -u ${USER},${PASS} -e "pget -n 2 -c ${file} -o ${dest}; bye"
}

# Each script has it's own SCRATCH directory.
readonly SCRATCH=$(mktemp -d -t tmp.XXXXXXXXXX)
chmod a+rx ${SCRATCH}
function cleanup {
  rm -rf "${SCRATCH}"
}
trap cleanup EXIT