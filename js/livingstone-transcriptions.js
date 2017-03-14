/*global jQuery, Drupal*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 */
(function ($) {
  'use strict';

  var base = '#transcription-viewer';

  function date_components(input) {
    var date_components = input.match(/(-?[0-9]{4})-?([0-9]{2})?-?([0-9]{2})?/),
        valid_components = $.isArray(date_components),
        extract_component = function (index) {
          var valid_component = valid_components && (typeof date_components[index] != 'undefined');
          return valid_component ? parseInt(date_components[index]) : null;
        };
    return {
      bce: input.match(/^-/),
      unknown: input.match(/^unknown$/i),
      year: extract_component(1),
      month: extract_component(2),
      day: extract_component(3),
      format: function () {
        var months = [
          "Jan", "Feb", "Mar", "Apr", "May", "June",
          "July", "Aug", "Sept", "Oct", "Nov", "Dec"
        ];
        var year = $.isNumeric(this.year) ? this.year : false;
        var month = $.isNumeric(this.month) ? months[this.month - 1] : false;
        var day = $.isNumeric(this.day) ? this.day : false;
        if (this.unknown) {
          return 'Unknown';
        }
        else if (this.bce && year) {
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
      },
      match: function() {
        var year  = $.isNumeric(this.year) ? this.year.toString() : '0000',
            month = $.isNumeric(this.month) ? this.month.toString() : '00',
            day   = $.isNumeric(this.day) ? this.day.toString() : '00',
            pad = function(n, width) {
              n = n + '';
              return n.length >= width ? n : new Array(width - n.length + 1).join('0') + n;
            };
        return pad(year , 4) + '-' + pad(month, 2) + '-' + pad(day, 2);
      },
      compare: function(b) {
        if (this.unknown && b.unknown) {
          return 0;
        }
        else if (this.unknown) {
          return 1;
        }
        else if (b.unknown) {
          return -1;
        }
        if (this.bce && b.bce) {
          // Normal compare.
          return this.match().localeCompare(b.match());
        }
        else if (this.bce) {
          return -1;
        }
        else if (b.bce) {
          return 1;
        }
        return this.match().localeCompare(b.match());
      }
    };
  }

  function format_dates(input) {
    var output = [];
    var dates = input.split(' ');
    var date;
    for (var i in dates) {
      date = date_components(dates[i]);
      output.push(date.format());
    }
    return output.join(' - ');
  }

  function TranscriptionDate(input) {
    this.value = input;
    this.label = format_dates(input);
    this.date = date_components(input);
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
            return a.date.compare(b.date);
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
