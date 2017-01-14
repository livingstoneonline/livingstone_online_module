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
    return output.join(' - ');
  }

  function format_date(input) {
    var months = [
      "Jan", "Feb", "Mar", "Apr", "May", "June",
      "July", "Aug", "Sept", "Oct", "Nov", "Dec"
    ];

    var date = input.match(/(-?[0-9]{4})-?([0-9]{2})?-?([0-9]{2})?/);
    var year = (typeof date[1] != 'undefined') ? parseInt(date[1]) : null;
    var month = (typeof date[2] != 'undefined') ? months[parseInt(date[2])-1] : null;
    var day = (typeof date[3] != 'undefined') ? parseInt(date[3]) : null;

    if (input.match(/^unknown$/i)) {
      return 'Unknown';
    }
    else if (input.match(/^-/)) {
      return Math.abs(parseInt(year)) + ' BCE';
    }
    else if (!month && !day) {
      return year;
    }
    else if (!day) {
      return month + ' ' + year;
    }
    else {
      return day + ' ' + month + ' ' + year;
    }
  }

  function TranscriptionDate(input) {
    var date = input.match(/(-?[0-9]{4})-?([0-9]{2})?-?([0-9]{2})?/),
        year = date[1] ? date[1] : '00',
        month = date[2] ? date[2] : '00',
        day = date[3] ? date[3] : '00';
    this.value = input;
    this.label = format_dates(input);
    this.unknown = input.match(/^unknown$/i);
    this.match = year + month + day;

    // Compare two TranscriptionDate.
    this.compare = function(b) {
      if (this.unknown && b.unknown) {
        return 0;
      }
      else if (this.unknown) {
        return 1;
      }
      else if (b.unknown) {
        return -1;
      }
      return this.match.localeCompare(b.match);
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
            date_select = $('select.date', toolbar);

        iframe.on('load', function() {
          var options = [];
          var totals = {};
          date_select.html('<option value="null">Select date</option>');
          iframe.contents().find("span.date[data-date]").each(function () {
            var date = $(this).attr('data-date');
            totals[date] = date in totals ? totals[date] + 1 : 1;
            options.push(new TranscriptionDate(date));
          });
          // Sort.
          options = options.sort(function(a, b) {
            return a.compare(b);
          });
          var counts = {};
          $.each(options, function(i, option) {
            var date = option.value;
            counts[date] = date in counts ? counts[date] + 1 : 1;
            var count = (totals[date] > 1) ? ' (' + counts[date] + ')' : '';
            date_select.append('<option value="' + option.value + '">' + option.label + count + '</option>')
          });

          // Resize.
          function resizeIframe() {
            iframe.height(iframe.get(0).contentWindow.document.body.scrollHeight + 'px');
          }
          resizeIframe();
          $(window).resize(resizeIframe);
        });

        // Change the displayed transcription.
        transcription_select.change(function(event) {
          var src = Drupal.settings.basePath + 'livingstone/manuscript/' + $(this).val() + '/transcript';
          iframe.attr('src', src);
        });

        // Scroll to the selected date.
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
