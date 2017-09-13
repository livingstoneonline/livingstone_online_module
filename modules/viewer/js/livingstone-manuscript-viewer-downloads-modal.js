/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 */
(function ($) {
  'use strict';

  /**
   * The DOM elements that represents the modal triggers.
   * @type {string}
   */
  var base = 'a.livingstone-manuscript-viewer-download-modal';

  /**
   * Initialize the modal triggers.
   */
  Drupal.behaviors.livingstoneManuscriptViewerDownloadsModal = {
    attach: function (context, settings) {
      // Add the element to which our logic will bind.
      if (!$('div.livingstone-manuscript-viewer-download-modal').length) {
        $('body').prepend('<div class="livingstone-manuscript-viewer-download-modal"></div>');
      }
      // Attach to links.
      $(base, document).once('livingstoneManuscriptViewerDownloadsModal', function () {
        $(this).click(function(event) {
          event.preventDefault();
          var url = $(this).attr('href');
          openModal(url);
          return false;
        });
      });
    },
    detach: function (context) {
      $(base).removeClass('livingstoneManuscriptViewerDownloadsModal-processed');
      $(base).removeData();
      $(base).off();
    }
  };

  /**
   * Show the modal window.
   */
  function openModal(url) {
    $('div.livingstone-manuscript-viewer-download-modal').prepend('<iframe src="' + url + '"></iframe>');
    $('body').addClass('download-modal-open');
  }

  /**
   * Removes the modal window.
   */
  function closeModal() {
    $('div.livingstone-manuscript-viewer-download-modal iframe').remove();
    $('body').removeClass('download-modal-open');
  }

  /**
   * Listens to messages from the viewer to remove itself.
   *
   * @param event
   *   Message from the viewer.
   */
  function receiveMessage(event) {
    if (typeof event.data.event == "undefined") {
      return;
    }
    switch(event.data.event) {
      case 'close':
        closeModal();
        break;
    }
  }
  window.addEventListener("message", receiveMessage, false);

}(jQuery));
