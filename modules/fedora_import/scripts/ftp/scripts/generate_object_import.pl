use Text::CSV;
use File::Basename;
use Switch;
use Data::Dumper;
use Digest::MD5 qw(md5 md5_hex md5_base64);

# For "Smartmatch is experimental"
no if $] >= 5.017011, warnings => 'experimental::smartmatch';

sub manuscript_info {
 my $content_model = "islandora:manuscriptCModel";
 my $type = "manuscript";
 my $private = '0';
 return ($content_model, $private, $type);
}

sub manuscript_page_info {
 my ($name, $path, $suffix) = @_;
 my $content_model = "islandora:manuscriptPageCModel";
 my $type = "manuscript_page";
 my $private = index($path, "public") == -1 ? '1' : '0';
 return ($content_model, $private, $type);
}

sub manuscript_additional_pdf_info {
 my ($name, $path, $suffix) = @_;
 my $content_model = "islandora:sp_pdf";
 my $type = "manuscript_additional_pdf";
 my $private = index($path, "public") == -1 ? '1' : '0';
 return ($content_model, $private, $type);
}

sub spectral_manuscript_info {
 my $content_model = "livingstone:spectralManuscriptCModel";
 my $type = "spectral_manuscript";
 my $private = '0';
 return ($content_model, $private, $type);
}

sub spectral_manuscript_page_info {
 my ($name, $path, $suffix) = @_;
 my $content_model = "livingstone:spectralManuscriptPageCModel";
 my $type = "spectral_manuscript_page";
 my $private = '0';
 return ($content_model, $private, $type);
}

sub illustrative_info {
 my $content_model = "islandora:sp_large_image_cmodel";
 my $type = "illustrative";
 my $private = '1';
 return ($content_model, $private, $type);
}

sub no_crop_info {
 my $content_model = "islandora:sp_large_image_cmodel";
 my $type = "no_crop";
 my $private = '1';
 return ($content_model, $private, $type);
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
my %objects = ();
my $csv = Text::CSV->new() or die "Cannot use CSV: " . Text::CSV->error_diag();
# Skip the header.
$csv->getline( *STDIN );
while ( my $row = $csv->getline( *STDIN ) ) {
  my ($pid, $dsid, $md5, $file) = $csv->fields();
  $objects{$pid}{'datastreams'}{$dsid} = $md5;
  if (!exists $objects{$pid}{'info'}) {
    $objects{$pid}{'info'} = [file_info($file)];
  }
}
$csv->eof or $csv->error_diag();

my @header = ('PID', 'CONTENT_MODEL', 'PRIVATE', 'TYPE', 'MD5');
print join(",", @header),"\n";
for $pid ( sort keys %objects ) {
  my @row = ($pid);
  my $md5 = '';
  for $dsid ( sort keys %{$objects{$pid}{'datastreams'}} ) {
    $md5 = $md5 . $objects{$pid}{'datastreams'}{$dsid};
  }
  push @row, @{$objects{$pid}{'info'}}, md5_hex($md5);
  print join(",", @row),"\n";
}
