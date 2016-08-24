#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME options [directory]

    Program generates the import.csv used by sync process to determine what content needs to be updated from the FTP.

    This program has no mandatory fields, and is meant to be run from the /Livingstone-Directors/0_Core-Data location in
    a local copy of the FTP data.

    OPTIONS:
       -h --help                show this help
       -f --force               regenerate all manifest.csv files even if they are up-to-date.
       -x --debug               debug
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
      --force)          args="${args}-f ";;
      --debug)          args="${args}-x ";;
      # Pass through anything else
      *) [[ "${arg:0:1}" == "-" ]] || delim="\""
         args="${args}${delim}${arg}${delim} ";;
    esac
  done

  # Reset the positional parameters to the short options
  eval set -- $args

  while getopts "hfx" OPTION
  do
    case $OPTION in
      f)
        readonly FORCE='-f'
        ;;
      x)
        readonly DEBUG='-x'
        set -x
        ;;
      h)
        usage
        exit 0
        ;;
    esac
  done
  shift $((OPTIND-1))

  if [[ -z "$1" ]]; then
    readonly DIR=$(pwd)
  elif [[ ! -d "$1" ]]; then
    eexit "The directory provide could not be found or is not a directory."
  else
    readonly DIR="$1"
  fi
}

function main() {
    cmdline ${ARGS}
    local EXEC_DIR="${DIR}"
    echo "Generating manifest file(s) ..."
    ${PROGDIR}/generate_manifest.sh -r ${FORCE} ${EXEC_DIR} 2>/dev/null | sed 's/^/    /'
    echo "Merging manifest files ..."
    # We must delete the old merged manifest file before merging existing.
    ${PROGDIR}/merge_manifests.sh ${EXEC_DIR} > "${EXEC_DIR}/merged_manifest.csv"
    echo "Processing merged manifest file ..."
    perl -I ${PROGDIR}/perl5/lib/perl5 ${PROGDIR}/process_merged_manifest.pl < ${EXEC_DIR}/merged_manifest.csv > ${EXEC_DIR}/processed_merged_manifest.csv
    echo "Generating import.csv file ..."
    perl -I ${PROGDIR}/perl5/lib/perl5 ${PROGDIR}/generate_import.pl < ${EXEC_DIR}/processed_merged_manifest.csv > ${EXEC_DIR}/import.csv
}
main
