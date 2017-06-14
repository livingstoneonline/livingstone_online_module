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
        $('.pane.transcription').animate({
          scrollTop: element.offset().top + 'px'
        }, 1000);
      }
    }

    /**
     * Sends a message to the viewer.
     */
    function sendPageMessage(label) {
      parent.window.postMessage({
        event: 'page',
        label: label
      }, "*");
    }

    // When page break is clicked let the viewer know.
    $('.TEI span.pb-title').click(function () {
      sendPageMessage($(this).text());
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
          var date_selector = dateSelector(event.data.label);
          transcriptionScrollTo(date_selector, event.data.offset || 0);
          $('.highlight').removeClass('highlight');
          $(date_selector).eq(event.data.offset || 0).addClass('highlight');
          break;
      }
    }

    window.addEventListener("message", receiveMessage, false);

    // Let the parent page know it's ready.
    parent.window.postMessage({
      event: 'ready'
    }, "*");
  });
}(jQuery));
