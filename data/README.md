This includes two scripts for exporting / importing data from the current production site, altering it's fields to work with the new theme.


Exporting the content:
```bash
drush node-export-export --type=section_page --file=/tmp/section_page_nodes.php
drush node-export-export --type=manuscript --file=/tmp/manuscript_nodes.php
```

Cleaning the content:
```bash
./convert_section_page_nodes.pl section_page_nodes.php
./convert_manuscript_nodes.pl manuscript_nodes.php
```

Importing the content into the new site:
```bash
drush node-export-import --uid=1 --file=sites/all/modules/custom/livingstone_online_module/data/section_page_nodes.php
drush node-export-import --uid=1 --file=sites/all/modules/custom/livingstone_online_module/data/manuscript_nodes.php
```
