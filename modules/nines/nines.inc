<?php

/**
 * @file
 * Defines the batch definition and operations for generating the RDF for NINES.
 *
 * @see http://wiki.collex.org/index.php/Submitting_RDF
 */

namespace NINES {

  use stdClass;
  use DOMDocument;
  use DOMElement;
  use DOMNode;
  use DateTime;
  use InvalidArgumentException;

  /**
   * Given a section page node, it generates a RDF file.
   *
   * @param stdClass $node
   *   A Drupal section_page node.
   *
   * @return stdClass
   *   A Drupal file object containing the exported RDF.
   */
  function export_section_page($node) {
    $alias = drupal_get_path_alias("node/$node->nid");
    $object = new Object($node->uuid);
    // Title.
    $object->title = $node->title;
    $object->alternatives[] = $node->field_section_subtitle['und'][0]['value'];
    // Date.
    $object->date = new Date(date_create("@{$node->created}"));
    // Text.
    $object->text = strip_tags($node->field_section_body['und'][0]['value']);
    $object->text = preg_replace('/Top ⤴/', '', $object->text);
    $object->text = preg_replace('/Return to top ⤴/', '', $object->text);
    $object->text = preg_replace("/([\r\n]{6,}|[\n]{3,}|[\r]{3,})/", "\n", $object->text);
    // Types.
    $object->setTypes(array(
      'Codex',
      'Collection',
      'Dataset',
      'Illustration',
      'Interactive Resource',
      'Manuscript',
      'Physical Object',
      'Sheet',
      'Still Image',
    ));
    // Disciplines.
    $object->setDisciplines(array(
      'Anthropology',
      'Book History',
      'Ethnic Studies',
      'Geography',
      'History',
      'Literature',
      'Manuscript Studies',
      'Political Science',
      'Religious Studies',
      'Science',
    ));
    // Genres.
    $object->setGenres(array(
      'Bibliography',
      'Catalog',
      'Collection',
      'Correspondence',
      'Criticism',
      'Ephemera',
      'Essay',
      'Historiography',
      'Life Writing',
      'Nonfiction',
      'Paratext',
      'Photograph',
      'Political Statement',
      'Reference Works',
      'Religion',
      'Travel Writing',
      'Visual Art',
    ));
    // Authors.
    $object->roles['AUT'] = 'Wisnicki, Adrian S.';
    // Publisher.
    $object->roles['PBL'] = 'Livingstone Online (livignstoneonline.org)';
    // Full text.
    $object->full_text = TRUE;
    // See Also.
    $object->seeAlso = url($alias, array('absolute' => TRUE));
    $contents = convert_to_rdf($object);
    return write_rdf_to_file(normalize_filename($node->uuid), $contents);
  }

  /**
   * Writes the given RDF to file, and creates a temporary Drupal file object.
   *
   * @param string $filename
   *   The filename to write the contents to.
   * @param $content
   *   The RDF to populate the file with.
   *
   * @return stdClass
   *   Drupal file object.
   */
  function write_rdf_to_file($filename, $content) {
    $file = new stdClass();
    $file->uid = 1;
    $file->filename = $filename;
    $file->uri = drupal_tempnam('temporary://', $filename);
    $file->filemime = 'application/rdf+xml';
    // Temporary file will be cleaned up by cron.
    $file->status = 0;
    // Write contents.
    file_put_contents($file->uri, $content);
    return file_save($file);
  }

  /**
   * Normalizes the given filename and adds the '.rdf' extension.
   *
   * @param string $filename
   *   The filename to normalize.
   *
   * @return string
   *   The normalised filename.
   */
  function normalize_filename($filename) {
    $filename = preg_replace('/[\(\),&?"\'`’\[\]:.]/', '', $filename);
    $filename = preg_replace('/[ -]/', '_', $filename);
    $filename = strtolower($filename);
    return "{$filename}.rdf";
  }

  /**
   * Generates an RDF string for the given NINES\object.
   *
   * @param \NINES\Object $object
   *   An object describing the NINES metadata.
   *
   * @return string
   *   The generated RDF.
   */
  function convert_to_rdf($object) {
    $rdf = new RDF($object);
    return $rdf->export();
  }

  /**
   * Given a manuscript node, it generates a RDF file.
   *
   * @param stdClass $node
   *   A Drupal manuscript node.
   *
   * @return mixed
   *   A Drupal file containing the exported RDF if successful, FALSE otherwise.
   */
  function export_manuscript($node) {
    $id = $node->field_manuscript_project_id['und'][0]['value'];
    $object = new Object($id);
    // Title.
    $object->title = $node->title;
    $object->alternatives[] = $node->field_manuscript_alt_title['und'][0]['value'];
    // Date.
    $date_label = $node->field_manuscript_dates['und'][0]['value'];
    $start_date = new DateTime($node->field_manuscript_start_date['und'][0]['value']);
    $end_date = new DateTime($node->field_manuscript_end_date['und'][0]['value']);
    $object->date = new DateRange($start_date, $end_date, $date_label);
    // Text.
    $object->text = strip_tags($node->field_manuscript_tei['und'][0]['value']);
    $object->text = preg_replace("/([\r\n]{6,}|[\n]{3,}|[\r]{3,})/", "\n", $object->text);
    // Types.
    $types = array();
    // Map genre to type.
    $genre = isset($node->field_manuscript_genres['und'][0]['value']) ? $node->field_manuscript_genres['und'][0]['value'] : '';
    if (preg_match('/map/i', $genre)) {
      $types[] = 'Map';
    }
    if (preg_match('/page proofs/i', $genre)) {
      $types[] = 'Page Proofs';
    }
    if (preg_match('/typescript/i', $genre)) {
      $types[] = 'Typescript';
    }
    if (preg_match('/drawing/i', $genre)) {
      $types[] = 'Drawing';
    }
    $object->setTypes(array_unique(array_merge($types, array(
      'Codex',
      'Collection',
      'Dataset',
      'Illustration',
      'Interactive Resource',
      'Manuscript',
      'Physical Object',
      'Sheet',
      'Still Image',
    ))));
    // Disciplines.
    $object->setDisciplines(array(
      'Anthropology',
      'Book History',
      'Ethnic Studies',
      'Geography',
      'History',
      'Literature',
      'Manuscript Studies',
      'Political Science',
      'Religious Studies',
      'Science',
    ));
    // Genres.
    $object->setGenres(array(
      'Bibliography',
      'Catalog',
      'Collection',
      'Correspondence',
      'Criticism',
      'Ephemera',
      'Essay',
      'Historiography',
      'Life Writing',
      'Nonfiction',
      'Paratext',
      'Photograph',
      'Political Statement',
      'Reference Works',
      'Religion',
      'Travel Writing',
      'Visual Art',
    ));
    // Authors.
    $authors = $node->field_manuscript_creators['und'][0]['value'];
    $authors = explode('; ', $authors);
    foreach ($authors as $author)  {
      $object->roles['AUT'][] = $author;
    }
    $addressees = $node->field_manuscript_addressees['und'][0]['value'];
    $addressees = explode('; ', $addressees);
    foreach ($addressees as $addressee)  {
      $object->roles['RCP'][] = $addressee;
    }
    // Publisher.
    $object->roles['PBL'] = 'Livingstone Online (livingstoneonline.org)';
    // Full text.
    $object->full_text = TRUE;
    // See Also.
    $object->seeAlso = url('in-his-own-words/catalogue', array(
      'absolute' => TRUE,
      'query' => array(
        'query' => $id,
      )
    ));
    $contents = convert_to_rdf($object);
    return write_rdf_to_file(normalize_filename($id), $contents);
  }

  interface DateInterface {
    public function label();
    public function value();
  }

  class DateUnknown implements DateInterface {

    function label() {
      return 'Unknown';
    }

    function value() {
      return 'Unknown';
    }

  }

  class Date implements DateInterface {

    private $value;

    public function __construct(DateTime $date) {
      $this->value = $date->format('Y');
    }

    public function label() {
      return 'none';
    }

    public function value() {
      return $this->value;
    }

  }

  class DateRange implements DateInterface {

    private $label;
    private $value;

    public function __construct(DateTime $start, DateTime $end, $label = NULL) {
      $start_year = $start->format('Y');
      $end_year = $end->format('Y');
      if (isset($label)) {
        $this->label = $label;
      }
      else {
        $same_century = substr($start_year, 0 , 2) == substr($end_year, 0 , 2);
        $this->label = ($same_century) ?
          $start_year . '-' . substr($start_year, 2 , 2) :
          $start_year . '-' . $end_year;
      }
      $this->value = $start_year . ',' . $end_year;
    }

    public function label() {
      return $this->label;
    }

    public function value() {
      return $this->value;
    }

  }

  /**
   * Class Object
   *
   * @package NINES
   */
  class Object {
    /**
     * Constants
     */

    /**
     * Adapted from the DCMI list of types, this term should describe the medium,
     * or format of the object.
     */
    const TYPE = array(
      'Codex',
      'Collection',
      'Dataset',
      'Drawing',
      'Illustration',
      'Interactive Resource',
      'Manuscript',
      'Map',
      'Moving Image',
      'Notated Music',
      'Page Proofs',
      'Pamphlet',
      'Periodical',
      'Physical Object',
      'Roll',
      'Sheet',
      'Sound',
      'Still Image',
      'Typescript',
    );

    /**
     * ARC Partner sites recommend the submission of names in the format of "Last,
     * First."
     *
     * Contributors are also encouraged to consult the Library of Congress
     * authorities list.
     *
     * Please be internally consistent and keep good records of any names you use.
     *
     * Please note: each element's content values pertain only to the
     * object at hand, not to the object's content or subject matter; when you
     * list a particular name as "author," this should be the author of the
     * object, not an author described in the object's text.
     *
     * ARC strongly encourages using <role:ART> or <role:AUT>, even when the agent
     * is unknown or anonymous. In such cases, use the standard values "Unknown"
     * or "Anonymous." For example, <role:AUT>Unknown</role:AUT>.
     *
     * Variants of those values ("Unk." or "Anon.") will degrade the usability of
     * the faceted browser.
     *
     * You may use ANY -- new rule as of April 2017 -- of the roles contained
     * in the list of the LOC MARC relator codes:
     * @see http://www.loc.gov/marc/relators/relaterm.html
     */
    const ROLE = array(
      'ART', // for Visual Artist
      'AUT', // for Author
      'EDT', // for Editor
      'PBL', // for Publisher
      'TRL', // for Translator
      'CRE', // for Creator
      'ETR', // for Etcher
      'EGR', // for Engraver
      'OWN', // for Owner
      'ART', // for Artist
      'ARC', // for Architect
      'BND', // for Binder
      'BKD', // for Book designer
      'BKP', // for Book producer
      'CLL', // for Calligrapher
      'CTG', // for Cartographer
      'COL', // for Collector
      'CLR', // for Colorist
      'CWT', // for Commentator for written text
      'COM', // for Compiler
      'CMT', // for Compositor
      'CRE', // for Creator
      'DUB', // for Dubious author
      'FAC', // for Facsimilist
      'ILU', // for Illuminator
      'ILL', // for Illustrator
      'LTG', // for Lithographer
      'PRT', // for Printer
      'POP', // for Printer of plates
      'PRM', // for Printmaker
      'RPS', // for Repository
      'RBR', // for Rubricator
      'SCR', // for Scribe
      'SCL', // for Sculptor
      'TYD', // for Type designer
      'TYG', // for Typographer
      'WDE', // for Wood engraver
      'WDC', // for Wood cutter
      // Terms from https://www.loc.gov/marc/relators/relaterm.html.
      'RCP', // Addressee
    );

    /**
     * Information about the disciplines that may be interested in the object.
     */
    const DISCIPLINE = array(
      'Anthropology',
      'Archaeology',
      'Architecture',
      'Art History',
      'Art Studies',
      'Book History',
      'Classics, Ancient History',
      'Dance Studies',
      'Economics',
      'Education',
      'Ethnic Studies',
      'Film Studies',
      'Gender Studies',
      'Geography',
      'History',
      'Labor Studies',
      'Law',
      'Literature',
      'Manuscript Studies',
      'Math',
      'Music Studies',
      'Philosophy',
      'Political Science',
      'Religious Studies',
      'Science',
      'Sociology',
      'Sound Studies',
      'Theater Studies',
    );

    /**
     * Basic descriptive genres for Collex materials.
     */
    const GENRE = array(
      'Advertisement',
      'Animation',
      'Bibliography',
      'Catalog',
      'Chronology',
      'Citation',
      'Collection',
      'Correspondence',
      'Criticism',
      'Drama',
      'Ephemera',
      'Essay',
      'Fiction',
      'Film, Documentary',
      'Film, Experimental',
      'Film, Narrative',
      'Film, Other',
      'Historiography',
      'Interview',
      'Life Writing',
      'Liturgy',
      'Musical Analysis',
      'Music, Other',
      'Musical Work',
      'Musical Score',
      'Nonfiction',
      'Paratext',
      'Performance',
      'Philosophy',
      'Photograph',
      'Political Statement',
      'Poetry',
      'Religion',
      'Reference Works',
      'Review',
      'Scripture',
      'Sermon',
      'Speech',
      'Translation',
      'Travel Writing',
      'Unspecified',
      'Visual Art',
    );

    /**
     * The federation that this object belongs to. Currently, the two legal values
     * of this are "NINES" and "18thConnect". Notice that an object can belong to
     * more than one federation.
     */
    const FEDERATION = array(
      'NINES',
      '18thConnect',
    );

    /**
     * The identifier for this object.
     *
     * @var string
     */
    public $id;

    /**
     * A shorthand reference to the contributing project or journal.
     * @var string
     */
    public $archive = 'livingstone';

    /**
     * The title of the object.
     * @var string
     */
    public $title;

    /**
     * An alternative title or name of the object.
     *
     * The distinction between titles and alternative titles is
     * application-specific. In Collex search results, the alternative title
     * displays below the main title, in plain (non-hyperlinked) text.
     * @var array
     */
    public $alternatives = array();

    /**
     * Title of the larger work, resource, or collection of which the present
     * object takes part can be used for the title of a journal, anthology,
     * book, online collection, etc.
     * @var array
     */
    public $sources = array();

    /**
     * A single keyword which is not currently displayed in some nodes, but is
     * displayed in the results for others. It may be applied to tags and for
     * future mining of data from ARC Partners sites. MESA also adds a
     * requirement that the term come from a recognized or approved-by-MESA
     * authority list.
     *
     * See the MESA metadata standards for more info:
     * @see http://wiki.collex.org/index.php/MESA_Metadata_Information#.3Cdc:subject.3E
     * @var array
     */
    public $subjects = array();

    /**
     * Adapted from the DCMI list of types, this term should describe the
     * medium, or format of the object.
     *
     * @var array
     */
    public $types = array();

    /**
     * Individuals or organizations involved in the creation of the object.
     *
     * Unlike other arrays this one is an array of associative arrays, such that
     * children have the following keys:
     *  - role: A valid role as defined by the constant above.
     *  - name: The name of te person who has the identified role.
     * @var array
     */
    public $roles = array();

    /**
     * Information about the disciplines that may be interested in the object.
     * @var array
     */
    public $disciplines = array();

    /**
     * Basic descriptive genres for Collex materials.
     * @var array
     */
    public $genres = array();

    /**
     * Date of the object.
     *
     * May contain either a four digit year AND NOTHING ELSE
     * (<dc:date>1959</dc:date>), or may contain a <collex:date> element inside,
     * its usage described in this entry and the next one.
     *
     * @see http://wiki.collex.org/index.php/Submitting_RDF#.3Cdc:date.3E
     * @var Date
     */
    public $date = NULL;

    /**
     * If present, a "true" value denotes that the content is free and available
     * for use by all people in all places, whereas as a "false" value denotes
     * that the content is restricted in some way to subscribers.
     * @var bool
     */
    public $free_culture = TRUE;

    /**
     * Plain text of the transcript within the nines:text element.
     *
     * Indexed by the COLLEX search engine and used for full-text queries.
     * This should be a "pure" transcript of the text content of the object,
     * without extraneous text from navigation elements, copyright statements,
     * etc. Encode plain text in UTF-8 format.
     * @var string
     */
    public $text = '';

    /**
     * Pointer to the web-accessible object as it is rendered in your own
     * interface. Distinct urls displaying the same content should each get an
     * rdfs:seeAlso entry usually an html page.
     *
     * During indexing, the NINES server issues a HEAD request to the specified
     * URL (not a GET) and follows redirects.
     * @var string
     */
    public $seeAlso = '';

    /**
     * The federation that this object belongs to. Currently, the two legal
     * values of this are "NINES" and "18thConnect". Notice that an object
     * can belong to more than one federation.
     * @var string
     */
    public $federations = array('NINES');

    /**
     * If present, a "true" value denotes that the content is was obtained by
     * OCR, so there may be mistakes.
     * @var bool
     */
    public $ocr = FALSE;

    /**
     * If present, a "true" value denotes that the text element points to the
     * full text of the object, and not a summary, or other abbreviated content.
     * In some cases, mostly for resources like victbib, this full text was NOT
     * the full text of the object in question, rather it was project-specific
     * text (like an annotated bibliography). In other cases it could be the
     * full text of a poem, for example, for which there is no online plain text
     * to harvest. If you intend to provide a link to full text on the web for
     * indexing, a "true" value is required. The value is not case-sensitive.
     * @var bool
     */
    public $full_text = FALSE;

    /**
     * This element identifies the language of the resource using the language
     * codes from the ISO 639-2 Language Code List. The content of dc:language
     * may be either from the first column (ISO 639-2 Code), the third column
     * (English name of Language), or the fourth column (French name of
     * Language). Please note that currently only the MESA search interface
     * allows the user to limit a search by language; NINES and 18thConnect
     * do not have this capability.
     * @var string
     */
    public $language = 'English';

    /**
     * This element allows you to declare geographical locations. The vocabulary
     * for these locations should be derived from the Getty Thesaurus of
     * Geographical Names Online <http://www.getty.edu/research/tools/vocabulary/tgn/index.html>.
     * The only place information in the metadata record should be related to
     * the source and provenance, the latter information appearing in the
     * description.
     * @var array
     */
    public $coverage = array();

    /**
     * The element allows you to record the date that the digital surrogate was
     * created if your project records such dates.
     * @var array
     */
    public $date_of_edition = array();

    /**
     * This element marks the date of peer review (really, the date of ingestion
     * into the ARC Catalog, which marks the end of the peer review process).
     * If a project re-submits rdf, the project should be reviewed again by the
     * node, and a new peer-review (ingestion) date added. The point of this
     * element is to let people know how recently this object in our catalog
     * has been updated by peer-reviewing and ingesting digital scholarship.
     * @var array
     */
    public $review_date = array();

    /**
     * This element is designed for adding descriptive information about the
     * resource or the metadata record (e.g., provenance, manuscript details,
     * metadata uncertainties, etc).
     * @var string
     */
    public $description = '';

    /**
     * @note we're not exposing the following elements:
     *  - <collex:source_xml>
     *  - <collex:source_html>
     *  - <collex:source_sgml>
     *  - <collex:image rdf:resource="">
     *  - <collex:thumbnail rdf:resource="">
     *  - <dcterms:hasPart rdf:resource="">
     *  - <dcterms:isPartOf rdf:resource="">
     *  - <dc:relation rdf:resource="">
     */

    /**
     * Checks if the given <dc:type> is valid according to the NINE guidelines.
     *
     * @param string $value
     *   The <dc:type> to check.
     *
     * @return bool
     *   TRUE if the given <dc:type> is allowed according to the NINE submission
     *   guidelines, FALSE otherwise.
     */
    public static function validType($value) {
      return in_array($value, self::TYPE);
    }

    /**
     * Checks if the given <role:**> is valid according to the NINE guidelines.
     *
     * @param string $value
     *   The <role:**> to check.
     *
     * @return bool
     *   TRUE if the given <role:**> is allowed according to the NINE submission
     *   guidelines, FALSE otherwise.
     */
    public static function validRole($value) {
      return in_array($value, self::ROLE);
    }

    /**
     * Checks if the given <collex:discipline> is valid.
     *
     * @param string $value
     *   The <collex:discipline> to check.
     *
     * @return bool
     *   TRUE if the given <collex:discipline> is allowed according to the
     *   NINE submission guidelines, FALSE otherwise.
     */
    public static function validDiscipline($value) {
      return in_array($value, self::DISCIPLINE);
    }

    /**
     * Checks if the given <collex:genre> is valid.
     *
     * @param string $value
     *   The <collex:genre> to check.
     *
     * @return bool
     *   TRUE if the given <collex:genre> is allowed according to the
     *   NINE submission guidelines, FALSE otherwise.
     */
    public static function validGenre($value) {
      return in_array($value, self::GENRE);
    }

    /**
     * Checks if the given <collex:federation> is valid.
     *
     * @param string $value
     *   The <collex:federation> to check.
     *
     * @return bool
     *   TRUE if the given <collex:federation> is allowed according to the
     *   NINE submission guidelines, FALSE otherwise.
     */
    public static function validFederation($value) {
      return in_array($value, self::FEDERATION);
    }

    /**
     * Checks if the given values are valid according to the given function.
     *
     * @param array $values
     *   The values to check.
     * @param $validation_function
     *   The function used to check if all the given values are valid.
     */
    public static function guard(array $values, $validation_function) {
      $valid_values = array_filter($values, $validation_function);
      $invalid_values = array_diff($values, $valid_values);
      if (!empty($invalid_values)) {
        throw new InvalidArgumentException(t('Invalid values used: @values', array(
          '@values' => implode(',', $invalid_values),
        )));
      }
    }

    /**
     * Constructor.
     *
     * @param string $id.
     */
    public function __construct($id) {
      if (!is_string($id) || empty($id)) {
        throw new InvalidArgumentException(t('Object requires a valid string for $id argument.'));
      }
      $this->id = $id;
      $this->date = new DateUnknown();
    }

    public function setTypes(array $types) {
      self::guard($types, 'self::validType');
      $this->types = $types;
    }

    public function setRoles(array $roles) {
      self::guard(array_keys($roles), 'self::validRole');
      $this->roles = $roles;
    }

    public function setDisciplines(array $disciplines) {
      self::guard($disciplines, 'self::validDiscipline');
      $this->disciplines = $disciplines;
    }

    public function setGenres(array $genres) {
      self::guard($genres, 'self::validGenre');
      $this->genres = $genres;
    }

    public function setFederations(array $federations) {
      self::guard($federations, 'self::validFederation');
      $this->federations = $federations;
    }

  }

  /**
   * Class RDF
   *
   * @package NINES
   */
  class RDF {

    /**
     * Constants
     */

    // Namespace prefixes.
    const COLLEX = 'collex';
    const DC = 'dc';
    const DCTERMS = 'dcterms';
    const RDF = 'rdf';
    const RDFS = 'rdfs';
    const ROLE = 'role';
    const LIVINGSTONE = 'livingstone';

    // Namespace URLS.
    const NAMESPACES = array(
      self::COLLEX => 'http://www.collex.org/schema#',
      self::DC => 'http://purl.org/dc/elements/1.1/',
      self::DCTERMS => 'http://purl.org/dc/terms/',
      self::RDF => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
      self::RDFS => 'http://www.w3.org/2000/01/rdf-schema#',
      self::ROLE => 'http://www.loc.gov/loc.terms/relators/',
      self::LIVINGSTONE => "http://livingstone.library.ucla.edu/test",
    );

    // Local name of the 'main' element.
    const LIVINGSTONE_ELEMENT = 'lsip';

    /**
     * The XML document representing the RDF.
     *
     * @var DOMDocument
     */
    private $doc;

    /**
     * Constructor.
     *
     * @param \NINES\Object $object.
     *   The NINES object to convert to RDF.
     */
    public function __construct($object) {
      $this->doc = new DOMDocument('1.0', 'UTF-8');
      $this->doc->xmlStandalone = FALSE;
      $this->doc->formatOutput = TRUE;
      $this->doc->preserveWhiteSpace = TRUE;
      $this->doc->loadXML(self::template($object));
      $this->addEach(self::DC,'title', $object->title);
      $this->addEach(self::COLLEX,'archive', $object->archive);
      $this->addEach(self::DCTERMS, 'alternative', $object->alternatives);
      $this->addEach(self::DC,'source', $object->sources);
      $this->addEach(self::DC,'subject', $object->subjects);
      $this->addEach(self::DC,'type', $object->types);
      foreach ($object->roles as $name => $values) {
        $this->addEach(self::ROLE, $name, $values);
      }
      $this->addEach(self::COLLEX,'discipline', $object->disciplines);
      $this->addEach(self::COLLEX,'genre', $object->genres);
      switch(get_class($object->date)) {
        case 'NINES\DateUnknown':
        case 'NINES\Date':
          $this->addEach(self::DC,'date', $object->date->value());
          break;
        case 'NINES\DateRange':
          $dc_date = $this->add(self::DC, 'date');
          $collex_date = $this->create(self::COLLEX, 'date');
          $dc_date->appendChild($collex_date);
          $label = $this->create(self::RDFS,'label', $object->date->label());
          $collex_date->appendChild($label);
          $value = $this->create(self::RDF,'value', $object->date->value());
          $collex_date->appendChild($value);
          break;
      }
      $this->addEach(self::COLLEX,'freeculture', $object->free_culture);
      $this->addEach(self::COLLEX,'text', $object->text);
      $this->addEach(self::RDFS,'seeAlso', $object->seeAlso);
      $this->addEach(self::COLLEX,'federation', $object->federations);
      $this->addEach(self::COLLEX,'ocr', $object->ocr);
      $this->addEach(self::COLLEX,'fulltext', $object->full_text);
      $this->addEach(self::DC,'language', $object->language);
      $this->addEach(self::DC,'coverage', $object->coverage);
      $this->addEach(self::COLLEX,'dateofedition', $object->date_of_edition);
      $this->addEach(self::COLLEX,'reviewdate', $object->review_date);
      $this->addEach(self::DC,'description', $object->description);
    }

    /**
     * Adds one or more elements for each given value.
     *
     * @param string $prefix
     *   The namespace prefix of the element.
     * @param string $name
     *   The name of the element to add.
     * @param mixed $values
     *   The text value(s) to add to the livingstone element, each will become
     *   a separate element.
     */
    private function addEach($prefix, $name, $values = NULL) {
      $url = self::NAMESPACES[$prefix];
      $values = is_array($values) ? $values : array($values);
      foreach ($values as $value) {
        $this->addQualifiedElement($prefix, $url, $name, $value);
      }
    }

    /**
     * Adds a element to the livingstone element.
     *
     * @param string $prefix
     *   The namespace prefix of the element.
     * @param string $name
     *   The name of the element to add.
     * @param mixed $value
     *   The text value to add to the livingstone element.
     *
     * @return DOMNode
     *   The added element.
     */
    private function add($prefix, $name, $value = NULL) {
      $url = self::NAMESPACES[$prefix];
      return $this->addQualifiedElement($prefix, $url, $name, $value);
    }

    /**
     * Creates an element but does not append it to the document.
     *
     * @param string $prefix
     *   The namespace prefix of the element.
     * @param string $name
     *   The local name of the element.
     * @param mixed $value
     *   The text value of the element.
     *
     * @return DOMElement
     */
    private function create($prefix, $name, $value = NULL) {
      $url = self::NAMESPACES[$prefix];
      return $this->createQualifiedElement($prefix, $url, $name, $value);
    }

    /**
     * Adds an qualified element to the livingstone element.
     *
     * @param string $prefix
     *   The namespace prefix of the element.
     * @param string $url
     *   The namespace url of the element.
     * @param string $name
     *   The local name of the element.
     * @param mixed $value
     *   The text value of the element.
     *
     * @return DOMNode
     *   The created element.
     */
    private function addQualifiedElement($prefix, $url, $name, $value = NULL) {
      $element = $this->createQualifiedElement($prefix, $url, $name, $value);
      return $this->appendToLivingstoneElement($element);
    }

    /**
     * Creates a qualified element without adding it to the document.
     *
     * @param string $prefix
     *   The namespace prefix of the element.
     * @param string $url
     *   The namespace url of the element.
     * @param string $name
     *   The local name of the element.
     * @param mixed $value
     *   The text value of the element.
     *
     * @return DOMElement
     *   The created element.
     */
    private function createQualifiedElement($prefix, $url, $name, $value = NULL) {
      $qualified_name = $prefix . ':' . $name;
      return $this->doc->createElementNS($url, $qualified_name, $this->normalizeValue($value));
    }

    /**
     * Appends the given element to the livingstone element.
     *
     * @param DOMElement $element
     *   The element to be appended.
     *
     * @return DOMNode
     *   The appended element.
     */
    private function appendToLivingstoneElement(DOMElement $element) {
      $nodes = $this->doc->getElementsByTagNameNS(self::NAMESPACES[self::LIVINGSTONE], self::LIVINGSTONE_ELEMENT);
      $parent = $nodes->item(0);
      return $parent->appendChild($element);
    }

    /**
     * Converts non-string values to their string equivalent.
     *
     * @param mixed $value
     *   The value to normalize.
     *
     * @return string
     *   The normalized value.
     */
    private function normalizeValue($value = NULL) {
      switch(gettype($value)) {
        case 'boolean':
          return $value ? 'true' : 'false';
      }
      return $value;
    }

    /**
     * Generates a base template of the RDF document.
     *
     * @param \NINES\Object $object
     *  Contains the data for generating an RDF document.
     *
     * @return string
     *   XML string representing a initial template of the RDF document.
     */
    private static function template($object) {
      $namespace = 'xmlns:' . self::LIVINGSTONE. '="' . self::NAMESPACES[self::LIVINGSTONE] . '"';
      $element = self::LIVINGSTONE . ':' . self::LIVINGSTONE_ELEMENT;
      return <<<EOT
<rdf:RDF
  xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
  xmlns:dc="http://purl.org/dc/elements/1.1/"
  xmlns:dcterms="http://purl.org/dc/terms/"
  xmlns:collex="http://www.collex.org/schema#"
  xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
  xmlns:role="http://www.loc.gov/loc.terms/relators/"
  {$namespace}>
  <{$element} rdf:about="{$object->id}">
  </{$element}>
</rdf:RDF>
EOT;
    }

    /**
     * Exports the RDF to a string.
     *
     * @return string
     *   The RDF representing the object.
     */
    public function export() {
      return $this->doc->saveXML();
    }
  }
}
