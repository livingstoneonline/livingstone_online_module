/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 */
(function ($) {
  'use strict';
  $(document).ready(function ($) {
    /**
     * Scroll to the given element in the transcription pane.
     *
     * @param {string} label
     */
    function transcriptionScrollTo(label) {
      var element = $("span.pb-title:contains(" + label + ")");
      if (element.length != 0) {
        $('body').animate({
          scrollTop: element[0].offsetTop + 'px'
        }, 1000);
      }
    }

    /**
     * Sends a message to the viewer.
     */
    function sendMessage(label) {
      parent.window.postMessage({
        event: 'page',
        label: label
      }, "*");
    }

    // When page break is clicked let the viewer know.
    $('.TEI span.pb-title').click(function () {
      sendMessage($(this).text());
      transcriptionScrollTo($(this).text());
    });

    /**
     * Receive an message from the viewer.
     */
    function receiveMessage(event) {
      if (typeof event.data.event == "undefined") {
        return;
      }
      switch (event.data.event) {
        case 'page':
          transcriptionScrollTo(event.data.label);
          break;
      }
    }

    window.addEventListener("message", receiveMessage, false);
  });
}(jQuery));
