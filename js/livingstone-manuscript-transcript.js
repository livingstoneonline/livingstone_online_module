/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 */
(function ($) {
  'use strict';
  $(document).ready(function ($) {

    function pageSelector(page) {
      return 'span.pb-title:contains(' + page + ')';
    }

    function dateSelector(date) {
      return 'span.date[data-date = "' + date + '"]';
    }

    /**
     * Scroll to the given element in the transcription pane.
     */
    function transcriptionScrollTo(selector, offset) {
      var element = $(selector).eq(offset);
      if (element.length != 0) {
        $('body').animate({
          scrollTop: element.offset().top + 'px'
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
      transcriptionScrollTo(pageSelector($(this).text()), 0);
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
          transcriptionScrollTo(pageSelector(event.data.label), event.data.offset || 0);
          break;
        case 'date':
          transcriptionScrollTo(dateSelector(event.data.label), event.data.offset || 0);
          break;
      }
    }

    window.addEventListener("message", receiveMessage, false);
  });
}(jQuery));
