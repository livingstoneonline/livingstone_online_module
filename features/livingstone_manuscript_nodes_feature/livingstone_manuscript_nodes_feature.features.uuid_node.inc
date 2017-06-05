<?php
/**
 * @file
 * livingstone_manuscript_nodes_feature.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function livingstone_manuscript_nodes_feature_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'title' => '1871 Field Diary (Fragments Integrated)',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1479166374,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '0c2b7dd1-f815-4479-9741-8aa0829fa864',
  'field_manuscript_addressees' => array(),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => '1871 Field Diary (Fragments Integrated), 23 March 1871-3 November 1871',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Field Diaries, 33, 37, 38, 39',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-2.95,25.95',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '23 March 1871-3 November 1871',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1871-11-03T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(),
  'field_manuscript_extent_size' => array(),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); diaries; field notes',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:015002',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Nyangwe; Manyema; Ujiji',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_015002',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone Online',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1871-03-23T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(
    'und' => array(
      0 => array(
        'value' => '
    
        
            
                1871 Field Diary (Fragments Integrated)
				1871 Field Diary (Fragments Integrated), 23 March 1871-3 November 1871
                David Livingstone
                Adrian S. Wisnicki
                
                    Adrian S. Wisnicki
                    Editorial Decisions
                    Transcription
                    TEI Encoding
					Proofing
					Editing
					Encoding Review
                	
                
                    Kathryn Simpson
                    Transcription
                    TEI Encoding
					Proofing
                				
				
                    Doug Emery
                    TEI Encoding
                
            
            
                Livingstone Online
                University of Maryland Libraries
                College Park, MD, USA
                2016
                liv_015002
            
            
                
                    
                        United Kingdom
                        Field Diaries, 033, 037, 038, 039
                    
                    
                        
                            
John Kirk This hand is thought
                                to be that of John Kirk.	
                            
Horace Waller This hand is thought
                                to be that of Horace Waller.
                            
Unknown Hand This hand is unknown
                                but thought not David Livingstone\'s.
                        
                    
					
					
						
                        	United Kingdom
                        	Blantyre
                        	David Livingstone Centre
                        	297b, 297c
						
					
					
					
						
	                        United Kingdom
	                        Edinburgh
	                        National Library of Scotland
	                        MS. 10703, ff. 36-39
						
					
					
					
						
	                        United Kingdom
	                        Blantyre
	                        David Livingstone Centre
	                        1120b
						
					
					
					
						
	                        United Kingdom
	                        Oxford
	                        Bodleian Library. Weston Library
	                        Waller MSS. Afr. s. 16.1, f. 172
						
					
                
                
                    1871 Field Diary (Fragments Integrated), 23 March 1871-3 November 1871
                    David Livingstone
                    23 March 1871-3 November 1871
                    Nyangwe; Manyema; Ujiji

                
            
        
        
            
                English
				Arabic
				Hebrew
				Latin
				Swahili
				Undetermined African Language
            
        
        

			
            Integration
            Data scrubbing and prep for XSL transformation

			
            Integration
            Data scrubbing and prep for XSL transformation

			
            Integration
            Data scrubbing and prep for XSL transformation

			
            Integration
            Data scrubbing and prep for XSL transformation

			
            Initial transcription and TEI encoding
            TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing
            
			
            Initial transcription and TEI encoding
            Proofing
            Editing
            
			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

			
            Initial transcription and TEI encoding
            Proofing
            Editing

        
    

	
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
	

	
       	
			
	
	

	




CII - to be copied into journal at 
Ujiji
 now 28



23rd March 1871 Left Kasongo - he gave a
goat &amp; guns &amp;c - country gently undulating
shewing green slopes fringed with wood
Grass from 4 to 6 feet = Luamba or
cotton meadow grass - Nyassi in patches
reached Katenga\'s about 6 miles off
many villages &amp; people passed us
carrying loads of provisions - cassava
from the 
chitoka
 or market - soil
a little sandy - allows good drainage



24th
 = Great rain in the night &amp;
morning - and sickness of
men prevented our march



25th
 Went to 
Marimwe
 7
½
1/2

miles off- many hamlets at
each station = country undulating
and grassy - trees scarce
Patches of Arum at every
village and cassava far
off on account of the pigs
which are now plenty - a
black ugly pig - crossed a rivulet &amp;
the 
Lohemba
 -



26th
 Went four miles and crossed the


Kabwe maji
 - 
the
then
 a mile beyond 
Kahembai

which flows into the 
Kunda
 and it
into 
Lualaba
 - country open and 
low hills appear in the North - We
met a party from the traders at 
Kasongo

chiefly Matereka\'s people - Salem &amp; 

Seyd
Syde

bin Sultan- They had eighty two captives
say they fought ten days to secure
them and two Malongwana &amp; two of the 



Banyamwezi
Nyamwezi

 - they had about 20
tusks and carried one who broke
his leg in fighting - We shall be safe
only when past the blood shed -
and murder


1 
Nyangwe



Lokengo
 3 

Kilonda



Bagenya 2
rowers

Likele 4 far

Bakuzz









Kibrinke

 
R
River

is rocky

Lohike
poisoned
arrows



	




CIII 27th
 along a ridge of land over
looking a well cultivated lowland with
hills in the distance where the Bogharib
feat was performed - many villages come
through rather tumble down ones 7 miles
a headman bothered  this one to give
a goat and in fear he did it. Arum
Arum common -


28th
 The 
Banian slaves are again
trying compulsion in I don\'t know
what - refused to take their bead
rations and began an oration
by the mouth of Chakanja - I
could not listen to it as he has
been concocting a mutiny against
me - It is excessively trying and
so many difficulties have been
put in my way I doubt whether
the Divine favour and will is
on my side We came six miles
today crossing many rivulets
running into the 

Kunda

which also we crossed in a
canoe - It is about thirty yards
wide and deep - Then near the
village where we sleep we crossed
the 
Liya
 about twenty yards and
going into 
Kunda
 &amp; 
Lualaba



I am greatly distressed because
no law here - they probably
mean to create a disturbance
at Abed

s
\'s
 place to which we
are near The Lord look on it


	



29th March - the slaves demanded

double allowance and as usual
told me of what they got near the
sea coast - We crossed the river


	




CIV - The MolembeThe 
Moangor
 by two 27
well made wattle bridges - It is 20 yards &amp; a
very strong current and is feared on that
account - 
the
then
 the 
Molembe
 in a canoe -
swelled by rains to 15 yards &amp; many rills and
much mud - Came about 7
½
1/2
 miles to
sleep at one of the villages of 
Nyangwe

Hope to reach Abed tomorrow About
sixty market women came past us
from the 
chitoka
 or market place
on the 
Lualaba
 - they pass thither
by night and come away about midday
having disposed most of their goods
by Barter - country open &amp; dotted
over with villages - Trees along the 
watercourses chiefly - Grass not very
long - four to six feet - Pigs abundant
country low as compared with 

Tangan-
-yika

 - about 2000 feet above the sea


The 
headmans
headman\'s
 house I am lodged
in contained the 
housewifes
housewife\'s
 little
conveniences in the shape of forty
pots - dishes baskets - knives &amp;c &amp;c
mats all which the wife removed
to another house I gave four strings
of beads and go on tomorrow
	


30th
 after seven miles we came
to 
Nyangwe
 market place where

Abed and Hassani have built
and thence sent their people over


Lualaba
 as far as the 
Loeki
 or


Lomame
 - Hope they will not
shed blood - Abed says my
words against bloodshed stuck
into him - and he ordered his
people to give presents to the chiefs
and not kill unless attacked


	




30 CV - 31st March 1871 Went down to 
take 

Pen squiggle to correct ink flow. The color of the ink differs from that of the surrounding text.

 a look at 
Lualaba
 here - It is narrower
than it is above but still a mighty river
about 3000 yards broad and deep - Has
many Islands of large size but at
these it is still over 2000 yards or
one 
miles
mile

Banks here are steep &amp;
deep - The banks of the other
rivers are of gravel - It flows
fast towards the North - people
very numerous but tomorrow
we shall see the great gathering
at market - This is held for

two one days and then omitted for three
slaves bought here are good as 
tailors of grass cloth but their
tongue is strange - they come
from far
	
	



Monday
1st April
1871

	



Rain early every morn-
-ing
I fear it will be
difficult to buy a canoe - The

Manyema have learned to distrust
all strangers and think to buy
means plunder and murder
	


2 
Chitoka
 or market contained
over a thousand people carrying
earthen pots and cassava
grass cloth fishes fowls - they
were alarmed at my coming
among them and ready to flee
many stood afar off in suspicion
many came from the other side
of the river with their goods
tomorrow market is held up river


	




CVI 3d April 1871 tried to secure a 
31
longitude by fixing a weight on the key 
of the watch helping it on - Will try in a
quiet place tomorrow - People all fear
us and they have good reason for
it in the villanous conduct of
many of the blackguard half castes
cannot get canoe so I wait to
see what will turn up


River is said to over flow all
its banks annually as the 
Nile

further down does - Here it is
over 3000 yards broad - or a mile
and a half - with large islands
In the distance 
is
it
 is 2 miles or 4000
yards - I sounded across yesterday
Near the bank it is nine feet. The
rest 15 feet &amp; one cast in the middle
was 20 feet - Between the islands
12 feet and nine feet again inshore



Mologhwe
 Kahemba gave us a 
small sheep - It is a mighty river truly
This morning 4th of 
avil
 time I
took distances and altitudes altern-
nately with a bullet for a weight
on the key - They may give a relative
Longitude soil stiff black loam and
very feverish

3d Arab month 4th

 


will appear in 2 or 3 days



5th
 - People cross over to buy


viramba


\'s
s
 or grass cloths - Arabs
asked many questions about the
Bible - How many prophets -
They say they believe all - I believe
all but 

Muhammad
Muhamad

 - 
7

			

			
	




CVII - was ill all yesterday by taking 2
cups of very sweet malofu or beer made
from bananas - shall touch it no more


7th April 1871 made this ink with the seeds
of a plant called by the Arabs 



Zingifure
Mzingifuri




It is known in 
India
 and here is used
by the Manyema to dye 
virambas
 and
ornament their faces and heads
I sent my people over to the other side
to cut wood to build a house for me
The borrowed one I live in had
s mud
walls &amp; floors which are damp foul
smelling and unwholesome - I shall
have grass walls and grass &amp; reeds
on the floor - of my own house - the
free ventilation will keep it sweet
This is the season called 
Masika
 - The
finishing rains - We have rain
in large quantity almost every night
and I could scarcely travel even if I
had a canoe - but still it is trying to
be kept back by suspicion and by
the wickedness of the wicked - The
Arabs are very kind to me 
sending cooked
food every day - I taught Abed to
make a Mosquito curtain of thin
print - He endured the persecution of
these insects sleeping on a high stage
when they were very numerous -


The Manyema are not trustworthy &amp;
they bring evil on themselves often
Paid one yesterday to bring a large
canoe - He brought one capable only of
carrying three and after men waited
some hours we have to put 
of
off
 crossing
till tomorrow -


	




CVIII. 8th April 1871 Every headman of 33
four or five huts is a 
Mologhwe
 Begin or chief and
glories in being called so -there is no political
cohesion - The 
Ujiji
an sla
very is an accursed
system but it must be admitted that the

Manyema too have faults the result of
ignorance of other peoples - Their isolation
has made them as unconscious of danger
in dealing with the cruel strangers as little
dogs in the presence of lions - their
refusal to sell or lend canoes for fear of
blame by each other will be ended by the
party of Dugumbe which has 10 head-
men taking them by force - they are
unreasonable and bloodyminded to-
-wards each other - Every Manyema would
like every other headman slain - They are
subjected to bitter lessons &amp; sore experience



Abed went over to 

Mologhwe
 Kahemba
and mixed blood with him - He was told
that two large canoes were hollowed out
and nearly ready to be brought for sale
If this can be managed peaceably it is a
great point gained and I may get one at
an Arab\'s price which may be 3 or 4
times the native price - Heavy rains
almost every night would prevent my
progress at present even if I had a canoe
There is no love lost among the three Arabs here
	



9th
 Rainy - but sent off people to cut
wood for house - The 
Loeki
 is said
by slaves to be larger than this
but we expect Abed\'s party back
from it in a few days with correct
information on that &amp; other
points - people said to be
very fierce &amp; dangerous
to the 
Ujijians



	






CIX.

 10th April 1871 Market today -
over 700 market people passed my door
It seems a pleasure of life to haggle &amp; joke
and laugh &amp; cheat - many go away with
care worn countenances - many are
old and carry heavy loads of dried
cassava earthenpots which they dispose
of for oil fish and relishes for their
food -  The men go flaunting in
gaudy 
lambas
 and carry little save
their iron wares fowls &amp; grass cloth
Bought two fishes with long snouts
very good eating
	


12th


New ℂ last night of 4th Arab
month - New house to be finished
today - The affair of Mteza resolves
itself into a 
a

 party of 25 Turks from


Suez
 under Ishmael coming up to


Lower Tanganyika
 &amp; living on an
island - Took ivory by force and
then 
-

 went away but five went to
visit Mteza - He was kind to them


when powder was spent
Afterwards ^ all ran away leaving all
their ill gotten ivory - 
Mteza said
to be circumcised &amp; to order his people
to undergo the rite but so many
lies are told one can believe nothing
The idea of a mission seems first
to have entered the Arab mind by
the beginning of 



bp
Bp


Bishop
 Mackenzie

s
\'s
 - but
tales 
very
vary
 from Mteza walking in
white and reading the Koran in
Arabic to the missionary getting
500 slaves &amp; 500 
frasilahs
 of ivory

and nothing else being done


	




CX. 13 April 1871 came into my new 35
house yesterday the first of the 4th Arab
a great comfort for the other was foul
full of vermin &amp; bad smelling -  Bugs
and 


Kapassi
Pagazi


 Arab 
accompaniements

accompaniments

made me miserable - Manyema huts
are all clean in comparison - Killed
a goat and gave the same beads that
were refused - These slaves require to
know that they are not the masters -

Abed says if slaves think that you fear
them they climb over you = This is
true - I clothed mine for nothing they
thought that my kindness was fear and
tried to ride rough shod over me -
	





Mologhwe
 Kahemba came over
and says that he will bring a canoe for
sale - 
Loeki
 due west of this is three
days off - Its confluence is four
days down 
Lualaba
 and all declare
it to be 
bosoa
 very large indeed -
	


14th
 Market today - Kahemba gave to

Abed two slaves as a present = I
have been writing part of a Despatch
in case of meeting people from the French
settlement on the 
Gaboon
 at 
Loeki

but the canoe affair is slow &amp; tedious
The people think only of war - getting
up a war against some one else as
price of it! They are a bloody minded
race - our protests for peace are
considered false = and that war in
some way is meant by buying a canoe
or getting one at all 
9



	





CXI
 
15th April
 the river 

Lomam
o
e



 enters


Lualaba
 a short distance below this but
on the Western bank - a spring of brine
rises in its bed &amp; the people cook it
down and sell the salt - The 
Lomam
o
e



is deep and is crossed by canoes of

Rashid &amp; people call it the 


Lofubu







Lofubu

 and not 

Lomam
o
e



 -


Nganze
 is further down and a 
market is held on its Northern
bank
	


16th April - It is believed that

seramp


Serampela
Zurampela

 gave Rashid

one three ^ (4) slaves as a present to the Arab
traders here and Rashid keeps two

of them and declares that these were
given to him by the chief - this is
the sort of dishonesty all practise if
they possibly can = The evidence is
not clear and Rashid
 will leave as
soon as possible and sell the slaves
ere the truth can be clearly known
This vitiates his evidence about the
cannibalism - but here they eat war captives 


 and say that some buy a slave
with a goat and eat him 

	


17th
 Rainy


18th

Market here - The Lepidosiren alive
in pots of water - White ants roasted
a chetina and another common snail
Lepidosiren is called Sembe
 - Abed
went a long way to see a canoe but
it was still further and he turned




One line of Hebrew text and four lines of Arabic. The first three lines of Arabic are a rough attempt at writing out the whole alphabet. The fourth line (technically undertext) presents a second attempt at writing the alphabet, but gets no further than the first two letters.
 

19th
 Dreary waiting but Abed

proposes to come &amp; trade along

with me this will render

the party stronger and he

will not shoot people in

my company - We shall

hear Katomba\'s people
s
\'s


story too
	


The following undertext appears in the lower right-hand corner of the page and is written perpendicularly to the rest of the text.



gnao


ml




	




CXII 20th April 1871

chief was to visit us yesterday but failed 37
probably through fear - Rashid got four
slaves by promising to bring a large body of
men to attack 

chipange
Chipange

 - came here and
after a deal of wrangling went off South
and will sell the slaves quickly so as to
end the matter - no honour among these
half castes -


The chief Mokandira says that 
Loeki

is small where it joins 
Lualaba
 but
another which they call the 
Lomame

is very much larger &amp; joins 
Lualaba
 too
but further down - Rapids reported
	



21st
 a common salutation here is

Ule hatsi - thou art on earth = Ua tala
thou lookest - Ua boka ^  or Uyoka
 thou awakest

Ule Koni - thou are here - U ri ho - thou
art here =

They deny cannibalism as common 

Pen squiggle to correct ink flow. The color of the ink differs from that of the surrounding text.

 - they
eat only a man taken ^ or killed in war - say
the meat is not good - and it makes
one dream of the man killed - some
West of 
Lualaba
 buy a slave with a
goat in order to eat him and eat him
they do - yet they are a fine looking race




Kunzi

 ^ or 

Kusi
 is North - 

Mhuru
 = South



ñkanda

 West or other side 
Lualaba





Mazimba
 = East = 
Bagenya people
of West of 
Lualaba
 -
(
Kanayumbe

 

R.
River
 &amp; island)

	



22nd
 Market here - The chief 

chimburu


Chimburu
Kimburu




came over but I did not see him - He is
said to be very handsome &amp; light coloured
	

Calculation in the lower left-hand corner of this page.
 
Two vertical pen squiggles to correct ink flow.

	

Moene Lualaba or 

Mologhwe
 Nyangwe
came too but I was not told who
he was till too late to do him honour
There are so many chiefs who shake
hands as a privilege it is confusing - they
	
touch one hand then clap both theirs together on
the chest - this is 
repeated twice 
10



	




CXIII - 23d April 1871. Journal



24 
Do
Ditto




Do
Ditto
 
Kamolondo
 is
about ^ twenty five miles broad The 
Lufira
 at


Katanga
 is a full bowshot wide - It goes
into 
Kamolondo
 - Lui means water
only 

Kayumba chakoma
 is
East of 
Lufira
 junction 

Kikonzi
Kalanza
is on the West of it and


Mkana
 of the underground dwellings
still further West - some are only 2
days from 
Katanga
 = Charwe people
are friendly - 
Kamolondo
 about ten
days distant from 
Katanga


	



25th
 News 
have
has
 come of four men
sent near to this to buy ivory - were
pressed to go to war and then a war
made when 2 were killed - We can go
no where but the people wish us to go
to kill others - a dreadful state truly
	

They force on a war against others by getting
traders to go ostensibly for trade then
send word that war is coming and
call out here it is - 
They
Then
 a fray takes
place inspite of all traders can do -
The Manyema are bloodminded &amp; no
mistake - I refused to send my men
to bring back Abed and Hassani\'s
people they would only add to the con-
fusion being as bloodthirsty as the

Manyema where no danger exists
Where the people can fight traders and
people are as civil as possible - At

Moenyempande

s
\'s
 Bogharib left a
debt of 28 slaves and did not dare to
fire a gun - Here his people bound
the headmen of villages till tusks were
brought for mere nothing - It is a 
sad sad tale to tell as this 
Manyema


villainy The Lord look on it


	





CXIV note for letter -

In reading about the Fountains of the 
Nile
 38
in boyhood the idea suggested by the words
of the ancient historian was that the head
waters welled up out of one ^ "ain" or eye and therein
without visible cause parted ^ to the North and


to the As a mere conjecture or trader 

^ South - 

 Possibly the primitive traveller ^ who
visited these springs ^ described them corre-
ctly enough in ^ non scientific common language as
issuing from one spot without dwelling


which is not apparent to the eye
on the fact ^ that though from one place
they gushed forth ^ on to from opposite slopes
of the watershed - The ancient priests who
heard his tale may have understood it
naturally but the supernatural agreed
best with all their notions 

or then
of their

 The


lifting up its head from the unseen abyss
wonderful river ^ and the marvellous
was transmitted to the time of 



Herodotus

in preference to the plain - The two
conical hills 
Crophi
 and 
Mophi

between which the fountains were
said to be situated seem to be later
embellishments of the primitive story

	


I am tired and weary - Have had a
perfect surfeit of seeing the grand
panorama of nature unfolding itself
in mountain valley woodland 

Buga
Mbuga


or prairie - The glorious tropical
vegetation in all is richness ^ beauty and
Majestic forms - peoples - beasts
Lakes and river and humanity in 
endless variety and of beautiful form 

Winwoode Reade seems to have hit the
exact truth in 
say
saying
 that the typical negroe is
not the West Coast African on whose
form &amp; features an unhealthy climate
has told injuriously for ages but the
ancient Egyptian is the true negro
though all our ideas of Africans 


to

of human
 
11

	


Two letters in Hebrew and one in Arabic. This appears to be an attempt to represent the same sound -- "shin -- in each of the two alphabets.





	




CXV - 26 April 1871 - Journal 
Chitoka


called Abed\'s nine slaves and asked their
countries and tribes - one with his front



when he
was
upper teeth extracted ^ about ten years of age
belongs to the Malobo tribe on the
other side of the 
Loeki
 - another comes
from the river 
Lombadzo
 or




Lombazo
Lombadzo


 on the West of 
Loeki
 This
may be another name for the 
Lomame

His country is called 

Ñañga

 and

(Ñoñgo) the tribe 
Ñoñgo
 - His chief 

Mpunzo




The Malobo tribe is under 
Yuñga


&amp; 
Lomadyo
 - another ^ toothless slave a mere boy
said he came from 
Lomame
 but his
statement was made in fear - the other 
two declared positively that no traders came
into their country - this promises ivory
for Abed who is now eager to embark
but not more so than I am - We look
anxiously for the return of Katomba\'s
and Abed

s
\'s
 people with news as to the
way
	



27th
 waiting anxiously but we
cannot hasten people far off - Even
the owners of the canoes cannot be
moved -"Yes Yes we shall bring them"
but they do not stir = they doubt us
	



28th 
Sun
Sunday

 - Abed sending off to other
side to buy slaves - a pretty woman
for 300 cowries and 100 strings of beads
she can be sold again for ivory - We
hear of a half caste reaching the other
side of 
Lomame
 - probably from


Congo
 or 

Ambriz

 - but reporters had
not seen him -


a man with ten slaves digging
malachite at 
Katanga
 for 3 months
gains a hundred 
frasilahs
 of copper
	

Calculation in the lower left-hand corner of the page.

	
It is very cheap - fountains
eight days from 
Katanga
 S =

	


	




CXVI. 
note for letter
 These four fountains seem to be 12
what the Egyptians priests ^ learned men of remote antiquity 41
considered to be the chief sources of the ^ renowned river

of 
Egypt

 which 
five
 for its beneficial effects ^



 and mysterious source
they regarded devoutly viewed as an emblem of the Deity

In my letter from 
Ujiji
 in 1869 which
I fear has been destroyed I described
the structure of the Watershed and added
information about Lake 
Lake Bangweolo

as a supplement to a letter of 
July 1868
The copy is at 
Ujiji
 so I now give from
memory some idea of its contents as 


explanatiery
explanatory
 of the springs of the 
Nile

which the  ancients may not have
known - The watershed situated between
ten and twelve degrees South Latitude is between
700 &amp; 800 miles in length - the general
height is between 4000 &amp; 5000 feet above
the level of the sea but mountains rise
stand at various parts of it which
are between 6000 &amp; 7000 feet above


the ocean - These are what Ptolemy
put down for reasons ^ now unknown as
"The mountains of the Moon"- Large flat
patches of the watershed elevation are


with slightly depressed valleys

^ flat upland forest ^ the trees on which


one or two miles apart on the stems

shew by their branches and the lichens ^
that the prevailing winds &amp; rains are
from the South East - 

Their
There
 are n
No
runnels to guide off the abundant


from the flats
tropical rains - The water sinks into
the somewhat sandy soil until it comes
to a stratum of prime white river sand su
ppor
-
ted on a bed of hardened soft yellow
sand^
stone which being impervious to
water guides the fluid ^ it to the nearest
valley - This structure was found
prevailing in the 
Kalahari Desert

when Mr Oswell and I digged for
water for our oxen in the sucking
places of the 
Bushmen and

Bakalahari

	


Fragment 

of
Original



of
Dr
 Livingstone

s
\'s


Journal 
in 
Africa




	




CXVII note
 The valleys into which the water is 40
led are covered with a thick sward of wiry
damp loving grass &amp; other aquatic plants up
to the verge of the forest - no bushes or trees
can live on the oozing earthen mantle
which supports the long grass and is
itself supported on water and the pearl
white ^ 
river
 sand above mentioned - The 
nearest approach to oozing earthen
sponge is our "Bog" but here we have
no peat nor yet the, in the sun, the
mosses or Heaths from which peat
is formed - The earthen sponge is a
great specific gravity and though
constantly pouring out clear what
water ^ which descends into the centre of the
valley &amp; forms a perennial rill = it is
only when the rains have supersat
urated
the flats and the slopes of the valleys
are so full as to lift up the whole
earthen sponge that the natural
valves by it weight was shut opens

especially the valves at its lower end

and the water of innundation in
all the upland streams is gently let
go - The ensuing floods happen
towards the close of the rainy season
and even after the rains have
entirely ceased the water generally


Then 

is clear - near the centre of all the
valleys on the watershed a rivulet
is formed whose perennial
flow is fed on each bank by 30
or a hundred yards of oozing sponge


Branches ^ rills enter it on all its course
down and these rills &amp; rivulets
are almost innumerable - that
is it would require more than half
a 
mans
man\'s
 lifetime to count them
a 
birds
bird\'s
 eye view of them would
appear somewhat like the vegetation


of frost on our window panes
or more closely the vegetation


	




CXVIII Note
 in 
Canada
 Balsam which mad 42 13
philosophical Instrument makers insist on
putting between the object lenses of the object


glasses of our Telescopes - These are the


the great rivers of

primary or ultimate sources of ^ the 
Congo



Zambesi
 and 
Nile
 - By their union
streams of from 20 to 30 yards broad are
formed and these again converge into
three ^ or four great lines of drainage = Large
Lacustrine rivers = extant specimens
of those which in prehistoric times
abounded in 
Africa
 - The Lakes and


no large river begins in a 
Lake

Lake rivers are not sources ^ but they
serve 
Bosoa = great somewhat the same end as
the cisterns made to regulate the supply
of water in our artificial canals
the natural valves of the watershed
The Lakes and the lacustrine rivers
unite in the important object
of holding back the sudden flushes
which otherwise would follow the
Tropical rains - In other cases 

of this country



small insignificant rivers
suddenly swell = a perfect
wall of water rushes down without
warning and in the memory of
persons still living whole car
avans
of slaves in the chains have been
swept away before they could escape
to higher ground in the immediate
vicinity - Without the 
determining
 restraining
machinery of natural valves and ^ 
Friction

Riverein ^ tons lakes broad above and

^ narrow below - a seven days Tropical
rain would make the grand old


Nile
 assume the character of a 
mountain torrent and rush up
with a "bore" compared to which


	





CXIX. Note
 The "bore" of the Hooeley at 
Calcutta
 43



would - would carry
a mere bagatella ^ carrying destruction or
death on its roaring waters, instead
of as by the kind ^ arrangement hand of Providence
it has done for ^ ages bearing by its slow
majestic swell and overflow fertility
and life to the millions of upper and
lower 
Egypt
 - the arrangement
which has from time immemorial
prevented the 
Nile
 from being a
curse 
always
 also detains a volume
of water tile ^ to be slowly let off sufficient
to supply the enormous evaporation
from a river which with remarkably
few influents in the more arid
part of its course and whose length
measured in Latitude and Longitude
from the sources to the sea is
about three thousand miles -
	


Beginning of Despatch which the Lord
grant I may have to write


I have the pleasure of reporting to
your Lordship that ^ at last I have succeeded in
reaching four remarkable fountains
on the watershed of this ^ inland country in -
each of which becomes at no great
distance off a large river - They rise
from the base of an earthen 

of


land swell of ---
mound which can scarcely be called
a hill as it is only about --- above
the general level It is covered with
wiry grass but neither bushes nor
trees though the country adjacent is all
covered with upland forest - In my letter
of November last year I mentioned
from hearing that the fountains were
not ten miles apart - I ought to have
said not a quarter of a mile apart
for by pacing I found the two fountains
on the North side just about ---


	





note CXX -
 I was not aware of 
Mr
Mister
 Young\'s search trip up 39 
the


Shire
 and 
Nyassa
 till February 1871 but feel
extremely thankful to 
H M
Her Majesty\'s
 Government and
all concerned in kindly inquiring after my
fate - Musa and his companions are fair
average speciments of the lower class of
Muhamadans of Arab extraction on the in 
East




	


Africa - Surampela a chief near 
Loeki
 -


island 
Ibwe
 = 

chipange
Chipange

 another gave



Syde bin Sultan

s
\'s
 people to attack Surampela


 


Lofubu
 river 300 yards by canoe -
300 
at Kimburu ^ 


Chinungwe


 
R
River




Ñanze


by canoe = 
Kansari a
man of Kimburu here today
these chiefs were visited by Rashid
who returned today - country
extremely muddy &amp; full of rills - The


Lofubu
 is a large river 300 
yds
yards
 &amp; deep
crossed by canoes - The 
Nganze
 is
another about 250 
yds
yards
 - canoes 
The captives we met before crossing
here were 

Surampela


Surampela\'s
 people - He is
a great chief - good looking and kind
though he had suffered severely by the
kindred of Rashid - He invited

Rashid to see a cannibal feast by some
of his people who had five victims all 
cut up some pieces roasted and some
boiled - saw human flesh actually eaten


Recieved
Received
 two slaves as a present and
plenty of provisions but no ivory - was
near the 
Loeki
 - the country is called



Ibwe



	



	





CXXI note. 


NKoñgolo
Nkoñgolo

 = deity 
Manyema


	



Hassani
has travelled much
but has a curious idea of the drainage


Lufira
 and 
Lualaba West
 begin 
ftns
fountains

each 3 fathoms broad = 
Lunga
 is
2 fathoms 
Do
Ditto

Hill between the four
fountains about a quarter of a mile
across without trees - He thinks
that 
Lufira
 and 
Lualaba
 both go
into 
Kamolondo
 which he says
is as broad as 
Moero
 - say 20  miles
His sketch confused enough is


Map




He confuses the flow up
and down = says that
another river rises in


Lunda
 which becomes
the 
Lomame
 West
of all 
Lualaba
s and it joins this


Lualaba
 far down


From 
Katanga
 to 
Luivi
 
R
River
 3 days
From 
Luivi
 to 
Charwe
 7 days
From Mpweto\'s to 

Nyembwakunda
Nyembwe kunda


5 days
From Chisabi to Nyembwe Kunda 3 days

Kipeta another 
Lekulwe
 River


Lofuvi
 
Do
Ditto


	



Usambe
 
R
River
 to 
Lualaba West
 from East


Makara
 
R
River
 
Do
Ditto
 Uyawa - Uyawa

Kirira a promontory enclosed

Katapa


From Mpweto to Nyembe 
K
Kunda

 5 days
and 3 from Chisabi Moenye 
Do
Ditto



Kayumbe
 to 
Nyembwe
 a
 6 days


	




CXXII - note

I was not aware of Mr Young

s
\'s
 search
trip up 
Shire
 &amp; 
Nyassa
 till February 1871 
36
but feel am extremely thankful to 
H M
Her Majesty\'s
 Government
and all concerned in kindly enquiring
after my fate - Musa and his companions
are fair average specimens ^ of the lower
classes of Muhamadans in 
East Africa



 for heartlessness and falsehood
The Sultan who knows his people better
than anyone else cannot entrust any
branch of his revenue to even the better
classes of his subjects but places all his
customs ^ 
income
 and money affairs in the hands
of Banians from India and his father did
the same before him - When the Muhama-
dan gentlemen of 
Zanzibar
 are asked
why their Sultan places all his pecuniary
affairs in the hands of aliens they at 

once frankly assert that it is on account
of their almost universal falsehood
and dishonesty - In their case religion
and morality are completely disjoined



ostentatious promises 
dont
don\'t
 imply decency


 Hence the idea of making any sacrifice



 to propagate Islam is to them a farce
and in all their long intercourse
with the natives on the mainland
they have propogated nothing but

syphilis and the domestic Bug - With
the disease they have been 
unfort

unhappily ^ too successful and the wide
prevalence of skin disease and bleared
eyes therefrom in their own offspring
makes it apparent that unlimited
polygamy is no barrier to the spread
of this foul complaint - Neither
Portuguese nor Arabs have sold trade
brandy to the natives - the only reason
I can discover for this great difference
between the East and West coasts is
that they are all too eager topers of it
themselves to carry it any distance


	




CXXIII. Journal = 29th April 1871 Abed
made some more red ink of 



Zingifure
Mzingifuri




for me - This is what I now write with
	


30th
 

chitoka
 here = added up the Rain
fall in 
Manyema
 of 1870-7
1 chiefly at


Bambarre
 = 61-98 inches - at


Mamohela
 it was rather scanty this
year - at 
Bambarre
 very copious -


Confused reports come of the 
traders
trader\'s

men two days distant but on the other
side - Have remained two months -
though sent for a few days - Went to fight
got between two rivers the bridges of which
were cut and several were killed in the
water - no dependance can be placed on
any one - I refused to send my slaves
because they would only add to the con-
-fusion and murder - If they go
anywhere I must go with them or
murder is certain - The loss in this 
case is part of the process of teaching
the Ujijians -"Thou shalt not kill"-


- Saw pieces of a remarkable spotted
fish with scales and tail prolonged
above 
Illustration of large fish.

all those who
come to the market
are eager traders and go off with a little
oil - salt - pepper shell fish and snails
Eels - clarias capensis - Beans
cloth - iron of fine quality worked
to shew its goodness 
Illustration of the spindles at each end of a knob, as described in the next two lines.
 


into long thin spindles at each end of
a knob of metal = Red bananas
appear and the oil is only a string of
beads for about a gallon - the old
women look careworn and anxious


The
They
 carry large loads to &amp; from the 
market The men wear a very
long 
lamba
 made up in folds
like a kilt - the women have the 
worst of it


	





CXXIV Journal 1st May 1871 Wednesday - 34



 Katomba\'s people arrived having 
cossed
crossed



R.
River
 
Lindi
 &amp; reached the 

Babira
Bira

 where they got a
s
much ivory as could be carried away
at 2 rings each tusk - The 

Babire
Bira

 kill
elephants now and brought tusks
for sale by the dozen - they dress the
hair like Bashukulompis upright -
and no quarrel occurred = My friends
here are eager to be off and I am eager for
a canoe - 
Lualaba
 becomes very large
after 
recieving
receiving
 the 

Nyengere

 black
water - six miles at least and it has
forest on each side - From the 


Shamikwa








 

Shamikwa

 it 
recieves
receives
 probably Baker

s
\'s

water - another water still larger
falls into it from the South West - This
probably the 
Lomame
 to which black
traders come to buy oil - an animal
with short horns and large body called

Bangala exists - horns brought =



2nd May
 - send a letter to Dr Kirk by




Moenemokaia
Moenemokia

 to buy no
more goods - but send letters to 
Ujiji

I send three to bring away Abed

s
\'s
 men
from 
Chipange
 but something hurried
up to shew war was meant and I refrain
	



3rd
 Got names of sleeping places
from Mvarawa on to crossing 
Lualaba

onto 
Abire
 - Good people all - no
quarrels with any one - 



Abed says confidentially that a canoe
will come in about 5 days - He is very
anxious to go himself to be first in
the ivory market - says that word
came after me not to help me for I was
sure to die whither I was going - The
wish is father to the wicked thought
They hate me and it is well they do


	





CXXV. Journal
 4th May 1871 -

Kasongo\'s people were struck of a great 
Friend
-
-ship with me came to the market of today &amp;
brought 60 pieces of 
lambas
 = They go

away and promise to bring me knives
and a sword for cloth - the metal is very
precious at the 

Babire
Bira

 - about 2000
people come to market - cassava dried
is exchanged for fish salt and oil = Iron
for 


lamba\'s
lambas


 Brava went 
of
off
 

yeter
yester
-
day with my letters to 
to

 Kirk &amp; Agnes

	



5th
 Heavy rains - Abed informed
me that men had come for goats to
enable them to secure people to drag a
large canoe from the forest where it
has been cut &amp; hollowed out to the


Lualaba
 - this so far is progress but
he needs one or two for himself and
will serve himself first though I
shall have to pay an enormous price
for it
	



6th
 Foggy morning - Men
returned from Chipange when
beads were done - Two killed
slaves without honour or honesty
	



7th
 Raining with rolling thunder
of 
Masika
 - a great body of 
fleecy cloud drifts fast from the
North - The same often comes 

from the 
S=
South


E-
East
. Abed said that
he would give me the first canoe
he got and would tell me the price - 
	



8th
 I promised to lend Abed
half my people if he would come away
as soon as we get the two canoes - 
This would enable him to trade well
even before his own people returned
from the West - was glad of the offer
He has eighty 

frasilahs
 of the
Matunda beads &amp;c strings



	




CXXVI Journal = 8th
 

Chitoka

 = bring a 32
tusk among the 

Babire
Bira

 -  

Zulampela


Zurampela
Surampela



\'s
people went off today homewards - 



9th
 River rising steadily &amp; covering an island


10th
 = the chief Pyanamomba came yesterday
from the other side South West - is of same
family as Kimburu - Abed bought two
and a half 
frasilahs
 of copper bracelets
with cowries = many white birds pass
 North = daily = one is Ibis religiosa
	



11th
 River rising fast and bringing
great quantities of aquatic grass &amp; duckweed
colour of water a little darker than at Cairo
People leaving islands for the higher forest
lands - men brought one canoe down to the 
water yesterday = and the men off trading
on our West are heard of as near - When
they come we shall set off though with only
one canoe - 

Babire
Bira

 very friendly - they

are on this side the 
Lindi
 - The Benya
on the other side use bows and arrows
They are not spoiled yet by the slaves =


A man here told me that he was going
to fight on the West of 
Lualaba
 and eat
those killed - Human flesh said he is better
than 
goats
goat\'s
 - saltish and even peppery - the
people here do not deny cannibalism save
as to people not slain in war - some say
it is not nice to eat their victims for they
dream of them afterwards - they throw away
the heads = Women never partake of it
in any part of Manyema - nor the young -
	


Afternoon Abed\'s people returned
at 2 PM from 2 days distance from 


Lomame
 - with a great number
of slaves and 16 tusks - "My soul is wearied
because of murderers" Abed says they must
be shot down these people - They want
to fight and eat us - great crowds
were slain as population is dense 


	





CXXVII Journal 11th May continued -


Lomame
 very large - Water black - goes into


Lualaba
 below this - People smelt copper
and it is very cheap = They were very civil &amp;
kind to the strangers but terrible fellows among
themselves and at last provoked
an attack in which many of the Bakuss
were killed and eighty captives taken
the s
trangers losing not a man - or
even being wounded - They redeemed their
friends with slaves - ! !
	



12th
 a set in rain from Nor West
did not deter the market today - people
came singing and sheltered with mats
as the copper is very cheap a supply is to
be sent for by the traders the day after to
morrow - 5 days to go 5 to trade and 5 to
return them down 
Lualaba
 - Abed
says he can put the one canoe all to
rights in a few days that is put
thole pins and helm in - He melts
copper tomorrow - I have to submit
and do it as graciously as I can - fine
tastefully wrought 
virambas
 are
made - and coffee comes from
West bank of 
Lomame
 - The people
are very numerous and very handsome
all look better than 

Banyamwezi
Nyamwezi

 -
It is a perfect haul of slaves for all -
	



13th
 people were shot down
though standing in amazement at
the guns as thunder &amp; lightning -
great numbers fell - they refused
passage through their country -
They have coffee plantations and
drink it after eating handing small


cupsful
cupsfull
 to all around - I send to
buy some - It seems good but



driled
dried
 in the fruit rind -


	





CXXVIII Journal 13th May 1871 continued 30
I wrote to 

Moenemokaia
Moenemokia

 to be sure &amp; take all my
goods out of Shereef

s
\'s
 hands &amp; deliver them to 
Moenye-
-ghere
 &amp; 

Syd
Syde
 bin Majid - and should Shereef prove
troublesome to beat him - and s
end him
off for not obeying consul\'s orders - 
afe too
and to send me by some one a sh
irt a
pair of trousers and one 
frasilah
 of


samsam
 beads = If I find them on coming
from the fountains back to 
Lualaba

they will be a boon - If lost no great harm
is done - an armring of copper 1
½
1/2
 thick
for one string of beads - ! Dura Pennis-
-etum
 &amp; maize grown largely - among
the Bakuss - who make 
wale
 but not
porridge of them - they wash regularly
Houses of two stories - little clothing
used - women slaves here have rather
rounded compressed heads but very
pleasant faces - &amp; ancient Egyptian 
round eyes = When they saw guns
they thought that they were the insignia
of the 
strangers
strangers\'
 chiefs - a long staff &amp;
a knob on the lower end blackened
with some medicine being the usual
official staff of chiefs = they feared
the 

Banyamwezi
Nyamwezi

 bows when drawn towards
them but guns taking aim were not
dreaded - their effects aroused mute
astonishment and looking up to the clouds
They use a very long handled spear darting
out from the long grass but keeping it
in hand - Their numbers are prodigious
The country literally swarms with people
save a few patches of forest and great
pools of standing water waist chest and
neck deep which slowly 
drains
drain
 off to the


Lomame
 - Many markets along their
route to which people come from far - 


Marketting
Marketing
 is as great an Institution
perhaps greater than shopping among
ourselves -


	




CXXIX Journal - 14th May 1871 - Men
sent to buy copper on West of 
Lualaba
 and
one man to hasten the canoe - The 
ownrs
owners

said to be sick


15th


In crossing the river Abed found
that 

Hassani had played him false
with 
the canoes and turned right
about to go off down river to the
ivory - I approved of this and
advised him to go and I would
help him to get copper by going up


Lomame
 from the confluence - He
will be nearer the copper mines
than we are now, and be buying ivory
all the time I was up at the copper &amp;
exploring - the canoe is to come to
me today and Abed delivers it to me


a row with two of my slaves
though they can employ Manyema
to bring grass wood everything
with the beads I give - I offered
the two ringleaders their discharge
This damped them woefully =
It is their misfortune to be slaves
and mine to be dependant on them -
the headman who sells the canoe and has


recieved
received
 600 cowries of the price came
today - 
Karenga
 - It has not been
moved an inch towards the water
though he got 3 goats to eat while dragging
it - !
	


16th
 a long talk with my mutineers
refuse to go unless Arabs were in
prow to go 
to
too
 - The loss of wages and
prospective punishment had an effect
as explained by Hassani - I told him
that they were deserting me to be 
recieved
received

by him This alarmed him &amp; made
him earnest in declaring that they
should not remain with him - This
is now blown over -


	




CXXX Journal - 16th May 1871 continued 26

Abed gave me a 
frasilah
 of 
Mantun
da
 b
eads
They alone pass current down riv
er 
have none - I gave him 7 dotis of 

American sheeting - i e 28 yar
ds 
which
is handsome payment - an 
unusually
large attendance at market today - 3000
at least - they catch the live Lepido siren
by the neck and lift him out to see his
size - fish very abundant - Earthen balls
such as is eaten in Safura were exposed
for sale and camwood ground and made
into small flat cakes - There is quite a

roar of voices during all the time of haggling
	



17th
 The disturbance about beads
was all a pretence in order to vex
me - I gave beads to buy provisions
this morning as canoe will certainly
come presently - they let it out that
they wished to go home to 
Zanzibar

This has been uppermost in
their minds all the way to 
Bambarre

and from thence here - They asked a 
writing of permission or a pass
which I refused - I shall wait
for Dugumbe = here as the mud is
excessive in front to the 
Luira
 
R.
River


	



18th
 resolved to take the guns from
the mutineers as bought with my money
in this Abed and Hassani agreed
and said they were all at my service
did not make a noise about it but
my demand was followed by several
wishing to go forward - they are
senseless slaves with no honour


	




CXXXI - Note Journal - 18th May 1871 
contin
continued
 =
a goat so fat it could scarcely walk sold
for a treble string of beads 
Small squiggle that appears to be Livingstone\'s way of signalling that the succeeding text should be inserted earlier in the sentence.
 fattened with
dura 
&amp; pennisetum &amp; given in the village
	




19th

 Abed gave me 200 cowries
and 
40 strings of a greenish bead
very much admired by all here -
advises me to return to 
Ujiji
 as the


Banian slaves are sure to desert
in front - spoke to them to give
up their guns and be gone but
all now professed willingness to go
on so being eager to finish my
work if possible I run the risk and
gave beads to buy provisions - I shall
do a little work and meantime 
Dug-
-umbe
 may arrive and I shall hire
men if he will at a thousand
dollars or £200 - When worried by
these untoward circumstances the

bowels plague me too and discharges
of blood relieve headache and
are as safety valves to the system
which I should not have had if I had
allowed Mr Syme to operate on me

Sir Roderick told me that his father
was operated upon by the famous

John Hunter and died at the early
age of forty in consequence
He himself spoiled his saddles
when a soldier by frequent

discharges from the Piles but
would never submit to an operation
and he is now eighty years
of age -

Turn to other sheet - CXXXII



	




CXXXII Note - the 



Zingifure
Mzingifuri



 with which 29
this is written is declared to be a good remedy
for curing the itch which plagues very
many both Arabs and natives
	


Near 
Lomame
 adultery is punished
by selling the culprit - his wife - Father-
children - a woman here was sold thus
for the crime of her husband = She
was bought for ¾ lbs of beads - They
all wash regularly and are cleanskin-
-ned in consequence - 
dont
don\'t
 know
porridge - all their grain is cooked as
"
wale
" in which the grains do not
cohere as with rice properly boiled -


The men are reckless fellows - one
was trying to sell a bracelet and it
being refused he lifted his spear and
made as if to plunge it into the


strangers
stranger\'s
 chest - "Barter I say" said
he in a brow beating way - This foolish
overbearing way was sometimes ans-
-wered by a ball in the chest and it
was scarcely to be wondered at for
pacific means were by Abed

s
\'s
 orders fairly
tried - presents to the chiefs - payment
of all guides - making friends with
influential men whose influence
was to be used on the 
strangers
stranger\'s
 side but
generally in rain when far into this
country and at last passage was
blocked up and much blood shed
they feared and fled from the drawn
bows of 

Wanyamwezi
Nyamwezi

 but looked at
guns as having no harm in them -
looked up to see thunderclouds in mute
amazement - and did not attempt
to use their very long spears though they
do produce fearful havoc in long grass


	




CXXXIII Note



Thundu
 = an antelope on 
Lualaba
: size of a 
large goat = lokolia colour or skin - Horns
straight &amp; tapering about 4 inches ---




Chobela

 a river which runs into


Kamolondo
 - 3 days from Mpneto\'s





Lualaba

 rises 10 feet above the
present level - 

 
At times
 but
generally about 15 feet -  then with
the water now 15 feet would be
30 feet of depth at flood --- which
is said to occur annually -
	



Maluñgwe a reddish skinned animal


Many white birds flying North 2 Ibis religiosa


10th May - 1871 = river falling fast -
people leaving islands and camping
in higher land of forest
	

11th
 
Kiziwa

 said to be name of 
Lake
Albert








Balegga
Lega


 first after leaving this
then 
Kasongo
 = a large tribe
then 


Baziri
Waziri


 or Wazire
- 
R
River
 

Lira
 - ^ or 
Luira

 black water?
- 
Banayuba

- 


Babire
Bira


 on this side 

Lolinde





Lolinde

 did not cross but


Benya
 with bows &amp; arrows

are on other side
	



Bagenya on other side of


Lualaba
 &amp; 
Lindi
 - 
Lualaba

makes so much Westing that when we
are on other side 
Lomame
 we shall be
about 6 weeks from mouth of 
Congo

but then both 
Lualaba
 &amp; 
Lomame

take a vast sweep back to the Eastward
to fall into or 
recieve
receive
 


L
Lake
 Albert
 water


	




CXXXII - Journal - 

 20th May 1871 - Abed
goes off down river today wisely for ivory
I am hindered by owner of canoe being
sick - a mere excuse I suspect. He says
that when he has sold all his goods he
will give me men and go himself too
to finish my work - I said "Haki a
Mungu" - and he said yes of a truth
I replied then I will give you a 
thousad
thousand

dollars on the spot - this is £200 -
	



21st
 Abed followed his people who
went off yesterday - White is rubbed on the

Manyema fare as token of joy at a birth
or other glad event - black as mourning
It is difficult to realize the state of those who
are utterly ignorant of the world besides
 and have heard no news save spearing
each other - Men cutting paddles

	



22nd
 Headman refuses to bring the
canoe without reason - River steadily
rising - colour darkening - wreck less



a young woman slave passed the word
all the others from 
Kuss
 near 

Lomame

 to
save their porridge and meat and with it pay
their passage across 
Lualaba
 and escape - It was
discovered and all are enchained this morn-
-ing - People came back from Abed for
some others who ran away - The slaves are
big strongly built men and women much

aspersion to the 
Zanzibar
 freedmen - 
Illicit intercourse is the general course that

reduced to slavery = and women tempt
men more openly than anywhere else
I have seen - save in the Haymarket
	



23d
 a party came today from 
Mamohela

to get a fresh haul of the ^ Bakuss slaves 


Babire
Bira

 ivory - Dugumbe
is conjectured to be near to Kasongo\'s -

Hassani says that we shall get canoes
and seems confident - The party West 


of this 
will return 7 days hence - 



	





CXXXIII Journal - 24th May 1871 
23
Market or 
chitoka
 a busy scene - every one in
dead earnest = little time is lost in friendly greetings
Then the vendors of fish run about with potsherds
full of snails or small fishes or clarias dried or
fresh and exchange for cassava steeped &amp; dried -
potatoes - vegetables - grain - bananas - flour -
palm oil - fowls - Each is intensely in
earnest for food or relishes as salt -
pepper and all make strong assertions
as to the goodness or badness of the articles
for barter and makes the sweat stands
in beads on the face and body - ^ 

squeeling
squealing

 pigs &amp; iron

^ 
knives
 are changed for cloths - some hide their 
wares in the large wicker funnel above
the basket but smile if I shake the finger
at them - a woman let fall a piece of


bassava
cassava
 which was shivered into twenty pieces
then demanded another piece I looked at
her and it was so manifestly unjust that
she laughed as I told her to take up her load &amp;

be gone - They appeal to each other in these

cases and have a natural sense of justice
About three thousand attended - many from
far - and much benefit is derived
The men flaunt about in gaudy 
lambas

in many folds kilt fashion = The women
work hardest - The potters slap and sing
their wares all round and invite buyers
to use their eyes as well as their ears in testing
their value - I bought two fine porous
earthen bottles of about a gallon each
for one string of beads - The women carry
huge loads on their backs strapped to the
shoulders and forehead = hands full
besides - the roundness of the pottery
is wonderful seeing no machines
used - Girls sell cups of water for a few fishes
	



25th
 making two shirts -



26th

S
Saturday
Sunday

The canoe bought by Abed
is not  the property of the vendor 

and the real owner refuses the
slave of Kalenga so the affair stands still =
and excuses are made of sickness &amp;c -

Hassani recommends seizure of


the canoes as no ing can 



	







CXXXIV


27th
 Journal


Several headmen came with a present of
two slaves to prevent a war which they have
fancied to be impending - assured that
no attack is intended they 
dont
don\'t
 believe it
When we force them to land canoes they
will conclude that they were right in their
fancy - I have been two months trying to buy
a canoe and now bamboozled by this head-
man\'s false pretences of ownership no
other headman will even remonstrate - All
knew that the trader was plundered by Kalenga
but no one would let us know - a very
strange people - Katomba\'s slave buyers
went off this morning across 
Lualaba


	



28th
 Hassani declared that since
he came here not a banana or bit of
cassava had even been presented to him
Market I generally visit to see the fish
and people one man offered me a few
small fish - another a sweet potato &amp;
piece of cassava - then a third 2 small
fishes - but 

manyema
Manyema

 are not liberal
saw a man with ten human jaw bones
strung over his shoulder - Asked if he eat
the flesh - yes and taking his knife he
said I cut up a man this way - I expressed
disgust at which he and others laughed
see many strange people every time I go
Two nice girls were selling 
Gumbe
 or
roasted white ants -
	



29th
 

Mologhwe
 Dambo &amp; two others
came to mix blood with Hassani - It is
simply a small incision made on the
arm &amp; blood from each rubbed on the spot
He says that he has promised him ten
canoes to be brought as soon as the copper
party under Manilla comes back to us
	



30th

River has fallen four inches
within the last four days - colour black or
very dark brown - considerable quantities
of wreck still float down -


copper 
safari
 returned today as
was appointed = successful -
brought a little coffee and vanilla



	






CXXXV
 
31st
 Manilla
 got fo
ur 
frasilahs
 of copper
bracelets 35 + 4 = 140 
lbs
pounds
 - brought specimens
of vanilla pods which the natives mix

with their coffee - How they know to
manipulate the flowers - Wisdom
dwells not with us alone = conceit of it does
	



1st June 1871 - Saturday
 = 
chitoka
 -
This being the Arab unlucky fifth
month our departure is put off to the

first of 6th month nine days hence

Manilla came yesterday from copper
bought 4
½
1/2
 
frasilahs
 = Brought me
4 
lbs
pounds
 of coffee unhusked or still in the
fruit find and dry - a day pot went
for six plantains = small shrimps for sale



2nd
 Hassani goes over 
Lualaba

today to speak about canoes - He is
confident of getting them - I am not -

Manyema are so untruthful it
will come to seizure yet - But they
are very honest = we never lose an
article by them -



3d

We had a discussion with

Hassani about these wretched 
Banian
slaves and he denies complicity with them -
He meant to speak only of canoes not going far
not them though he spoke distinctly of my
return in a short time with him when he
had got his ivory - The slaves too protested
that they never refused to obey me!! = though
they asserted that all declined to go further
the threat to take the guns alone cowed them
apart from this they were pleased with the
prospect of plundering Manyema and
getting slave by this means = Send
men to speak about the canoe -
	



4th
 I send five men to speak to the
headman Kalenga and to demand either
the canoe he sold or two others or the
thousand cowries - three goats and beads
they are ordered to speak only and speak
much then come away - Kalenga 
cooly
coolly

says "Wait till Abed comes back and I
shall return the goods to him" - this is
childish but like Manyema - He was
told by Abed in the presence of two
headmen that he had given the canoe to
me and Kalenga was at once to deliver it


to them on my account - He had it not!


	





CXXXVI Journal =
 5
th
 June 1871
men delayed for want of a canoe to ferry them
across - 

chitoka

 today brings many - 
The
They

speak to him only but must I fear seize
canoes for there is no honour among them
I have been here for two months negotiating
for one and after paying an exhorbitant
price find that I am the victim of deliberate
falsehood = Hassani was all day yesterday
talking to those who promised canoes and
he will get none = No one can 
concieve
conceive
 how
they dawdle and lie to get goods they mean
not to pay - The feeling of importance imparted
by haggling with strangers is dear to their hearts.
	



6th
 Mokandira\'s child died so we
are again hindered from going = Market
people beaten and plundered I paid
some who were robbed by my men slaves
I am sick at heart in knowing of these
outrages = Manyema are bad but slaves
ten times worse -
	



7th
 hindered by canoe though paid for
being given to another - I fear that we must
march on land which in front is extremely
wet and muddy -



8th
 River rose again six inches and
then fell three = water very dark brown &amp;
much wreck - duckweed &amp; grassy islands
float down = Rain nearly ceased = Great
masses of cloud float down from 
Nor
North
West
but more frequently go up from 
Nor
North
East -



9th
 Men went yesterday afternoon
to Kalenga - He refuses to refund the price
of the canoe to anyone but Abed = tries
to draw the real owner into a scrape by
complaining that he refused his slave as
price of the canoe and goats too = We have
nought to do with that and Think it best to
retire and let Abed punish him ^ if he
likes - Hassani\'s canoes not come =
so we go on foot day after tomorrow
It is very grievous to be cheated after
losing nearly three months in the business
but Kalenga has no canoe and I must not
be the first to do what may be called injustice
The Arabs would like to see me using force

Dugumbe delays strangely but probably
by his divination declaring all this month
to be most unlucky - 
Wends
Winds
 tonight =

Arab fifth month - Lord help me


	






CXXXVII Journal = 10th June 1871


New moon not appearing last night
prevents 
safari
 from starting tomorrow - 20
It is dangerous for a small party to go if
like mine cowardly &amp; mutinous = No
one visits villages three miles off on account
of floods 


 which never end = No canoe
can be got for love or money = mixing the
blood makes no friendship so I decline
it when invited - Arabs do it with all
who have power but the Manyema do it
to get presents of beads and perform no
other duty of friendship = Elsewhere one
becomes a member of the family and
his safety is ensured by information
against all enemies in the country - Here
all knew Kalenga\'s falsehood but were
silent!
	



11th
 New ℂ last night - Dugumbe will
leave 

Kasongo

 today - we leave on the 14th


Hassani over river for canoes but probably
in vain - River fell three inches in
the last three days - Much wreck floating
down - water colour of strong tea =
	



12th
 Hassani has got 4 canoes and
hopes to get seven = the conduct of Kalenga
to me is not be endured - It is the most
childish impertinence because he thinks
nothing will be done to him but talk as

Manyema do &amp; have done for ages -
I send my men tomorrow to demand
either canoe or goods and to bind
him in case of refusal till he delivers
the one or the other - then buy a canoe
and return with it = that the owner of
the canoe he sold without leave refuses
the woman he sent to buy with is to his
dark mind a sufficient excuse for
delivering neither money nor vessel
I must wait for Dugumbe for I have
no powder and but few beads === He
will be here by the 20th 
currt
current

 =
	



13th
 
chitoka
 = men off to force Kalenga
to reason = if he refuses to refund to
bind and give him a flogging - if It is
entirely lost then return and get
of my beads to buy another canoe
down the river - Kalenga fled -


	




CXXXVIII Journal 14th
 Hassani got nine
canoes - In 3 he put 63 persons - I shall
send down the river on the left bank tomorrow
to try and buy one - 
Safari
 off this morning
High winds have begun from South East and
shew cessation of the rains = Every thing
is drying as soap sugar mud &amp;c
	



15th
 canoe sent to get medicine for
a sick wife - detains us today - I paid for
both medicine and canoe = and on



16th
 got the men off very doubtful
if they will succeed in buying one for
all of them imitate the overbearing
manner of 
Zanzibar
 slaves




Safari
 comes back from West with 2
100
slaves 200 or 300 cowries per slave or 11-10
bunches of beards per head that is about 50
single strings about a foot long each =
River fallen a foot = Dugumbe near but
detained by his divination
	



17th
 stragglers come in from Dugumbe
\'s
large camp - My people reached 
Tambu


yesterday and will get a canoe if they only have
a little common sense - a note from

Palamotto says letters have come by Governor
for me and are at 
Ujiji
 = If I get a little
powder from Dugumbe &amp; the canoe comes
I shall be ready to run down the river
	



18th
 The Arabs of Dugumbe\'s party saw

Shereef flourishing about my valuable
chronometer watch on his dirty body
This is like to break my heart - I have
no chronometer going - I suspect the
Longitude of Baker to be all wrong but
cannot correct it - Dugumbe has
passed a short way down 
Lualaba
 to
build his Mosemba or dwelling place
	



19th
 Heavy shower at 4 AM - last 19th
of June finished the rains - Dugumbe goes
West to 
Lomame
 and across it when
his station here is built = this will open
all 
Lake Lincoln
 for he has an immense
party = 500-600 guns as Ujijians count
and is fond of going into new fields


	




CXXXIX Journal = 20th June 1871 - Two
of the party of Dugumbe brought presents of 
19
four large fundos of beads each = I am
waiting for my people and canoe. Katomba\'s
people came back from the West yesterday
well satisfied with fine slaves cheap -
I look  on the drove they brought un-
chained with a sort of pleasure after
looking at many not traded for but
murdered for - 
	



21st
 Dugumbe found it best to
come back to the 
chitoka
 here - He says
that he will buy me a canoe if my men
fail in getting one = This stirs up Hassani
and Manilla = who might have
got a tenth for me with their nine
	



22nd
 Visited Dugumbe = He sends
back to 
Ujiji
 two months hence and
I shall send then for goods - and
make it a point to come back here
	



23 = a touch f
of fever first here
	



24th
 better and thankful = the

Bakuss have flat Egyptian feet
women\'s round foreheads and the
rest of the head slopes backwards
and upwards = a stout built
race both men and women good slaves
	



25th
 Hassani\'s son circumcised
caused a feast
	



26th
 Hassani\'s boat party foiled by narrows
4 days down - a canoe tilted over &amp; 5 lives lost


Banian slaves come back - people all
fled and blamed Kolokolo\'s men for
killing and stealing their relations - p

follow another te for Hassani\'s men

were shot at in the rapids with arrows &amp;

Kolokolo\'s deeds blamed - Oh horrible!!
	



27th
 a cataract on North side of the


Luamo
 prevents my going up the
river to 
Kamolondo
 -


	




CXL. Journal 27th June 1871 continued
It is in answer to my prayers that I have
been mercifully prevented from going
down river for I would have been the
leading canoe into the narrows and it
is said cataract beyond the entrance
a dyke of rock cuts across country &amp;
the two points of it a little ajar cause
the enormous mass of water to wheel
behind one and make a whirlpool
in which canoes are carried round &amp; round
helplessly - Had we gone down 
Luamo

as I wished the same danger would have
been incurred = I now go across to the


Lomame
 - buy a canoe there and go up
to 
Katanga
 = It is probable that the Dyke
down river runs across into 
Lomame

so even if past the first narrows we
should have others to ascend in 
Lomame


	


I wrote to 

Moenemokaia
Moenemokia

 to take
my watch from Shereef and keep it till
a safe conveyance turned up - and
as Shereef used monthly 3 dotis calico
for himself - 2 
Do

Ditto
 for his woman 2 
Do

Ditto

for each of his slaves besides beads and
knew he was breaking 
consuls
consul\'s
 orders - he
was to be delivered to the Governor for Seyed
Majid = I 
dont
don\'t
 know whether 

Syed
Seyed
 bin 
Majid will do as I say but all will see that
I feel very sore as to the watch and that
I am without one to measure distances
and position = Shereef brought 8 cases
of brandy for his own use and made
my porters carry it so I paid for the drunk-
ards swill = I asked also why he had
destroyed the consult\'s packet containing
the list of goods &amp; notice of the watch - 
I shall send by Dugumbe\'s people for my 
goods and will come back here to 
recieve
receive

them


River fallen 3
2 feet - dark brown water
and wreck still floating down


	






CXL
CXLI
. Journal = 27 June 
cont.ed

continued
 

Kauzene
Kanzene

 = 
16

gave a 
Zouady
Zonady
 of beads

Kisingite above as well as below this
so I go west to 
Lomame
 &amp; probably
escape the basaltic dyke if it goes so far
West
	



28th
 eight villages in flames on the
other side 
Lualaba
 = The Bagenya
are seizing the country of Mohombo
and all the straggling people of this 
camp are over helping on the

begun by 
Manilla Syde Habib\'s slave
work of destruction ^ and catching slaves
or rather free people to be made into
slaves = nothing surprised me more
in England than the numbers of
persons met with who would
fain be slave owners - Persons
of the seedy scribe class asked
with an air of concern Will the
Africans work? Yes if you can
pay them = the lengthening of visage
caused by this answer told as
plainly as looks can tell that seedy
had speculated on gratuitously
employing the labour of others
though it was evident that he
sorely needed to be employed him-
-self in something else than penny
a lining = The Bagenya
are fishermen by taste and sell
the produce of their nets &amp; weirs
to the other tribes who cultivate
the soil at the different markets
	



29th
 Manilla\'s foray burns ten


village
villages
 for a debt of 3 slaves
whose price he advanced =
The villagers are our market people


	




CXLII. Journal 30th June 1871

1st
 July = Sunday
 = Went to Dugumbe and told
him my plan was to go with the 
safari
 he
sends West to 
Lomame
 - then buy a canoe
and go up the Lake towards 
Katanga

visit the excavations and return to this
place if he would get his people to bring
some of my goods from 
Ujiji
 = He
said that he would write out my order
that the natives here and on the other
side had been poisoned against me
I know that this is the case but have
kept quiet - The Muhamadans are
unmitigated Liars and say that "I 
dont
don\'t

want slaves nor ivory but I want to 
kill people" and they persuaded them 
not to sell a canoe to me but let them
have all = Hassani knows it all =
but swears that he does not join in the 
slander and did not know of Manilla

s
\'s

foray = pointing up to Heaven = &amp;c &amp;c
The falsehood of Muhamad has been
transmitted to his followers -



2nd July 1871 = The upper stratum of
clouds is from the 
NorWest
NorthWest
 = the lower from
the South East - When they mix or change
places the temperature is much lowered
Morning fogs shew river to be warmer
than the air
	



3rd
 
Safari
 of Hassani off down
river and on land entirely - Leaves the 
unfortunates who turned back after;
actually reaching the ivory = gave him
and Abed hints as to meeting with Baker

s


to report themselves and me to the head
of Pasha Baker

s
\'s
 expedition &amp; not flee -
	



	




CXLIII Journal - 4th July 1871 = ill



5th
 Dugumbe promises assistance in 
14
buying a canoe at 
Lomame
 = and
powder = says what I know otherwise
that the 
Banian slaves have been
chief propagators of the slander
among the Manyema that I "wanted
no slaves nor ivory but only to 
kill people"- Susi - Chumah
 hear
it all and remain quiet = Dugumbe
has nearly finished his house and


Safari
 is to be on 9th
 or 10th
 =
the 
seconday
second day
 of the New ℂ Fungo 7 -
It is not open refusal now but secret
villany and slander I have to
contend against in the 
Banian slaves

	



5th
  River fallen
3 feet in all - that is one foot
since the 27th June = dark brown
	



6th
 consult Dugumbe &amp; offer
1000 dollars for other attendants =
kill a Tassa goat = I am unable to
buy any by Shereef

s
\'s
 villainy =
	


6th
 
con.
continued
 Mokandira and other head
men of 
Nyangwe
 came with a
pig - also goat as a present on
my going away - I refused
till I come back and protested
against the slander about my
wishing to kill people = this will
be widely reported =
	



7th
 woman reproved for
beating a slave frequently came and
apologized and we made friends

again telling to speak softly as
she was now the 
slaves
slave\'s
 mother
slave came from beyond 
Lomame

and must have been a lady


	




CXLIV Journal - 8th July 1871 -

Kimburu comes to mix blood with Dugumbe
today and will give him 3 or 4 slaves - He has
performed the ceremony with four traders and
seems anxious for peace and friendship
	



9th
 Dugumbe advised explaining
my plan of going to 
Lomame
 &amp; thence to


Katanga
 and excavations to see what the


Banian slaves will object to - I did so
this morning but no remarks were
made - these may come at River only
and stop me again = they only participate
in the Arab slander - I am the pioneer
say they others will follow and kill and
take the country - What can the poor people
do but believe the Moslem lies - the Lord
open the way for me =



River fallen three inches since 5th
 

curt

current


	



10th
 Manyema children do not 
creep as do others on their knees - 
but begin by putting forward one
foot and using one knee = I have
seen a child use both feet and the
hands but never the knees = !!


New ℂ last night = 7th month of Arabs

Many guns fired at blood mixing
	


11th
 
Chitoka
 = bought ten different
species of small fish and sketched
eight = most are the same as on


Nyassa
 = a very active species of
glanis of dark olive brown colour
was not sketched but a spotted
one with offensive spine on back was
Sesamum seed abundant now =
and cakes of pounded ground nuts as 
on the West coast = the new comers
have been taught by the market women
to deal fairly and not overreach them
they are certainly clever traders and
prefer dealing in the market to any
where else = there they are in countenance
by each other


	





CXLV - Journal 12th July 1871 - 
13
The 
Banian slaves told me that they
would go to 
Lomame
 but no further
This I suspected would be the case - 
I report to Dugumbe and if he does not
help must go back to 
Bambarre
 and
send to 
Zanzibar
 for other people
I am fairly in the power of the


Ujiji
an slaves - Shereef destroys
my letters = the Governor does
the same to prevent evidence of
his plunder going to the coast
Lord help me - When told that
they would lose all their pay they
said they would not lose their lives
and would be employed by others &amp; get
more pay = Dugumbe will speak to 
them -
	



13th
 Dugumbe came and spoke to
the 
Banian slaves = They profess to
wish to go back to 
Ujiji
 to bring

Shereef as a leader - They have no
one to beat them say they or order
them = The upshot was that they refuse
to go and it was well to let Dugumbe
hear them say we "Hawezi" are
unable = non possumus =
I then said to Dugumbe I have goods at


Ujiji
 I 
dont
don\'t
 know how many but
they are considerable = Take them all
and give me men and if not enough
I will add to them = only 
dont
don\'t
 let
me be forced to return to 
Ujiji
 so
near the end of my work - He said
that he would consult his company
and form a plan =
	


14th
 Dugumbe consulted his
Arab company and one Adie said
to me your slaves are very bad shewing
that Dugumbe had given a truthful
account of them = I am distressed

&amp; perplexed what to do so as not
to be foiled but all seems against me
			
			
	




CXLVI Journal = 15th July 1871

The reports of guns on the other side
of 
Lualaba
 tell of Dugumbe\'s men
murdering Kimburu and another for
slaves = 
Manilla is in it again = and
it is said that Kimburu gave him
3 slaves to sack the ten villages we
saw in flames - He is meeting his doom
in spite of mixing blood and giving
nine slaves for the operation =

Moenemgunga was his victim = &amp; so
it goes on making me fear to go
with Dugumbe\'s people to be partakers
in their blood guiltiness




Chitoka
 about 1500 people came
though many villages were burning
before us = I saw three of Dugumbe

s
\'s

people with guns in the market place
with wonder but thought it ignorance
and retired - when 50 yards off two guns
were fired and a general flight took
place - goods thrown away in terror
firing on the helpless canoes took
place = a long line of heads in the water
shewed the numbers that would perish
for they could not swim two miles
shot after shot followed on the terrified
fugitives = great numbers died -
and a worthless Moslem asserted
that all was done by the people of the 
English - This will spread though the
murderers are on the other side plundering
and shooting - It is awful - terrible
a dreadful world this = as I write
shot after shot falls on the fugitives
on the other side who are wailing loudly
over those they know are already
slain = Oh let thy kingdom come =

	




CXLVII Journal - 15th July continued 
11
The canoes were all jammed in a creek at
the bottom of the market place
and the owners could not get them
out - women threw away their
produce and scrambled for dear
life - men left their paddles in dread
as the merciless fire was rained
upon them by other men who must have
been cognisant of the plan of Murder
The women soon sank into their watery
graves - I counted 33 canoes afloat + 19 still in the
creek

one capsized - some overcrowded so as
to be logged in the stream without paddles
one long canoe that could have held
30 was occupied by one man who
seemed to have lost his head - others
paddled fast to save the sinking till
in danger of swamping - no one
will ever know how many perished
in this bright summer morning
All the camp people set on the land
comers &amp; plundered them = Women
were carrying loads for hours of what
the water comers had thrown down

Manilla\'s brother was over at one
village of a friend - I sent men to
rescue him with our flag to
protect them for Dugumbe\'s
people are shooting right and left &amp;
without a flag they might have been
victims - I count twelve villages
 burned this morning = this with
the previous ten makes twenty two -

Dugumbe wisely objected to my
men going to rescue the brother of

Manilla - He would send his own
men who were known to all the 
fighting crew = -


	




CXLVIII Journal 15th July continued
I went over to Dugumbe and proposed to
catch the bloodhounds who fired in the


chitoka
 and on the canoes and put their
heads on poles = He declared it was done
by Manilla\'s people to destroy the market
Eighteen women and a man had been
taken out of the water as they scrambled
along the long grass on the water\'s edge
I got them to frank them back to their
friends and they slept at our camp waiting
for their friends to come and claim them
the other Manyema would charge for
their redemption so I manage all for
them myself - Four came and claimed
the saved ones and of course got their
relatives = In 
Manyema
 war the market
women are never molested - these
Moslems are inferior to them in sense
of justice and right = I write names
of the women and the husbands who
claim them so that if deception is
practised we may know them
	





16th
 = liberating captured
got them all into the hands of husbands
and friends - one had a ball shot through
the thigh - a pretty woman = the canoes
are to be delivered to the owners too -


A 

manyema
Manyema

 man said to be murdered
by one of Dugumbe\'s people after finish-
ing a piece of work = said he was tired
and refusing to do more was killed by an
axe - friends came - cried over and burned
him -



12 
AM
PM

 Dugumbe\'s people shooting
people on other side 
Lualaba
 = set
fire to a village on bank = many
captives caught on other side river


	




CXLIX Journal 
10

1 PM The marauders are returning in
canoes and firing their guns beating
drums and doing all they can to say
"see the conquering heroes come"
They are answered by the women
lullilooing and friends in Dugumbe\'s
camp firing guns of welcome = The
smokes of many villages ascend
straight up and form clouds above
I count seventeen villages in flames
and these of our market people =

Dugumbe says that he did not send
this foray - and Tagamoio the head of
it says that he went to punish the
friends of Manilla who being a slave
had no right to make war &amp; burn
villages - 
Manilla confesses to me
that he did wrong in that and loses
all his beads and many friends in 
-


consequence
	


2 PM
an old man called Kabobo
came for his old wife - I asked her
if this were her husband she went
to him and put her arm lovingly
round him and said "yes" I gave
her five strings of beads to buy food
she bowed down and put her fore-
-head to the ground as thanks and
old Kabobo did the same = The tears
were in her eyes as she went off
	



Tagamoio
 has caught seventeen
women = or say by his party

the captives by Arabs = 27 ----
Dead by gunshot = 25 ----
2 heads of chiefs brought over
to be sold to relations


	




CL Journal 16 July
drowned 5 men &amp; women ^ of 
Ñomba

 numbers unknown
of 
drownd
drowned
 in river of the people generally
They can only be spoken of as by hundreds



4 PM went over to Dugumbe
He had a number of headmen and made
them mix blood and promise to bri
ng
market people - Tagamoio kept out
of sight - this open murder fills me
with unspeakable horror = and I wish
to get away from it = I cannot go
in Tagamoio

s
\'s
 company and must
either go up 
Lualaba
 or down which
ever my 
Banian slaves choose - It
is a great affliction to have such at all



17th
 Went over to Dugumbe and
spoke of my plan = 

Muanamosunba
Muanamosimba


denied that 27 people were captured
only ten but why ten? and of our
best friends = the market people = I
spoke of my plan as he advanced no
other = I cannot go with Tagamoio\'s
murderers = the 
Banian slaves say
that they would go only to 
Lomame
 and
then return - it would not be possible to 
force them beyond that for whatever the

Ujijian slaves may talk they all
hate to have me a witness of their blood-
-shed and would connive at the desertion
of my slaves = Tried to go down 
Lualaba

and up 
Tanganyika

but that too was
objected to It remained only to go up river
and on to 
Ujiji
 = Dugumbe asked them
why they refused to go = answer "Afraid"
then you are cowards -"Yes we are" are
you not men = 
Ans
Answer
 -"We are slaves"
I said that I was glad that they


	




CLI - Journal 17th July 1871 continued 
12
confessed it before Dugumbe = they
would lose all pay - I had entreated them
not to throw it away but if not theirs
no wonder they care not for it - At
last I said that I would start for 
Ujiji

in three days on foot = All asked here


t to be ashamed to ask beads or


anything else they possessed but


said that I had enough for going
back to 
Ujiji
 to get other people - 
It is a sore affliction forty four 
days back or 300 miles at least
45 days and all after feeding the slaves 
	

Series of calculations on the left-hand side of the page.

	
for twenty one months -
but it is for the best - though
if I 
dont
don\'t
 trust the riffraff
of 
Ujiji
 I must wait for
other men at least ten
months - I shall go through


Rua
 - see the excavations
first and then the four
fountains and after
that 
Lake Lincoln





18th
 the murderous
assault on the market people
was Hell without the fire
and brimstone = it brought
on headache which might
have been serious had it
not been relieved by a 
copious discharge of 
blood - I was held up all 
yesterday afternoon with


the impression which the
bloodshed made - It filled
	
me with unspeakable horror


Dont
Don\'t
 go away say the chiefs
but I cannot stay here in

agony -


	




CLII Journal 19th July 1871

Dugumbe sent me a fine goat 
2
a maneh of gunpowder = 100 of
fine blue beads and 230 cowries
as good in the way = I proposed
to leave a doti 
merikano
 &amp; one of


Kanike
 to buy specimens of
workmanship - He sent two 
very fine large swords and two
equally fine spears and said that
I must not send anything =
and would buy others with his
own goods = I sent one piece of 
Kanike

and one ^ doti of 
merikano
 as he has
no cloth and is very friendly
no action as to the captives = 
	

	


Calculation.


	
	

= River fallen 4
½
1/2
 feet
in all = since 5 

ult
ultimo



one and a half foot

	
	


Few market people appear
today - formerly they came
in crowds - a few came from
the West bank with salt to buy
back the baskets with which
they and others carried food
for sale = about 200 came
in all chiefly of those who
have not lost relatives - seven
canoes instead of fifty - an
old established custom has
great charms for this people
if no fresh outrage is committed
it will be re-established
No canoes come into the creek of
death but land above it at


Ntambewe
\'s = Pack up to start 20th




	




CLIII Journal - 20th July 1871 
15
Start back for 
Ujiji
 300 miles - 
off - One doti 
Kanike
 to Susi

2 Dotis 
Merikano
 to 
Do

Ditto
 for wife
	


 made but a short march
as I have been long inactive
and it is unwise to tire
oneself at beginning of a
journey - one does not
get over it - one man
detained by sporadic 

cholera which seems to 
be serious
	


21st
 waiting to see what
turn the sickness may
take = if favourable will
leave him with Dugumbe

Dugumbe came over to 

advise me not to wait
for the sick man but
leave him to his care = It
was not altogether on the 
sickness I waited - I
was told falsely about
him while my slaves
were negotiating for
women with whom
they cohabited - Dugumbe
advised haste which I 
am only too anxious to
make and to travel in a
compact body as stragglers
are cut off - He lost a 
woman and his party
seven people in the 



	




CLIV. Journal = 22nd July 1871 off
at daylight about six miles to
village of 
Mañkwara
 where I
spent the night in going - the
chief Mokandira coveyed us
thither = promised him a 
cloth if I came across from


Lomame
 = wonders much at
the underground houses - 
never heard of them before I told
him = many of the rivulets
and rain gullies dried up
grass burning going on = I
heard sporadic thunder today
and a few drops of cold rain
fell = same sprinkling yesterday



23d
 
Will
We shall
 reach 
R.
River
 
Kunda

tomorrow = 24 crossed it = 50 
yds
yards

in two canoes then went up into




LaBango
LoBango



 = crowds followed all
anxious to carry loads for beads
several market women saluted us
In going from 
LoBango
 to the


Nyangwe
 
chitoka
 and back they
about 25 miles in one day
with heavy loads such as no 
slave would carry =

The most High speaking in 
Exekiel
Ezekiel

of 
Jerusalem

says I put of my come-
liness upon thee = If he does not put
of his comeliness on me I shall never
be comely in soul = If he does not
impart to me of his goodness I
shall never be good - but like
these wretched Arabs in whom
Satan has full sway - the god of this
world having blinded their eyes -


	




CLV - Journal = 25th July 1871 
17
we came over a beautiful 
country yesterday - a vast
hollow with much culti-
vation is intersected by a 
ridge on which the villages
are built - the path runs
along its top and we see the
fine country all spread out
below with different shades
of green marking the plantations
this great hollow is drained
by the 
Kunda
 = into 
Lualaba

Today we descended into
another hollow drained 
by the fast flowing 

Ka-
hembai

 into 
Kunda
 then
on to another ridge with
a great many villages
burned off by Matereka\'s
foray - The We met the horde
climbing up on to the ridge
as we went 
N W.
North West
 They
slept on the ridge and
next morning in sheer
wantoness set their lodgings
on fire = The slaves had
evidently carried the fire
along and applied it to villages
in their route - It was done
only because they could
do it without danger - 
and it was such fun to 
make Mashenebe houseless

	





CLVI Journal 26th July 1871 -
came up out of the last valley of
denudation drained by the 
Kahembai

and then along a level country
Met 4 men in hot haste to
announce a woman\'s death.
Two died lately North &amp; two South
of this of dysentery or some
disease of Abdomen = Pleurisy
common from cold winds of the
North West - Twenty two men
with large shields came to carry
the woman\'s body and all her
gear to her own home for burial
about twenty women followed
them &amp; the men waited under the
trees till they had wound up the
body - The women of Kama
in large numbers went to weep
for her smeared their bodies
with clay - The relatives put
soot on their faces and shields
	



27th
 left Kama\'s and soon
through many groups of villages
of Kasongo welcomed by Matereka

Syde bin Sultan and another
bought two milk goats reasonably


28th
 rest 29th Sunday rest

Matereka sends a party to 
Ujiji

with me for goods this will
increase our safety among
the irritated people between
this and 
Bambarre
 = It is
colder here than at 
Nyangwe


Kasongo is off in the forest 
N.
North

of this guiding a party &amp; buying
ivory when he can for himself
			
			
	




CLVII. Note 
Manyema
 
Nyangwe
 = 18

12 July 1871 = our statesmen seem to have
come to the conclusion that Railways
and Telegraphs will be better managed
by the Government than by private
companies - The reasons for that
seem to apply to the Great Newspapers
as the "Times" which are certainly
not so well managed for the safety
of the nation by private anonymous
contributors as they would be
by the agents of Government
both 
angency
agency
 and public official
being responsible to the country
nothing could be more dangerous
to the welfare of the country than
pigheaded effusions of a secret 
con-
conclave



or club frequenters
clave indulging in merciless vi-
-tuperation against Louis Napoleon
who in spite of the extremest
abuse which could be raked up
against him in ^ specimens ancient &amp; modern

railing has proved himself to be
a wise and able ruler - a true friend
to 
France
 and a good ally to 

England


Then again the Times laboured to
misrepresent the Northerners in
th
e
great Black war - It was
t our great misleading Journal
and the utmost efforts of our
statesmen were required to prevent
the b
lightful calamity of a war
with the United States which was
imminent through the 
hole
whole
 and

corner machinations of irrespons-
ible penny a liners = Every Northern
victory was noticed with the in-
sulting insinuation that it must
be remembered that the account
came through Northern channel
s



	




CLVIII Notes = Southern successes
were issued without any such damaging warning
Why were Englishmen kept in the dark as
to the steady crushing advances of the North-
ern army on 
Richmond
 while the 
Journal Des 
Debats
Débats
 gave truthful
news of the War - Simply because
the ruling power has influence in


France
 which Government unfortu-
nately does not possess in 
England

them who can tell the harm done
to our name and arms by divulging
all the secrets of the Crimean war
This led to a compromise in the 
suppression of the Indian mutiny
by which the irresponsible con-
-clave brought the Indian command
to its knees - Is it for the honour
or dignity of 
England
 that this secret
Inquisition should be tolerated
Is it not a fact that the Times of
late years is always in the wrong
always on the losing side - Nothing
could shew the need of guidance
from a superior power than the late
affair in 
Jamaica
 - The Times
talked and railed but the 
Govt

Government

aware of the outrageous legis-
lation that inevitably led to the 
outbreak applied the common
sense remedy by abolishing the
legislative assembly = We English
have been so accustomed to feel
proud that by the freedom of the
Press our rulers could be bearded
that we 
we

 have allowed a secret
Inquisition to ride roughshod
over all law and order and 
make itself supreme in defiance
of dignity and common sense
			
			
	






CLVIX
CLIX
 

Note Journal Note
 The foregoing
Note to be amplified &amp; sent to the 21
"Times" in laughing forebodings of his
awful-ire-Jupiter 
tonans





Journal some Manyema are
going with us to 
Ujiji
 = Arabs
anxious to hear my opinion of the
Bloody massacre of 
Nyangwe

but I 
decling
declining
 to enter on it - They
know all about it already -
	



30th July 1871 left and went
about 3 miles to a village
overlooking the 
Shokoye
 a man
a little ill refuses to march
though the others carry his
bundle = - They send thirty
tusks with us and are glad
of the opportunity to get more
goods from 
Ujiji
 - about a 
dozen Manyema go the 
first that ever travelled so
far
	



31st
 came yesterday to
village on hill and today
went through the defile between


mt
mountain
 
Kimazi
 and 
Kiyila

a cavern on the pass side
of the latter with a 
slatactite
stalactite

pillar in entrance = came
on to Mangala\'s numerous
villages and two being ill
on the 
1st August = Wedens-
day
 = we rest - a large
market assembles in
their midst -


	






Journal CLX  2 August 1871
Left Mangala\'s and came through 25
a great many villages all deserted at
our approach in consequence of the 
vengeance taken by Dugumbe

s
\'s
 party
for the murder of some of his 
Drawing of the head of an African individual.

followers = Kasongo\'s men
eager plunderers of other Manyema
had to scold and threaten them
and will set some to watch their
deeds tomorrow = Plantains 
Drawing of the head of an African individual.

very abundant and good =
came to 
Kitette
 and lodged in a 
village of Loembo = about thirty
smithy
ies or rather foundrdies in 
Drawing of the head of an African individual.
 the
villages we passed = they are
very high in the roof to avoid fires
and 
Drawing of an African hut.
 thatched with a sort of wild

plan-tain leaf from which sparks
andrain run off equally well -
	



Batata = ancients = Molenda
Mbayo = 

Yamba
Yamva

 = Kamoanga

Kitambwe = Ñoñgo = 

aulumba
Aulumba



Yeñgeyenge = Sim^
baa = Mayañga
Loembwe recently dead = offer them
goatsflesh = Konḡolako kwa where
they came from - == effigies of in court




3d = August three slaves escaped
by night and as all are enjoined to
help us we are constrained to
wait so as not to abandon ivory
but it is vexatious to wait for
fugitives = Men sent in pursuit met
others coming from 

Kasongo

 to
carry so we go on homeward
sacrifice
s
ar
e 
offered to 



	






CLXI Journal 
24


4th
 came through miles of
villages burned because men
refused Abdullah lodging
a goat speared by a lurking
revenge seeker -


5th




6th
 ^ came on to 
to

 
Boma
 village through
many miles of palm or bananas 



7th
 to village ill every step  -
in pain


8th
 people shewed suspicion
by running away - In passing
along the narrow path with a 
wall of dense vegetation touch-
ing each hand a large spear
was thrown at me from my
right and it glanced past my
back heavily into the soil about
20 feet beyond me = the two men
from whom it came were about
30 feet off only &amp; bolted - I 
dont
don\'t

know how it missed except by
the man being too sure of his aim
and God\'s good hand upon me
I was in front 
and
 
of
 a small squad
and the main body had been
allowed to go till the leader came
the guilt is 
h Bogharib\'s - a little
way on a gigantic tree burned off
so as to fall with a fearful crash
one yard from my body &amp; covered
me with dust thank God
			
			
	





Notes CLXII = 
Uruko
 

Kuss
Bakuss

 or 

Kuns
Bakuss

 name of coffee -


Kanone
 = Manyema name of Ibis religiosa -


Makéssi
 
Do
Ditto 

Do
Ditto
 of oysters = Pearls are said
to be found in them but no use is made
of them = never strung = boreing not thought 
of

	


The handwritten undertext that follows appears at the center of the page beneath another layer of text also written by Livingstone.

Note send for 


frasila

frasilah



 

samsam






Frasilahs
 
Langio
 --- 3 -



Frasilahs
 Pink --- 3

Jorahs americano - 
30

Jorahs Kanikeo -- 30
china box of Tea -- Indianlata
2
Pack china Tea Wine 

4


clothing - 4 shirts -
Medicines 4 Tr

owse
rs --- stockings

Pens = Paper letters ink

 - Watch = 



	


 sugar - candles

By Dugumbe\'s men =
			
			
	


The overtext that follows continues from the bottom of the page, but appears in the middle of the page. Livingstone has written this text perpendicularly over another portion of text already on the page.

as they think that I await

Bogharib - He offered
to bring me ten goats for
my three if I would send
my guns - It would
only make matters
worse 
Dugumbe
had a women speared
here our two women
were borne off to be
eaten - the chief
shewed us on 10th

spot where they
had killed one man
and eaten him lately

11th
 came to 
Mamohela









9th
 four hours of narrow 
Calculation on the right-hand side of the page.

path in dense vegetation



Adie goes to 
Lomame



waylaid by spearmen = a
woman and girl killed and a
spear again missed me by a 
hairbreadth in front = peering
into each hole of the vegetable
mass expected each moment to 


to

 hear the rustling of spears and the
ru
shing away of the enemy - I
be
came sick &amp; weary &amp; careless
of me taunted us but we could

ein = Heartsore reached

He offered to g
o


declined

			
			
	





CLXIII
 Note = The Manyema are so afriad of guns that


one gets the loan of a musket to settle any disputed
claim - merely carrying it on his shoulder gives him 
22

all the influence he needs though it is known that he


cannot use it = spears are disregarded = however


many one may have - but a musket is potent
	

Note = 24th May - The party that came through
from 
Mamohela
 report a great fight at

Mwana mpunda\'s and they saw the dead
cut up for cooking with bananas - This




conforms
confirms
 Rashid\'s evidence - 

Mokandirwa
Mokandira




the chief at 
Nyangwe
 says that they eat those


killed in war only - that the meat is not
good and it makes the eater dream of the dead
Another man not so trustworthy said that
it is saltish and even peppery = needs but
a little condiment - It seems  to be cannibal-
-ism out of revenge or to inspire courage
	

Note 
Gulu
 deity above or Heaven -


Mamvu
 = earth = 
Gulu
 is personal &amp;
men on death go to him - 
Nkoba
 lightning

	

Note = 

Zurampela
Surampela

 is about ^ 


N
North


 West
of this - in going thither 3 days off the




Luive
 
R.
River
 of very red water is crossed


Mabila
 
R
River
 
recieves
receives
 it into its very dark
water which flows into 
Lualaba


	

Note = many oysters in 
Lualaba
 - The
shells very thick and deformed by inse
It is probable that Pearls are in them
	




Kalonda

 = salt springs on West side of the


Lualaba
 - not hot - boiled for salt
	



Kirila
 islet 3 miles below 
Nyangwe



Magoya


do
ditto
 6 
do
ditto
 - people and trees on it




Kūla
 or 
Nkula
 name of salt lagoon on
West of 
Lualaba
 -



Lualaba
 is never 
fordatable
fordable
 anywhere at
anytime except by canoes
	

Two days from this a rapid exists e

 side of the river = this side a



Kirians
 its name =
	


Rice in ear in 73 days = D


 = m



			

			

	

	




words
 Batulu = Husbands Sima 36



Pia = Milango

	

to be ordered from 
Zanzibar

a few soft black lead pencils
2 
Frasilahs
 cowries
500 Sungomazi neck beads (not cracked)
in box with saw dust packing
Sardines = Sugar - 50 
lbs
pounds
 = 25 
lbs
pounds
 coffee no Tea
2 Flour in Tins or waterproof bags = old Tarpaulins
Guns flints = Rifles - 
Residue of a red wax seal.

3000 cartridges - caps
63
Nautical 
At
Atlas
 / 72
(old musical box -) present

Ghamess Wodrin Lagh to
point out men (good)
not to go to 


Unyinyembe
Unyanyembe





	




11th
 
Mamohela
 = rest half a day -
ill still but we cannot delay - I do very
devoutly thank the Lord for sparing my


my

 life three times in 24 hours - No Lort
d
is good a stronghold in the day of trouble and
he knows them that trust in him -


12 Remain at 
Mamohela
 
vil
village
 - the camp is
all burned off - First rain fell in evening
of the 11th
 Thunder - Laid dust -


13th
 on to 


Lolindi
Lolinde


 suffering much - a man
brought a Kite nearly full fledged out of
its nest on a tree - This is the first breeding
case I am sure 
off
of
 -


14th
 over many brisk burns to 
vil
village
 on
side of mountain range = a little rain fell
after dark - near 
Luamo
 it ran in paths
&amp; some burns and caused dew -


15th
 to Muanambongo\'s - Golungo
bush buck with stripes across body &amp; spots
along all the side in a ^ two rows



16th
 To 
Luamo
 very ill with bowels -


17th
 cross it and send a message to Katomba
at Moenengoi\'s = sent present of food back

	



18th 
Aug.
August
 1871 on to Katomba&amp; welcome 37 by
all the heavily laden ivory Arabs = 3 relays take on
the spoil = 
Kenyengere

attacked and 150 captives
taken = about 100 slain - an old feud of Moenemgoi\'s



M.
Muhamad
 Bogharib still at 
Bambarre
 with all my letters
for now unsent! No news whatever from 
Ujiji




19th 
S.
Sunday

 - rest - 20th
 
Do

Ditto
 from weakness - 21st
 Palms 22 
Bam
barre




	



28th
 better &amp; thankful = to Monandenda\'s on the


R
River
 
Lombonda
 = Katomba\'s 
safari
 has a thousand
	

Map.

	


Frasilahs
 &amp; Muhamad

s
\'s
 300
	


29 ill all night &amp; remain


30 attendant ill remain at

Monandenda\'s 
6 AM


	
	


31st
 1 
Sept
September
 
Sat.
Saturday

 up
half over mountains
and sleep in dense forest


2d
 over range &amp; down
onto marble capped
	

Series of calculations.

	
hill = 26
7 = 
Nyangwe
 women expert in
diving for oysters = = news of 
killd
killed
 unclothe them^
-selves




3d

Rest Equinoctial gales to 
Lohombo




4th
 
vil
village
 in front of 
Lohombo
 - 5 
Kasangangazi




6 th
 Rest 7 th
 
Mamva
 8 th
 Rest 
9 th
 
Do
Ditto
 
Do
Ditto



	




Kasongo\'s near 
Lualaba
 - In writing about the
slave trade I have been obliged to use most distressing
caution in order not to give those who have never
seen it the appearance of plausibility in drawing out
from their club sofas "exaggeration" - "
overdrawing"
like Mrs Stowe\'s Uncle Tom\'s Cabin - The like would
be 
philosophers

philosopher\'s
philosophers\'

 doubt if there be a Hell - but I have
been in it twice once on the 
Shire
 where we
had to clear the paddle wheels &amp; chain cable of the
dead every morning before we could start
and the horrible scenes of crocodiles &amp; carrion are
unbearable to be even glanced at by the imagination
again - on the 
Kilwa
 slave route to 
Nyassa
 -

Then the Hell scenes I dare ^ not commit to paper
or even think on - I drive them from my
thoughts if even they intrude as intrude in
part they will do on suddenly awaking at
dead of night - getting up &amp; walking about
sometimes relieves me but writing about
them in constrained oppressed style as hinted
above jaded
my mind so that I could
rather think of nothing else or

I could not think on
necessary things and neglected all my own
and family interests - Lord Palmerston\'s offer of
service to me fell flat on my ear &amp; heart



The text that follows is written in John Kirk\'s hand and lies beneath Livingstone\'s writing in the lower left-hand corner of the page.



12/2/
70
1870




John Kirk



	




Series of calculations.
 3
8





Five lines of text: three in Arabic and two in Nagari. These are not in Livingstone\'s hand. The Arabic corresponds to the English undertext on this page (“Dr David Livingstone HRM Consul Ujiji &amp; Elsewhere”), and the first two lines can be translated thus: “This is to the most honorable Doctor Livingstone, consul of the Glorious [or Great] Queen, in Ujiji.” The last Arabic line reads simply, “Amen.” However, this is not an absolute translation. “This is to” can also be read as “the one who writes this informs,” while “most honorable” can also be read as “may his glory be eternal.”




The text that follows is written John Kirk\'s hand and lies beneath Livingstone\'s writing in the center of the page.


Dr David Livingstone



HRM
His Royal Majesty\'s
 Consul 
Ujiji
 &amp; Elsewhere

	
	



R
River
 
Kanayumbe


&amp; islands
	


Bagenya peoples

other side R

iver 


Lualaba



	
	



Kusi
 North



Mhuru
 = South



Liñkanda
 West or other side
	



Mazimba
 East
	

	




Series of calculations.



	




Series of calculations. A note at the top of the page states that these calculations were made in the "camp at 4° 10\' Lat Lualaba called Nyangwe."
 39




Shamikwa
 
R
River
 9 days


Nyengere black water




Babire
Bira

 upright hair

	




Series of calculations. A note at the top of the page states that these calculations describe the "Total Rainfall in Manyema 1870-71."
 5




Residue of a red wax seal.





Residue of a red wax seal.





Residue of a red wax seal.



			

			

	

	




28 
Septr

September
 1871 
cont
continued
 -

Journal = 20th camp
from 
Bambarre
 = 4
½
1/2

Hours to last crossing of


R
River
 
Lo
vum

ngumba
 = 
	


29th
 4
½
1/2
 to under 
Mt

Mount
 -

Ngoilu = fruit plum
= good = rapid current
of forty yards &amp; knee
deep = 21st camp -



30 
Do
Ditto
 4 waters
many buffaloes
rest 3 hours
and go on to


Masuko
 camp
6 hours or 7

22 camp
	


1st 
Oct
October
 Monday
on to Mketo

s
\'s

in mountains


2nd
 Rest -


safari
 reported


23 camp

	

The text that follows is written in an unknown hand and lies beneath Livingstone\'s writing at a perpendicular angle.


Dr Livingstone


care of Dr Kirk
	

	



3d
 to go on

Ghamees 

W.
West

 I
fighting with th

e
chief Merere -

Moenenyun
on 
me
my
 side

Ghamees on
other and




Unyembe
Unyanyembe



Arabs on 
Embossed seal of the Royal Geographical Society.

a third side

Merere is
mad - cut
off hand
of Makoa
- drunkeness



R
River

 =


Read Bible
four times
through = 
Manyema



	



3d
 Masuko nearly ripe and in
great abundance = on to camp of


Masudi

24th camp -


5th 
Oct
October

 to 
Loanda
 
vil
village
 = send
to 



Kasonga
Kasongo



 for canoe - go


6th
 on to 

Kasonga
Kasongo


\'s 
vil
village
 -


7th
 Rest there = eyes
inflamed = 

Kasonga
Kasongo


to come today -

Calculation.


			

			

	

	




23d
 


Oct.
October
 1871
 arrived at 
Ujiji
 = and 172a
found that Shereef had sold off
all my goods for slaves &amp; ivory
in spite of remonstrance by
the chief men here - came impudently
and offered me his hand !!!


24th
 Rest dispirited &amp; sore


25th
 call Shereef &amp; demand my
goods - said Ludha had ordered him
to stay a month &amp; then leave
Had divined on Koran &amp; found
I was dead - then sold all = write letter


26th
 News from 
Garaganza

many Arabs killed - road
shut up - one Englishman there

	





Series of squiggles to correct ink flow across the top portion of the page.



Series of calculations that cover the bottom portion of the page.




	

	




172b 

ult.
ultimo






Series of calculations in pencil at the center of the page as well as two inked squiggles to correct ink flow.




27th
 condole Seyed bin 
Madjid
Majid


whose son is killed there


Thursday 1st 
Novr

November

 very hot
feverish - Rain soon -


3d 
Sat.
Saturday




	








Livu
Liren








Calculation at the top center of the page.






Megera apanda

goes into 

Losizi








Postal stamp that reads "MAURITIUS A AP 13 69."



Series of squiggles to correct ink flow.



Two cancelled one-penny British postal stamps affixed to the page.







Dr. Kirk
 

Consulate 



Zanzibar

 

care of 
H.M.
Her Majesty\'s
 Commissioner 



Seychelles




 

			

       	
	


',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_viewable' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-11-14 23:32:54 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to John Kirk 2',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '0f2ca096-7443-4cb3-a211-ee4b67c4946a',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Kirk, John 2, 1832-1922',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to John Kirk 2, 13 February 1871',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1967',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-2.95,25.95',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '13 February 1871',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1871-02-13T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 2,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => 'folio',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_002715_thumbnail.jpg',
        'uri' => 'public://liv_002715_thumbnail_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 235321,
        'status' => 1,
        'type' => 'image',
        'uuid' => 'ea3198c7-e8d5-41b0-88ca-b46b9f49313c',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 100,
          'width' => 72,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 80,
        'width' => 58,
        'uuid_features_packaged_file_path' => 'assets/liv_002715_thumbnail_0.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002715',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Manyuema Country',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002715',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'National Library of Scotland: MS. 10701, 154',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1871-02-13T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Horace Waller',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '4d774356-3664-48ba-b4f1-88073170923c',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Waller, Horace, 1833-1896',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Horace Waller, 21 June 1865',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1753',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '55.77742,-4.05505',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(
    'und' => array(
      0 => array(
        'value' => 'MS. 10780',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '21 June 1865',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1865-06-21T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 4,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '8vo',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002346',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Burnbank Road, Hamilton',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002346',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Bodleian Library. Weston Library: Waller MSS. Afr. s. 16.1, 137-138',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1865-06-21T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => '"Dr. Livingston\'s Discoveries in Central Africa," Illustrated London News 27 December 1856, 643',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1481756171,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '570a03bc-c944-47a7-887c-b6f2f7300db5',
  'field_manuscript_addressees' => array(),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => '"Dr. Livingston\'s Discoveries in Central Africa," Illustrated London News 27 December 1856, 643',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '53.214587,-1.665579',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Illustrated London News',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '27 December 1856',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1856-12-27T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 1,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'clippings (information artifacts); engravings (prints)',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_012051_thumbnail.jpg',
        'uri' => 'public://liv_012051_thumbnail.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 18367,
        'status' => 1,
        'type' => 'image',
        'uuid' => '18cab9b4-2b6b-47c1-b225-bb61fa2d12bc',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 100,
          'width' => 66,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 100,
        'width' => 66,
        'uuid_features_packaged_file_path' => 'assets/liv_012051_thumbnail.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:012051',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => '[Britain]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_012051',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'David Livingstone Centre',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1856-12-27T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-12-14 22:56:11 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Horace Waller',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '581c29b9-b142-4b30-b834-8d5740d152b8',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Waller, Horace, 1833-1896',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Horace Waller, [19 September 1864]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1488',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '51.38,-2.36',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(
    'und' => array(
      0 => array(
        'value' => 'MS. 10780',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '[19 September 1864]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1864-09-19T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 2,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '8vo',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_002067_thumbnail.jpg',
        'uri' => 'public://liv_002067_thumbnail_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 17914,
        'status' => 1,
        'type' => 'image',
        'uuid' => 'c6d0009e-2378-42ba-b954-d06b396872ec',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 100,
          'width' => 73,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 80,
        'width' => 58,
        'uuid_features_packaged_file_path' => 'assets/liv_002067_thumbnail_0.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002067',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => '[Bath]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002067',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Bodleian Library. Weston Library: Waller MSS. Afr. s. 16.1, 78--79',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1864-09-19T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(
    'und' => array(
      0 => array(
        'value' => '
	
		
			
				Letter to Horace Waller
                Letter to Horace Waller, [19 September 1864]
				Livingstone, David, 1813-1873
			
			
				Livingstone Online
				College Park, MD, USA
				University of Maryland Libraries
				2016
				liv_002067
			
			
				Bodleian Library. Weston Library; Waller MSS. Afr. s. 16.1, 78--79
				Letters, 1488
				
Waller, Horace, 1833-1896; 
				
[19 September 1864]

				[Bath]
			
		
		
			
				English
			
		
		
			
				2011-12-13
				Jared McDonald initial transcription and XML encoding.
            
			
			
				2010-12-13
				Adrian S. Wisnicki XML corrections.
            
			
			
				2010-12-15
				A.J. Schmitz proof reading.
           
			
			
				2012-09-25
				Heather F. Ball second XML editing.
            
			
			
				2016-10-30
				Anne Martin final review.
            
			
		
	

	
		
			

	



Monday morning


My dear Waller


Could you draw
a gigantic human
head - not an
ugly one - with
a lip ring in it
to 
shew
show
 at the
theatre tonight.
I shall see you 
at the section of 

	


of geography today





D L
David Livingstone

 is in ^ the terrific
labour pains of
his mouse - 
wont
won\'t

mention Bishop 
T.
Tozer


at all


	




	




			

		
	

',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'A Note on Fever for Dr McWilliam Transmitted by Favour of Capt. Washington',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '6866591e-6198-4b2a-90f9-d843256e8b07',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'A Note on Fever for Dr McWilliam Transmitted by Favour of Capt. Washington, 28 November 1860',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Papers and Reports, 18',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-16.166667,33.6',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(
    'und' => array(
      0 => array(
        'value' => 'MS. 10777',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '28 November 1860',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1860-11-28T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 4,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '322 x 203',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); official reports',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_002688_thumbnail.jpg',
        'uri' => 'public://liv_002688_thumbnail_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 16590,
        'status' => 1,
        'type' => 'image',
        'uuid' => 'e9ddecc2-4f8f-4275-91cd-ac2120b2cb1f',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 100,
          'width' => 64,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 80,
        'width' => 51,
        'uuid_features_packaged_file_path' => 'assets/liv_002688_thumbnail_0.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => 'Transactions of the Epidemiological Society of London, 1:1 (1860), 235-242. The Lancet (London), 24 Aug. 1861, 184-186. Michael Gelfand, Livingstone the Doctor; His Life and Travels: A Study in Medical History (Oxford: Basil Blackwell, 1957), 297-303. ',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002688',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => '[Tette]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002688',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'National Museum of the Royal Navy (Great Britain): MS. 120',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1860-11-28T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => '1870 Field Diary (Fragments Integrated)',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1479166374,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '7470bf0c-afa1-47b0-a613-9547c57e8f59',
  'field_manuscript_addressees' => array(),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => '1870 Field Diary (Fragments Integrated), 17 August 1870-22 March 1871',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Field Diaries, 35, 37',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-2.95,25.95',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, Agnes 3, 1847-1912; Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '17 August 1870-22 March 1871',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1871-03-22T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(),
  'field_manuscript_extent_size' => array(),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); diaries; field notes',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:015001',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Bambarre; Manyema',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_015001',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone Online',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1870-08-17T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(
    'und' => array(
      0 => array(
        'value' => '
    
        
            
                1870 Field Diary (Fragments Integrated)
				1870 Field Diary (Fragments Integrated), 17 August 1870-22 March 1871
                David Livingstone
				Agnes Livingstone
                Adrian S. Wisnicki
                Christopher Lawrence
				
					Adrian S. Wisnicki
					Transcription
					TEI Encoding
					Proofreading
                    Editorial Decisions
					Coding Review
				
                
                    Megan Ward
                    Transcription
                    TEI Encoding
					Proofreading
                    Editorial Decisions
                
                
                    Heather F. Ball
                    Transcription
                    TEI Encoding
                    Editorial Decisions
					Proofreading
					Quality Control and Integration
                
                
                    Ashanka Kumari
                    Transcription
                    TEI Encoding
					Proofreading
                
				
                    Erin Cheatham
                    Transcription
                    TEI Encoding
					Proofreading
                
				
                    Alexander Munson
                    TEI Encoding
					Proofreading
                
            
            
                Livingstone Online
                University of Maryland Libraries
                College Park, MD, USA
                2016
                liv_015001
            
            
                
                    
                        United Kingdom
                        Field Diaries, 035, 037
                    
                    
                        
                            
Unknown Hand This hand is unknown
                                but thought not David Livingstone\'s.
                        
                    
					
					
						
	                        United Kingdom
	                        Blantyre
	                        David Livingstone Centre
	                        297a
						
					
					
					
						
	                        United Kingdom
	                        London
	                        British Library
	                        Add.MS.50184, f. 169
						
					
					
					
						
	                        United Kingdom
	                        Oxford
	                        Bodleian Library. Weston Library
	                        MSS. Afr. 16 (Box 6)
						
					
					
					
						
	                        United Kingdom
	                        Edinburgh
	                        National Library of Scotland
	                        MS.10703, ff. 1-2
						
					
					
					
						
	                        United Kingdom
	                        Oxford
	                        Bodleian Library. Weston Library
	                        MSS. Afr. 16 (Box 6)
						
					
					
					
						
	                        United Kingdom
	                        Blantyre
	                        David Livingstone Centre
	                        297b
						
					
					
					
						
	                        United Kingdom
	                        Blantyre
	                        David Livingstone Centre
	                        297d
						
					
					
					
						
	                        United Kingdom
	                        Edinburgh
	                        National Library of Scotland
	                        MS.10703, ff. 3-23
						
					
					
					
						
	                        United Kingdom
	                        Blantyre
	                        David Livinstone Centre
	                        297e
						
					
					
					
						
	                        United Kingdom
	                        Edinburgh
	                        National Library of Scotland
	                        MS.10703, ff. 24-26
						
					
					
					
						
	                        United Kingdom
	                        Blantyre
	                        David Livingstone Centre
	                        297b
						
					
					
					
						
	                        United Kingdom
	                        Edinburgh
	                        National Library of Scotland
	                        MS.10703, ff. 27-31
						
					
					
					
						
	                        United Kingdom
	                        Edinburgh
	                        National Library of Scotland
	                        MS.10703, ff. 32-35
						
					
                
                
                    1870 Field Diary (Fragments Integrated), 17 August 1870-22 March 1871
                    David Livingstone
                    Agnes Livingstone
                    17 August 1870-22 March 1871
                    Bambarre; Manyema
                
            
        
        
            
                English
                Greek
				Latin
                Lega-Shabunda
				Malagasy
				Nyamwezi
				Persian
                Scottish Gaelic
                Swahili
				Turkish
				Undetermined
            
        
        

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Proofing and quality control and integration 
            Proofreading        
            Proofreading and additional transcription
            Initial transcription and XML encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Proofing and quality control and integration
            Proofing
			Initial transcription and XML encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
            Quality control and TEI encoding
			Proofing
			Proofing
			Additional proofing and TEI encoding
            Initial transcription

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Proofing and quality control and integration
            TEI Encoding and Proofing
            Transcription and TEI Encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Quality control and TEI encoding
			Proofing
			Proofing
			TEI encoding and revision
            Initial transcription

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Proofing and quality control and integration
            Transcription editing and proofreading
            Initial transcription and XML encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Proofing and quality control and integration
            Proofreading and XML encoding
            Initial transcription and XML encoding

			
			Review and corrections
			Addition of @refs
	            
				Coding corrections
				Coding review
	            Quality control and integration
	            
	            Proofreading and additional XML encoding
	            Proofreading and additional XML encoding
	            Initial transcription and XML encoding
	            
	            Proofing and XML encoding
	            Proofing and XML encoding    
	            Initial transcription and XML encoding
	            
	            Proofreading
	            Proofreading
	            Initial transcription and XML encoding
	            
	            Proofreading
	            Proofreading and XML encoding
	            Initial transcription and XML encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
			Quality control and integration
			Proofreading
            Proofreading and XML encoding
            Initial Transcription and XML encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
			Quality control and integration
            Proofing
			Proofing
            Initial transcription and XML encoding

			
			Review and corrections
			Addition of @refs
			Coding corrections
			Coding review
            Quality control and integration    
            Proofing
            Proofing
            Initial transcription and TEI encoding

			
			Review and corrections
			Addition of @refs
	            
				Coding corrections
				Coding review
	            Quality control and integration
	            
	            Proofing and additional TEI encoding
	            Proofing and additional TEI encoding
	            Initial transcription and TEI encoding
	            
	            Proofing
	            Proofing
				Initial transcription and TEI encoding

			
			Review and corrections
			Addition of @refs
	            
				Coding corrections
				Coding review
	            Quality control and integration
	            
	            Proofing
				Proofing
	            Initial transcription and TEI encoding
	            
	            Proofing
	            Proofing and TEI encoding
	            Initial transcription and TEI encoding

        
    


	
       	
			

	

	

	
	       

for the isolation in which they live
The head of Moenekuss is said to be
preserved in a pot in his house
and all public 

 matters are gravely

	
	
	
communicated to it as if his spirit
dwelt therein - His body was eaten
The flesh removed from the head
and eaten too - His 
fathers
father\'s
 head is
said to be kept also

    
	
	

The foregoing refers to 
Bambarre

alone - In other districts graves 
shew
show

that 
sepulture
sepulcher
 is customary - Here no
grave appears - Some admit the

    
	
	
existence of the practice here - others
deny it - In the 





Metamba



 country

and adjac



ent

 to 
Lualaba
 - a quarrel with
a wife often ends in the husband killing
her and eating her heart mixed up

    
	
	
in a huge mess of 

goats

goat\'s
 flesh -
This has the charm character - fingers
are taken as charms in other parts 
In 
Bambarre
 alone is the depraved

    
	
	
taste the motive for cannibalism


    
	
	


On
 17th August 1870 Monamyembo
the chief who was punished by 

M
Muhamad
 Bogharib
lately came 

 bring two goats - One
he gave to Muhamad the other to



Moenekus
Moenekuss

\' son acknowledging
that he had killed his elder brother
    
	
	
He had killed eleven persons over


in our absence
at 
Luamo
 - in addition to those

killed in villages on our 
SE
South East
 when
we were away - It transpired
that 


T
K
andahara
 brother of old

Moenekuss whose village is

	
	   
near this - killed 3 women &amp; a child and
that a ^ 

trading
 man came over from 
Kasangangazi

and was murdered too for no reason but
to eat his body - Muhamad ordered old




Tandahara

Kandahara



 to 



bring
 ten goats and take 
		
	
	   
them over to 
Kasangangazi
 to pay
for the murdered 



man
 - When they 
tell of each other\'s deeds they disclose
a horrid state of bloodthirsty callousness
	
	
	
People over hill 
NNE
North North East
 of this killed a
person out hoeing - if a cultivator is alone
he is almost sure of being slain.

Some said that people in the vicinity
or 

hyaenas
hyenas

 stole the buried dead, but

Posho\'s wife died and in 

Wanyamesi
Nyamwezi


    
	
	
fashion was thrown out of camp un-
buried - Muhamad threatened an attack if

Manyema did not cease exhuming the 
dead - it was effectual - neither men nor



hyaenas
hyenas

 touched her though exposed now
for seven days 24th August 1870


    
	
	


When the rains ceased in June

I wished to go Northwards along the 


Lualaba
 &amp; buy a canoe but my

attendants professed fear of the water

I then promised not to buy a canoe
    
	
	
but this elicited that they were determined
not to go at all- the head Arabs told
me that they were in the habit of going
to the women whose husbands were
away and getting food and spending
the night with them - They then
    
	
	
refused rations - not understanding 
why I 
enquired
inquiried
 the reason = they replied 
that the beads were not enough - the

Arabs said "they are about to desert" &amp;


\'
"
that is a slave custom" -
	
	
	

I spo



k
e long to them advising them
earnestly not to desert &amp; lose all their
arrears of pay - - But on going out
from me one called out "Who
will he get to carry his
    
	
	
things" - then a loud "Ha ha ha" to make
me hear it. On telling them that Seyed
Majid had punished those who deserted

Speke &amp; the consul would certainly be
angry to hear that I had been thrown
away by them in the middle of the cannibal
    
	
	
country where I could get no carriers
as the Manyema will not go to the next
village - Simon said "give me a bit
of paper to tell that I am a very bad
boy" - This was supposed to be witty
&amp; he added "let Seyed Majid chain

	
	
me - beat me - shoot me
\'
"
 I want to go to 
Lualaba


Abram said the others intended to throw down my
bundles &amp; run away in the forest - "He was tired
with seven 
years
years\'
 work" These two are the bring 


Katomba at whose voice they trembled spel

    
	
	
in 

ly
 &amp; they said they would go but seeing




that
 he did nothing again refused - The knowledge

that I 
wont
won\'t
 punish as the Arabs do is the



reason on their desertion - the murders

they committed at 
Kabuire
 dest
royed what
    
	
	
little of moral nature they possessed - I would
not have brought them from 
Ujiji
 as the deterioration
was then visible in stealing from me to pay their
prostitutes but Thani behaved so strangely to

my packet of letters, refusing it - than send

	
	
it back "because he did not know the contents"
I feared its destruction and then I should be
waiting for other men from 
Zanzibar
 in vain
I therefore strained my utmost to finish up


up

 my work with what I had

    
	
But now these worthless slaves had me
at their mercy &amp; wished to be masters - to take
what beads they chose and go or remain just
as it suited their fancy - they thought that

	
	
I did not know where they got food and when
declaring their rations of beads too small they
bought grass cloth clothing, knives spears
and dainties - With three Susi - Chuma 

    
	
and GardnerI set off - intending to join 

M-
Muhamad

Bogharib or Josuf on 
Lualaba
 -  We went
with three deputies from the head Arabs &amp;
their slaves - but they hated me &amp; tried to get


			
    
	
away from me - I however kept up and
on the fourth day passed through nine villages
destroyed by the worthies who did not wish
me to see more of their work - Then

    
	
met with 

Mohamad
Muhamad
 Bogharib &amp; 

Josuph
Josuf

 coming
back from 

Kasongo\'s
 - I slept at a village
a little way from them &amp; was met in morning
with the news that a man of the party which

    
	
eschewed 
any
my
 company had been stabbed by
night in revenge for the slaughter of relatives
&amp; burning of nine villages - 

Mohamad
Muhamad


refused to engage in a wholesale manner

    
	
to revenge the dead one and seeing that I had no
friend &amp; only three people I turned back - the
mud was grievous &amp; as I waded it all
my feet were torn to pieces and irritable

    
	
eating ulcers begun which have dis-
abled me ever since - I now spoke with my
friend Muhamad and he offered to go with 
me to see 
Lualaba
 from 
Luamo
 - but

    
	
I explained that merely to see &amp; measure
its depth would not do - I must see whither
it went - This would require a number of his
people in lieu of my deserters &amp; to take

    
	
them away from his ivory trade which
at present is like gold digging - 
To
^ I must
 make
amends &amp; I offered him two thousands
Rupees &amp; a gun worth seven hundred

    
	


Rs.
Rupees
 2700 in all on £270. He agreed &amp; should
he enable me to finish up my work in one
trip down 
Lualaba
 &amp; round to 
Lualaba West

it would be a great favour - The severe

    
	

Pneumonia in 
Marungu
 - the choleraic
complaint in 
Manyema
 &amp; now irritable
ulcers warn me to retire while life lasts -


Muhamad

s
\'s
 people went North &amp; East &amp; West 

    
	
from 

Kasongo\'s
 - 16 Marches North = - 10 
Do

Ditto

West - and 4 
Do

Ditto
 
E. &amp; SE.
East &amp; South-East

 - The average march
was 6
½
1/2
 hours say 12\' about 200\' North &amp; 
W
West



Lat.
Latitude
 of 

Kasongo

 say 4° South - they may

    
	
have reached 1°-2°
S.
South

 They were now in the 







Balegga
Lega

 country
Legaland


 &amp; turned - It was all
dense forest - never saw ^ the sun except when
at a village &amp; then the villages were 

    
	
apart People very fond of sheep which
they call 
Ngombe
  or ox - tusks never used -
They went off to where an elephant had formerly
been killed &amp; brought the tusks rotted and eaten

    
	
or gnawed by "
Dezi
" a Rodent probably the




aulo
anlo

 

candatus
caudatus

 swindermanus
 - Three ^ large rivers
were crossed breast &amp; chin deep - In one
they were five hours and a man in a
 
    
	
small canoe went ahead sounding for water
capable of being waded - much water &amp; mud
in the forest = 

 This report makes me thankful
I did not go for I should have seen nothing -
and been worn out by fatigue &amp; mud

    
	

The 
river of the 
Metunda


 had black water
and 2 hours to cross it - breast deep




R
River
 Mohungu
 = breast deep -




R
River
 of 
Mbite


 also large 



crossed about 40 smaller rivers

    
	
All along 
Lualaba
 &amp; 





Metambe
Metamba





 the sheep

ar

e hairy dewlaps = no wool = Tartar
breed? small thin tails -

    
	



a
A
 broad belt of meadowland with no
trees lies along 
Lualaba
 - Beyond that it
is all dense forest. and trees so large
one lying across path is breast high
clearances exist only around villages

    
	
People very expert smiths and

weavers of the "

Lamba

" - make fine large
spears knives and needles = Market-
places called "
Soko
" - numerous all
along 
Lualaba
 - To these the 

Barua
Luba



    
	
of the other bank come daily in large
canoes bringing grass cloth, salt, flour,

cassava, fowls - goats - pigs &amp; slaves =
Women beautiful with straight noses
and well clothed When the men

    
	
of districts are at war the women take
their goods to market as if at peace and
are never molested - all are very keen

traders buying one thing with another &amp;
changing back again and any gain
made is one of the enjoyments of life -

    
	

I knew that my people hoped to be
fed by Muhamad Bogharib when
we left the camp at 
Mamohela

but he told them that he would not
have them - This took them aback -
but they went &amp; lifted his ivory

    
	
for him and when a parley was thus
brought about talked him over saying
that they would go to me &amp; do all I
desired - never came - but as no
one else would take them I gave
them three loads to go to 
Bambarre

 
    
	
There they told Muhamad that I would
not give them their beads &amp; They did not like
to steal 

 - They were now trying to get
his food by lies - I invited them 3
times to come &amp; take beads but having
supplies of food from the camp

    
	
women they hoped to get the upper
hand with me and take what they
liked by refusing to carry or work


Mohamad
Muhamad
 spoke long to them but speaking
mildly makes them images that the 

spokesman is afraid fo them - They

    
	


they

 kept away from my work &amp;
would fain join Muhamad\'s but he


wont
won\'t
 have them - I gave beads to
all but the two ringleaders - their
conduct looks as if a quarrel had
taken place between us but no such

    
	
excuse have they - on leaving 

Nassick


African Asylum where they had been
clothed fed &amp; taught for years they
sent an anonymous note to me abusing
all the teachers &amp; complaining of

    
	
bad treatment - They were sent to their own
people but had all been slaves and
remained with me only to escape being
made to work again - If the freed men 
in 

America

 turn out well it
will be because they were taught

    
	
to work - These might either work play
or do nothing at 
Nassick
 &amp; not one of
them could handle a tool = they hoped
for long to get back to a life of idleness
and such as they described would have
 
    
	
any English boys - the teacher feared
that if punished for idleness they
would run away &amp; bring discredit
on the Asylum They were of the lowest
or criminal class in 
Africa


    
	
and boasted in my hearing that
when fed to the full they stole pigs - kept

 &amp; fattened them with their extra food
them ^ at the school &amp; killed &amp; 
eat
ate
 them

When returning to 
Bambarre
 the 

people of Moenemokia
 came to fight as

    
	
they were drunk &amp; fled as soon as they
saw resistance - no danger of being
turned up ^ on made my good boys rush
off unbidden &amp; capture women &amp;

goats - another case occurred &amp;

    
	
off they ran but captured only fowls
and tobacco - two of them have captives
 
now bound in their possession
I am powerless as they have left
me and think that they may do as
they like and the Manyema are

    
	
bad is the song - their badness consists
in being dreadfully afraid of guns
and the Arabs
 can do just as they
like with them and their goods - If
spears alone were used the Manyema

    
	
would be considered brave for they fear
no one though he has many spears
They tell us truly "that were it not for
our guns not one of us would return
"


to our own country". Moenemokia
killed 2 
Arab agents
 &amp; took their guns

    
	
This success led to their asserting
in answer to the remonstrances of the
women "We shall take their goats guns
and women from them" The chief in
reporting the matter to 

Moenemgor
Moenemgoi

 at


Luamo
 said the Englishman told

    
	
my people to go away as he did not
like fighting but my men were filled
with "
malofu
" or 
palm toddy &amp; refused 

"to their hurt" Elsewhere they
made regular preparation to have a

    
	
fight with 
Dugumbe\'s people just to
see who was strongest. They with their 
spears &amp; wooden shields or the Arabs
with what in derision they called tobacco
pipes (guns) They killed eight or nine Arabs.

    
	
The Manyema villages are situated on
slopes - often on the spurs of mountains
for the sake of quick drainage - The
streets run nearly East &amp; West to catch
the full influence of the Sun - The huts

    
	
are of a square form = the walls being of
well beaten clay - they are well supplied
with firewood piled up on shelves along
the walls inside - This is the women\'s work
thatch of leaves or grass - low in the
roof and still lower by each housewife

    
	
having form 20 to 30 neatly made bas-
kets and as many earthen pots hung
to the ceiling - A raised platform of
clay is the sleeping place - a fire at its
side gives light &amp; heat - while a wall

    
	
screens it from the middle compartment
another wall divides off a private room
for stores - the villages are very numerous
a clump of them forms a district with
its headman - It is usually isolated from

    
	
every other - nothing would induce men
to go into next district - they came 5 or 6
miles through the intervening forest
then after civilly inviting us to come
back by the same route on our return

    
	
went back - fear of being killed &amp; eaten
was the reason assigned or simply 
they were at war with their next neighbours
no traders seem ever to have come in
before this - 

Barua
Luba

 brought copper

    
	
and skins for tusks and the 

Babira
Bira


&amp; Baguha coarse beads - The 



Bavira
Babira


Bira


are now enraged at seeing Ujijians
pass into their ivory field - and
no wonder - They took the tusks

    
	
which cost them a few strings of beads
and 
recieved
received
 weight for weight in beads
thick brass wire &amp; loads of calico

To be copied into Journal
 



David Livingstone



            

            

	





	
	




I
 
Bambarre
 18 August 1870 – I learn from Josuf &amp; Moenepembe

who have been to 
Katanga
 and beyond that there is a Lake 
N N W
North North West


of the copper mine and 12 days distant – It is called 
Chibungo
 and is 

said to be large – seven days West of 
Katanga

 flows another 
Lualaba


the dividing line between 
Rua
 and 

Lunda

 or 


Londa
Lunda


 - It is very large 

and as the 
Lufira
 flows into 
Chibungo
 it is probable that the 
Lualaba 

West
 and 
Lufira
 form the Lake = 
Lualaba West
 and 
Lufira
 rise by 

fountains South of 
Katanga
 3 or 4 days. 


Liambai
 and 
Lunga
 
ftns

fountains




are only about 10 miles distant from 


Lualaba West
 &amp; 
Lufira
 fountains
.

a mound rises between them the most remarkable in 
Africa


Were this spot in 
Armenia
 it would serve exactly the description
 
of the 
garden of Eden
 in Genesis with its four rivers – the 



Gihon
 – 
Pison
 
Hiddekel
 and 
Euphrates
 – As it is it possibly 

gave occasion to the story told Herodotus by the 
secretary of
    

Minerva
 in the city of 
Sais
 about two hills with conical tops



Crophi
 and 
Mophi
 – midway between them ^ said he are the 
fountains of the 



Nile


 – fountains which it is impossible to fathom - Half the
 
water runs Northward into 
Egypt
 - half to the South towards 
Ethiopia
.

Four fountains rising so near to each other would readily be supposed to 

have one source and half the water flowing into the 
Nile
 – the other 


ha
ve
lf

 to the 
Zambesi
 required but little imagination to originate, seeing
 
the actual visitor would not feel bound to say how the division 

was effected He could only know the fact of waters rising at one 

spot and separating to flow North and South – The conical 

tops to the mound looks like invention as also do the names.


A slave bought on 
Lualaba East
 came from 
Lualaba
 
West
 in about twelve days – These 
two Lualabas
 may form 

the loop depicted by Ptolemy and 
upper and lower Tanganyika
 

be a third arm of the 
Nile
 – Patience is all I can exercise – these 


irritable ulcers hedge me in now as did my attendants in June

but all will be for the best for it is in Providence &amp; not in me 


	
	



II. The watershed is between 700 and 800 miles long from West to East

or say from ^ 22°- 23° –- to 34° ^ -35°
 East longitude – Parts of it are enormous

sponges - In other parts innumerable rills unite into rivulets which ^ 
again
 
form rivers – 
Lufira
 for instance has nine rivulets and 
Lekulwe
 other 

nine – The Rose of a garden watering can is a not very apt similitude as
 
the rills do not spring off the face of it, and it is 700 miles across the circle

but in the numbers of rills coming out at different heights on the slope

there is a faint resemblance, and I 
cant
can
 at present think of no other – I am

a little thankful to old 
Nile
 for so hiding his head that all "theoretical 
dis-

-coverers
" are left out in the cold With all real explorers I have

a hearty sympathy, and I have some regret at being in a manner compelled obliged to speak

somewhat disparagingly of the opinions formed by my predecessors

The work of Speke and Grant is part of the history of this region and since 

the discovery of the 
sources of the 
Nile


 was asserted so positively

in making a somewhat similar claim it seems necessary to 

explain –, not offensively I hope, wherein their mistake lay – My

opinions may yet be 
shewn
shown
 to be mistaken too – but at present I cannot
 


concieve
conceive
 how - When Speke discovered 
Victoria Nyanza
 in 1858
 
he at once concluded that therein lay the 
sources of the 
Nile


 His 

work after that was simply following a foregone conclusion and 


subsequently as soon as he and Grant looked towards the
 


Victoria Nyanza
 they turned their backs on the 


Nile
 fountains



and so every step of their splendid achievement of following

the river down took them further &amp; further away from the 


Caput
 



Nili


 – 
As soon as When
 it was 
percieved
perceived
 that the little river that leaves 

the 
Nyanza
 though called they called it the 
White Nile
 would not account 

for that great river they might have gone West and found 

Head waters as the 
Lualaba
 to which it can bear no comparison

Taking ^ their 
White Nile

 80 or 90 
yds
yards
 or say 100 
yds
yards

 as its breadth the 
Lualaba


far south of the North end Latitude of its point of departure



shews
shows
 and
 average breadth of ^ 
from 4000 to 6000 yards and always deep.


Baker discovered the 
lower portion of Tanganyika
 – He

came farther up the 
Nile
 than any traveller in modern times

but turned when about 700 miles short of the 
sources




	
	






III. 
a
A
 
Dutch lady explorer
 deserves our sympathy more than any

other for after the loss of he severest domestic afflictions, the loss of her

two aunts by fever she nobly persevered until after she was assured

by Speke and Grant that they had already discovered in 
Victoria

Nyanza
 the 
sources
 she sought – that they not, honestly enough no

doubt, given their own mistaken views - She had 
shewn
shown
 so much

wise foresight in providing not only a steamer but means of

further progress by land and water she must inevitably have

reached the true head waters – I cannot 
concieve
conceive
 of her stopping

short of 
Lake Bangweolo
 – We great He donkeys say exploration

was not becoming her sex – considering that more ^ than sixteen hundred 

years have elapsed since Ptolemy put down the results ^ of early 


explorers, and Emperors, Kings, Philosophers – all the great 

men of antiquity longed to know the fountains whence flowed 

the famous river – and long in vain – exploration does not 

seem to have been very becoming the other sex either – she came 

further up the river than the centurions sent by Nero Caesar 

and 
shewed
showed
 such indomitable pluck as to reflect honour on her race

I know nothing about her save by what has appeared in the public 

papers but taking her exploration along with what was done 



no long time could have elapsed before the laurels 

by Lady Baker I am proud to think that  a



worthy part for ^ the modern rediscovery of the 
sources of the 



Nile


 should have been plucked by the ladies -


In 1841 the ^ 
2nd Egyptian ^ 
2nd
 expedition ^ 

 under D\'Arnauld &amp; Sabatier 

reached North 
Lat.
Latitude
 4° 42\' - This was a great advance into the 



the

 
Interior
 as compared with Linant in ^ 
1827
 13° 30\' 
N.
North

 and even on 

the explorations of Jomard but it turned when nearly a thousand miles from the 
sources






	
	








IV. 
57B 24 August 1870 = Four gorillas or 



soko\'s


sokos
Sokos





 were killed 
169
 


yesterday an extensive grass burning forced them out of 

their usual haunt and coming on the plain they were soon 

speared – they often go erect but place the hands on the head

as if to steady the body - When seen thus he is an ungainly 

beast - The most sentimental young lady would not call him 

a "dear" but a bandy legged – pot-bellied – low looking villain

without a particle of the gentleman in him – other animals

especially the antelopes are graceful and it is pleasant to
 
see them either at rest or moving in motion – the natives 

also are well made, lithe and comely to behold – 

Soko



if large would do well to stand for a picture of the Devil. 

He takes away my appetite by his disgusting bestiality 

of appearance - His light yellow face 
shews
shows
 off his ugly 

whiskers and faint apology for a beard – The forehead 

villainously low with high ears is well in the background

by the great dog mouth – teeth slightly human but the 

canines 
shew
show
 the beast by their large development – the 

hands or rather the fingers are like those of the natives

The fat of the flesh is yellow and the eagerness with 

which the 

Manyuema
Manyema

 devour it leaves the impression 

that eating 

Sokos

 was one sta



g
e by which they arrived 

at being cannibals – they say the flesh is delicious –





       
            

            





	

	






Bambarre
, 25th August, 1870.


One of my waking dreams is that the legendary 
tales about Moses coming up into 
Inner 


Ethiopia


 with Merr his foster-mother, and 
founding a city which he called in her honour 
"
Meroe
," may have a substratum of fact. 
He was evidently a man of transcendent 
genius and we learn from the speech of 



St.
Saint
 Stephen
 that "he was learned in all 
the wisdom of the Egyptians, and was mighty
in words &amp; in deeds." The deeds must have 
been well known in 
Egypt
 for "he supposed 
that his 
brethern
brethren
 would have understood 
how that God by his hand would deliver 
them, but they understood not." His supposition 
could not be founded on his success in 
smiting a single Egyptian. He was too great 
a man to be elated by a single act of prowess
but his success on a large scale in 
Ethiopia
 
afforded reasonable grounds for believing 
that his 
brethern
brethren
 would be proud of their 
countryman, and disposed to follow his 
leadership, but they were slaves. The notice 
taken of the matter by 
Pharaoh
  
shewed
showed
 
that he was eyed by the great as a dangerous  	


304

	
if not powerful man. He "dwelt" in 


Midian
 for some time before his gallant 
bearing towards the shepherds by the well, 
commended him to the Priest or Prince 
of the country. An uninteresting wife and 
the want of intercourse with kindred spirits 
during the long forty years\' solitude of a 

herdsman\'s life, seems to have acted injuriously 
on his spirits, and it was not till he had
with Aaron struck terror into the Egyptian 
mind, that the "man Moses
" again became 
"very great in the eyes of 
Pharaoh
 and 
his servants." - The Ethiopian woman whom 
he married could scarcely be the daughter 
of Reuel or Jethro for Midian was descended 
from Keturah, Abraham\'s concubine, and 
they were never considered Cushite or 

Ethiopian. If he left his wife in 
Egypt
 
she would now be some 50 or 60 years old, 
and all the more likely to be despised by 
the proud prophetess Miriam as a daughter 
of Ham. I dream of discovering some 
monumental relics of 
Meroe
 and if anything 
of confirmatory of sacred history does remain 
I pray to be guided thereunto. If the sacred
chronology would thereby be confirmed, I would 
not grudge the toil &amp; hardships, hunger 
&amp; pain, I have endured - the 

irritable ulcers would only be discipline. -

This 

Manyema country
 is unhealthy not 
so much from fever as from debility of the 
whole system, induced by damp, cold, and 

indigestion. This general weakness is ascribed 
by some to maize being the common food. It  	

	
shows itself in weakness of bowels &amp; choleraic  
purging. This may be owing to bad water, 
there is no scarcity, but it is so impregnated 
with dead vegetable matter, as to have the  
colour of tea. Irritable ulcers fasten on any 
part attached (?) by any accident, and 
it seems to be a spreading fungus for the 
matter settling on any part near becomes a
fresh centre of propagation. The vicinity 
of the ulcer is very tender, and it eats in 
frightfully if not allowed rest. Many slaves 
die of it, and its periodical discharges 
of bloody ichor
 makes me suspect it to be a 
development of fever. Support seems to be 
essential, but the 
ichor forcing its way out is 
so painful the supporting bandages have to 
be loosed. I have found lunar caustic useful. 
A 
plaister
plaster
 of wax, and a little finely ground 

sulphate of copper is used by the Arabs, and 
so is 

cocoa-nut oil

 and 
butter
. These ulcers 
are excessively intractable. There is no healing 
of them before they eat into the bone, especially 
on the shins. The pain causes slaves to cry 
the whole night long.


Rheumatism is also common and it cuts 
the natives off. The traders fear these diseases 
and come to a stand if attacked, in order 
to use rest in the cure. "Taema," or 

Tape-
worm

 is frequently met with - No remedy 
is known among the Arabs &amp; natives for it. 

Syphilitic 

 skin diseases are common among 

Manyema - large scabs on face &amp; body, 
even among children. The Arabs increase 
them by impure intercourse. Filthy takers all.   	

	



6

 

11


White leprosy is also common. Malachite 
ground on a stone with water is good for 

irritable ulcers. 

When Speke saw that his little river out of 
the 
Victoria Nyanza
 would not account for 
the 
Nile
, the more philosophic course would 
have been instead of conjecturing a backwater, 
to strike ^ west across the great valley, and there 
not to mention 

Baker\'s water
 which he too 
might have called a Lake, he would have  
come to the 
central Lualaba
, not 
90 or 100 
yards
 but from 
2000 to 6000 yards and 
always deep - this  near the bottom of the 
trough, and then further West another 


Lualaba
, a worthy companion to that in 
the centre. The 
central Lualaba
 I would 
fain call the 
Lake River Webb

, - the 
Western
 
the 
Lake River Young

. The 
Lufira
 and


Lualaba West
 form a Lake  the native name 
of which, "
Chibungo
"  must give way to 
Lake 

Lincoln

. I wish to name the 
fountain of 
the 
Liambai
 or 
Upper Zambesi


, 

Palmerston 
fountain
, using these two names by way 
of placing my poor little garland on their 
tombs, and adding that of Sir Bartle 
Frere to the 
fountain of 
Lufira


. Three 
names of men who have done more to 
abolish slavery &amp; the slave-trade than 
any of their contemporaries.



4th October 1870
. A 
trading party came from


Ujiji
, arrived on 23d 
Sept

September

, left for 
N.W.
North West
 four 
days afterwards. Report an epidemic raging 
between 
coast
 &amp; 
Ujiji
 &amp; very fatal. Syde bin 
Habib and Dugumbe coming - they have letters

	
and perhaps people for me, so I remain, though 
the irritable ulcers are well-nigh healed. 
I fear that my packet for 
the coast
 may 
have fared badly, for the 

Lewale

 has kept  

Musa Kamaal by him so that no evidence 
against himself or dishonest man Musa 
bin 
Saloom
Salem

 should be given. My box and 
guns with Despatches I fear will never be sent. 

Zahor, to whom I gave calico to pay carriers
has been sent off to 
Lobemba
. Muhamad
sowed rice yesterday. Has to send his 
people who were unsuccessful among 

Balegga
Lega


away to the 





Metambe
Metamba





, where they got ivory 
before. - I cannot understand very well 
what a "Theoretical Discoverer"  is. If anyone 
got up and declared in a public meeting 
that he was the theoretical discoverer of 
the "philosopher\'s stone", of perpetual motion 
for watches, should we not mark him as 
a little wrong in the head? So of the 


Nile
 
sources
. The Portuguese crossed the 
Chambeze
 
some seventy years before I did, but to them 
it was a branch of the 
Zambesi
 &amp; nothing 
more. Cooley put it down as the 
New Zambesi
 
and made it run backwards, uphill
between 
3000 &amp; 4000 feet
! I was misled by 
the similarity of names and a map to think 
it the 
Eastern branch of the 
Zambesi


. I was 
told that it formed a large water in the 
South West. This I readily believed to be 
the 
Liambai
, in the 
Barotse Valley
, and 
it took me eighteen months of toil to work 
back again to the 
Chambeze
 in 
Lake 
Bangweolo
, and work out the error into   	

	


12

which I was led. Twenty-two months elapsed 
ere I got back to the point whence I set 
out to explore 
Chambeze
, 
Bangweolo
, 


Luapula
, 
Moero
, and 
Lualaba
. I spent 
two full years at this work, and the 
Chief 
Cazembe was the first to throw light on 
the subject. - "It is the same water here 
as in the 
Chambeze
, the same in 
Moero
 
&amp; 
Lualaba
 and one piece of water is just 
like another.  Will you draw out calico 
from it that you wish to see it? As your 

chief desired you to see 
Bangweolo
, go to 
it, and if in going north you see a travelling 
party, join it - if not come back to me
and I will send you safely by my path along 


Moero
." 

fox

 



8th 
Octr

October
 1870
. - 
Mbarawa &amp; party came yesterday
from Katomba at 
Mamohela
. Reports that 

Jangeonge (?) with 


Moeneokela
Moeneokila

\'s men had been 
killing people of 



Metamba



 or forest, and 

four of his people slain. He intended 
fighting, hence his desire to get rid of me 
when I went north. Got one and a half 
tusks, but little ivory, but 
Katomba\'s party 
got fifty tusks. Abdullah had got two tusks 
also been fighting, and Katomba had sent 
a fighting party down to 
Lolinde
. Plunder &amp; 
murder is Ujijian trading
. Mbarawa got 
his ivory on the 
Lindi
 or as he says "
Urindi
" 
which has black water, and is very large - 
An arrow could not be shot across; its 


400 or 500 yards
 had to be crossed by canoes, 
goes into 
Lualaba
. - It is curious that all 
think it necessary to say to me, "The Manye   	

	

Manyema are bad - very bad." The 

Balegga
Lega

 
will be let alone, because they can fight, and 
we shall hear nothing of their badness. My 

slavelings join in the chorus of the Manyema 
being bad. The 

Babemba
Bemba

 were good said 

Simon, and he killed two because he was
safe. - -

  

            

            

	



	
	



X.
 to be copied into Journal = 10th 
Octr

October
 1870 
came
Came
 out of hut today 
1


 
after being confined to it since 22nd July or 80 days – by irritable

ulcers on the feet - The last 20 days I suffered from fever
 
which reduced my strength, taking away my voice and 

purging me = appetite good but the third mouthful of any 

food caused 





n
ausea

 &amp; vomiting – purging took place of

profuse sweating – I am thankful to feel myself well – 

only one ulcer open the size of a split pea – Malachite was

the remedy most useful but the beginning of the rains may
 
have helped the cure as it does to others = copper rubbed down

is used when malachite cannot be had – We expect 


Syde 
Bin
bin
 Habib soon - He will take to the river and I 
 
hope so shall I – The 
native traders reached people who 

had horns of oxen got from left bank of 
Lualaba
 – 

Ka-

tomba
’s people
 got most ivory namely 50 tusks – the others 

only four – the 



Metamba



 or forest is of immense extent 

and there is room for much ivory to be picked up 

at 5 or 7 bracelets of copper per tusk if the slaves sent 

will only be merciful – The nine villages and a 100 men 

killed by 
Katomba’s slaves
  at 

Nasangwa
\'s

 were 

all about a string of beads fastened to a powder horn 

which a 


manyema
Manyema

 man
 tried in vain to steal – – 
Ka
Katomba



gets 25 of the 50 tusks brought by his people



	
	


XI. 
we
We
 expect letters &amp; perhaps men by Syde 
Bin
bin
 Habib.
 

No news from 
the coast
 had come to 
Ujiji
 save a rumour
 
that some one was building a large house at 


Bagamoio
Bagamoyo


 

but whether French or English no one can say – possibly 

the Mission urged on by 
Colonel Playfair &amp; Dr Kirk 


Tozer curiously enough follows the policy of 


Bp
Bishop

 Mackenzie

which he so formally repudiated – Rearing boys got from 


captives of men of war and writing to 
India
 that to teach 

the young thus obtained is the great secret of mission work 

He does not know that the especial instruction 

of the young has been advocated &amp; acted on for the last 

30 years in 
Africa
 
India
 

South Seas

 &amp; elsewhere – Possibly 

the erection of a huge establishment on the 
mainland


may be a way of laboriously proving that it is more healthy 

than the island to which he was driven by fear of death 

It will take a long time to prove by stone &amp; lime that the higher 

lands 200 miles inland 
ar
are
 better still both for longevity 

and work – I am in agony for news from home

All I feel sure of now is that my friends will all wish 

me to complete my task – I join in the 
wis
wish
 now as 

better than doing it in vain afterwards


	
	



XII. The Manyema hoeing is little better than scraping the 
2




soil &amp; cutting through the roots of grass &amp; weeds by a horizontal
 
motion of the hoe or knife – They leave the roots of maize


groundnuts – sweet potatoes &amp; dura to find their way into 

the rich soft soil, and well they succeed so there is no need

for deep ploughing - The groundnuts &amp; 

cassave
cassava

 hold their 

own against grass for years Bananas if cleared of 

weeds yield abundantly – 
Muhamad sowed rice 

just outside the camp without any advantage being secured 

by the vicinity of a rivulet and it yielded for one measure 

of seed one hundred &amp; twenty measures of increase – This 

season he plants and on the damp soil
 
along a rivulet called 



bonde
Bonde


 The rainwater does not
 
percolate far – The clay retains it about 2 feet beneath the
 
surface – this is a cause of unhealthiness to man – Fowls 

and goats have been cut off this year in large numbers 

by an epidemic -






Sentence to be inserted after "
"
\'
there may only be a thread
"
\'
 

of water at the bottom but the mud is grievous" Some 20 

or 40 yards of the path on each bank is mixed up by the feet 

of passengers into a deep 
stickey
sticky
 mass – 



You
 may put one 

foot on each side 
and
of
 the walk and waddle onwards but soon

that fails you for the rank vegetation often usurps the few

foot holds you have and down


inches you come into the mire



	
	



XIII. Often too the path takes the bed of the rill for 50 or 60 
yds
yards

 

as if the first passenger had gone that distance seeking a space 

of forest less dense for his path = Near a village the road run-

-ning along a rivulet may have been to make it difficult for an 

enemy to find a path by night = The approaches to hamlets on the
 
side of a hill are certainly made with a view to confuse marauders 

for they come near the dwellings and then ascend to a point
 
above the highest point of the village, and they go winding up 

and down the steepest parts of the slope The rank vegetation 

being left so that it is impossible to take a straight course –  


The visit of the Ujijian traders
 must be felt by the 
Man-

-yema
 to be a severe infliction - The huts are appropriated and 

no leave asked – Firewood - pots – baskets of food used without 

scruple and anything that pleases is taken away – Usually the 

women flee into the forest and return to find the whole place a
 
litter of broken food – I tried to pay the owners of the huts in 

which I slept but often in vain for they were hidden in the forest

and feared to come near – It was common for old men 

to come forward to me with a present of bananas as I passed 

uttering with trembling accents "Bolongo
" "Bolongo" friendship
 
friendship. If I stopped to make a little return present others
 
ran for plantains or 
palm toddy = The slaves eat up what 

they demanded without one word of thanks - "but they are 

bad" "

dont
don\'t
 give them anything" "Why what badness is there in 

giving food" - "O they like you" "but hate us" - one man gave
 
me an iron ring and seemed inclined to be friendly – 

yet they are undoubtedly bloodthirsty to other Manyema 


&amp; kill each other
       
            

            

  	

	

	







16th 
Octr

October
 1870
 - Moenemgoi 
the chief came to tell me that Monamyembo 
had sent five goats to 
Lohombo
 to get a charm 
to kill him. "Would the English and Kolokolo 
(Muhamad) allow him to be killed while 
they were here?" I said that it was a false 
report but he believes it firmly. Monamyembo 
sent his son to assure us that he was 
slandered, but thus quarrels and bloodshed 
feuds arise. The great want of the Manyema 
is national life. Of this they have none. 
Each headman is independent of every other. 
Of industry they have no lack, and the villagers 
are orderly towards each other, but they go 
no further. If a man of another district ventures 
among them it is at his peril. He is not 
regarded with more favour as a Manyema 
than one of a herd of buffaloes is by the 
rest. He is almost sure to be killed. 



Moenekus
Moenekuss

 had more wisdom than his 
countrymen. His eldest son went over to 



Monamyembo\'s
 who was subject to the father
was killed by five spear wounds. The old 

chief went and asked "Who had kllled slain 
his son"? "None knew, perhaps the Bahombo." 


he
He
 went thither - They denied it - Then they 
said "Perhaps Monamdenda" - he denied. 


question
Question
 repeated, received same answer - 
"
didn\'t
Didn\'t
 know." The old man ^ then died - This,   	

	


8.
 15
though he was heartbroken was called witch-
craft by Monamyembo. Eleven people were 
murdered, and after this cruel man was 
punished he sent a goat with the confession 
that he had killed 

Moenekus
Moenekuss

\' son. This 
son had some of the father\'s 

 wisdom. 
The others he never could get to act like men 
of sense.



The sites chosen for some of the most signal 

Grecian oracles were marked by the rushing 
forth of a living spring from the recesses of 
the native rocks of 
Greece
, the 
Castalian 
springs
 at 
Delphi
, the rushing stream of 
the 
Hercynia
 at 
Lebadea
. It was felt that 
nothing could so well express the Divine voice
speaking from the hidden abysses of the 
unseen world as those inarticulate but lively 
ebullitions of the life giving element from its 
unknown mysterious sources. The prophetic 
utterances in the remoter 
East
 were the 
bubbling, teeming springs of life in those hard 
primitive rocks, in those dry parched levels. 
"My heart is inditing" - is bursting, bubbling 
over with a good matter. This image would be 
drawn from the abundant crystal fountains
which all along the valley of the 
Jordan
 pour 
forth their full grown streams, - scattering 
fertility and verdure as they flow over the 
rough ground, - "boiling or bubbling over" of 
the "Divine fountain of Inspiration within 
the Soul." 

"The words of Judgment bursting out one by 
one, slowly, heavily, condensed, abrupt from 
the prophet\'s heavy and shrinking soul; each   	

	
sentence wrung forth with a groan, as though 
he had anew to take breath before he uttered a  
renewed woe; each word forming a whole for 
itself, like one heavy toll of a funeral knell." 
(Pusey) - - (Jowett) "At the time when our 
Saviour came into the world the Greek language 
was in a state of degeneracy &amp; decay. But that  
degeneracy may be ranked among the causes 
that fanned the growth of Christianity. It was 
a preparation for the Gospel, the decaying soil 
in which the new elements of life were to come 
forth, the one common speech of the then 
civilized nations of the world. The definiteness 
of earlier forms of human speech would have 
imposed a limit on the freedom of the Gospel. 
A religion which was to be universal required
that the division of languages, no less than 
of nations should be broken down. It pleased 
God through broken and hestitating forms of 
speech to reveal the universal truth for which 
the Greek of Plato would have been no fitting temple". - 


  
   

            

            

	

	
	



XIV 13th 
Octr

October
 1870 – 

Lions

Lion\'s
 fat is asserted to be a certain  
1


preventative to the bite of the Tsetse – Lions are very numerous

in 
Urori
 and many are killed and the fat sold – the Garaganza

use it to protect their cattle and when smeared on the animals

the Tsetse comes not near them on accout of the smell – 



on coming inland the safe way is to go to 1 
Mdonye
  



2 

Makinde
 3 

Zungomero
 4 
Masapi
 5 
Irundu



then turn 
^
 North to the Nyamnyams and thence to the 
Nyembe




6 
Nyamgore
 &amp; then South to 

Merere’s


                	

and so on South to 

Merere’s
 – A woman chief lies in

the straight way to Merere but no cattle live in her land – 

another insect lights on the animals &amp; when licked off bites the tongue

or breeds &amp; is fatal as well – as tsetse – It is large in size – 




Tipotipo &amp; Syde bin Ali come to 
Nyembe
 – thence

to 



Nsamas

Nsama\'s


 cross 
Lualaba
 at 



Mpwetos

Mpweto\'s


 – follow left bank

of that river till they cross the next 
Lualaba
 &amp; so into 



Lunda
 of 
Matiamvo – much ivory may be obtained

by this course &amp; it 
shews
shows
 enterprise –-




Syde bin Habib &amp; Dugumbe will open up the



Lualaba
 this year and I am hoping to enter the 
West

Lualaba
 or 



Youngs

Young\'s
 river
, and if possible go up to



Katanga
 – The Lord be my guide &amp; helper – I feel the 
3



want of medicine strongly as much almost as of men


	
	





Turn over = safe way to avoid the 



2
 Tsetse in going to 

Merere\'s
 ^ North to 1 
Mdonye


2 
Makinde
 3 
Zungomero
 4 
Masapè


5 
Irundu
 6 
Nyamgore
 = then South

to 

Merere\'s






Msene
 6 days from 


Unyembe
Unyanyembe


 North


market &amp; many Arabs live there







all these ten Rivers go into 




Uerere




Uerere










Mokunge
 three eyes or fountains all

very hot.








Livingstone has here drawn a map, which he places at "about 1° South 
Lat.
Latitude

" The map depicts a series of 10 rivers running west to east, all flowing "to 




Uerere




Uerere


 Lake
" in the east (which lake does not itself appear on the map). The rivers are laid out in the following order from north (top) to south (bottom) (distances in days between them are also provided): 
Sombo 
R
River


, 


R
River
 Kabilo
, 


R
River
 Molegere
, 
Mokunge
 (hot fountain), 
Simnambe 
R
River


, 


R
River
 Ngoye
, 
Mokunge 
R
River


, 
Mogonye 
R
River


, 
Kipembo 
R
River


, and 
Lua 
R
River


. Then the following, separate set of rivers, running east to west and uniting into a single river, appear: 
Kuruse 
R
River


, 
Lobondo 
R
River


, and 


R
River
 Logumba
. The path of Ramadan and Hassani as a dotted line runs across these rivers north to south ending at what appears to be a village, 

Kanyingere

, in the south. Finally, near its center, the map also identifies the 

Balegga
Lega

 country and notes that "





Balegga
Lega

 country
Legaland


 all excessively mountainous."








 Travelled 199

hours but so

mountainous 

say 200 miles








 Rivers crossed

by Ramadan &amp;


Hassani August

and 

Septr

September
 1870

in 


Balegga
Legaland


 -

They fall into 





U-

-
irere
erere







 
-
?
 

Baker
\'s



or what a


"large water" -

            

            

	

 

	
	



XVII to be copied - 19th 
Octr

October

 
Bambarre
 = The Ringleading



Nassick
 deserters sent Chuma to say that they were going with the


people of Muhamad
 wh
at
ich

 left today to the 



Metamba



 = I said 

that I had naught to say to them – They would go now to the






Metamba



 which on deserting they said they so much feared &amp; left

me to go with only three attendants and get my feet torn to

pieces in mud &amp; sand = They probably meant to go back to the

women at 
Mamohela
 who fed them in the absence of their husbands

They were told by Muhamad - that they must not follow his 

people and he gave orders to bind them &amp; send them back if

they did – They think that no punishment will reach them

whatever they do – They are freemen &amp; need not work or do any

thing but beg. "English" they call themselves &amp; the Arabs fear

them though the eagerness with which they engaged in 
slave

hunting 
shewed
showed
 them to be genuine niggers – To lie without

compunction seems to be one of their 
Indian
 acquisitions – Ibram

said "that I told him to beg"! and Simon said that I had spoken

to him only once &amp; he would 




ha
ve gone on intended to go till I took

the gun from him – Derrides any entreaties 

Katumba
Katomba

 spoke

persuasively several times &amp; he refused to go – The gun would

have been used to steal from the Manyema as it was when we

came back here to bully them for four fowls.



20th
 

first
First
 heavy rain of this season fell yesterday afternoon


It is observable that the permanent halt to which the Manyema

have come is not affected by the appearance of superior men among

them - They are stationary &amp; improvement unknown - 

Moenekus
Moenekuss

 paid


smiths to teach his sons and they learned to work in copper &amp; iron

but he never could get them to imitate his own generous and

obliging deportment to others – He had to reprove them perpetually for

mean short sight ways and when he died he virtually left no

successor for his sons are both narrow minded, mean, 

short sighted creatures, without dignity or honour –










Lonzua
 
Luaze
 
Luanzo

 







All they can say of




their forefathers is that 

they came from 
Lualaba
 up 
Luamo
 then to 
Luelo
 and

thence here – The name seems to mean forest people – 




Manyuema
Manyema

 =  


p
page
72 into Last 
Journal
Journals

 
p
page
72



The party under Hassani
 crossed the 
Logumba
 at 




Kanying
Kanyin

-

gere
’s
 – and went 
N. &amp; N.N.E.
North &amp; North North-East
 – They found the country

becoming more &amp; more mountainous till at last when



one day
 from 




Uerere




Uerere




 it was perpetually up &amp; down



They slept at a village on the top They could send for 

water to the bottom only once. It took so much time to

descend &amp; ascend – Rivers all flowed into 




Uerere




Uerere




 or



Lower Tanganyika
 Hot fountain – water could not

be touched nor stones stood upon  

Balegga
Lega

 very un-

friendly – collected in thousands – we

came to buy ivory -

said Hassani &amp; if

there is none we       

go away



Map of "


Riverein
Riverine
 Lake Tanganyika
" and its major affluents.





"Nay" shouted they, "you

came to die here" then

shot with arrows - when

shot was returned they

fled &amp; would not come

to receive the captives
 


	
	
  


XVIII. 25th 
Octr

October
 1870- 
Last 
Jour
Journals

 
f
folio
 II  72 
Bambarre
 = to be copied 



In this Journey I have endeavoured to follow with

unswerving fidelity the line of duty – my course has

been an even one turning neither to the right hand

nor the left though my route has been tortuous

enough = All the hardship hunger &amp; toil were met

with the full conviction that I was right in persever-

ing to make a complete work of the exploration of the 



sources of the 
Nile


 – Mine has been a calm —

hopeful endeavour to do the work that has been given

me to do whether I succeed or whether I fail – The prospect

of death in following pursuing what I knew to be

right did not make me veer to one side or the other

I had a strong presentiment during the first three

years that I should never live through the work enterprise

but that weakened as I came near to the end of the 

journey – and a strong desire to discover any

evidence of the great Moses having visited these

parts bound me – spellbound me – I may say

for if I could bring to light anything to confirm

the sacred oracles I should not grudge one whit all

the labour expended – I have to go down the 
central

Lualaba
 or 

Webb’s lake river
 – Then up the 
Western


or 



Youngs

Young\'s
 lake river
 to 


Katanga
 head waters
 &amp; then 

retire – I pray that it may be to my native home


Syde bin Habib – Dugumbe – Juma Merikano


Abdullah Masudi are coming in with 700 muskets

and immense store of beads copper &amp;c They will

cross 
Lualaba
 &amp; trade West of it – I wait for them

because they may have letters for me – I have had no


letter from 
th
the
 Foreign Office
 – The last I had was a 

piece of the most 
exhuberant
exuberant
 impertinence that 


ever left the Foreign or any other office – I was to

have no claim for any services rendered = no

position when my work was done – 

Lord Russells

Lord Russell\'s


name had been obtained to it though a statesman

like him might bind future Governments to

to give 

h

H

e never would enjoin them not to give

This bore internal evidence of being the effusion

of the 
supernumerary undersecretary Murray

I expect only the same treatment that Murray would

claim for himself – The offer of other work or

of being provided with another office – The slave

trade on the 
West Coast
 having ceased he ought

to have resigned but he thought to earn his salary

by unjustly stopping mine – The only annoyances

I have suffered were from this as Lord Clarendon

called it an "ungracious &amp; unjust" letter. and from a 


letter of busybody instructions from the 

R.G.S.
Royal Geographical Society


 
(Sheet 9)




	
	








	
		

Syde bin Salem Burashid


family Lumke

		

		
		



Mengongo

 
soga
 – 
Guke
 a fish



sangardo
 – 
Do

Ditto

		
	






XIX. 
28 
Octr

October


 

Moenemokaia
Moenemokia

 who has travelled further

than most Arabs said to me "If one goes with a good

natured civil tongue, he may pass through the worst

people in 
Africa
 unharmed" This true – time

also is required – one must not run ^ through a country, but

give the people time to become acquainted with

you and let their first fears subside —



29th
 The Manyema buy their wives from each other

a pretty girl brings ten goats – saw one brought

home today – she came jauntily with but one 


attendant and her husband walking behind -

They stop five days – then go back and remain other

five days at home – The husband fetches her again

Many are pretty – and have perfect forms and

limbs – They hoe large spaces for maize – It is 

merely scraping the surface The soil is so rich

no more is needed



31st 
Oct
October

 – 

Monangoi
Moenemgoi

 of 
Luamo
 – married to the

sister of Moenekuss came some time ago to beg that




Kanyingere

 be attacked by 
Muhamad\'s people – 

no fault has he "but he is bad" – 

Monangoi
Moenemgoi

 the 


chief here offered two tusks to effect the same thing

on refusal he sends the tusks to Katomba &amp; may get 

his countryman spoiled by him – "He is bad" is all they 

can 
alledge
allege
 as a reason – Meantime this chief here 

caught a slave who escaped = a prisoner from 




Moenemokia\'s
 and sold him or her to Moenemokia 

for 30 spears &amp; some knives – When asked about this 


captive he said "she died" – It was simply theft - but 

he does not consider himself bad



2nd November 1870  – The plain without trees 

that flanks the 
Lualaba
 on the right bank

called 

Mbuga

 is densely peopled and the  

inhabitants are all civil and friendly – From 

50 to 60 large canoes come over from the left 

bank daily to hold markets – These people too are 

good but the dwellers in the 



Metamba



 or 

dense forest are treacherous and murder a single 

person without scruple – The dead is easily concealed

while on the plain all would become aware of it


I long with intense desire to move on &amp; finish 

my work – I have also an excessive wish to find 

any thing that may exist proving the visit of the 

great Moses &amp; the ancient 
Kingdom of Tirhaka






but I pray give me just what pleases Thee my 

Lord – and make me submissive to Thy will in all things

            
			

	
	





XX.
 I 
recieved
received
 information about Mr Young\'s search 

trip up 
Shire
 and 
Nyassa
 only in February 1871 and 

now take the first opportunity of offering hearty thanks

to 

H M
Her Majesty\'s
 Government and all concerned in kindly enquiring 

after my fate – 
Musa and his companions
 are fair average

specimens for heartlessness and falsehood of the lower 

classes of 

Muhamadans
Muhammadans

 in 
East 
Africa


 - When on the 



Shire
 we swung the ship into midstream every night in order 

to let the air put in motion by the water pass from end to end


Musa\'s brother in law stepped into the water one morning

in order to swim off for a boat – and was seized by a crocodile

The poor fellow held up his hand imploringly but Musa and 

the rest allowed him to perish – on my denouncing his 

heartlessness, Musa replied “Well – no one tell him = go in there" 

When at 
Senna
 a slave woman was seized by a crocodile,

four 

Makololo
Kololo

 rushed in unbidden and rescued her – 

though they knew nothing about her. From long inter-

course with both I take these incidents as typical of the  

two races. Those of mixed blood possess the vices of both 

races and the virtues of neither – A gentleman of superior 

abilities has devoted life and fortune to elevate the 

Johanna
  

men but fears that they are "an unimprovable race"

The 
Sultan of 
Zanzibar

 who knows his people better than 

any stranger cannot entrust any branch of his revenue 

to even the better class of his subjects but places

his customs income and money affairs in the hands 

of 
Banians from 
India

, and his father did the same

before him – When the 


Muhamadan
Muhammadan

 gentlemen of



Zanzibar
 are asked Why their sovereign places all his

pecuniary affairs and fortune in the hands of aliens they 

frankly avow that if he allowed any Arab to farm his 

customs he would receive nothing but a crop of lies - Burton

had to dismiss most of his people at 
Ujiji
 for dishonesty – 





Spekes

Speke\'s
 followers deserted at the first approach of danger


Musa fled in terror on hearing a false report from a half

caste Arab about the 



Mazitu
Maviti


Ngoni

 150 miles distant though 

I promised to go due West and not turn to the North till far 

past the beat of that tribe – The few liberated slaves with  

whom I went on had the misfortune to be 


Muhamadan
Muhammadan



slaves in boyhood but did fairly till we came into close 

contact with 

moslems
Moslems

 again. A black Arab ^ was released 

from a 12 years bondage by Cazembe through my own 

influence and that of the 
Sultan\'s letter = We travelled 

together for a time and he sold the favours of his female 

slaves to my people for goods which he perfectly well knew 

were stolen from me – He 
recieved
received
 my four deserters

and when I had gone off to 


L
Lake
 Bangweolo
 with only four 


attendants the rest wished to follow but he dissuaded 

them by saying that “I had gone into a country where there 

was war” – He was the direct cause of all my difficulties 

with these liberated slaves but judged by the 

East 
Africa


n 


Moslem
 standard as he ought to be and not by ours - He is

a very good man, and I did not think it prudent to come 

to a rupture with the old blackguard –


	
	


	
	


	
	


	
	


Geographical calculations relating to the 
Lindi River
 and the villages of 
Nyangwe
 and 
Ujiji
.




Last Journals 
Vol
Volume
 
p
page
 71
 

            

            

	

    

    
	


XXI Laba means in the Manyema dialect medicine - 
3

a charm - "boganga" This would make  
Lualaba
 mean the
river of medicine or charms - but we do not hear of
its being famed among them as the 
Ganges
 is in


India
 - and possibly this is not the proper meaning 
of the word - Muhamad and others found its banks
very healthy and it yields abundant food both 
in its waters and on its banks. The sacred River 
does not accord with the fact of 
Lualaba
 being
applied to the 
Lufira
 when it becomes large
and also to the third 
Lualaba
 or 

Young\'s river

still further West dividing 
Rua
 from 


Lōnda
Lunda


 -

Hassani thought that it meant great because
it seemed to mean flowing greatly or grandly -



Cazembe caught all the slaves that escaped
from Muhamad and placed them in charge of 
Funga-
-funga
 so there is little hope for fugitive slaves so long as

Cazembe lives =  This act is to the 

Arab\'s
Arabs

 very good -
He is very sensible and upright besides - XXI


    
	


XXII 3d 
Novr

November
 1870 
got
Got
 a 
Kondo 

hondoas
hondeas


 the large 
double billed Hornbill The ^ 

Buceros cristata

 
Kangomira
 of the 
Shire
 and 
the 
Sassassa of 
Bambarre

 - It is good eating = The
fat of an 

orangetinge
orangutan


 like that of the zebra I keep
the hide to make a spoon of it - An Ambassador
at 


Stanboul
Istanbul


 or 
Constantinople
 was 
shewn
shown
 a

hornbill spoon and asked if it were really the bill
of the Phoenix - He replied that he did not
know but he had a friend in 
London
 who knew
all these sort of things - The Turkish Ambassador
in 
London
 brought the spoon to 
Professor Owen
He observed something in the divergence of the
fibres of the horn which he knew before and
went off into the Museum of the 
college
College
 of Surgeons
and brought a preserved specimen of this very 
bird - "God is great - God is great" said the Turk 
This is the Phoenix of which we have heard so often =
I heard the professor tell this at a dinner of the



London
 Hunterian Society in 1857. 

    
	


XXIII There is no great chief in Manyema or 

Balegga
Lega

 
4

all are petty headmen each of whom considers himself a

chief - It is the Ethnic State with no cohesion between
the different portions of the tribe - Murder cannot 
be punished except by a war in which many
fall and the feud is made worse and trans-
mitted to their descendants. 


cor


cor
copied



copied



+ The 

Soko

 is represented by some to be extremely
cunning stalking succesfully men &amp; women
while at their work - kidnapping children -
and running up trees with them - He seems
to be amused by the sight of the young native
in his arms - but comes down when tempted 
by a bunch of bananas and as he lifts that
drops the child - The young 

Soko

 in that case would
cling closely to the armpit of the older - One man
was cutting out honey from a tree and naked a 



Soko

 suddenly appeared &amp; caught by 
by

 the privates 

    
	

XXIV then let him go Another man was hunting 
and missed in his attempt to stab a 

Soko

 - 

Soko

 seized
the spear &amp; broke it then grappled with the man who
called to his companions "




Soko

 has caught me" he bit off
the ends of his fingers 

and escaped unharmed -
both men are now alive at 
Bambarre
 

Soko


is so cunning and has such sharp eyes that no
one can stalk him in front with ^ out being seen by
his small sharp eyes, hence when shot it is
always in the back - When surrounded by men
and nets he is generally speared in the back too
otherwise he is not a very formidable beast -
He is nothing as compared in power of damaging
his assailant to a leopard or lion - He is
more like a man unarmed - It does not occur
to him to use his canine teeth which are long
and formidable - 

Sokos

 come down in the 
forest within a hundred yards of our camp &amp; would be  
unknown but for giving tongue Like fox hounds
This is his nearest approach to speech -

    
	


XXV A man hoeing having his privates uncovered 
5

behind was stalked by a 

Soko

 and seized thereby - He
roared out but 

Soko

 giggled &amp; grinned &amp; left him
as if he had done it in play - a child caught up
by 

Soko

 is often abused by being pinched &amp; scratched 
and let fall He is said sometimes to use a 
spear drawn out of his own body but this is denied
by some - 

Soko

 kills the Leopard occasionally by
seizing both paws &amp; biting them so as to disable
them - 

Soko

 goes up a tree groans over his 
wounds &amp; sometimes recovers - while Leopard
dies - At other times both 

Soko

 &amp; Leopard die -

Lion kills him at once and sometimes tears his
limbs off but does not eat him - 

Soko

 eats
no flesh - 


small bananas 

are his dainties but
not maize - his food consist of wild fruits
which abound - one 
Stafene
 or 
Manyema mamwa
 is
like large sweet sop but indifferent in taste &amp; flesh



Soko

 brings forth at times twins - never catches women


    
	



XXVI A very large 

Soko

 was seen by 

Muhamads

Muhamad\'s


hunter sitting picking his nails - tried to stalk him but
he vanished - Some Manyema think that their buried
rise as 

Sokos

 - one was killed with holes in his ears
as if he had been a man - 


 He is very strong - fears guns
but not spears -



The 
Heathen Philosophers
  were content with mere 
guesses at the future of the Soul - The elder prophets

were content with the Divine support in life and in 
death - The later prophets
 advance further as

Isaiah - "Thy dead men shall live together with my
dead body shall they arise - awake and sing ye that 
dwell in the dust for thy dew is as the dew of herbs
the earth also shall cast out her dead" This taken
with the sublime spectacle of Hades in the XIV chap
seems a forecast of the future but Jesus instructed

Mary and her sister and Lazarus &amp; Martha without
hesitation spoke of the resurrection at the last
day  as a familiar doctrine far in advance of its


Mosaic law in which 
she h
she had
 been reared


    
	


XXVII 
6


 




Ikwenu alumwa = 
Lualaba
 salutation


a ko sema iamwu Manyema 
Do

Ditto
 to men


Doshanga kakaka 
Do

Ditto
  to women





Monyungo chief was sent for five years among the





Watuta
Batuta


Ngoni

 to learn their language and ways - He sent
his two sons and a daughter to 
Zanzibar
 to school
Kills many of his people says they are so bad if
not killed they would murder strangers - Unruly
ordered some of them to give their huts to Muhamad
refusing he put fire to them &amp; they soon called
out "let them alone we will retire" - He dresses
like Arabs has ten loaded guns at his sitting place
four pistols - two swords several spears and
a two bundles of the 

Batuta
Ngoni

 spears - laments
that his 

 father filed his 

 teeth when 

 he was young

The names of his very numerous people is 

Bawungu
Bungu




country Wungu
 = his other names are Iranga - Mohamu


    
	


XXVIII The 

Basango
Sangu

 on the other hand consider their chief
as a deity and fear to say aught wrong lest he should hear
them = They fear both before him &amp; when out of sight = The
Father of 


Merere never drank pombe or beer and 
assigned as a reason that a great man who had
charge of people\'s lives should never become
intoxicated so as to do evil = Bange he never
smoked but in council smelled at a bunch of it
in order to make his people believe it had 
great effect on him - - 
Merere drinks pombe
freely but never uses Bange - He alone kills

sheep - He is a lover of mutton - and beef
but neither goats nor fowls are touched by him


9 th 
Novr

November
 1870 
sent
Sent
 to 
Lohombo
 for dura
and planted some 
Nyumbo
 - I long excessively
to be away and finish any work by the 
two Lacustr
Lacustrine rivers
 
Lualaba
 of 

Young

 and 

Webb


but wait only for Syde &amp; Dugumbe who may

have letters and as I do not intend to return

    
	

XXIX hither but go through 
Karagwe
 homewards 
7

I should miss them altogether - I groan and am
in bitterness at the delay but thus it is - I pray
for help to do what is right but sorely am I
perplexed and grieved and mourn - I
cannot give up making a complete work of
the exploration 




10th November 1870 a party of 

Katombas

Katomba\'s
 men
arrived on their way to 
Ujiji
 for carriers - they
report that a foray was met 
S W
South West
 of 
Mamohela

to recover four guns which were captured
from Katomba and his people killed when
last here - Three were recovered and ten
of the 
Arab party slain The people of 
Manyema


fought very fiercly with arrows and not till
many were killed and others mutilated would
they give up the guns - They probably expected
this foray and intended to fight to the last

    
	



XXX - They had not gone in search of ivory while
this was enacting consequently 


Muhamads

Muhamad\'s
 men 
have got the start of them completely by going along


Lualaba
 to 

Kasongo\'s
 and then along the western verge
of the 



Metamba



 or forest to 
Loinde
 or 
Rindi 
R
River


 -
The last men sent took to fighting instead of trading
and returned empty - The experience gained
thus and at the South West will probably
lead them to conclude that the Manyema are
not to be shot down without reasonable cause
They have sown rice and maize at 

Mamo-
hela

 but cannot trade now where they got
so much ivory before - Free men were
killed at 
Rindi
 or 
Loinde
 and one escaped
The reason of this outbreak by men who have
been so peaceable is not divulged but anyone
seeing the wholesale plunder to which the houses
&amp; gardens were subject can easily guess the rest
                
    
                
    
	


XXXI 

Mamohela
 camp had several times been 
8


set on fire at night by the tribes which suffered assault
but did not effect all that was intended - The Arabs
say that the Manyema now understand that
every gunshot does not kill - The next thing they
will learn will be to grapple in close quarters
in the forest where their spears will outmatch
the guns in the hands of slaves - It will follow
too that no one will be able to pass through this 
country - this is the usual course of 


Suaheli
Swahili



trading
 - It is murder and plunder and each

slave as he rises in his 
owners
owner\'s
 favour is
eager to 
shew
show
 himself a mighty man of valour
by cold blooded killing of their country men
If they can kill a fellow nigger their pride boils up
The conscience is not enlightened enough to cause un-
-easiness and Moslemism gives less than the light of
nature - I am grievously tired of living here.

    
	

XXXII Muhamad is as kind as he can be but to
sit idle or give up before I finish my work are
both intolerable I cannot bear either yet am forced
to remain by want of people - Merciful Father Help me 





11th 
Novr

November

 Wrote to Muhamad bin Saleh at 
Ujiji

for letters and medicines to be sent in a box of





china
China


 tea which is half empty - If he cannot 
get carriers for the long box itself - then he is
to send these the articles of which I stand in
greatest need -


Friends of a boy captured at 


Monanyembe
Monamyembo



brought three goats to redeem him - He is sick
and emaciated - one goat was rejected - The boy
cried tears when he saw his grandmother
and the father too when his goat was rejected
"So I  returned and considered all the oppressions
that are done under the Sun - and behold the tears
of such as were 

were


 oppressed and they had



    
	


XXXIII no comforter, and on the side of their oppression 
9


there was power but they had no comforter" 

Ecc
Ecclesiastes
 
IV-I
4:1


the relations were told either to bring the goat or let the
boy die - This was hard hearted - at 
Mamohela

ten goats are demanded for a captive &amp; given too
Here three are demanded "He that is higher than the


"

highest regardeth, and there be higher than they
"

 


"

marvel not at the matter"


I did not write to 
the coast
 for I suspect that the



Lewale

 Syde bin Salem 
Buraschad
Burashid



 destroys my
letters in order to quash the affair of robbery by his
man 

Saloom
Salem

 he kept the other thief Kamaals by
him for the same purpose - Muhamad writes
to Bin Saleh to say that I am here &amp; well - that I
sent a large packet of letters in June/69 - with money
received no answer - nor my box from 


Unyembe
Unyanyembe



and this is to be communicated to the consul by a friend
at 
Zanzibar
 - If I wrote it would only be to be burned
This is as far as I can see at present

    
	


XXXIV. The friend who will communicate with
the consul is Muhamad bin Abdullah the 

Wuzeer





Seyd
Seyed
 Suleiman is the 



lewale
Lewale



 
of
or
 the Governor of 
Zanzibar
 

Suleiman bin Ali or 

Sheikh Suleiman
 the Secretary



The 
Mamohela
 horde is becoming terrified
Every party going to trade has lost three or four
men and the last foray lost ten and saw
that the Manyema can fight - They will soon
refuse to go among those whom they have forced
to be enemies - one of the Bazula invited a 
man to go with him to buy ivory - when well
in among 

Zulas
Bazula

 he asked if his gun
killed men and how - He was 
shewn
shown
 a bale


 and powder and stabbed his informant dead 
no one knows the reason of this but the
man probably lost some of his relations else-
where - This is called murder without cause




    
	


XXXV. When Syde and Dugumbe come I hope to 
10

get men and a canoe to finish my work among
those who have not been abused by Ujijians 
and still retain their natural kindliness of
disposition None of the people are ferocious
without cause, and the sore experience which
they gain from slaves with guns in their hands
usually ends in sullen hatred of all strangers
the education of the world is a terrible one
and it has come down with relentless rigour
on 
Africa
 from the most remote times - What
the African will become after the 

awfully
awefully

 hard
lesson is learned is among the future devel-
opments of Providence - When He who is
higher than the highest accomplishes his purposes
This will be a wonderful country and again
something like what it was of old - When Zerah
and Tirhaka flourished &amp; were great

    
	

The soil of 
Manyema
 is clayey and 
XXXVI
 remarkably
fertile - The maize sown for it rushes up to seed
and everything is in rank profusion if only it
be kept clear of weeds - 

Bambarre
 people
are indifferent cultivators planting maize

Bananas &amp; plantains and groundnuts only
No dura a little cassava - no perisetum
or 
meleda
 - pumpkins melons 
Nyumbo

though they all flourish in other districts
a few sweet potatoes appear but elsewhere
all these nature grains and roots are abundant
and cheap - No one would choose this as a 
residence except for the sake of Moenekuss &amp;
The people are honest never steal though
stolen from by our people as Simon and

Amoda of my party and others of 
Muhamad\'s


    
	


XXXVII 
Oil is very dear while at 
Lualaba
 a 
11

gallon may be got for a single string of beads and beans

ground nuts - cassava maize plantains in rank
profusion The 

Balegga
Lega

 like the 

Bambarre
 people
trust chiefly to Plantains and ground nuts - 
To play with parrots is their great amusement -


13th 
Novr

November
 1870 - The men sent over to 
Lohombo

about 30 miles off got two and a half loads of

dura for a small goat - but the people were
unwilling to trade - "If we encourage Arabs
to trade they will come and kill us with their guns"
so they said and it is true - The slaves are overbearing
and when this is resented then slaughter ensues.
Got some sweet plaintains and a little oil
which is useful in cooking and with salt as butter
on bread - but all were unwilling to trade -




Monangoi
Moenemgoi

 was over near 
Lohombo
 and heard of a
large 
trading party coming and not far off, This may be

Syde &amp; Dugumbe but reports are often false

    
	


XXXVIII When 
Katomba\'s men were on the late foray
they were completely overpowered &amp; compelled by the 
Man-
-yema
 to lay down their guns and powder horns on 
pain of being instantly despatched by bowshot - they were
mostly slaves who could only draw the trigger &amp; make
a noise 
Katomba had to rouse and all the Arabs
who could shoot and when they came they killed many
and gained the lost day - The Manyema did not
kill anyone who laid down his gun &amp; powder horn
This is the beginning of an end which was easily


percieved
perceived
 when it became not a trading but a 
murdering horde of savages and when wherever
invited by old feuds in order to get goats
and then sell the captives back for ten goats each


Buceros cristata
 - screams &amp; picks at his
tail till he discharges the contents of his bowel Then
leaves him - It is called "play" by the natives and
in the 

Suaheli
Swahili

 "Utane" or

    
	


XXXIX
 "
Msaha
" - fun or wit. He follows other birds in the same 
12


merciless way - screaming &amp; pecking to produce purging

Manyema call it "Mambambwa" - The Buffalo bird
warns its big friend of danger - calling Chāchāchā



Rhinocers
Rhinoceros
 
birds
bird

 calls out Tyetyetye tye for 

the same purpose - Manyema call Buffalo bird
"
Mojela
" 






Suahel
Suaheli


Swahili







Suahel
Suaheli


Swahili




 "
Chassa
"



a
A
 climbing plant is known in 
Africa
 as 



ntulung
Ntulung


-




-ope
ope




which mixed with flour of dura kills mice -
They swarm in our camp and destroy everything
but Ntulungope is not near this



The foray above mentioned was undertaken by 

Katomba for twenty goats from 
Kassessa
!
Ten men lost for twenty goats but they will think
twice before they try another foray





one
One
 dollar a day is ample for provisions for a 
large family at 
Zanzibar
 - What nice flesh of

goats or ox or fowls - bananas milk butter - sugar eggs


bazarre mangoes - potatoes


    
	


XL. Ambergris is boiled in milk and sugar
and used by the Hindoos as a means of increasing
blood in their systems - a small quantity is a dose 

Ambergris is found along the shore of the sea at


Barawa
 or 
Brava
 and at 

Madagascar


as if the sperm 
whate
whale

 
Changoi
 got rid of it
while alive - 
Lamos
 or 
Amu
 is wealthy
and well supplied with everything as grapes

peaches wheat cattle camels &amp;c - The trade
is chiefly with 

Madagascar

 - The houses are
richly furnished with furniture dishes from


India
 - At 
Garaganza
 there are hundreds of 


Arab traders
 
there
There
 too all fruits abound
and the climate is healthy - from its elevation
Why cannot we missionaries imitate these


Arabs in living on heights?

            
			

    

    
	




XLI Copy
 







Manyuema
Manyema

 country
 180 miles say 
13


West of 
Ujiji

 15 
Nov
November


1870



The 
Right Honourable Lord Stanley





My Lord As soon as I recovered suffi-
-ciently to be able to march from 
Ujiji
 I went
up 
Tanganyika
 about 60 miles and thence
struck away 
N W
North West
 into the 
country of the 

Manyuema
Manyema


or Manyema

 - the reputed cannibals
 - My object
was to follow down the 
central line of drainage
of the great 


Nile
 valley



 which I had seen passing
through the great 
Lake Bangweolo
 and changing 
its name from 
Chambeze
 to 
Luapula
 - then on
passing through 
Lake Moero
 assuming the name


Lualaba
 and becoming itself a great 


Riverein
Riverine

Lake
 at first 
eight to ten miles broad
 with several
inhabited islands in it, and then holding a breadth
of from two to six miles
 as far as it is known
I soon found myself in the large bend which this
great 
Lacustrine River
 makes by going West and



    
	

 

XLII then turning away to the North - Two hours were the 
utmost I could accomplish in a day, but by persever-
ing I gained strength and came up with the 
trading party
of Muhamad Bogharib
 who by 
native medicines and
carrying me saved my life in my late severe illness
in 
Marungu
 Two days before we arrived at


Bambarre
 the residence of the most  influential

Manyema chief called Moenekuss we met a
band of Ujijian traders
 carrying 18000 
lbs
pounds

weight of ivory bought in this new field for a
mere trifle in thhick copper bracelets and beads
The traders had been obliged to employ their slaves
to collect the ivory and slaves with guns in their
hands are often no better than Demons - We
heard but one side of the story - The slave version
and such as would have appeared in the Newspaper
if they had one - "The Manyema were bad
- they were always in the wrong - wanted to eat the

slaves and always gave them just occasion to capture
people 
goats sheep fowls and grain
" - 

    
	


XLIII The masters did not quite approve of this but the 
14

deeds were done and then masters and men joined in
one chorus "The Manyema are bad bad bad very
bad" - In going West of 
Bambarre
 I followed the


Luamo
 a river of from 100 to 250 yards broad
which rises in the mountains opposite 
Ujiji
 and
flows across the great bend when near its
confluence  I was among people who had been
maltreated by the slaves and they naturally looked
on one as if of the same tribe with their persecutors

Africans are not unreasonable though 
though


smarting under wrongs if you can fairly make
them understand your claim to innocence and
do not appear as having your "back up" The
women here were particularly outspoken in asserting
our identity with the crueuel strangers - on calling to
one vociferous lady who gave me the head trader

s
\'s
 
name, just to look if he and I were of the same

colour she refused with a bitter little laugh "Then you
must be his brother" The worst the men did


    
	



to

 XLIV to us was to turn out in force armed
with their large spears &amp; wooden shields and 
shew
show

us out of their districts - Glad that no collision
took place we 
returnedreturned
 to 
Bambarre
 and then 
with our 
friendfriend Muhamad struck away due
North he to buy ivory and I to reach
another part of the 
Lualaba
 and buy a canoe -

The country is extremely beautiful but difficult
to travel over The mountains of light grey
granite stand like islands in 

Now
New

 Red
sandstone and mountain and valley are all
clad in a mantle of different shades of green
The vegetation is indescribably rank through
the grass if grass it can be called which is over
half an inch in diameter in the stalk and from
ten to twelve feet high nothing but elephants 
can walk The leaves of this 
Megatherium

grass are armed with minute spikes which as
we worm our way along 

elephants

elephant\'s



 walks rub
disagreably on the side of the face where the

    
	


XLV 
the

 gun is held and the hand is made sore by 
15

fending it off for hours the other side for hours - The Rains
were fairly set in by November and in the morning
or after a shower these
 leaves were loaded with
moisture which wet us 
toto 
thethe bone - The valleys are
deeply undulating and in each innumerable
dells have to be crossed There may be only a
thread of water on the bottom but the mud mire
or Scotticé "
glaur
" is grievous - thirty or
forty yards of the path on each side of the
stream are worked by the feet of passengers
into an adhesive 
compoundcompound - By placing
a foot on each side of the narrow footway one
may waddle a little way along but the rank
crop of grass gingers &amp; bushes  cannot spare
the few inches required for the side of the foot and


downdown he comes into the mire - The path often runs
along the 
bedbed of the rivulet for 60 or more yards

    
	


XLVI as if he who first cut it out went that distance

seekinging a part of the 
forestforest less dense than the rest
for his axe In other cases the "
Muale palm"
from which here as in 

Madagascar

 grass cloth is
woven and called by the same name "
Lamba
"
has taken possession of a valley - the leaf stalks
as thick as a 
sstrong 
mans
man\'s
 arm fall off
and block up all passage save by a path
made and mixed up by the feet of elephants
and buffaloes The slough therein is 
groan
grown


compelling and deep Every now &amp; then the

traders with rueful 
facesfaces

 stand panting
The sweat trickles down my face, and I
suppose I look as grim as they though I
express a hope that good prices will reward
them for 

as

on
 
the coast
 for ivory obtained with
so much toil - In some cases the subsoil
has given way beneath the 

elephants



elephant\'s

elephants\'


 enormous
weight - The hole is filled with mud and one
taking it all to be about calf deep

    
	
 

XLVII steps in to the top of the thigh and 

flapsflaps
 on to a 
16

seat, soft enough, but not luxurious - a merry laugh
relaxes the facial muscles and I conjecture that this
gruesome fun is all I shall ever get for the explorations
Some of the 
numerousnumerous 
riversrivers which in this
region flow into 
Lualaba
 are covered with
living vegetable bridges - a species of dark


glossyglossy grass with its roots and leaves is
the chief agent in felting into a mat that covers
the 
wholewhole stream  When stepped upon it yields
twelve or fifteen inches and that amount of
water 
risesrises on the leg - At every step the foot
has to be lifted high enough to place it on the

unbent mass in front and this fatigues
like walking on deep snow - Here &amp; there  
holes appear which we could not sound with
a stick six feet long - They gave the impression
that any where one might plump through
and finish the chapter - Where the water is

    
	



X
V
L
VIII
 

is

 
shashallow The Lotus or sacred 
Lilly
Lily


sends it roots to the bottom and spreads it broad
leaves over the floating bridge so as to make believe
that the mat is its crown but the grass referred to
is the real supporting agent -

Between each district of 
Manyema
 broad
belts of the primeval forest still stand - Into
these the sun though vertical cannot pene-
trate except by sending down ^ at Midday thin pencils
of rays into the gloom - The rain water
stands for months in stagnant pools
made by 

elephants

elephants\'
 feet and the dead leaves
decay on the damp soil and make the
water of the numerous rills &amp; rivulets of the 
colour of strong tea - The climbing plants
from the size of 
whipwhipcord to that of a man
of 
wars
war\'s
 
hawserssers
 are so many the ancient
path is the only passage When one of the giant
trees falls across the road it 
makesmakes a 
wallwall


    
	


XLIX breast high to be climbed over - and the mass 
17

of tangled climbers brought down makes cutting a
path round it a work of time which travellers never
undertake The shelter from the sun of the Forest
makes it pleasant but the roots of trees high out
of the soil across the path keep the eyes constantly
looking down and a good shot gun does no
harm to parrots or quince fowls on their
tops - I have heard 
gorillahs
gorillas
 here called 

Sokos



prowling within fifty yards without getting a
glimpse of them - Their call to each other resem-
bles that of a Tom cat not so loud or far
reaching as that of the peacocks - When in flight
they give tongue not unlike fox hounds - His
nest is a poor contrivance resembling that
of our cushat dove Here he sits in pelting rain
with his hands on his head - The natives call it
his house and laugh at him for being such a
fool as after building it not to go beneath it
for shelter - Bad water and frequent wettings

    
	


L. told on us all by choleraic symptoms &amp; loss
of flesh -  Meanwhile the news of cheap ivory
caused a sort 
Californian gold fever at 
Ujiji

It prevented me from getting any carriers save
the worthless liberated slaves who by thieving
lying and 
fornication
cowardice

 have been a perpetual
annoyance during all this Journey - The

traders eager to secure all the 

Pagazi

 or

carriers spread the report that I would go
away to my own country and leave them as

Speke did his as 
Suez
 - We were now
overtaken by a horde ^ from 

Ujiji

 numbering 600 muskets
all eager for ivory The elephant tusks had
been left to rot with the other bones in the
interminable forests where the animals were
killed - The natives knew where they had been
left and if treated civilly readily brought the

precious teeth many half rotten or gnawed

    

          
	

LI by the teeth of a 
rodent
 animal to sharpen his 
18

teeth as 

London
 rats do on leaden pipes - I had already
in this Journey two severe lessons that travelling
in an unhealthy climate in the rainy season
was killing work and besides being unwilling
to bear company with the new comers I feared
that any present weakness ^ by further exposure might result in
something worse went back seven days
and on the 7th February last went into winter 
quarters at a camp formed by the heads of
men as civil and kind as I could wish - a

letter obtained from the 
Sultan of 
Zanzibar





through the kind offices of Sir Bartle Frere
has been of immense service to me with most
of his subjects - I had no medicine - some though
sent for twice had been unaccountably detained
at 


Unyembe
Unyanyembe


 by the Arab 

Lewale

 or governor


Two English guns in the box are surely not

    
	

LII. not too much for his virtue  - Rest - boiling
all the water 
Series of calculations, rotated ninety degrees, over which, it appears, Livingstone then wrote the main narrative text of the diary.
 I used and a new species of potato
famed among the natives as a restorative soon
put me to rights again 
The rains continued
into July and 58 inches fell The mud from
the clayey soil was awful and laid up some
of the strongest in spite of their intense eagerness
for ivory I lost no time after it was feasible
to travel in preparing to go North but my

attendants were fed and lodged by the slave
women whose husbands were away from
the camp on trade and pretended to fear going
into a canoe I consented to refrain from
buying one - They then feared the people though
the inhabitants were reported by the slaves
to be remarkably 
frienvly
friendly

  elsewhere I could
get the country people to carry from village
to village and was comparatively independent

    
	


LIII. when as happened with some they deserted 
19

into the arms of prostitutes six times over - But in


Manyema
 no one can be induced to go into the
next district for fear they say of being killed &amp;
eaten - I was at their mercy and entreaty was
answered by calling when out of sight "who
will carry his things" and a loud laugh to make
me hear - The head Arabs
 remonstrated
and they literally trembled and consented to go
anywhere but on 
find
finding
 that no compulsion
was to be used refused again - When I had
gone with my only three attendants I could not
regret the absence of the rest for three of them
had previously gone unknown to me to
a slave war and came back boasting that
they had killed four of the people whose kindness
to us had touched my heart and nothing could
exceed the eagerness with which uninvited
they ran off to help to enslave their countrymen

    
	


LIV nothing but danger would have

deterred  them from slavehunting and
here there is none for the report of gun makes
the Manyema flee in terror On no account
would I have brought them here but I suspected
that my letters

 to 
the coast
 for other men
had been destroyed and I had a sore longing
to finish my work and retire - The country
to the North is even more difficult than that
I have described for except a broad belt of





Buga
Mbuga



 or Prairies along the right bank of
the 
Lualaba
 it is all forest saving the clearing
round each village - and these are ten miles
apart - The rivers and rivulets are innumer-
able I crossed fourteen in one day from
knee to thigh deep - 


Muhamads

Muhamad\'s
 party was

five hours in crossing one in flood - a man
in a small canoe went sounding among

    
	




LV. 
20

 the trees to find where it was 
breast
deep In another case they were two hours in a river

from breast to neck deep and they saw
nothing but gloomy forest - though they went
near to what the 

Balegga
Lega


 call 




uerere
Uerere








uerere
Uerere





 or 
lower
Tanganyika
 named by its discoverer 
Albert 
Nyanza
 For the first time in my life my
feet failed - When torn by rough travel
instead of healing kindly as heretofore an

irritable eating ulcer fastened on each foot
and laid me up for five months - these are
common here and 
slaves
 whose wailing
may be heard the whol
e
 night long are
often killed by them - I have been minute
even to triviality that your Lordship may have
some idea of the obstacles to progress in this
region exploration is only possible by canoes
and as soon as I get men who have been

taught to work four or five months will


    
	


LV
 finish all I have to do - What remains
to be accomplished may be understood
by the following -




    
	



LVI continuation of a Despatch to Lord Stanley
 
21




This great 
Lacustrine river
 which I call



Webb\'s Lualaba
 is only one of 
threethree
 each of
which 
havinghaving thee 
samesame native 
namename 

requiresrequires




 an 

EnglishEnglish
 
epithetepithet to distingtinguish it The




riverriver Lufira
 
risesrises in a fountainain South
West of this which 
II would fain 
callcall 

Bartle 
Frere\'s fountain
 and 
thth
 When it becomes
very large it is called 
Lualaba
 West of this one


againagain another great 
riverriver beginsins 
inin 
aa fountain
and from 
itsits 
sourcesource down 
itsits 
onlyonly native
name is 
Lualaba
 - I wish to add 

Young\'s


Youngs

 Lualaba
 and 

Bartle Frere\'s Lualaba

unite and form a Lake the native name of
which is 
Chibungo
 but I am fain to call it


Lake Lincoln


 - Looking back from this to the
full 
growngrown gushing fountains not more 

    
	

LVII 
moremore than 

tenten miles apart The
largest of these fountains at which a man
cannot be seen on the other side is the source
of the 
Liambai
 or upper 
Zambesi
 this
I name after good Lord Palmerston
Near it rises the 
Lunga
 which further
down is called 
Luenge
 and still further
off 
Kafue
 or 
Kafuge
 - I would name it



Oswell Fountain
 These four fountains
gushing forth so near to each other
and forming great rivers are probably the
unfathomable springs of the 
Nile
 men-
-tioned to Herodotus by the 
secretary
retary
 of

Minerva
 in the citycity of 
SaisSais

 fromfrom which

    
	

LVIII 

 "half the water flowed" = from 





Youngs

Young\'s


 and 
22




Bartle Frere\'s
 fountains
 = "Northward into


Egypt
" - and the other half = "from 





Palmerstons
Palmerston\'s


 
and 



Oswell


Oswell\'s


 fountains
 = "into 
Inner 
Ethiopia


"
I heard of this remarkable mound &amp; fountains
some 200 miles distant on the South West - again
on the South East 150 miles off - again on
the North East 180 miles distant and
now on the 
N.N.E.
North North East
 many intelligent

Arabs who have visited the spot give the
very same information as having excited
their admiration as much as it that of
the natives - I have ventured to give name by
anticipation - I shall write no 



other
 letter
till I have either succeeded or fallen - The
names of Palmerston Lincoln &amp; Frere I wish
to honour as of men who have done more

    
	

LIX for the abolition of the slave trade &amp; slavery
than any of their 
cotemporaries
contemporaries
 - The great and 
good man Palmerston and Lincoln are no
longer among us, and I desire to place, as it were
my poor little garland of love on their tombs.


By degrees the conviction has crept across
my mind that all we moderns can fairly do in
in common modesty claim is 
is

 the rediscovery
of the 
sources of the 
Nile


 which had sunk into
oblivion somewhat like the circumnavigation
of 
Africa
 by the Phoenician Admiral of one
of the 

Pharoahs

Pharaoh\'s

 about 

B C
Before Christ
 600 He
was not believed because he reported
having the sun on his right hand in
passing round 
Libya
 This stamps the tale
of the Admiral to us as genuine By placing
the 
fountains of the 
river of Egypt


 between

10°-12° South 
Lat.
Latititude

 Ptolemy  genuine

    
	


LX
 geography from men who had visited this very 
23

region By making the water collect into 
two or
three large Lacustrine rivers
  - Extant speci-
-mens of those which in prehistoric times
abounded in 
Africa
 and in 
the south
 are still
called "melapo" - in the 
North
 "


Wady\'s
Wadys


" both
words meaning the same thing = river beds
where no water ever now flows, he did
what no mere theorist
 would dream of doing



Ptolemys

Ptolemy\'s
 predecessors were probably the real
collectors of the facts he made use of and the
former explorers must have travelled extensively
Had I left at the end of two years I could have
given little more light on the country than the

Portuguese who in their three slaving visits
to Cazembe asked for slaves &amp; ivory alone
and heard of nothing else - I 
enquired
inquired
 about the
waters till ashamed and almost afraid of being
put down as affected with 
Hydrocephalus


 - I had
to feel my way and every step of the way, and

    
	

LXI was generally groping in the dark for who cared


were
where
 the rivers ran - Many a wary foot I trod ere
I gained a clear idea of the drainage which flows
from the watershed in 
10°-12° South on which stand





Ptolemys

Ptolemy\'s
 mountains of the moon



 - The length of
this watershed is between 700 &amp; 800 miles from 
West to East - Here the 
fountains of the 
Nile


 do
unquestionably arise - The mountains on it 
are between 600 &amp; 700 feet above the sea
The idea of melting snow is if I remember
rightly is not Ptolemy\'s 


Kenia
Kenya


 &amp; 
Kilimanjaro
 
are said to be snow capped but no one
even reached the snow - They send no water to
any part of the 
Nile
 and never could have
been meant by the correct ancient explorers

 


I would fain crave your 

Lordships

Lordship\'s

 approboation
of my labours but the 

supernumerary undersecretary



Murrays

Murray\'s

 impertinent letter forbids any 
Govt

Government

from allowing me any claim no matter what
services I may render 


David Livingstone



      
            

            

	



	
	


LXII 22nd 
Novr

November
 1870 copied foregoing despatch - It
will be delivered by 

Muhammad
Muhamad
 Bogharib into the consul\'s
hands at 
Zanzibar





24th 
Novr

November

 Herpes is common at the plantations 
in 
Zanzibar
 but the close crowding of the houses
in the town they think prevents it. The lips &amp;
mouth are affected &amp; constipation sets in for 3
days - cured by going over to mainland
Affections of the lungs are cured by residence at




Bariva
Barawa


 or 
Brava
 and also on mainland



the
The
 Safari of Halzani took my letters from


Ujiji
 but person employed I do not know


25th 
Nov
November

 
wrote
Wrote
 to Tom Agnes - Young - Webb 

Oswell 
Dr Hamilton
 Sir Roderick 
Sir Bartle Frere -

Tracey - Stearns of 
Bombay
 - Maclear = Bleek

Brother John in 
Canada
 = 
Letters to be delivered
by 

Muhammad
Muhamad
 Bogharib into 

Col
Colonel
 Playfair or Dr Kirk\'s
own hands at 
Zanzibar
 - 

Lt

Lieutenant
 Kinnaird &amp; 

B
Bevan
 Braithwaite



	
	


LXIII 29th 
Novr

November
 1870 


Safura


 is the name of the
disease clay or earth eating at 
Zanzibar
 = It often 
affects slaves and the clay is said to have a pleasant
odour to the eaters, but it is not confined to slaves
nor do slaves eat in order to kill themselves - It is
a diseased appetite and sick men who have plenty 
to eat are often subject to it - The feet swell
flesh is lost - and the face looks haggard - The
patient can scarcely walk for shortness of breath
and weakness and he continues eating till he
dies = Here many slaves are now diseased with





safura
Safura



 The clay built in walls is preferred and


Manyema women when pregnant often eat it.
The cure is effected by drastic purges for seven
days and nothing of ^ 
fish

 butter - milk or beef must
enter his mouth for 

three


two



 years after it -- old

vinegar or cocoa trees put into a large 
bason
basin
 &amp;
old slag made red hot cast into it - Then "Mbuye ^ 
asofoetida
"
1/2 a rupee in weight - . copperas 
sulph
sulphate
 
Do

Ditto
 
a small glass of this fasting morning &amp; evening

	
	


LXIV
 produces vomiting &amp; purging of black dejections - 
This is continued for seven days - no meat eaten but
only old rice or dura &amp; water - a fowl
 in course of time
no ^ 
fish
 butter eggs or beef for two years on pain of death

Muhamad\'s father had skill in the cure and the
above is his prescription - 

Safura

 is thus a 
disease per se - It is common in Manyema &amp; 
makes me in a measure content to wait for
my medicines - from the description inspiss-
ated bile seems to be the agent of blocking up the
gall duct and duodenum and the clay 



or
 earth
may be nature trying to clean it away - the
clay appears unchanged in the stools and in
large quantity a 


Banyamwezi
Nyamwezi

  carrier
 who
bore an enormous load of copper is now by 

Safura


scarcely able to walk - He took it at 
Lualaba
 where
food is abundant &amp; he is contented with his lot -

squeeze a fingernail &amp; if no blood appears beneath it




Safura

 is the cause of the bloodlessness -

	
	

LXV a dread of encountering this disease without any
any medicine reconciles me partially to this detention 




2 
Decr

December
 1870 

Sokos

 collect together and make a drumming 
noise some say with hollow trees then burst forth
into loud yells well imitated by the natives - If a man
has no spear 

Sokos

 goes away satisfied - If
wounded he 
siezes
seizes
 the wrist lops off ends of the 
fingers and spits them out - slaps the cheeks
of his victim and bites without breaking the
skin - draws out a spear but never uses
it - takes some leaves and stuffs them into
his wound to stanch the blood = Does not
wish an encounter with an armed man = He 
sees women do him no harm &amp; never molests them
a man without a spear is nearly safe from him
They beat hollow trees as drums with hands
and then scream as music to it. When men
hear them they go to 

Sokos

 but 

Sokos

 never
goes to men with hostility - Manyema say "

Sokos


is a man" "&amp; nothing bad in him" a 

Sokos

 was killed
near this with holes in his ears - He had died a man &amp; 
risen
rose
 a 

Soko




	
		


LXVI. 
opinion
Opinion
 and facts - 2 Rhinoceroses 

scary
story


chivalry - Helmore found by Baldwin starving no

hunter - no horses no medical man - Sekeletu
blamed though he got not £8000 to place him
on Healthy 
Highlands
 and I was accused as 
morally guilty of his death though no letter was
sent to me - saying he had come ^ or gone to 
Linyanti





Bishop addressed no teaching - 

Makololo
Kololo



followed me and I was blamed because they 
vitialed all the teaching - then being none as
2nd Bishop said to me an astounding fact
that people living with them have been taught
absolutely nothing - Idleness was the bane of
that mission and then loitering in the swamps
killed them - I bore the accusations in 
silence - I felt that so to do was chivalrous -
Loss of heat or presence of mind - Absalom

Saul -




6th 
Decr

December
 1870 
oh
Oh
 for Dugumbe or Syde. !! to come
but this delay may all be for the best.

	
	


LXVII. The Parrots all seize their food &amp; hold it with the
left hand - the Lion too is left handed - He strikes with
his left - so are all animals - left handed save man.



I noticed a very pretty woman come on marriage with 
Mona-
mosimba
 past this quite jauntily about a month ago
ten goats were given - Her friends came and asked
another goat which being refused she was enticed away
became sick of Rheumatic Fever two days afterward
and died yesterday - not a syllable of regret for the 
beautiful young creature but for the goats "Oh"
"our ten goats" they cannot grieve too much - "Our
"



ten goats! Oh Oh"!







Basang
Basango


Sangu

 wail over those who die in bed but not
over those who die in battle = The cattle are a salve
for all sores - women even raise no wailing


Another man killed in a village within ^ 


½
1/2
 miles
 sight
of this - They quarrelled and there is virtually no

chief - the man was stabbed and village burned and
people all fled - They are truly a bloody people -


	
	


LXVIII 

Sokos

 live in communities of about ten each having his 
own female - an intruder from another camp is beaten off with 
their fists and loud yells - If one tries to seize the female of another
he is  caught on the ground and all unite in boxing &amp;
biting the offender - a male often carries a child
especially if they are passing from one patch of forest
to another over a grassy space - He then gives it to the
mother




a
A
 man died near this Monasimba went to
his wife and after intercourse and washing he
may appear among men - If no widow
can be obtained he must sit naked behind
his house till some one happens to die - all the
lowest of the low - and especially in bloodiness
the man who killed a woman without cause
goes free - He offered his grandmother to be 
killed in his stead and after a great deal of talk
nothing was done to him - !

	
	



LXIX

8 
Decr

December
 1870 - Suleiman bin Juma lived on the
mainland ^ 

Mosessane

 opposite 
Zanzibar
 - It is impossible to deny his
power of foresight except by rejecting all evidence - He
frequently foretold the deaths of great men among Arabs
and he was preeminently a good man upright &amp; sincere
"
shirti
" none like him now for goodness or 
skill - He said that two middle sized white
men with straight noses &amp; flowing hair down to
the girdle behind came at times &amp; told him things
to come - He died ^ 12 years ago lately &amp; left no successors 
told his own disease three days beforehand
by cholera



Heresi a ball of hair rolled in stomach of a

lion is a grand charm to the animal &amp; to 

Arabs - 

Muhammad
Muhamad

 has one




10th 
Decr

December

 I am sorely let and hindered in this


Manyema
 - Rain every day and often at night
I could not travel now even if I had men but
I could make some progress - this is the sorest delay
I ever had - I look above for help &amp; mercy

            

            

	

	
	


LXX. 


Lions

Lion\'s
 fat is regarded as a sure preventative of 
24



Tsetse or 
Bungo
 - This was noted before but I add now
that it is smeared on the ox tail - preserves hundreds of the



Banyamwesi
Nyamwezi

 cattle in safely while going to 
the Coast
 -
It is also used to keep  pigs and Hippopotami
away from gardens - - The smell is probably
the efficacious part in Heresi





12 
Decr

December

 It may all be for the best that I am so
hindered and compelled to inactivity - advance
to 
Lohombo
 was the furthest point of traders
for many a day - slaves returning with ivory
were speared mercilessly by Manyema because
they did not know guns could kill &amp; their
spears could - Katomba coming to Moenekuss
was a great feat three or four years ago
Then Dugumbe went on to 
Lualaba
 and fought his
way - So I may be restrained now in mercy
till men come - those I had were not men nor
yet slaves - Hybrids between bond &amp; free
 so petted 

&amp; coddled as to think the English feared them

	
	


LXXI The Neggeri an African animal attacks the
testicles of man and beast - cuts them off and retires
contented - Buffaloes are often castrated by him -
Men who know it squat down &amp; kill him with knife
or gun - 
Lions fear 

him

the

 

Zibu
 or 
Ratel






Zibu
 or 
Mbuidé
 flies at the tendo 

achilles
Achilles

 =

Ratel? -  
Fisi ea Baharai
 probably the seal
is abundant in the seas but the Ratel or badger
probably furnished the skins for the Tabernacle

Bees die or escape from his droppings

or urine and he eats the honey in safety -

Lions &amp; all other animals fear his attacks of the heel


about 25 to a measure
the 

Babemba
Bemba

 mix a handful of castor oil seeds with
the dura ^ and they 

pou
gri
nd 
Meleza
 = usages makes them like it


is not perceptible in porridge

The nauseous taste and the oil is needed where so
much farinaceous or starchy matter exists and


the bowels are regulated by the mixture
experience ^ has taught them the need of a fatty ingredient







Moamba - Chassa - brother of 
Do

 
Chambeze
 = other brother of

Chassa - 
Do

 in way - Moenewifa large country - 
Komanga

and 6 days to 
Barari
 thence 

	
	


LXXII. Goambari is a prisoner at 

Merere\'s
 guarded 
25

by a thousand or more men to prevent him intriguing with

Monyungo who is known as bloodthirsty - In the third
generation 



charura
Charura

\'s

Charura\'s
 descendants numbered sixty
able bodied spearmen - Garahenga ^ or Kimamure
 killed many of
them -  

charura
Charura

 had six white attendants with
him but all died before he did and on becoming

chief he got all his 
predecessors
predecessors\'
 wives - Merere
is the son of a woman of the royal stock and of a
common man - Hence he is a shade or two
darker than Charura\'s descendants who are very
light coloured and have straight noses - They
shave the head and straight hair is all cut off - 
they drink much milk warm from the teats of the

cows and think that it is strengthening by its heat.
The descent is 
1 Charura - 2 Mokasi - 3 
Moenye-
gumbe
 = 4 Mamerere = Merere =
 Mogandira son of 3
died after one 
years
year\'s
 rule - Kimamure a coward followed
2nd son of 3 made Merere general = Goambari called

Monyungo to first Merere - Kimamure or otherwise 
Garahen-
ga
 killed many by Merere\'s hand - calls himself his slave
but rules him and all besides

	
	


LXXIII 

Decr

December
 23d 1870 - 

Bambarre
 people suffer hunger now
because they will not plant cassava - This 
trading party eats all
the maize and sends to a distance for more - Manyema buy from
them with 
malofu
 or Palm toddy - Rice all coming into ear
but Manyema planted more 
Maize ripening - mice a pest
a strong man among Manyema does as he pleases &amp;
no chief inteferes - a man\'s wife of ten goats was
given off to a Mene man and his child now grown
is given away too - comes to Muhamad for redress
Two Elephants killed were very large but have
small tusks - They come from 
South
 in the rains
All animals as elephants buffaloes - zebras
are very large in 



Basango
Sangu

 country
 - tusks full
in the hollows weigh very heavy - animals fat
&amp; good in flesh Eleven goats for the flesh


24th
 Between 25 and 30 slaves have died in the present
epidemic - also many Manyema - Two yesterday at


Kandawara
 - The feet swell then the hands and 
face and in a day or two they drop dead - It came
from 
the East
 and is very fatal - few escape who take
it.


    
	


LXXIV. 
a
A
 woman was accused of stealing maize - the 
ch
ief

 
26

here sent all his people yesterday - plundered all she had in 
her
house and garden and brought her husband bound in
thongs till he shall pay a goat -- She is said to be inn
ocent




Monangoi
Moenemgoi

 does this by fear of the traders here an
d

as the people tell him as soon as they are gone th

e

vengeance he is earning by injustice on all sides
will be taken - I told the chief that his head would
be as also Kasessa\'s.

Three men went from Katomba to 

Kasongo\'s
 to
buy 
viramba


 - a man was speared belonging to

Kasongo - these three then fired into a mass of 
men who collected one killed two another three &amp; so on 
So now that place is shut up from traders -
and all this country will be so as soon as the

Manyema learn that guns are limited in their power
of killing and especially in the hands of slaves who
cannot shoot but only make a noise - These 

Suaheli
Swahili


are the most cruel and bloodthirsty missionaries in
existence and withal so impure in talk &amp; acts - spreading

syphilis Buboes &amp; chancres- The Lord sees it.

	
	



LXXV 28 Decr 1870 Moenembag the most intelligent of the 
two sons of 

Moenekus
Moenekuss

 in power told us that a man was
killed &amp; eaten a few miles from this yesterday - Hunger the reason
assigned = on speaking of tainted meat he said that the Manyema
put meat in water two days to make it putrid &amp; smell high = The
love of high meat is the only reason I know for their cannibalism
but the practice is now hidden on account of the disgust that
the traders expressed against open man eating when they
first arrived - Lightning very near us last night - The

Manyema say that when it is so loud fishes of large
size fall with it - an opinion shared in with them
by the Arabs = But the large fish is the 
clarias capensis

of Smith and it is often seen migrating in single file
along the wet grass for miles - It is probably this
that the Manyema think falls from lightning.


30th
 Rain daily - a woman murdered without cause
close by the camp - murderer said she is a witch &amp; speare
d


her - body exposed till affair is settled probably by fine of g

the Manyema are the most bloody callous savages I
know - one puts a scarlet feather on ground and challeng
es

those near to stick it in the hair - He who does so must kill a
man or woman - and so none dare wear skin of musk ca
t




Ngawa
 unless he has murdered - guns alone prevent them
from killing us all - and for no reason either.

            

            

	

	
	

 


LXXVI 16th January 1871 Ramadan ended last 
4

night and it is probable my people &amp; others from the

cohort will begin to travel 



 after three days of feasting

It has been so rainy I could have been done little though
I had had 

 people 

 






22nd
 a party reported to be in the way hither - This
is likely enough - 

but reports are so often false doubts
arise -  Muhamad says he will give men when the
party of 


Hassani
Hassani



 comes or when Dugumbe
arrives My 
Nassickers cooly assert
that they did not desert after this
it will be 

im- possible

impossible
 to take the 
ringleaders

 but some
will believe

 them as for
instance 
Mr Tozer &amp; Co


    

Series of calculations over lower half of page in, apparently, pencil and different kinds of inks. In some cases Livingstone has inked over calculations and text. Text includes: "Chirubi", "middle", "S End", "Kipya", "Landsend", "Mpabali", "Sea Horizon", and "



Kasonga
Kasongo



".


     

	
	






7






Drawing of a map with the Equator at the top, Lake 
Chibungo
 or 

Lincoln

, Lake 
Moero
, and Lake 
Tanganyika
, with latitude markings.


There is no desert in all the
country said to be travelled over
It is every where fertile &amp; covered
with rank vegetation = this is the
most unlikely part of the tale

            

            

	
                
    

	
	



LXXVIII 24th January 1871 - Muhamad mentioned 
27

this morning that 

Moenemokaia
Moenemokia

 &amp; Moeneghere his
brother brought about thirty slaves from 
Katanga

to 
Ujiji
 affected with swelled Thyroid glands
or 
Goitre
 and that drinking the water of 

Tang-
anyika

 proved a perfect cure to all in a very
few days. Sometimes the swelling went
down in two days after they began to use the
water in their ordinary way of cooking washing
and drinking - Possibly some ingredient of
the hot fountain that flows into it - for the 
people on the 
Lofubu
 in 

Isana\'s country
 had
the swelling - Shut in bays were decidedly
brackish while the body of 
Tanganyika
 was
quite fresh -

The odour of putrid elephant\'s meat in a house kills

parrots - The Manyema keep it till quite rotten
but know its fatal effects on their favorite

birds


	
	


LXXIX. 28th January 1871 - 
a
A
 safari under Hassani
and 

Ebed
Abed

 arrived with news of great mortality
by cholera (

Towny

) at 
Zanzibar
 - and my "brother"
who I conjecture to be Dr Kirk has fallen - The men
I wrote for have come to 
Ujiji
 but did not know 
my whereabouts - When told by 
Katomba\'s men 
they will come here - and bring my much longed
for letters &amp; goods - 70,000 thousand victims in


Zanzibar
 alone! and it spread inland to the






Masai
Maasailand





Maasai

 and 


Ugogo







Ugogo
Bagogo


Gogo



 - cattle shivered and fell dead
the fishes in the sea died in great numbers. Here
the fowls were first seized and died and then men - 
thirty perished in our small camp made still 
smaller by all the able men being off trading at the





Metamba



 and how many Manyema died we


dont
don\'t
 know - The survivors became afraid of
eating the dead - Formerly the pest kept along
the sea shore now it goes far inland and will
spread all over 
Africa
 - This we get from 
Mecca



filth - nothing was done to prevent the place being
made a perfect cesspool of 
animals
animals\'
 guts &amp; ordure of men

    
                
	
	






LXXX --
 
a
A
 piece of skin bound round chest of an arm &amp; half of 
28


it hanging down prevents waste of his strength and he
forgets and fattens ----



Abed\'s party bring 200 
Frasilahs
 of all sorts of beads &amp;
They will cross 
Lualaba
 &amp; open a new field in the
other or 

Young\'s Lualaba
 - all 
central 
Africa


 
Weight calculation at the end of this line.

will soon be known - The evils inflicted by
these Arabs are enormous but probably not greater
than the people inflict on each other -----


Merere has turned against the Arabs and killed one
robbing several others of all they had though he has
ivory sufficient to send down 7000 
lbs
pounds
 of ivory to 
the
coast
 and 
recieve
receive
 loads of goods for 500 men - He
looks as if insane &amp; probably is so - He will soon be
killed - His insanity may be the effect of Pombe of
which he drinks largely - and his people may have
told him that the Arabs were plotting with 
Goambari

He restored Muhamad\'s ivory and slaves and sent for
the other traders who had fled - said his people had

spoken badly and he would repay all losses -

	
	





LXXXI Two young elephants were sent by Mteza to

Seyed Majid by 
was
way
 of the 

Lewale

 - 



Watuta
Batuta


Ngoni

 came stealing



Banyamwezi
Nyamwezi

 cattle &amp; 
Mteza\'s men went out to them
and twenty two were killed The 


Lewale

\'s people did nothing
The Governor\'s sole anxiety is to obtain ivory and no
aid is rendered to the traders 
Seyed Suleiman the 




wanzeer
wuzeer





is the author of the do nothing policy - Sent away all the 


Sepoys
 as too expensive an old man &amp; avaricious
The 




Bagogo
Gogo

 plunder traders unchecked = one of the
young elephants died in the way to 
the coast
 - It is
reported that 
Egyptian 

turks
Turks


 came up &amp; attacked

Mteza but lost many people and fled - A Moslem
mission to Mteza was a falsehood though the
details given were circumstantial - Falsehood
is so common one can believe nothing the Arabs
say unless confirmed of other evidence - They are
followers of the Prince of lies Muhamad


- His cool
appropriation of the knowledge gained at 
Damascus

and from the Jews is perfectly disgusting - All his
deeds were done when unseen by any witnesses

	
	



LXXXII. It is worth noticing that all admit the decadence 
29

of the Moslem power and they ask how it is fallen -
they seem sincere in their devotions &amp; reading the Koran
but its meaning is comparatively hid from most of the



Suaheli
Swahili


 - the 

Persian Arabs
 are said to be gross
idolators and awfully impure - Earth from a grave
at 

Kurbelosi
Kurbelori




\'s
 is

 put in the turban and worshipped - some of the
sects 
wont
won\'t
 say "Amen"!


Moenyegumbe never drank more than a mouthful
of pombe - He said the wisdom of a chief is dangerous
He kills people and 
it
he
 ought never to be excited by beer -
When young he could make his spear pass right through



an elephant and stick in the ground on the other side -
He was a large man and all his members were largely
developed - hands fingers all in proportion to his great
height - lived to old age with strength unimpaired --

Goambari inherits his white colour and sharp nose =
but not his wisdom or courage - Merere killed five of his
own people for exciting him "against the Arabs -" the

half caste is the murderer of many of 

charura
Charura

\'s
descendants - His father got a 


 ^ daughter
 of Moenyegumbe

for courage in fighting the 

Babena
Bena

 of 
Ubena



	
	



LXXXIII. 
my
My
 long detention in 

Manyema

 leads me to 
believe that they are truly a bloody people - cold blooded
murders are frightfully common and they say that but for
our presence they would ^ be still more frequent - They have no
fear of spears and shields - guns alone frighten them - they
tell us frankly and quite truly that but for our firearms not
one of us should even return to his country - some kill
in order to be allowed to wear the red tail feathers of a

parrot in their hair - and they are not ugly like the 

West
coast
 negroes many men have as finely formed heads as
would be found in 
London
 - We English
 if naked would
make but a poor figure beside the strapping forms and
finely shaped limbs of Manyema men &amp; women - their
cannibalism is doubtful but my observations raise
grave suspicions a Scotch jury would say "not proven"
The women are not guilty -

The cholera came along the seashore from 
Mecca
 but
this year it came inland and made great havoc - Goats
and fowls died not by the pest  but by its companion



 cattle shivered and fell dead - about 30 people died in
our small camp and how many Manyema we 
dont
don\'t
 know

Letters from 
Mecca

 told of its coming from that focus
of filth but t
a
h
e rest of the world must do nothing for
political economy says we must not 
interfere


	
	


LXXXIV - 4th February 1871 - Ten of my men from 
30
 
the
coast
 have come near to 
Bambarre
 and will arrive today
I am extremely thankful to hear it for it assures me
that my packet of letters



 was not destroyed - they know
at home by this time what has detained me and the
end to which I strain



Do

Ditto
 only one letter reached and 40 are missing - 
James
was killed today by an arrow - the assassin was hid
in the forest till my men going to buy food came
up - I propose to leave on the 12th
 I have
sent Dr Kirk a cheque for 
Rs
Rupees
 4000 Four thous- 
-and - Great havoc was made by cholera and
in the midst of it my friend exerted himself
greatly to get men off to me with goods - First
gang of porters all died. When they came to 
Ujiji




Sherreef
Shereef

 the head man stopped wth four and
is now feasting &amp; drinking on my goods though
he knows me to be here -


8th
 The ten men refusing to go North influenced
probably 
be
by
 Shereef &amp; my two ringleaders who



 try this means to compel me to take them

	
	


LXXXV 9th February 1871 - 
the
The
 man who contrived the
murder of James came here drawn by the pretence that he
was needed to lead a party against the villages which he
led to commit the outrage - His thirst for blood is awful
He was bound &amp; word sent to bring the actual 
murders
murderers
 within
3 days or he suffers death - He brought 5 goats 
think
thinking
 that would
smooth the matter over


11th
 Men struck work for higher wages - I consented
to give them 6 six dollars a month if they be-
-haved well - If ill, I diminish it - so we hope
to start tomorrow - another mutiny quelled by 

M
Muhamad

 &amp; me




12th
 
the
The
 men sent are all 
slaves of the Banians

 &amp;
came with a lie in their mouths - They were 

lascars


or soldiers - they objected to going today so I wait
till tomorrow = orders given today not attended to
so I had to treat them as slaves and promised
on the word of an Englishman that I would shoot
the ringleader against my orders - Muhamad
swore that he would kill them if they contended with
me and they gave in and but for Mabruki sick

we should go  tomorrow



	




Unyembe
Unyanyembe




 6 six dotis each 
to 
Ujiji
 3 three each of the 

Pagazi


three 



pagasi
pagazi



  4 four 
 each Ghamees Sudi Salem

from 12th  February onwards
	

	
	



LXXXVI 13th 
Feby
February
 1871 - 
Mabruki seized with 
31


choleraic purging detains us today - gave Muhamad
5 Pieces 
amerikano
 5 
Do

Ditto
 
Kanike
 &amp; 2 
frasilahs
 
samsam



He gives me a note to Hassani for 20 thick copper bracelets

Yesterday  crowds came to eat the meat of the man who
misled James to his death spot - We want the man
who set the Mbanga men to shoot him - They were much
disappointed when 
the
they
 found that no one was killed
and are undoubtedly cannibals 




1
6

th Friday - 
started
Started
 today Mabruki making himself
very ill as all who have been at 

Nassick
 coddling school 
do 
Muhamad roused him out by telling how I travelled
when much worse - chief gave me a goat &amp; Muhamad an-


go
other

 but in coming through the forest on the neck of the
mountain the men lost three &amp; have to go back for them
and return tomorrow - Simon &amp; Ibram were bundled on



 camp and imprudently followed me when they ca
me

up I told them to be off or I would certainly shoot them

	
	


LXXXVII. 17th
 
waiting
Waiting
 at a village on the Western slope
for the men to come up with their goats if they have
gone back to the camp - 
Muhamad would not allow

the deserters to remain among his people nor would I
it would only be to imbue the minds of my 
slav
es

with their want of respect for all English and total
disregard of honesty &amp; honour - They came after me
with inimitable effrontery believing that though I said
that I would not take them - they were so valuable I
was only saying what I knew to be false - I warned
them off and they went away among Manyema -

The goats were brought by a Manyema man who
found one fallen in a pitfall &amp; dead - He ate it &amp; brought
one of his own in lieu of it - I gave him 10 strings of
beads &amp; he presented a 
fowl in token of good willl -


18th
 
went
Went
 on to a village on the 

Lulwa

 and on the

19th
 reached Moenemgoi who dissuaded me so
earnestly against going to Moenekurumbo for the
canoe of Molembalemba that I agreed not to venture

20th 
to
To
 ford only one canoe now as 2 men of

Katomba were swept away in the other &amp; drowned
They would not sell the remaining canoe so I go


N W
North West
 on foot to Moene Lualaba where five large
canoes are abundant - grass &amp; mud grievous but
my men lift me over 
the waters 21st
 



Moenendebas

Moenendeba\'s








Mr 

andso
Andso



 twill be
When I am gone


            

            

	

	



	
	
	


LXXXVIII 

21st
 
arrived
Arrived
 at 

Monandewa\'s 
vil.
village


 
32


situated on a high ridge between two deep &amp; difficult
gullies - People obliging &amp; kind = chief\'s wife made a 
fire for me in the evening unbidden - 

22nd
 on 
N.W.
North West
 to
a high hill called 


Chibaude
Chibande
 a yunde
 with a 
spring of white water at the village on the top - Hunger
from some 
unknow
unknown
 cause but people cultivating
now on the plain below with a will - 


23d
 on
to two large villages with many 
banana plants
around but men said they were in fear of
the traders and shifted their villages to avoid
them - We then went on to the village 
Kahombogola

with a feeble old man as chief - country beautiful
and undulating - light green grass covers it all 
save at the brooks where the eye is relieved by
the dark green of lines of trees - grass tears the
hands and wets the extremities constantly - soil
formed of debris --&gt; of granite rocks - rough &amp;
stoney but everywhere fertile - one can rarely
get a bare spot to sit down and rest




24th
 
to
To
 a villagvillage near 
Lolinde 
R.
River


 then
cross 
Loengadze
 &amp; sleep on bank of 
Luha
 

R.
River




	
	


LXXXIX 
to
To
 
Mamohela
 welcomed by all the

Arabs - and got a letter from Dr Kirk
 and

another from the Sultan
 - and from 
Muha-


mmad
mad



 bin Nassib going to 
Karagwe
 
all anxious to be kind Katomba gave

flour - nuts fowl &amp; goat - a new way
opened to 

Kasongo\'s
 much shorter than
that I followed - I rest a few days &amp;
then go on -


1st March 1871 I was to start this morning
but the Arabs asked me to take seven of their
people going to buy 
viramba
  as 
as




 they 
know the new way the offer was gladly
accepted - I gave a note to Katomba

to take my double barrelled gun at 
Ujiji

I pay him this for all his services &amp;
he gives me a young she 

Soko

 to be carried
for me there 
Ujiji
 - She is a most friendly
little beast came up to me at once making

	
	
	

XC her chirrup of welcome - smelled my clothing
&amp; held out her hand to be shaken - I slapped her
palm without offence though she winced - She
began to untie the cord with which she was
afterwards bound with fingers &amp; thumbs
in quite a systematic way and on being 
interfered with by a man looked daggers &amp;
screaming tried to beat him with her hands
she was afraid of his stick and faced him
putting her back to me as a friend = When
allowed to unloose herself she walked away
using the hands as crutches - treading on the 
backs of the fingers on the spaces between
the first joint from the nail to the second
the knuckles &amp; back of the hand being held
perpendicularly - sometimes she walks 
upright but the crutch movement in
which the feet are lifted forward together
is the common way of going - she holds
out her hand for people to lift her up and

carry her quite like a spoiled child then
bursts into a passionate cry somewhat
like that of a kite wrings her hands quite
naturally as if in despair &amp; sometimes adds
a foot to make the appeal more tender -
she sits eighteen inches high - Her black
long hair was beautiful while she was tended
by her mother who was killed - she eats
everything - comes and sits down on my 
mat beside me as a child would do - covering
herself with a mat to sleep - makes a 
nest of grass or leaves and wipes her
face with a leaf - - When wounded 

Soko


stuffs leaves into the hole - is not mis-
chievous as the monkeys are   




MS.10703





	
	
	


XCI = I present
ed
 my double barrelled gun to 
33


Katomba as he has been very kind called 
away from 
Ujiji
 - He gave me the 

Soko


but will carry it to 
Ujiji
 for me - I have tried
to refund all that the Arabs have ap-
-pended on me I left 
Mamohela
 on

2nd March and came to 

Munanbunda\'s

seven of 
Moene
l
a
kila\'s people go with
us and serve as guides - on the 3rd

we came to 
Monangongo
 

4th

 






 
Headman hid himself from fear as
we are near to where bin Juma killed five
men - then on 5th
 we came through the
same dense forest country as on 4th

and reached villages beside some hills
called 
Mobasilange
 - the village at
which we sleep is called 
Bazilange

most of them are very pretty and stand
on slopes the main streets East and
West allow the bright sun stream his



	
	   

XCII 
his

 clear rays from one end to the 
other and dry up the moisture of the frequent
showers - a little verandah is often put
in front of the door - Here at dawn the 
family gathers round the fire and 
sit
sits
 in
the enjoyment of the delicious air talking
over their little domestic affairs &amp; waiting
till the sun warms them - the leaves of the 
forest trees around and near them are
bespangled with thousands of dew drops
the cocks crow &amp; strut - the kids gambol &amp;
leap - The older goats make believe fighting
the fairy scene is no doubt one never
forgotten by the young whose infamy is 
guilded by the 
scene picture
 whose beauty is quite
indescribable - Thrifty winces often make
the heap of grass roots which bake their
clay pots ^ or make salt serve as the morning fire - In some
cases all the village is deserted as we come
near - doors are shut &amp; a bunch of leaves


	
	   
	

XCIII on a handful of reeds green placed across
it to say "no entrance here" - 
chickens not caught 
while all the fowls and goats are carried off

w
e
a
il for the hens &amp; tell like the smoking fires
of flight from the 
slave traders

 - They have
found out that I am not a slaver and
when the people remain stand calling
as I pass - "This is the good one ^ 
Bolongo
" - "Friend-
ship Friendship" - They sell their fine iron
rings eagerly for a few beads - The rings are
out of fashion since beads came in - 
"slaves" slap grown men in sheer wanton-
-ness I have threatened to thrash them if
I see them but out of sight of me they do it
still - The owners confess that all the mischief
is done by slaves, and then when Manyema
resent and kill the nasty curs vengeance 
is taken by guns - The free men behave
better than the slaves = The Manyema are
far more beautiful than other free of



	
	   

XCIV bond of 
Zanzibar
 - The men say "if we had 


Manyema women we should get beautiful 
children" Many women are very pretty &amp; the men
handsome. Hands feet &amp; limbs perfect - orifices
of the nose widened by snufftakers - teeth not
filed except a little space between two front incisors


5th March 1871 We heard today that 


Muhamads

Muhamad\'s

people passed us on the West with much ivory
I lose thus 20 copper rings I was to take from
them and all the notes they were to make
for me of the rivers they crossed =



6th
 
passed
Passed
 through very large villages with many
forges in active work - men followed us as if
to fight but we got them to turn peaceably
we 
dont
don\'t
 know who are enemies so many
have been maltreated &amp; had relatives killed - The

rain of yesterday
 made paths so slippery that
the feet of all were sorely fatigued and on
coming to 

Mangara\'s
 I resolved to rest on 7th

near 




mt

Mt



Mount
 
Kimari
Kimazi


 - gave a cloth &amp; beads in lieu
of a fine fat goat from chief a clever good man
               
                
    




	
	
	


XCV 9th March 1871. We marched about five hours 
34

across a grassy plain without trees = 



Buga
Mbuga



 or Prairie
The torrid sun nearly vertical sent his fierce rays down
and fatigued us all - crossed two ^ 
Sokoye
 streams by bridges &amp;
slept at a village on a ridge of woodland overlooking





Kasonga
Kasongo



 - After two hours this morning we came
to a villages of this chief &amp; at one were welcomed
by the safari of Salem Mokadam
 &amp; I was given 
a house - 

Kasonga
Kasongo

 is a very fine young man
with European features and very clever and
good - Has four guns - 


Muhamads

Muhamad\'s
 people
were led by his and spent all their copper for
some fifty 
frasilahs
 of good ivory  
Calculation here.

From this party men have been sent
over 
Lualaba
 and about fifty 
frasilahs
 obtained
All praise 

Kasonga
Kasongo

 - - this place is about

6 miles ^ East from 
Lualaba
 and very healthy


10th
 


Muhamads

Muhamad\'s
 people are said to have gone
to 
Luapanga a powerful chief who told
them they were to buy all their ivory from



    
	

XCVI him - He had not enough and they wanted 
to go on to a people who have ivory doorposts
But he said "You shall go neither forwards nor
backwards but remain here" He called an
immense body of archers and said "you must
fight these" - they killed Luapanga and many 
of his people called Bahika - crossed a very
large river the 
Morombya
 or 
Morombwe

and again the 
Pembo river
 but 
dont
don\'t
 seem
to have gone very far North -

I wished to go from this in canoes but 
Ka-
songo
 has none so I must tramp for 5 or 6
days to Moene Lualaba to buy one if I have credit
with Abed






11th
 Had a long fierce oration from Amur in
which I was told again &amp; again that I should be
killed and eaten - people wanted a white one
to eat = I needed 200 guns - must not go to die - 
I told him that I was thankful for advice if given by
one who had knowledge but his vehement threats

    
	
	

XCVII were dreams of one who had never gone
anywhere but sent his slaves to kill people = He
was only frightening my people and doing me an
injury - Baker had only twelve people &amp; came
near to this. "Were the people cannibals" &amp;c &amp;c
I left this noisy demagogue after saying I thanked
him for this warnings but saw he knew not 
what he was saying - The 
traders from 
Ujiji


are simply marauders, and their people
worse than themselves thirst for blood more
than for ivory - Each longs to be able to tell a tale
of blood, and 
Manyema are an easy prey


Abed
 
Hassani
 assaulted the people at 

Moene Lualaba\'s

and now they keep to the other bank and I am
forced to bargain with Kasongo for a canoe
and he sends to a friend for one to be seen on
the 13th
. This 
Abed
 declared to me that he would
not begin hostilities but he began nothing
else. The propsect of getting slaves over -
-powers all else &amp; blood 
blood

 flows
in horrid streams - The Lord look on it
He will have some tale to tell Muhamad Bogh
arib




	
	


XCVIII 12th
 Rashid left today for Moene Lualaba
and I wait for 


Kasongos

Kasongo\'s
 messengers
 to return
This spot is pretty - land undulating with trees
enough to be beautiful - Rice grows well and
food is abundant - 

Kasonga
Kasongo

 says that he has
but one tongue &amp; never lies - He is a contrast
to the Arabs who are nearly all liars - Musa &amp;
party are fair average opennness of Moslem
falsehood - The only difference between their religion



and them is that Muhamad lied to force his
countrymen to give up idolatry - The impudence 
of his lies is their chief feature - As a trader he 
went to 
Damascus
 &amp; heard of 

St

Saint
 Paul\'s trans-
lation to the third heaven - Muhamad at once


concieved
conceived
 the idea of a translation to the seventh
heaven - He had no miracle to 
shew
show
 in evidence
but without shame tried to appropriate Moses
bringing water out of the rock but with the characteris-
tic of all false miracles for no reason - did not



Livingstone has placed a very large "X" in the margin here.

 take water as all others did on his camel and
worked his miracle where it was not needed =
	
    
	
	


XCIX - 13th
 
sent
Sent
 my people to examine the canoe




Kasonga
Kasongo

\'s men did not reach it yesterday

afraid because their 
Headman Kasongo
gave 
Hassani &amp; Muhamad\'s people ivory
to assault the people at 

Moene Lualaba\'s
 
the trap laid was 25 copper bracelets given as debt
They killed many and captured many more


and hope not to return here
for no reason but to get slaves ^ -  they
were market people famed by all as 
good &amp; civil - Kasongo\'s goodness extends
only to the traders - I told him that they
would attack him too when they had finished
all about him and he would go yet in a

slave yoke like other Manyema It is 
terrible this 
Manyema trade - It is simply
stealing people and shedding human blood
as a sort of salvo or accompaniment 
to be able to say we fought 
Kasongo\'s
enemies - Marvel not at the matter
there be higher than they.

    
	


C - 14th March 1871 Men did not return yesterday
I heard only lately of 

Youngs
Young\'s
 search for me on 
Nyassa

and am deeply  thankful to 

H M
Her Majesty\'s
 Govt

Government
 and all
concerned in taking trouble to ascertain my fate


Musa and his companions
 are fair average speci-
-mens of the lower classes of half caste 
Muham-
-madans

 - one need never expect aught from them
but heartlessness and falsehood - one like them-
-selves who had been properly punished by Manganja
came past us and reported that he had been 
plundered by 



Mazitu
Maviti


Ngoni

 or 

Batuta
Ngoni

 150 miles distant ^ 

N.
North




Musa was terrified &amp; though I offered to go due
West till far past the beat of the 

Batuta
Ngoni


 as soon
as I turned my face thither ran away - they alleged
no other reason whatever but fear of 

Batuta
Ngoni

 - The

Sultan who knows his people better than anyone
else entrusts all his reverence &amp; money affairs to


Banians from 
India

 - His father did the same - He
says if he trusted his 


customs
custom\'s


customs
 income in the hands of
his own 
Muhammadan subjects they would steal it


35
 all - purloin the whole - This being true of the better
	
    
	
	

CI. 
15th

 nothing better can be expected from their inferiors
Falsehood seems ingrained in their constitutions
No wonder that in all this region they have never tried
to propagate Islamism The natives soon learn to hate
them, and slaving as carried on by the Kilwans
and the Ujijians is so bloody as to prove an
effectual barrier against proselytism - The



Muhamadan
Muhammadan
s have in all their intercourse
in 
East 
Africa


 propagated nothing but

syphilis and the domestic bug
 - In spreading
the disease they have been distressingly successful
even in 
Manyema
 - Filthy talkers all their
speech to the natives is too disgusting to 
noticed - to avoid provoking ill will
I listened as if I heart it not -


16th
 The party here assaulted 
Kasongo\'s people

yesterday and killed three men capturing as
usual women &amp; children - My men not come 
back - I fear engaged in some broil


17th - 18th
  
not
Not
 come yet though two men were
sent after them 19th
 as I feared having killed
three men - I am clear of blood guiltiness -
no large canoe seen - people angry because Kasongo
sent traders to them killed their guide and wounded
others - I can send no where without danger of my men
eagerly engaging in bloodshed -



20th
 I am heart sore and sick of human blood -





20th


Series of calculations related to "Pieces Kanike."









21st
 Kasongo\'s 
brothers
brother\'s
 child died
and he asked me to remain today while
he buried the dead and he would give
me a guide tomorrow - Being rainy
I stop willingly -


Dugumbe is said to purpose going
down the river to 
Kanayumbe River
 
and build on the land 
Kanayumbe



which is a loop formed by the river &amp; is large




Kanayumbe loop
 &amp; river
Small map of the river and the region encircled by it.
 He is believed to possess great power
of divination and even of killing
unfaithful women


22nd
 I am detained another day by sickness of
one of the party - very cold rain yesterday from


Nor West
North West
 - I hope to go tomorrow towards the


sokoni
 or great market of this region -


            

       	
	


',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_viewable' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-11-14 23:32:54 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Joseph B. Braithwaite',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '9b4cb536-914c-4a4b-880b-229ace9fd355',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Braithwaite, Joseph B., 1818-1905',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Joseph B. Braithwaite, 12 November 1861',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1141',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-17.693333,35.315278',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '12 November 1861',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1861-11-12T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 4,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '228 x 185',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_001688_thumbnail.jpg',
        'uri' => 'public://liv_001688_thumbnail_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 17206,
        'status' => 1,
        'type' => 'image',
        'uuid' => '0ef2450f-ec30-4365-939b-0447dff532e7',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 93,
          'width' => 100,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 75,
        'width' => 80,
        'uuid_features_packaged_file_path' => 'assets/liv_001688_thumbnail_0.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:001688',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'HMS "Pioneer"',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_001688',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'National Library of Scotland: MS. 20312, 85-86',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1861-11-12T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Sidney Strong',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a506404f-b983-48e2-99db-50e08c64945a',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Strong, Sidney, ?-1863',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Sidney Strong, 25 March 1862',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1208',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-18.0775,35.776667',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(
    'und' => array(
      0 => array(
        'value' => 'MS. 10779',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '25 March 1862',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1862-03-25T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 8,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '324 x 204',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => 'Oxford, Cambridge, Dublin and Durham Mission to Central Africa, Occasional Paper, 1862, 36-38. ',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:001759',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Kongone Mouth of Zambesi',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_001759',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Bodleian Library. Weston Library: U.M.C.A. B4 (ii), 81-84',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1862-03-25T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'A Portion of a Page of David Livingstone\'s 1871 Field Diary (CXVII). Facsimile from David Livingstone\'s Last Journals (1874,2:opposite 114)',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1489442622,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'bf43ae52-43c8-46f8-a4aa-2e373766a396',
  'field_manuscript_addressees' => array(),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'A Portion of a Page of David Livingstone\'s 1871 Field Diary (CXVII). Facsimile from David Livingstone\'s Last Journals (1874,2:opposite 114), 1874',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '53.214587,-1.665579',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Hodson, Cooper; Livingstone, David, 1813-1873; Waller, Horace, 1833-1896',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => 1874,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1874-12-31T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(),
  'field_manuscript_extent_size' => array(),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'books; diaries; facsimiles (reproductions); publications',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_014098_thumbnail.jpg',
        'uri' => 'public://liv_014098_thumbnail_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 18819,
        'status' => 1,
        'type' => 'image',
        'uuid' => '5c389967-3752-4f1b-a766-080c3d7d7abc',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 86,
          'width' => 100,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 86,
        'width' => 100,
        'uuid_features_packaged_file_path' => 'assets/liv_014098_thumbnail_0.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:014098',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => '[Britain]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_014098',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'National Library of Scotland',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1874-01-01T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2017-03-13 22:03:42 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Jose M. Nunes',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'cb65603d-3610-4379-a589-a331b1710397',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Nunes, Jose M.',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Jose M. Nunes, 1 January 1861',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1063',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-18.039444,35.610556',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(
    'und' => array(
      0 => array(
        'value' => 'MS. 10779',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873; Waterson, Jane Elizabeth, 1843-1932',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '1 January 1861',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1861-01-01T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 4,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); copies (derivative objects); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:001609',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Shupanga',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_001609',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Zimbabwe. National Archives: LI 1/1/1, 1202-1205',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1861-01-01T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Robert L. Playfair and John Kirk 2',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'e6b0aebc-9bf9-42bd-a077-2cdb8f20008e',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Kirk, John 2, 1832-1922; Playfair, Robert L., 1828-1899',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Robert L. Playfair and John Kirk 2, November 1870',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1956',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-2.95,25.95',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => 'November 1870',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1870-11-30T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 4,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '123 x 119',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => 'Reginald Foskett, ed., The Zambesi Doctors: David Livingstone\'s Letters to John Kirk, 1858-1872 (Edinburgh: Edinburgh University Press, 1964), 140-144. Christie\'s (London), 25 Sept. 2008, http://www.christies.com/lotfinder/books-manuscripts/david-livingstone-5115315-details.aspx (accessed 13 Apr. 2015). ',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002557',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Bambarre, Manyema Country',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002557',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Private owner',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1870-11-01T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'Letter to Majid ibn Sa\'id Al-Busaid',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'ee7269e8-3873-4b30-b403-5a910666cf2e',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => 'Majid ibn Sa\'id Al-Busaid, 1834/5-1870',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'Letter to Majid ibn Sa\'id Al-Busaid, 20 April 1869',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Letters, 1937',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '-4.9,29.683333',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(
    'und' => array(
      0 => array(
        'value' => 'MS. 10734',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '20 April 1869',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1869-04-20T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 3,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => 'folio',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'autographs (manuscripts); copies (derivative objects); letters',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => 'William Garden Blaikie, The Personal Life of David Livingstone (London: John Murray, 1880), 388-389. ',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002537',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => 'Ujiji',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002537',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'David Livingstone Centre: 1115, 502-504',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1869-04-20T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'A Livingstone Relic: An Inkless Letter, Written on a Copy of The Standard, Durrants Press Cuttings',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f0c8c712-f877-4f14-9d7a-82a6e47cec17',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'A Livingstone Relic: An Inkless Letter, Written on a Copy of The Standard, Durrants Press Cuttings, 1912',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '53.214587,-1.665579',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'The Standard',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => 1912,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1912-12-31T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(
    'und' => array(
      0 => array(
        'value' => 2,
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_extent_size' => array(
    'und' => array(
      0 => array(
        'value' => '429 x 162',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'clippings (information artifacts)',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_image' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'liv_014085_thumbnail.jpg',
        'uri' => 'public://liv_014085_thumbnail_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 14373,
        'status' => 1,
        'type' => 'image',
        'uuid' => '8b09a4b3-f4ad-44b2-8d87-95ffc569efba',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'metadata' => array(
          'height' => 100,
          'width' => 54,
        ),
        'alt' => NULL,
        'title' => NULL,
        'height' => 80,
        'width' => 43,
        'uuid_features_packaged_file_path' => 'assets/liv_014085_thumbnail_0.jpg',
      ),
    ),
  ),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:014085',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => '[Britain]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_014085',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'National Library of Scotland: MS. 42442, 5-6',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1912-01-01T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  $nodes[] = array(
  'title' => 'A New or Striped Variety of Eland, Found North of Sesheke (Printed in Reverse from a Wood Engraving in Narrative of an Expedition to the Zambesi and its Tributaries), with Annotations on Verso',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'manuscript',
  'language' => 'und',
  'created' => 1466437440,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'fef77af9-ce05-4566-9405-11fda3bcd29a',
  'field_manuscript_addressees' => array(
    'und' => array(
      0 => array(
        'value' => '',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_alt_title' => array(
    'und' => array(
      0 => array(
        'value' => 'A New or Striped Variety of Eland, Found North of Sesheke (Printed in Reverse from a Wood Engraving in Narrative of an Expedition to the Zambesi and its Tributaries), with Annotations on Verso, [1865]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_catalogue' => array(
    'und' => array(
      0 => array(
        'value' => 'Books, 03 (supplement)',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_coordinates' => array(
    'und' => array(
      0 => array(
        'value' => '53.214587,-1.665579',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_copy_of_item' => array(),
  'field_manuscript_creators' => array(
    'und' => array(
      0 => array(
        'value' => 'Livingstone, David, 1813-1873; Whymper, Josiah, 1813-1903',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_dates' => array(
    'und' => array(
      0 => array(
        'value' => '[1865]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_downloadable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'field_manuscript_end_date' => array(
    'und' => array(
      0 => array(
        'value' => '1865-12-31T23:59:59',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_extent_pages' => array(),
  'field_manuscript_extent_size' => array(),
  'field_manuscript_genres' => array(
    'und' => array(
      0 => array(
        'value' => 'annotations; autographs (manuscripts); drawings (visual works); wood engravings (prints)',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_hidden' => array(),
  'field_manuscript_image' => array(),
  'field_manuscript_other_versions' => array(
    'und' => array(
      0 => array(
        'value' => 'Sotheby\'s Cat., 17 Dec. 1981, lot 130. ',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_pid' => array(
    'und' => array(
      0 => array(
        'value' => 'liv:002819',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_places_created' => array(
    'und' => array(
      0 => array(
        'value' => '[Britain]',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_project_id' => array(
    'und' => array(
      0 => array(
        'value' => 'liv_002819',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_shelfmark' => array(
    'und' => array(
      0 => array(
        'value' => 'Private owner',
        'format' => NULL,
      ),
    ),
  ),
  'field_manuscript_start_date' => array(
    'und' => array(
      0 => array(
        'value' => '1865-01-01T00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'date',
      ),
    ),
  ),
  'field_manuscript_tei' => array(),
  'field_manuscript_viewable' => array(
    'und' => array(
      0 => array(
        'value' => 0,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'date' => '2016-06-20 15:44:00 +0000',
  'user_uuid' => '0ff19f94-945c-48e1-bab1-4969fb58aea1',
);
  return $nodes;
}
