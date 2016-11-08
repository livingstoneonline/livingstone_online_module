/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 */
(function ($) {
  'use strict';

  /**
   * The DOM elements that trigger the modal.
   * @type {string}
   */
  var base = 'a.livingstone-manuscript-viewer-modal';

  /**
   * Initialize the Livingstone Manuscript Viewer.
   */
  Drupal.behaviors.livingstoneManuscriptViewerModal = {
    attach: function (context, settings) {

      // Attach to links.
      $(base, document).once('livingstoneManuscriptViewerModal', function () {
        $(this).click(function(event) {
          event.preventDefault();
          pushState($(this).data('pid'), 0);
          openModal($(this).data('pid'));
        });
      });

      // Attach to the body, only on initial load open the viewer if params
      // are set. There is no detach for this function.
      $('body', document).once('livingstoneManuscriptViewerModal', function () {
        var uri = new URI();
        if (typeof uri.query(true).view_pid != "undefined") {
          openModal(uri.query(true).view_pid, uri.query(true).view_page);
        }
      });
    },
    detach: function (context) {
      $(base).removeClass('livingstoneManuscriptViewerModal-processed');
      $(base).removeData();
      $(base).off();
    }
  };

  /**
   * Show the viewer for the given manuscript pid and page.
   *
   * @param pid
   *   The PID of the manuscript to display.
   * @param page
   *   The page of the manuscript to display.
   */
  function openModal(pid, page) {
    page = page || 0;
    var url = '/livingstone/manuscript/' + pid + '/view';
    $.get('/livingstone/manuscript/' + pid + '/access', function (data) {
      if (data.viewable) {
        $('body').prepend('<div class="livingstone-manuscript-viewer-modal"><iframe src="' + url + '"></iframe><div>');
        $('body').addClass('modal-open');
      }
    });
  }

  /**
   * Removes the viewer from the page.
   */
  function closeModal() {
    $('body').removeClass('modal-open');
    $('.livingstone-manuscript-viewer-modal').remove();
  }

  /**
   * Checks if the viewer is defined in the DOM.
   *
   * @return {bool}
   *   TRUE if the viewer is defined FALSE otherwise.
   */
  function viewerExists() {
    return $('.livingstone-manuscript-viewer-model > iframe').length > 0;
  }

  /**
   *
   */
  function pushState(pid, page) {
    var uri = new URI(top.location);
    if (typeof pid != "undefined" && typeof page != "undefined") {
      // Push page
      uri.setSearch({
        view_pid: pid,
        view_page: page
      });
      history.pushState({ pid: pid, page: page }, '', uri.toString());
    }
    else {
      uri.removeSearch({
        view_pid: undefined,
        view_page: undefined
      });
      history.pushState({}, '', uri.toString());
    }
  }

  /**
   * Handles popState events (the back button).
   *
   * @param {object} event
   */
  function popState(event) {
    if (event.state && typeof event.state.page != "undefined") {
      if (!viewerExists()) {
        // We can back into a state where the viewer was open.
        openModal(event.state.pid, event.state.page);
      }
      else {
        // Viewer is open tell it to change it's page.
        sendMessage('page', event.state.pid, event.state.page);
      }
    }
    else {
      // Nothing on the stack? Close the viewer.
      closeModal();
    }
  }
  window.addEventListener('popstate', popState, false);

  /**
   * Sends a message to the viewer.
   *
   * @param event
   * @param pid
   * @param page
   */
  function sendMessage(event, pid, page) {
    var targetFrame = $('.livingstone-manuscript-viewer-modal > iframe')[0];
    targetFrame.contentWindow.postMessage({
      event: 'page',
      pid: pid,
      page: page
    }, '*');
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
        pushState();
        break;
      case 'page':
        pushState(event.data.pid, event.data.page);
        break;
    }
  }
  window.addEventListener("message", receiveMessage, false);

}(jQuery));
