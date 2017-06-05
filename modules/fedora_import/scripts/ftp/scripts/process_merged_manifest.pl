use Text::CSV;
use File::Basename;
use Switch;
use Data::Dumper;

# For "Smartmatch is experimental"
no if $] >= 5.017011, warnings => 'experimental::smartmatch';

sub get_pid {
  my ($name, $path, $suffix, $match) = @_;
  my $re = qr/($match)/;
  my ($pid) = $name =~ $re;
  if (!$pid) {
     die "Could not determine the identifier of $path$name$suffix\n"
  }
  $pid =~ s/liv_/liv:/;
  return $pid;
}

sub manuscript_info {
    my ($name, $path, $suffix) = @_;
    my %datastreams = (
        ".zip" => "ZIP",
        ".jpg" => "TN",
        ".xml" => ["MODS", "TEI"]
        );
    my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}');
    my $content_model = "islandora:manuscriptCModel";
    my $type = "manuscript";
    my $private = '0';
    my $dsid;
    if (! exists $datastreams{$suffix} ) {
        return ();
    }
    else {
        # Check the name for DSID reference.
        if(ref($datastreams{$suffix}) eq 'ARRAY') {
            my @matches = grep { index($name, $_) != -1; } @{$datastreams{$suffix}};
            if (!scalar @matches) {
                die "Could not determine the datastream identifier of $path$name$suffix\n"
            }
            $dsid = $matches[0]
        }
        else {
            $dsid = $datastreams{$suffix};
        }
    }
    return ($pid, $content_model, $type, $private, $dsid);
}

sub manuscript_page_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".tif", "OBJ",
     ".txt", "TXT",
     ".xmp", "XMP",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}');
 my $content_model = "islandora:manuscriptPageCModel";
 my $type = "manuscript_page";
 my $private = index($path, "public") == -1 ? '1' : '0';
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $content_model, $type, $private, $dsid);
}

sub manuscript_additional_pdf_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".pdf", "OBJ",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}');
 my $content_model = "islandora:sp_pdf";
 my $type = "manuscript_additional_pdf";
 my $private = index($path, "public") == -1 ? '1' : '0';
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $content_model, $type, $private, $dsid);
}

sub illustrative_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".tif", "OBJ",
     ".txt", "TXT",
     ".xmp", "XMP",
     ".xml", "MODS",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}');
 my $content_model = "islandora:sp_large_image_cmodel";
 my $type = "illustrative";
 my $private = 1;
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $content_model, $type, $private, $dsid);
}

sub no_crop_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".tif", "OBJ",
     ".txt", "TXT",
     ".xmp", "XMP",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}_noCrop');
 my $content_model = "islandora:sp_large_image_cmodel";
 my $type = "no_crop";
 my $private = 1;
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $content_model, $type, $private, $dsid);
}

sub type_info {
  my ($name, $path, $suffix) = @_;
  if (index($path, "manuscripts") != -1) {
    my %type_extensions = (
        'manuscript' => [".xml", ".zip", ".jpg"],
        'manuscript_page' => [".tif", ".txt", ".xmp"],
        'manuscript_additional_pdf' => [".pdf"],
    );
    foreach my $type (sort keys %type_extensions) {
        if (grep { $suffix eq $_ } @{$type_extensions{$type}}) {
          return $type;
        }
    }
  }
  elsif (index($path, "illustrative") != -1) {
    return "illustrative";
  }
  elsif(index($path, "no_crop") != -1) {
    return "no_crop";
  }
}

sub file_info {
  my ($filename) = @_;
  my ($name, $path, $suffix) = fileparse($filename, qr/\.[^.]*/);
  my $type = type_info($name, $path, $suffix);
  switch ($type) {
    case "manuscript" { return manuscript_info($name, $path, $suffix); }
    case "manuscript_page" { return manuscript_page_info($name, $path, $suffix); }
    case "manuscript_additional_pdf" { return manuscript_additional_pdf_info($name, $path, $suffix); }
    case "illustrative" { return illustrative_info($name, $path, $suffix); }
    case "no_crop" { return no_crop_info($name, $path, $suffix); }
    else { return () }
  }
}
# Build the datastream table first.
# Build the
my @header = ('PID', 'CONTENT_MODEL', 'TYPE', 'PRIVATE', 'DSID', 'FILE', 'MD5');
my $csv = Text::CSV->new() or die "Cannot use CSV: " . Text::CSV->error_diag();
while ( my $row = $csv->getline( *STDIN ) ) {
    my ($file, $md5) = $csv->fields();
    # If false to output it to the file thingy.
    my @info = file_info($file);
    if (@info) {
      push @info, $file, $md5;
      foreach (@teams) {
        print "$_\n";
      }
      print join(",", map {qq("$_")} @info),"\n";
    }
}
$csv->eof or $csv->error_diag();
