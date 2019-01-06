#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

readonly INFILE_DIR=/var/lib/mysql-files

# Print command usage.
function usage() {
  cat <<- EOF
    usage: $PROGNAME options

    Updates the import database local files table with data from Solr.

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
  readonly HOST=$(vget 'islandora_solr_url')

  return 0
}

# The list of fields to fetch form Solr.
function solr_fl_parameter() {
  # PID, CONTENT_MODEL, PRIVATE, DSID_MD5, ...
  echo 'PID%2CRELS_EXT_hasModel_uri_s%2Chidden_b%2Cfedora_datastream_latest_*_MD5_ms'
}

# Filter only those content model in which we copy from the FTP.
function solr_fq_parameter() {
  echo "RELS_EXT_hasModel_uri_s%3A(*manuscript*%20OR%20*spectral*%20OR%20*sp_pdf%20OR%20*sp_large_image_cmodel)"
}

function objects_file() {
  local fq=$(solr_fq_parameter)
  local fl='PID%2CRELS_EXT_hasModel_uri_s%2Chidden_b%2Cchecksum_s%2CTYPE'
  local url="${HOST}/collection1/select?q=*%3A*&rows=100000&fq=${fq}&fl=${fl}&wt=csv&indent=true%27&sort=PID%20asc"
  local output=${INFILE_DIR}/local_object_table.csv
  curl -sL "${url}" -o ${output}
  sed -i -e 's/info:fedora\///g' ${output}
  sed -i -e 's/true/1/g' ${output}
  sed -i -e 's/false/0/g' ${output}
  sed -i -e 's/,$/,\\N/g' ${output}
  sed -i -e '1,1s/RELS_EXT_hasModel_uri_s/CONTENT_MODEL/g' ${output}
  sed -i -e '1,1s/hidden_b/PRIVATE/g' ${output}
  sed -i -e '1,1s/checksum_s/MD5/g' ${output}
  [ -s ${output} ] || echo 'PID,CONTENT_MODEL,PRIVATE,MD5,TYPE' > ${output}
  chmod a+r ${output}
  echo ${output}
}

# Can't use environment variables or other functions here as parallel does not know about them.
function get_datastream_checksums() {
  local host=${1}
  local pid=${2}
  local fq="RELS_EXT_hasModel_uri_s%3A(*manuscript*%20OR%20*spectral*%20OR%20*sp_pdf%20OR%20*sp_large_image_cmodel)"
  local fl='fedora_datastream_latest_*_MD5_ms'
  local url="${host}/collection1/select?q=PID:\"${pid}\"&rows=100000&fq=${fq}&fl=${fl}&wt=json&indent=true%27&sort=PID%20asc"
  curl -sL "${url}" | grep 'MD5_ms\":' | sed "s/.*latest_\(.*\)_MD5_ms\":\[\"\([^\"]*\).*/${pid},\1,\2/g"
}
# Make the function available to GNU parallel.
export -f get_datastream_checksums 

function datastreams_file() {
  local input=${1}
  local output=${INFILE_DIR}/local_datastream_table.csv
  local fq=$(solr_fq_parameter)
  local fl='fedora_datastream_latest_*_MD5_ms'
  local pids=($(csvcut ${input} -c PID | tail +2))
  echo 'PID,DSID,MD5' > ${output}
  SHELL=$(type -p bash) parallel get_datastream_checksums ${HOST} {} ::: ${pids[@]} >> ${output}
  [ -s ${output} ] || echo 'PID,DSID,MD5' > ${output}
  chmod a+r ${output}
  echo ${output}
}

# Gather information about existing data and insert it into the batch_import.existing table.
function update_local_tables() {
  local objects_file=$(objects_file)
  local objects_headers=$(head -n 1 ${objects_file})
  local datastreams_file=$(datastreams_file ${objects_file})
  local datastreams_headers=$(head -n 1 ${datastreams_file})
  # Empty the table first.
  sql_query "TRUNCATE TABLE livingstone_fedora_local_objects;"
  # Import the CSV file.
  sql_query "LOAD DATA LOCAL INFILE '${objects_file}' INTO TABLE livingstone_fedora_local_objects FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES (${objects_headers});"
  # In Solr we use hidden_b on manuscripts, to represent if the pages are hidden, but we should never have a policy on
  # islandora:manuscriptCModel.
  sql_query "UPDATE livingstone_fedora_local_objects SET PRIVATE=false WHERE CONTENT_MODEL = 'islandora:manuscriptCModel';";
  # We don't track type in Solr so we must add it here.
  # islandora:manuscriptCModel.
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='manuscript' WHERE CONTENT_MODEL = 'islandora:manuscriptCModel';";
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='manuscript_page' WHERE CONTENT_MODEL = 'islandora:manuscriptPageCModel';";
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='manuscript_additional_pdf' WHERE CONTENT_MODEL = 'islandora:sp_pdf';";
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='spectral_manuscript' WHERE CONTENT_MODEL = 'livingstone:spectralManuscriptCModel';";
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='spectral_manuscript_page' WHERE CONTENT_MODEL = 'livingstone:spectralManuscriptPageCModel';";
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='illustrative' WHERE CONTENT_MODEL = 'islandora:sp_large_image_cmodel' AND PID NOT LIKE '%_noCrop';";
  sql_query "UPDATE livingstone_fedora_local_objects SET TYPE='no_crop' WHERE CONTENT_MODEL = 'islandora:sp_large_image_cmodel' AND PID LIKE '%_noCrop';";
  # Empty the table first.
  sql_query "TRUNCATE TABLE livingstone_fedora_local_datastreams;"
  # Import the CSV file.
  sql_query "LOAD DATA LOCAL INFILE '${datastreams_file}' INTO TABLE livingstone_fedora_local_datastreams FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES (${datastreams_headers});"
  sql_query "DELETE FROM livingstone_fedora_local_datastreams WHERE DSID='DC' OR DSID='RELS-EXT' OR DSID='RELS-INT' OR DSID='POLICY' OR DSID LIKE '%JP2';";
  # Update the checksums in the table.
  sql_query "set group_concat_max_len = 4096; UPDATE livingstone_fedora_local_objects o SET MD5 = (SELECT MD5(GROUP_CONCAT(MD5 SEPARATOR '')) FROM livingstone_fedora_local_datastreams d WHERE d.PID = o.PID ORDER BY DSID)";
}

# Entry Point.
function main() {
  cmdline ${ARGS}
  mkdir -p ${INFILE_DIR}
  update_local_tables
}
main
