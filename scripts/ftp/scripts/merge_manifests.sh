#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME options [directory]

    Program merges the manifests files into a single manifest which can be used
    to generate an import.csv file.

    OPTIONS:
       -h --help                show this help
          --prefix=value        prefix the paths in the merged manifest (defaults to /Livingstone-Directors/0_Core-Data)
       -x --debug               debug

    Examples:
       Run:
       $PROGNAME /path/to/folder
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
      --prefix)         args="${args}-p ";;
      --debug)          args="${args}-x ";;
      # Pass through anything else
      *) [[ "${arg:0:1}" == "-" ]] || delim="\""
         args="${args}${delim}${arg}${delim} ";;
    esac
  done

  # Reset the positional parameters to the short options
  eval set -- $args

  while getopts "hxp:" OPTION
  do
    case $OPTION in
      p)
        readonly PREFIX=${OPTARG}
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

  return 0
}

# Finds all the manifest files.
function find_manifest_files() {
    local directory=${1}
    find ${directory} -type f -name "manifest.csv"
}

# Entry Point.
function main() {
    cmdline ${ARGS}
    local files=$(find_manifest_files "${DIR}")
    local output="${SCRATCH}/manifest.csv"
    local prefix="${PREFIX:-/Livingstone-Directors/0_Core-Data}"
    # Empty the output file to be safe.
    echo -n '' > "${output}"
    for file in ${files}; do
        local folder="${file%%/manifest.csv}";
        local path="${prefix}${folder#${DIR#}}";
        sed -e "s|^\"|\"${path}/|g" "${file}" >> "${output}"
    done
    # Empty the output file to be safe.
    cat "${output}" | sort
}
main
