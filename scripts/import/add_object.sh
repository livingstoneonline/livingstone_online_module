#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME options pid

    Attempts to add the given object to Fedora from the FTP server.

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

  if [[ -n "$1" ]]; then
    readonly PID="$1"
  else
    eexit "PID argument missing."
  fi

  return 0
}

function download_files() {
    local pid="${1}"
    local private="${2}"
    local type="${3}"
    local path="${4}"
    local dest="${SCRATCH}/${pid}"
    mkdir -p "${dest}"
    case ${type} in
      "illustrative")
        add_illustrative "${pid}" "${path}"
        ;;
      "no_crop")
        add_no_crop "${pid}" "${path}"
        ;;
      "manifest")

        ;;
      "manuscript_page")
        add_manifest_page "${pid}" "${path}" "${private}"
        ;;
      "manuscript_additional_pdf")

        ;;
      *)
        eexit "Unknown manifest file type."
        ;;
    esac
}

function main() {
  cmdline ${ARGS}
  mysql livingstone -e "SELECT * FROM livingstone_fedora_remote_files as r WHERE PID NOT IN (SELECT DISTINCT PID from livingstone_fedora_local_files) AND r.PID = '${PID}';"

}