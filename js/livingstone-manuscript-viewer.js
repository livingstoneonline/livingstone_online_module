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
   * Cause all page redirects to occur in the parent of the iframe.
   */
  $(document).on('click', 'a', function(event) {
    var location = $(this).attr('href');
    if (typeof(location) != "undefined" && location !== '#' ) {
      event.preventDefault();
      top.location.replace(location);
    }
  });

  /**
   * The DOM element that represents the Singleton Instance of this class.
   * @type {string}
   */
  var base = '#livingstone-manuscript-viewer';

  /**
   * Initialize the Livingstone Manuscript Viewer.
   */
  Drupal.behaviors.livingstoneManuscriptViewer = {
    attach: function (context, settings) {
      if (Drupal.LivingstoneManuscriptViewer[base] === undefined) {
        $(base, document).once('livingstoneManuscriptViewer', function () {
          Drupal.LivingstoneManuscriptViewer[base] = new Drupal.LivingstoneManuscriptViewer(base, settings.livingstoneManuscriptViewer);
        });
      }
    },
    detach: function (context) {
      $(base).removeClass('livingstoneManuscriptViewer-processed');
      $(base).removeData();
      $(base).off();
      delete Drupal.LivingstoneManuscriptViewer[base];
    }
  };

  /**
   * Creates an instance of the Livingstone Manuscript Viewer widget.
   *
   * @param {string} base
   *   The element ID that this class is bound to.
   * @param {object} settings
   *   Drupal.settings for this object widget.
   *
   * @constructor
   */
  Drupal.LivingstoneManuscriptViewer = function (base, settings) {
    // Private Members.

    // Set fixed high before init so reference strip works.
    //$('#openseadragon').height(500);
    //$('#item-details').height($(window).height() - 150);
    $('#item-details').mCustomScrollbar({
      autoHideScrollbar:true,
			theme:"rounded-dark"
    });
    //$('#transcription').height($(window).height() - 150);
    $('#transcription').mCustomScrollbar({
      autoHideScrollbar:true,
			theme:"rounded-dark"
    });

    /**
     * Checks if the given number is a valid page number.
     *
     * @param {int}
     *   The page number to check.
     *
     * @return {bool}
     */
    function validPageNumber(num) {
      return $.isNumeric(num) && num >= 0 && num < pages.length;
    }

    var that = this,
        pid = settings.pid,
        pages = settings.pages,
        initialPage = settings.initialPage,
        hasTranscription = settings.hasTranscription,
        viewer = new OpenSeadragon($.extend({
          element: $('#openseadragon', base).get(0),
          tileSources: $.map(pages, function(page) {
            return {
              pid: page.pid,
              width: page.width,
              height: page.height,
              maxLevel: page.levels
            };
          }),
          initialPage: settings.initialPage,
          sequenceMode: true,
          showReferenceStrip: true,
          referenceStripPosition: 'BOTTOM',
          referenceStripSizeRatio: 0.1,
          showZoomControl: false,
          showHomeControl: false,
          showRotationControl: false,
          showFullPageControl: false,
          showSequenceControl: false,
          //toolbar: "toolbar",
          imageLoaderLimit: 5,
        }, settings.openSeaDragon.options));

    // Set default height dynamically.
    $(window).resize(function () {
//      $('#openseadragon').height(window.innerHeight - $('#toolbar').height());
     // $('#item-details').height(window.innerHeight - 150);
     // $('#transcription').height(window.innerHeight - 150);
    });

    // Public Members.
    $.extend(this, {
      viewer: viewer,
    });

    /**
     * Zoom in a single unit.
     */
    function doSingleZoomIn() {
      var viewport = viewer.viewport;
      if ( viewport ) {
        viewport.zoomBy(
          viewer.zoomPerClick / 1.0
        );
        viewport.applyConstraints();
      }
    }

    /**
     * Zoom out a single unit.
     */
    function doSingleZoomOut() {
      var viewport = viewer.viewport;
      if ( viewport ) {
        viewport.zoomBy(
          1.0 / viewer.zoomPerClick
        );
        viewport.applyConstraints();
      }
    }

    /**
     * Get the current percentage of the zoom.
     *
     * @return {float}
     */
    function getZoomPercentage() {
      var viewport = viewer.viewport,
          min = viewport.getMinZoom(),
          max = viewport.getMaxZoom(),
          range = max - min,
          current = viewport.getZoom(true),
          percent = (current - min) / range;
      return percent;
    }

    /**
     * Sets the given page without firing any events or setting the state.
     */
    function setPage(page) {
      if (validPageNumber(page)) {
        $('select.page-select').val(page);
        viewer._sequenceIndex = page;
        viewer._updateSequenceButtons( page );
        viewer.open( viewer.tileSources[ page ] );
        if( viewer.referenceStrip ){
          viewer.referenceStrip.setFocus( page );
        }
      }
    }

    /**
     * Listen for page events.
     */
    function receiveMessage(event) {
      if (typeof event.data.event == "undefined") {
        return;
      }
      switch (event.data.event) {
        case 'page':
          if (typeof event.data.page != "undefined") {
            setPage(event.data.page);
          }
          else {
            setPage(initialPage);
          }
          break;
      }
    }
    window.addEventListener("message", receiveMessage, false);

    /**
     * Notifies the parent frame that we have changed pages.
     *
     * @param {int} page
     *   The new page number.
     */
    function sendSetPageMessage(page) {
      parent.window.postMessage({
        event: 'page',
        pid: pid,
        page: page
      }, "*");
    }

    function hideToolbar() {
      $('#toolbar').animate({
        opacity: 0.50,
        height: "25px"
      }, {
        progress: function () {
          $(window).trigger('resize');
        }
      });
    }

    function showToolbar() {
      $('#toolbar').animate({
        opacity: 1,
        height: "50px"
      }, {
        progress: function () {
          $(window).trigger('resize');
        }
      });
    }

    function setToolbarPage(page) {
      $('select.page-select').val(page);
      // Set the next / prev icons.
      if (page == 0) {
        $('#side-nav .arrow-left').css('border-right-color', 'grey');
      }
      else {
        $('#side-nav .arrow-left').css('border-right-color', 'white');
      }
      if (page == pages.length - 1) {
        $('#side-nav .arrow-right').css('border-left-color', 'grey');
      }
      else {
        $('#side-nav .arrow-right').css('border-left-color', 'white');
      }
    }

    /**
     * Setup the toolbar and bound actions to it.
     */
    function initializeToolbar() {

      // Zoom Slider.
      $( "#zoom-slider" ).slider({
        min: 1,
        max: 100,
        slide: function( event, ui ) {
          var viewport = viewer.viewport,
              min = viewport.getMinZoom(),
              max = viewport.getMaxZoom(),
              range = max - min,
              zoom = range * ( ui.value / 100);
          viewport.zoomTo(min + zoom);
        }
      });

      viewer.addHandler("animation", function (data) {
        var value = getZoomPercentage();
        $('#zoom-slider').slider('value', value * 100);
      });

      // Zoom Out.
      $('a.zoom-out.icon').click(function () {
        var viewport = viewer.viewport;
        doSingleZoomOut();
      });

      // Zoom In.
      $('a.zoom-in.icon').click(function () {
        var viewport = viewer.viewport;
        doSingleZoomIn();
      });

      // Rotate.
      $('a.rotate.icon').click(function () {
        var viewport = viewer.viewport,
            current = viewport.getRotation();
        viewport.setRotation((current + 90) % 360);
      });

      // Item Details.
      $('.item-details.icon').click(function () {
        $('#item-details').toggle();
        $('#openseadragon').toggleClass('item-details-open');
      });

      // Transcription.
      if (hasTranscription) {
        $('.transcription.icon').click(function () {
          $('#transcription').toggle();
          $('#openseadragon').toggleClass('transcription-open');
          setTimeout(function () {
            $('#transcription').mCustomScrollbar("scrollTo", $("span.pb-title:eq(" + viewer.currentPage() + ")"));
          }, 1000);
        });
      } else {
        $('.transcription.icon').addClass('disabled');
      }

      // Page.
      $('select.page-select').change(function () {
        viewer.goToPage(parseInt($(this).val()));
      });

      viewer.addHandler("page", function (data) {
        setToolbarPage(data.page);
        sendSetPageMessage(data.page);
        $('#transcription').mCustomScrollbar("scrollTo", $("span.pb-title:eq(" + data.page + ")"));
      });

      // Close
      $('.close.icon').click(function () {
        parent.window.postMessage({ event: 'close'}, "*");
      });

      // Bind hover events.
      $('#toolbar').hover(
        function () {
          showToolbar();
        },
        function () {
          setTimeout(function () {
            if (!$('#toolbar').is(":hover")) {
              hideToolbar();
            }
          }, 1000);
        }
      );
      // First time, toggle hide after 5 seconds.
      setTimeout(function () {
        if (!$('#toolbar').is(":hover")) {
          hideToolbar();
        }
      }, 5000);

      // Navigation prev.
      $('#side-nav .prev-icon').click(function () {
        var page = viewer.currentPage() - 1;
        if (validPageNumber(page)) {
          viewer.goToPage(page);
        }
      });

      // Navigation next.
      $('#side-nav .next-icon').click(function () {
        var page = viewer.currentPage() + 1;
        if (validPageNumber(page)) {
          viewer.goToPage(page);
        }
      })
    }

    /**
     * Setup the reference strip and bound actions to it.
     */
    function initializeReferenceStrip() {
      function zeroPad(num, places) {
        var zero = places - num.toString().length + 1;
        return Array(+(zero > 0 && zero)).join("0") + num;
      }

      function showReferenceStrip() {
        var element = $('div.referencestrip');
        element.addClass('hover');
        element.parent().addClass('hover');
        element.css('margin-bottom', '0px');
        $('#reference-nav').show();
      }

      function hideReferenceStrip() {
        var element = $('div.referencestrip');
        element.removeClass('hover');
        element.parent().removeClass('hover');
        element.css('margin-bottom', '-' + (element.clientHeight / 2) + 'px');
        $('#reference-nav').hide();
      }

      $('div.referencestrip').hover(function() {
        showReferenceStrip();
      }, function () {
        hideReferenceStrip();
      });

      $('#reference-nav').hover(function() {
        showReferenceStrip();
      }, function () {
        hideReferenceStrip();
      });

      // Add numbers on show.
      $('div.referencestrip > div').hover(function() {
        $(this).addClass('hover');
        $(this).prepend('<div class="page-num">' + zeroPad($(this).index() + 1, 4) + '</div>');
      }, function () {
        $(this).removeClass('hover');
        $('div.page-num', this).remove();
      });

      // Scroll left.
      var scrollLeft;
      $('#reference-nav .prev-icon').mousedown(function () {
        scrollLeft = setInterval(function(){
          var e = jQuery.Event( 'keydown', {
            which: $.ui.keyCode.LEFT,
            keyCode: $.ui.keyCode.LEFT
          });
          viewer.referenceStrip.innerTracker.keyDownHandler(e);
        }, 50);
        return false;
      });
      $('#reference-nav .prev-icon').mouseup(function() {
        clearInterval(scrollLeft);
        return false;
      });
      $('#reference-nav .prev-icon').mouseout(function() {
        clearInterval(scrollLeft);
        return false;
      });

      // Scroll right.
      var scrollRight;
      $('#reference-nav .next-icon').mousedown(function () {
        scrollRight = setInterval(function(){
          var e = jQuery.Event( 'keydown', {
            which: $.ui.keyCode.RIGHT,
            keyCode: $.ui.keyCode.RIGHT
          });
          viewer.referenceStrip.innerTracker.keyDownHandler(e);
        }, 50);
        return false;
      });
      $('#reference-nav .next-icon').mouseup(function() {
        clearInterval(scrollRight);
        return false;
      });
      $('#reference-nav .next-icon').mouseout(function() {
        clearInterval(scrollRight);
        return false;
      });

    }

    // Start up.
    initializeToolbar();
    initializeReferenceStrip();

    // Set GUI.
    setToolbarPage(initialPage);

    // Set default height dynamically.
    //$('#openseadragon').height($(window).height());

    /**
     * Wait to display.
     */
    setTimeout(function () {
      $('body').removeClass('loading');
    }, 3000);
  }

}(jQuery));

// This is how we're going to deal with authentication for Djatoka, Where
// going to override the authentication function for the menu callback to
// access the image, or we can let it take straight from Fedora (making a
// global exception for localhost).
