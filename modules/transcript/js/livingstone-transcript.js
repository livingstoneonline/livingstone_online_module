/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 */
(function ($) {
  'use strict';

  /**
   * Object representing a transcription date, used for sorting and displaying dates.
   *
   * @param {string} input
   *   One or more date strings separated by a single whitespace.
   *
   * @constructor
   */
  function TranscriptionDate(input) {

    /**
     * Converts the given date into an object of it's constituent parts.
     *
     * @param {string} input
     *   Date to convert.
     * @returns {{bce, unknown, year, month, day, format: format, match: match, compare: compare}}
     *   Object describing the date.
     */
    function dateComponents(input) {
      var date_components = input.match(/(-?[0-9]{4})-?([0-9]{2})?-?([0-9]{2})?/),
        valid_components = $.isArray(date_components),
        extract_component = function (index) {
          var valid_component = valid_components && (typeof date_components[index] !== 'undefined');
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

    /**
     * Formats the given date(s).
     *
     * @param {string} input
     *   One or more date strings separated by a single whitespace.
     * @returns {string}
     */
    function formatDates(input) {
      var output = [];
      var dates = input.split(' ');
      var date;
      for (var i in dates) {
        date = dateComponents(dates[i]);
        output.push(date.format());
      }
      return output.join(' - ');
    }

    this.value = input;
    this.label = formatDates(input);
    this.date = dateComponents(input);
  }

  /**
   * Object representing a single pane in the display.
   *
   * @param {jQuery} pane
   *   The element that
   *
   * @constructor
   */
  function TranscriptionPane(pane) {
    var toolbar = $('.transcription-viewer-toolbar', pane),
        transcription_select = $('select.transcript', toolbar),
        date_select = $('select.date', toolbar);

    /**
     * Looks for the element that corresponds to the currently selected transcript.
     *
     * @returns {boolean|jQuery}
     *   The transcript element as a jQuery object if found, false otherwise.
     */
    function getTranscript(project_id) {
      var transcript = $('.transcription-viewer-content', pane).closest('.' + project_id);
      return transcript.length ? transcript : false;
    }

    /**
     * Looks for the element that corresponds to the currently selected transcript.
     *
     * @returns {boolean|jQuery}
     *   The transcript element as a jQuery object if found, false otherwise.
     */
    function getSelectedTranscript() {
      var project_id = transcription_select.val();
      return getTranscript(project_id);
    }

    /**
     * Returns the active transcript if found.
     *
     * @returns {boolean|jQuery}
     *   The transcript element as a jQuery object if found, false otherwise.
     */
    function getActiveTranscript() {
      var transcript = $('.transcription-viewer-content', pane).closest('.active');
      return transcript.length ? transcript : false;
    }

    /**
     * Activates the given transcript, and deactivates any currently active transcripts.
     *
     * @param {jQuery} transcript
     *   The element representing the transcript to make active.
     */
    function setActiveTranscript(transcript) {
      if (transcript) {
        // Un-active current transcript.
        $('.transcription-viewer-content', pane).each(function () {
          $(this).removeClass('active');
        });
        // Activate the transcript.
        transcript.addClass('active');
        if (transcript.hasClass('livingstone-transcript-delayed-load')) {
          var pid = transcript.data('pid'),
              dsid = transcript.data('dsid');
          $.ajax({
            dataType: "json",
            url: '/livingstone/transcript/' + pid + '/' + dsid,
            success: function (data) {
              var parent = transcript.parent();
              // Add css.
              $.each(data.css, function(key, value) {
                $("<link/>", {
                  rel: "stylesheet",
                  type: "text/css",
                  href: '/' + key,
                }).appendTo("head");
              });
              // Add Transcript.
              transcript.remove();
              transcript = $(data.html);
              transcript.addClass('active');
              parent.append(transcript);
              // Update dates.
              updateDates(transcript);
            }
          });
        }
        // Update dates.
        updateDates(transcript);
        // Scroll to top?
      }
    }

    /**
     * Setup Date values for the currently displayed document.
     *
     * @param {jQuery} transcript
     *   The element representing the transcript from which we extract the dates.
     */
    function updateDates(transcript) {
      var options = [],
          totals = {};
      // Clear out old values.
      date_select.html('<option value="null">' + Drupal.t('Select date') + '</option>');
      // Check if select picker is present.
      if (date_select.selectpicker) {
        date_select.selectpicker('val', 'null');
      }
      else {
        date_select.val('null');
      }
      // Extract dates.
      transcript.find("span.date[data-date]").each(function () {
        var date = $(this).attr('data-date');
        totals[date] = date in totals ? totals[date] + 1 : 1;
        options.push(new TranscriptionDate(date));
      });
      // Sort dates.
      options = options.sort(function(a, b) {
        return a.date.compare(b.date);
      });
      // Populate the select field.
      var counts = {};
      $.each(options, function(i, option) {
        var date = option.value;
        counts[date] = date in counts ? counts[date] + 1 : 1;
        var count = (totals[date] > 1) ? ' (' + counts[date] + ')' : '';
        date_select.append('<option value="' + option.value + '">' + option.label + count + '</option>')
      });
    }

    /**
     * Generates a selector for the given date.
     *
     * @param {string} date
     *   The date to select for.
     * @returns {string}
     *   The CSS selector to match the date element in the document.
     */
    function dateSelector(date) {
      return 'span.date[data-date = "' + date + '"]';
    }

    /**
     * Scroll to the given element in the transcription pane.
     *
     * @param {jQuery} container
     *   The element to scroll.
     * @param {string} selector
     *   The selector used to grab
     * @param {number} offset
     *   The index of the element to scroll to in the set of selected results.
     */
    function scrollTo(container, selector, offset) {
      var element = $(selector).eq(offset);
      if (element.length !== 0) {
        $(container).animate({
          scrollTop: Math.abs(element.position().top + container.scrollTop()) + 'px'
        }, 1000);
      }
    }

    /**
     * Bind Events.
     */

    // Change the active transcript when the transcription selection changes.
    transcription_select.change(function() {
      setActiveTranscript(getSelectedTranscript());
    });

    // Scroll to the appropriate element when the selected date changes.
    date_select.change(function() {
      var select = $(this);
      var selected = $("option:selected", this);
      var value = select.val();
      var date_selector = dateSelector(value);
      var options = $('option[value="' + value + '"]', this);
      var offset = 0;
      $.each(options, function (i) {
        if ($(this)[0] === selected[0]) {
          offset = i;
          return false;
        }
      });
      scrollTo(getActiveTranscript(), date_selector, offset);
      // Add highlight.
      $('.highlight').removeClass('highlight');
      $(date_selector).eq(offset).addClass('highlight');
    });

    // This is the first past so we must explicitly activate
    setActiveTranscript(getSelectedTranscript());
  }

  /**
   * Field Element to
   * @type {string}
   */
  var base = '.transcription-field-display';

  /**
   * Initialize the Transcript display for the double field element.
   *
   * @note This will be called after every Ajax action.
   */
  Drupal.behaviors.livingstoneTranscriptDoubleField = {
    attach: function () {
      $(base, document).once('livingstoneTranscriptDoubleField', function () {
        // Setup controls and date display.
        $('.pane', $(this)).each(function () {
          new TranscriptionPane($(this));
        });
        // Add tooltips to all content if qtip is present in the theme.
        if ($.qtip) {
          $('.transcription-viewer-content', base).find('[title][title!=""]').each(function () {
            $(this).on('mouseenter', function (event) {
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
      });
    },
    detach: function () {
      $(base).removeClass('livingstoneTranscriptDoubleField-processed');
      $(base).removeData();
      $(base).off();
    }
  };

}(jQuery));
