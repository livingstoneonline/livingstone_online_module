/*global jQuery, Drupal*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 */
(function ($) {
  'use strict';

  var base = '#transcription-viewer';

  function format_dates(input) {
    var output = [];
    var dates = input.split(' ');
    for (var i in dates) {
      output.push(format_date(dates[i]));
    }
    return output.join('-');
  }

  function format_date(input) {
    var months = [
      "Jan", "Feb", "Mar", "Apr", "May", "Jun",
      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    ];
    // Bug in javascript with BCE dates.
    var date = new Date(input);
    var day = date.getDate();
    var month = date.getMonth();
    var year = date.getFullYear();
    if (input.match(/^unknown$/i)) {
      return 'Unknown';
    }
    else if (input.match(/^-?[0-9]{4}$/)) {
      return year + (input.match(/^-/) ? ' BCE' : '');
    }
    else if (input.match(/^-?[0-9]{4}-[0-9]{2}$/)) {
      return months[month] + '. ' + year;
    }
    else {
      return day + ' ' + months[month] + '. ' + year;
    }
  }

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
            page_select = $('select.page', toolbar),
            date_select = $('select.date', toolbar);

        // Populate the page select.
        iframe.on('load', function() {
          var options = [];
          var totals = {};
          page_select.html('<option value="null">Select page</option>');
          iframe.contents().find("span.pb-title").each(function () {
            var page = $(this).text();
            page_select.append('<option value="' + page + '">' + page + '</option>')
          });
          date_select.html('<option value="null">Select date</option>');
          iframe.contents().find("span.date[data-date]").each(function () {
            var date = $(this).attr('data-date');
            totals[date] = date in totals ? totals[date] + 1 : 1;
            options.push({ value: date, label: format_dates(date) });
          });
          options = options.sort(function(a, b) {
            return new Date(a.value.split(' ')[0]) - new Date(b.value.split(' ')[0]);
          });
          var counts = {};
          $.each(options, function(i, option) {
            var date = option.value;
            counts[date] = date in counts ? counts[date] + 1 : 1;
            var count = (totals[date] > 1) ? ' (' + counts[date] + ')' : '';
            date_select.append('<option value="' + option.value + '">' + option.label + count + '</option>')
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

        // Scroll to the selected page.
        date_select.change(function(event) {
          var select = $(this);
          var selected = $("option:selected", this);
          var value = select.val();
          var options = $('option[value="' + value + '"]', this);
          var offset = 0;
          $.each(options, function (i, option) {
            if ($(this)[0] == selected[0]) {
              offset = i;
              return false;
            }
          });
          iframe.get(0).contentWindow.postMessage({
            event: 'date',
            label: value,
            offset: offset
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

        // Remove Level 2 image.
        $('.field-name-field-section-page-image').remove();
      });
    },
    detach: function () {
      $(base).removeClass('livingstoneTranscriptionsViewer-processed');
      $(base).removeData();
      $(base).off();
    }
  };

}(jQuery));
