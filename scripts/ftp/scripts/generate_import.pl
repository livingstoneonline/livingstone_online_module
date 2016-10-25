use Text::CSV;
use File::Basename;
use Switch;
use Data::Dumper;

my @input_header = ('PID', 'CONTENT_MODEL', 'TYPE', 'PRIVATE', 'DSID', 'FILE', 'MD5');
my @output_header = ('PID', 'CONTENT_MODEL', 'TYPE', 'PRIVATE', 'MODS_MD5', 'MODS_FILE', 'OBJ_MD5', 'OBJ_FILE', 'PDF_MD5', 'PDF_FILE', 'TEI_MD5', 'TEI_FILE', 'TN_MD5', 'TN_FILE', 'TXT_MD5', 'TXT_FILE', 'XMP_MD5', 'XMP_FILE', 'ZIP_MD5', 'ZIP_FILE');

my %rows = ();
my $csv = Text::CSV->new() or die "Cannot use CSV: " . Text::CSV->error_diag();
$csv->column_names(@input_header);
while ( my $hr = $csv->getline_hr( *STDIN ) ) {
    my $PID = $hr->{PID};
    my $DSID = $hr->{DSID};
    if ( ! exists $rows{$PID} ) {
        $rows{$PID} = {
            'PID' => $hr->{PID},
            'CONTENT_MODEL' => $hr->{CONTENT_MODEL},
            'TYPE' => $hr->{TYPE},
            'PRIVATE' => $hr->{PRIVATE},
        };
    }
    $rows{$PID}{$DSID."_MD5"} = $hr->{MD5};
    $rows{$PID}{$DSID."_FILE"} = $hr->{FILE};
}
$csv->eof or $csv->error_diag();
print join(",", @output_header),"\n";
foreach my $PID (sort keys %rows) {
  my @out = ();
  for my $column (@output_header) {
    if (! exists $rows{$PID}{$column} ) {
      push @out, 'NULL';
    }
    else {
      push @out, $rows{$PID}{$column};
    }
  }
  print join(",", @out),"\n";
}
