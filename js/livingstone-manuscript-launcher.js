/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 *
 * @todo When small number of pages the reference strip doesn't go the full width of the viewer.
 */
(function ($) {
  'use strict';

  /**
   * The DOM elements that represents the launchers.
   * @type {string}
   */
  var base = 'a.livingstone-manuscript-launcher';

  /**
   * Initialize the Livingstone Manuscript Viewer.
   */
  Drupal.behaviors.livingstoneManuscriptLauncher = {
    attach: function (context, settings) {

      // Attach to links.
      $(base, document).once('livingstoneManuscriptLauncher', function () {
        $(this).click(function(event) {
          event.preventDefault();
          pushState($(this).data('pid'), 0);
          openViewer($(this).data('pid'));
        });
      });

      // Attach to the body, only on initial load open the viewer if params
      // are set. There is no detach for this function.
      $('body', document).once('livingstoneManuscriptLauncher', function () {
        var uri = new URI();
        if (typeof uri.query(true).view_pid != "undefined") {
          openViewer(uri.query(true).view_pid, uri.query(true).view_page);
        }
      });
    },
    detach: function (context) {
      $(base).removeClass('livingstoneManuscriptLauncher-processed');
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
  function openViewer(pid, page) {
    page = page || 0;
    var url = '/livingstone-viewer/' + pid;
    if (typeof page != "undefined") {
      url = url + '/' + page;
    }
    $('body').prepend('<iframe class="livingstone-manuscript-viewer" src="' + url + '"></iframe>');
  }

  /**
   * Removes the viewer from the page.
   */
  function closeViewer() {
    $('iframe.livingstone-manuscript-viewer').remove();
  }

  /**
   * Checks if the viewer is defined in the DOM.
   *
   * @return {bool}
   *   TRUE if the viewer is defined FALSE otherwise.
   */
  function viewerExists() {
    return $('iframe.livingstone-manuscript-viewer').length > 0;
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
        openViewer(event.state.pid, event.state.page);
      }
      else {
        // Viewer is open tell it to change it's page.
        sendMessage('page', event.state.pid, event.state.page);
      }
    }
    else {
      // Nothing on the stack? Close the viewer.
      closeViewer();
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
    var targetFrame = $('iframe.livingstone-manuscript-viewer')[0];
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
        closeViewer();
        pushState();
        break;
      case 'page':
        pushState(event.data.pid, event.data.page);
        break;
    }
  }
  window.addEventListener("message", receiveMessage, false);

}(jQuery));
