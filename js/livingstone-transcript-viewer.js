/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 */
(function ($) {
  'use strict';

  /**
   * The DOM elements that represents the launchers.
   * @type {string}
   */
  var base = '#transcription-viewer';

  /**
   * Initialize the Livingstone Transcript Viewer.
   */
  Drupal.behaviors.livingstoneTranscriptViewer = {
    attach: function (context, settings) {
      // Attach to links.
      $(base, document).once('livingstoneTranscriptViewer', function () {
        // Bind 
        $(this).click(function(event) {
          event.preventDefault();
          pushState($(this).data('pid'), 0);
          openViewer($(this).data('pid'));
        });
      });
    }
  };

}(jQuery));
