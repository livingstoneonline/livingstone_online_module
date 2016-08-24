#!/usr/bin/env bash

readonly DATASTREAMS=(MODS OBJ PDF TEI TN TXT XMP ZIP)

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