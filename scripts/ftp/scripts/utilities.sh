#!/usr/bin/env bash

# Print error message before exiting.
function eexit() {
  echo "$@" 1>&2
  exit 1
}

# Each script has it's own SCRATCH directory.
readonly SCRATCH=$(mktemp -d -t tmp.XXXXXXXXXX)
chmod a+rx ${SCRATCH}
function cleanup {
  rm -rf "${SCRATCH}"
}
trap cleanup EXIT