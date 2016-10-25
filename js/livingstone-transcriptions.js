/*global jQuery, Drupal*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 */
(function ($) {
  'use strict';

  var base = '#transcription-viewer';

  Drupal.behaviors.livingstoneTranscriptionsViewer = {
    attach: function (context, settings) {
      var element = $(base),
          panes = $('div.pane', base);
      $.each(panes, function () {
        var pane = $(this),
            toolbar = $('.transcription-viewer-toolbar', pane),
            content = $('.transcription-viewer-content', pane),
            iframe = $('iframe', content),
            transcription_select = $('select.transcript', toolbar),
            page_select = $('select.page', toolbar);

        // Populate the page select.
        iframe.on('load', function() {
          page_select.html('');
          iframe.contents().find("span.pb-title").each(function () {
            var page = $(this).text();
            page_select.append('<option value="' + page + '">' + page + '</option>')
          });
        });

        // Change the displayed transcription.
        transcription_select.change(function(event) {
          var src = Drupal.settings.basePath + 'livingstone-tei/' + $(this).val();
          iframe.attr('src', src);
        });

        // Scroll to the selected page.
        page_select.change(function(event) {
          iframe.get(0).contentWindow.postMessage({
            event: 'page',
            label: $(this).val()
          }, "*");
        });

        // Listen for page change events in the child iframe.
        function receiveMessage(event) {
          var iframe_window = iframe.get(0).contentWindow;
          var data = event.data;
          if (event.source == iframe_window &&
              typeof data.event != "undefined" &&
              data.event == 'page' &&
              typeof data.label != "undefined") {
            page_select.val(data.label);
          }
        }
        window.addEventListener("message", receiveMessage, false);
      });
    },
    detach: function () {
      $(base).removeClass('livingstoneTranscriptionsViewer-processed');
      $(base).removeData();
      $(base).off();
    }
  };

}(jQuery));
