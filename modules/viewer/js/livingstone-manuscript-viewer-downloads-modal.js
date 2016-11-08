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
    $('body').prepend('<div class="livingstone-manuscript-viewer-modal"><iframe src="' + url + '"></iframe></div>');
    $('body').addClass('modal-open');
  }

  /**
   * Removes the modal window.
   */
  function closeModal() {
    $('div.livingstone-manuscript-viewer-modal').remove();
    $('body').removeClass('modal-open');
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
