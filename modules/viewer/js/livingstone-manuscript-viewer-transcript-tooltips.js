/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Displays tooltips in the transcription panel.
 */
(function ($) {
  'use strict';
  $(document).ready(function ($) {

    /**
     * Attaches tooltips to transcription elements of the given iframes.
     *
     * @param iframes
     *   An jQuery object containing the iframes in which to attach tooltips.
     */
    function attachToolTips(tei) {
      $(tei).once('livingstoneTranscriptScroll', function() {
        $(this).scroll(function () {
          var api = $(this).find('[data-hasqtip]').qtip('api');
          if (api) {
            api.destroy();
          }
        });
      });
      $(document).click(function () {
        var api = $(this).find('[data-hasqtip]').qtip('api');
        if (api) {
          api.destroy();
        }
      });
      $(tei).find('[title][title!=""]').each(function () {
        $(this).once('livingstoneTranscriptToolTip', function () {
          $(this).on('mouseenter', function(event) {
            var position = this.getBoundingClientRect();
            var width = (position.right - position.left);
            var top = position.top;
            var left = position.left + width;
            $(this).qtip({
              prerender: false,
              style: {
                tip: false,
                classes: 'qtip-bootstrap'
              },
              position: {
                at: 'top center',
                my: 'bottom center',
                viewport: true,
                adjust: {
                  screen: true,
                  method: 'shift',
                  resize: true
                },
                target: [left, top]
              },
              show: {
                solo: true,
                ready: true,
                event: event.type
              },
              hide: {
                fixed: true,
                delay: 1000,
                event: 'click unfocus'
              },
              events: {
                hide: function (event, api) {
                  api.destroy();
                }
              }
            });
          });
        });
      });
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
        case 'open':
          // Opened viewer, so attach qtip logic.
          var iframe = $('.livingstone-manuscript-viewer-modal').find('iframe');
          iframe.load(function() {
            $(this).contents().find('body').click(function () {
              var api = $(this).find('[data-hasqtip]').qtip('api');
              if (api) {
                api.destroy();
              }
            });
            $(this).contents().find('.transcription-viewer-content').each(function () {
              attachToolTips($(this));
            });
          });
          // If already loaded.
          iframe.contents().find('.transcription-viewer-content').each(function () {
            attachToolTips($(this));
          });
          break;
        case 'close':
          $('.qtip').remove();
          break;
      }
    }
    window.addEventListener("message", receiveMessage, false);

  });
}(jQuery));
