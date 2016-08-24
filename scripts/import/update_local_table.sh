#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

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

  readonly HOST=$(/usr/local/bin/drush -r /var/www/html vget --format=string --exact 'islandora_solr_url')

  return 0
}

# The list of fields to fetch form Solr.
function solr_fl_parameter() {
  # PID, CONTENT_MODEL, PRIVATE, DSID_MD5, ...
  local fl='PID%2CRELS_EXT_hasModel_uri_s%2Chidden_b'
  for datastream in MODS OBJ PDF TEI TN TXT XMP ZIP; do
    fl+="%2Cfedora_datastream_latest_${datastream}_MD5_ms";
  done
  echo ${fl}
}

# Filter only those content model in which we copy from the FTP.
function solr_fq_parameter() {
  echo "RELS_EXT_hasModel_uri_s%3A(*manuscript*%20OR%20*sp_pdf%20OR%20*sp_large_image_cmodel)"
}

# Query solr for all all datastream checksums.
function solr_query() {
  local fl=$(solr_fl_parameter)
  local fq=$(solr_fq_parameter)
  local host="http://livingstoneonline.org"
  local url="${HOST}/collection1/select?q=*%3A*&rows=100000&fq=${fq}&fl=${fl}&wt=csv&indent=true%27"
  local output=${SCRATCH}/solr_results.csv
  curl -L "${url}" -o ${output}
  sed -i -e '1,1s/RELS_EXT_hasModel_uri_s/CONTENT_MODEL/g' ${output}
  sed -i -e '1,1s/hidden_b/PRIVATE/g' ${output}
  sed -i -e '1,1s/fedora_datastream_latest_//g' ${output}
  sed -i -e '1,1s/_MD5_ms/_MD5/g' ${output}
  sed -i -e 's/info:fedora\///g' ${output}
  sed -i -e 's/true/1/g' ${output}
  sed -i -e 's/false/0/g' ${output}
  sed -i -e ':a; s/,,/,\\N,/g; ta' ${output}
  sed -i -e 's/,$/,\\N/g' ${output}
  # Insert 'TYPE' column.
  awk 'BEGIN{FS=OFS=","} {$4="TYPE,"$4""; $0=$0""} 1' ${output} > ${SCRATCH}/solr_results.csv.tmp
  cp ${SCRATCH}/solr_results.csv.tmp ${output}
  cp ${output} /tmp/solr_results.csv
  chmod a+r ${output}
  echo ${output}
}

# Gather information about existing data and insert it into the batch_import.existing table.
function update_local_table() {
  local file=$(solr_query)
  local headers=$(head -n 1 ${file})
  # Empty the table first.
  mysql -e "TRUNCATE TABLE livingstone.livingstone_fedora_local_files;"
  # Import the CSV file.
  mysql --local-infile=1 -e "LOAD DATA INFILE '${file}' INTO TABLE livingstone.livingstone_fedora_local_files FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES (${headers});"
  # In Solr we use hidden_b on manuscripts, to represent if the pages are hidden, but we should never have a policy on
  # islandora:manuscriptCModel.
  mysql livingstone -e "UPDATE livingstone_fedora_local_files SET PRIVATE=false WHERE CONTENT_MODEL = 'islandora:manuscriptCModel';";
  # We don't track type in Solr so we must add it here.
  # islandora:manuscriptCModel.
  mysql livingstone -e "UPDATE livingstone_fedora_local_files SET TYPE='manuscript' WHERE CONTENT_MODEL = 'islandora:manuscriptCModel';";
  mysql livingstone -e "UPDATE livingstone_fedora_local_files SET TYPE='manuscript_page' WHERE CONTENT_MODEL = 'islandora:manuscriptPageCModel';";
  mysql livingstone -e "UPDATE livingstone_fedora_local_files SET TYPE='manuscript_additional_pdf' WHERE CONTENT_MODEL = 'islandora:sp_pdf';";
  mysql livingstone -e "UPDATE livingstone_fedora_local_files SET TYPE='illustrative' WHERE CONTENT_MODEL = 'islandora:sp_large_image_cmodel';";
  mysql livingstone -e "UPDATE livingstone_fedora_local_files SET TYPE='no_crop' WHERE CONTENT_MODEL = 'islandora:sp_large_image_cmodel' AND PID LIKE '%_noCrop';";
}

# Entry Point.
function main() {
  cmdline ${ARGS}
  update_local_table
}
main
