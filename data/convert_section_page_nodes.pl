#!/usr/bin/perl

use strict;
use warnings;

$^I = '.bak'; # create a backup copy

while (<>) {
    s/field_section_page_sections/field_section/g;
    s/body/field_section_body/g;
    s/field_section_page_tag_line/field_section_overview/g;
    s/field_section_page_main_image/field_section_image/g;
    s/field_carousel_image/field_section_carousel_image/g;
    s/field_section_page_image/field_section_grid_image/g;
    s/field_section_page_byline/field_section_byline/g;
    s/field_section_page_date/field_section_date/g;
    s/field_subtitle/field_section_subtitle/g;
    s/field_level_2_teaser/field_section_teaser/g;
    s/field_pre_title/field_section_pre_title/g;
    s/field_outbound_link/field_section_outbound_link/g;
    s/field_open_new_tab/field_section_open_in_new_tab/g;
    s/field_transcriptions/field_section_page_transcription/g;
    # Fix file urls and referential links to other section pages.
    print;# print to the modified file
}
