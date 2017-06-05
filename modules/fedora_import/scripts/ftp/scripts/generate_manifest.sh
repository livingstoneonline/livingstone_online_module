#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME options [directory]

    Program generates a manifest for the given directory. Overwriting the
    existing manifest if present.

    If the directory is not given it's assumed to be the directory in which
    the program was called from.

    The recursive option will generate the manifest for all child directories
    in the given directory.

    By default this will only regenerate existing manifest.csv files if they are not
    the newest file in the respective directory, unless --force is specified.

    OPTIONS:
       -h --help                show this help
       -r --recursive           recursively generate manifests
       -f --force               regenerate all manifest.csv files even if they are up-to-date.
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
      --force)          args="${args}-f ";;
      --recursive)      args="${args}-r ";;
      --debug)          args="${args}-x ";;
      # Pass through anything else
      *) [[ "${arg:0:1}" == "-" ]] || delim="\""
         args="${args}${delim}${arg}${delim} ";;
    esac
  done

  # Reset the positional parameters to the short options
  eval set -- $args

  while getopts "hrxf" OPTION
  do
    case $OPTION in
      x)
        readonly DEBUG='-x'
        set -x
        ;;
      f)
        readonly FORCE=1
        ;;
      r)
        readonly RECURSE=1
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

function checksum() {
    if hash md5sum 2>/dev/null; then
        echo md5sum
    else
        echo "md5 -q"
    fi
}

function directory_files() {
    local directory="${1}"
    find "${directory}" -maxdepth 1 -type f -name "liv_*" ! \( -name "*.csv" -o -name "*~" \) | sort
}

function directories() {
    local directory="${1}"
    find "${directory}" -type d | sort
}

function generate_manifest() {
    local directory=$1; shift
    local files=$@;
    local checksum=$(checksum)
    local newest=$(ls -t ${directory} | head -1)
    if [ -z "$files" -o "$files" == " " ]; then
        echo "No files found in ${directory}." 1>&2
        return
    fi
    if [ -z "${FORCE}" -a ${newest} == "manifest.csv" ]; then
        echo "${directory}/manifest.csv exists and is the newest file in the directory." 1>&2
        return
    fi
    echo "Generating ${directory}/manifest.csv."
    echo -n '' > ${directory}/manifest.csv
    if hash parallel 2>/dev/null; then
        # Limits to argument length to parallel
        # cause us to use a scratch file.
        echo "${files}" > ${SCRATCH}/input.txt
        parallel 'echo \"{/}\",\"`'"${checksum}"' {} | cut -d" " -f1`\" >> '"${directory}"'/manifest.csv' :::: ${SCRATCH}/input.txt 2> /dev/null
    else
        for file in ${files[@]}; do
            local filename=$(basename ${file})
            local md5=$(${checksum} ${file} | cut -d' ' -f1)
            echo "\"${filename}\",\"${md5}\"" >> ${directory}/manifest.csv
        done
    fi
}

# Entry Point.
function main() {
    local files;
    local directories;
    cmdline ${ARGS}
    if [ -z "${RECURSE}" ]; then
        files=$(directory_files "${DIR}")
        generate_manifest "${DIR}" "${files[@]}"
    else
        directories=$(directories "${DIR}")
        for directory in ${directories}; do
            files=$(directory_files "${directory}")
            generate_manifest "${directory}" "${files[@]}"
        done
    fi
}
main
