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
    function attachToolTips(iframes) {
      function attach() {
        var iframe = this;
        $(this).parent().scroll(function () {
          var api = $('iframe', this).contents().find('[data-hasqtip]').qtip('api');
          if (api) {
            api.destroy();
          }
        });
        $(this).contents().find('[title][title!=""]').each(function () {
          $(this).on('mouseenter', function (event) {
            var offset = $(iframe).offset();
            var position = this.getBoundingClientRect();
            var width = (position.right - position.left) / 2;
            var top = offset.top + position.top;
            var left = offset.left + position.left + width;
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
      }
      iframes.each(function () {
        var loaded = $(this).attr('loaded') == '1';
        if (!loaded) {
          $(this).load(attach);
        }
        else {
          attach.apply(this);
        }
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
          var iframes = $('.livingstone-manuscript-viewer-modal').find('iframe');
          iframes.each(function () {
            $(this).load(function () {
              attachToolTips($(this).contents().find('iframe#transcription'));
            });
          });
          break;
        case 'close':
          $('.qtip').remove();
          break;
      }
    }
    window.addEventListener("message", receiveMessage, false);

    // Initialize.
    var iframes = $('.transcription-viewer-content').find('iframe');
    attachToolTips(iframes);
  });
}(jQuery));
