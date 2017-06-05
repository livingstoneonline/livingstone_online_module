#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME [options] [remote directory] [local directory]

    Program mirrors the given remote directory to the given local directory.

    OPTIONS:
       -h --help                show this help
       -x --debug               debug

    Examples:
       Run:
       $PROGNAME /path/to/folder/on/ftp /path/to/local/folder
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
      --user)          args="${args}-u ";;
      --password)      args="${args}-p ";;
      --debug)          args="${args}-x ";;
      # Pass through anything else
      *) [[ "${arg:0:1}" == "-" ]] || delim="\""
         args="${args}${delim}${arg}${delim} ";;
    esac
  done

  # Reset the positional parameters to the short options
  eval set -- $args

  while getopts "hupx" OPTION
  do
    case $OPTION in
      x)
        readonly DEBUG='-x'
        set -x
        ;;
      u)
        readonly USER=${OPTARG}
        ;;
      p)
        readonly PASSWORD=${OPTARG}
        ;;
      h)
        usage
        exit 0
        ;;
    esac
  done

  # Remote directory.
  shift $((OPTIND-1))
  readonly REMOTE="${1}"

  if [[ -z "${2}" ]]; then
    readonly LOCAL=$(pwd)
  elif [[ ! -d "${2}" ]]; then
    eexit "The local directory provided could not be found or is not a directory."
  else
    readonly LOCAL="${2}"
  fi
  return 0
}

function download() {
  local user=${1}
  local password=${2}
  local remote_directory=${3}
  local local_directory=${4%/}${remote_directory}
  mkdir -p ${local_directory}
  lftp -e "mirror ${remote_directory} ${local_directory}" -u ${user},${password} -p 21 agnes.unl.edu
}

function main() {
  cmdline ${ARGS}
  download ${USER} ${PASSWORD} ${REMOTE} ${LOCAL}
}
main