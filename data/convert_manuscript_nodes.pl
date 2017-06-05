#!/usr/bin/perl

use strict;
use warnings;

$^I = '.bak'; # create a backup copy

while (<>) {
    s/'pid' =>/'field_manuscript_pid' =>/g;
    s/'image' =>/'field_manuscript_image' =>/g;
    s/'dates' =>/'field_manuscript_dates' =>/g;
    s/'creators' =>/'field_manuscript_creators' =>/g;
    s/'addressees' =>/'field_manuscript_addressees' =>/g;
    s/'places_created' =>/'field_manuscript_places_created' =>/g;
    s/'extent_pages' =>/'field_manuscript_extent_pages' =>/g;
    s/'extent_size' =>/'field_manuscript_extent_size' =>/g;
    s/'genres' =>/'field_manuscript_genres' =>/g;
    s/'repository_shelfmark' =>/'field_manuscript_shelfmark' =>/g;
    s/'copy_of_item' =>/'field_manuscript_copy_of_item' =>/g;
    s/'other_versions' =>/'field_manuscript_other_versions' =>/g;
    s/'catalogue_number' =>/'field_manuscript_catalogue' =>/g;
    s/'project_id' =>/'field_manuscript_project_id' =>/g;
    s/'tei' =>/'field_manuscript_tei' =>/g;
    s/'date_range_start' =>/'field_manuscript_start_date' =>/g;
    s/'date_range_end' =>/'field_manuscript_end_date' =>/g;
    s/'viewable' =>/'field_manuscript_viewable' =>/g;
    s/'hidden' =>/'field_manuscript_hidden' =>/g;
    s/'downloadable' =>/'field_manuscript_downloadable' =>/g;
    s/'alt_title' =>/'field_manuscript_alt_title' =>/g;
    s/'coordinates' =>/'field_manuscript_coordinates' =>/g;
    print; # print to the modified file
}
