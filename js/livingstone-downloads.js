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
  var base = '#downloads';

  /**
   * Initialize the Livingstone Transcript Viewer.
   */
  Drupal.behaviors.livingstoneDownloads = {
    attach: function (context, settings) {
      // Attach to links.
      $(base).show();
      $(base, document).once('livingstoneDownloads', function () {
        $('.close.icon').click(function(event) {
          parent.window.postMessage({ event: 'close' }, "*");
        });
      });
    }
  };

}(jQuery));
