#!/usr/bin/env bash

readonly PROGNAME=$(basename $0)
readonly PROGDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly ARGS="$@"

source ${PROGDIR}/utilities.sh

function main() {
    local ftp_server=$(vget 'livingstone_ftp_server')
    local ftp_user=$(vget 'livingstone_ftp_user')
    local ftp_password=$(vget 'livingstone_ftp_password')
    local solr_host=$(vget 'islandora_solr_url')
    local solr_query="http://${solr_host}/select?q=RELS_EXT_hasModel_uri_s%3A%22info%3Afedora%2Fislandora%3AmanuscriptCModel%22%2C%0ARELS_EXT_hasModel_uri_s%3A%22info%3Afedora%2Fislandora%3AmanuscriptPageCModel%22%2C%0ARELS_EXT_hasModel_uri_s%3A%22info%3Afedora%2Fislandora%3Asp_large_image_cmodel%22%0ARELS_EXT_hasModel_uri_s%3A%22info%3Afedora%2Fislandora%3Asp_pdf%22%2C%0ARELS_EXT_hasModel_uri_s%3A%22info%3Afedora%2Flivingstone%3AspectralManuscriptCModel%22%2C%0ARELS_EXT_hasModel_uri_s%3A%22info%3Afedora%2Flivingstone%3AspectralManuscriptPageCModel%22&sort=PID+asc&rows=100000&fl=PID%2CRELS_EXT_hasModel_uri_s%2Cchecksum_s%2Chidden_b%2Cfedora_datastream_latest_*_MD5_ms&wt=xml&indent=true"

    # Generate SQL file.
    generate-import-state-sql \
        --ftp-dest /var/lib/mysql-files \
        --ftp-server "${ftp_server}" \
        --ftp-port 21 \
        --ftp-user "${ftp_user}" \
        --ftp-password "${ftp_password}" \
        --ftp-skip false \
        --ftp-src "/Livingstone-Directors/0_Core-Data" \
        --solr "${solr_query}" \
        --sql /var/lib/mysql-files/import-state.sql

    # Import State via SQL file.
    `/usr/local/bin/drush -r ${DRUPAL_ROOT} sql-connect` < /var/lib/mysql-files/import-state.sql

    # Update last import date.
    /usr/local/bin/drush -r ${DRUPAL_ROOT} php-eval "variable_set('livingstone_import_table_updated', date('Y-m-d H:i:s'));"
}
main
