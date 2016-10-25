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
    return ($pid, $dsid);
}

sub manuscript_page_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".tif", "OBJ",
     ".txt", "TXT",
     ".xmp", "XMP",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}');
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $dsid);
}

sub manuscript_additional_pdf_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".pdf", "OBJ",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}');
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $dsid);
}

sub spectral_manuscript_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
      ".jpg" => "TN",
      ".xml" => ["MODS", "TEI"]
      );
  my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}');
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
  return ($pid, $dsid);
}

sub spectral_manuscript_page_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".gif", "GIF",
     ".tif", "OBJ",
     ".txt", "TXT",
     ".xmp", "XMP",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}');
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
   if ($suffix eq '.gif') {
     if (index($name, "cropped") != -1) {
       $dsid = 'CROPPED_GIF';
     }
     else {
       $dsid = 'GIF';
     }
   }
   else {
     $dsid = $name;
     # Remove prefix.
     $dsid =~ s/liv_[0-9]{6}_[0-9]{4}_//;
     # Remove file suffix if present.
     $dsid =~ s/\..*//;
     # Remove parentheses.
     $dsid =~ s/[()]//g;
     # Transform invalid characters to underscore.
     $dsid =~ s/[^a-zA-Z0-9-_]/_/g;
     # Append type suffix.
     $dsid = $dsid . '_' . $datastreams{$suffix};
     # Upper case the DSID
     $dsid = uc $dsid;
   }
 }
 return ($pid, $dsid);
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
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $dsid);
}

sub no_crop_info {
  my ($name, $path, $suffix) = @_;
  my %datastreams = (
     ".tif", "OBJ",
     ".txt", "TXT",
     ".xmp", "XMP",
 );
 my $pid = get_pid($name, $path, $suffix, 'liv_[0-9]{6}_[0-9]{4}_noCrop');
 if (! exists $datastreams{$suffix} ) {
     return ();
 }
 else {
     $dsid = $datastreams{$suffix}
 }
 return ($pid, $dsid);
}

sub type_info {
  my ($name, $path, $suffix) = @_;
  if (index($path, "spectral") != -1) {
    my %type_extensions = (
        'spectral_manuscript' => [".xml", ".jpg"],
        'spectral_manuscript_page' => [".tif", ".txt", ".xmp", ".gif", ".zip"],
    );
    foreach my $type (sort keys %type_extensions) {
        if (grep { $suffix eq $_ } @{$type_extensions{$type}}) {
          return $type;
        }
    }
  }
  elsif (index($path, "manuscripts") != -1) {
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
    case "spectral_manuscript" { return spectral_manuscript_info($name, $path, $suffix); }
    case "spectral_manuscript_page" { return spectral_manuscript_page_info($name, $path, $suffix); }
    case "illustrative" { return illustrative_info($name, $path, $suffix); }
    case "no_crop" { return no_crop_info($name, $path, $suffix); }
    else { return () }
  }
}

my @header = ('PID', 'DSID', 'MD5', 'FILE');
print join(",", @header),"\n";
my $csv = Text::CSV->new() or die "Cannot use CSV: " . Text::CSV->error_diag();
@rows = ();
while ( my $row = $csv->getline( *STDIN ) ) {
    my ($file, $md5) = $csv->fields();
    my @info = file_info($file);
    if (@info) {
      push @info, $md5, $file;
      push @rows, [@info];
    }
}
$csv->eof or $csv->error_diag();
@ordered_rows = sort { $a->[0] cmp $b->[0] || $a->[1] cmp $b->[1] } @rows;
foreach my $row (@ordered_rows) {
  print join(",", @{$row}),"\n";
}
