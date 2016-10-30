/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 */
(function ($) {
  'use strict';

  /**
   * Cause all page redirects to occur in the parent of the iframe.
   */
  $(document).on('click', 'a', function(event) {
    var location = $(this).attr('href');
    var target = $(this).attr('target');
    if (typeof(location) != "undefined" &&
    location !== '#' &&
    target != "_blank") {
      event.preventDefault();
      top.location.replace(location);
    }
  });

  /**
   * The DOM element that represents the Singleton Instance of this class.
   * @type {string}
   */
  var base = '#viewer';

  /**
   * Initialize the Livingstone Manuscript Viewer.
   */
  Drupal.behaviors.livingstoneManuscriptViewer = {
    attach: function (context, settings) {
      settings = settings.livingstoneManuscriptViewer;
      $(base, document).once('livingstoneManuscriptViewer', function () {
         new Viewer(base, settings);
      });
    },
    detach: function () {
      $(base).removeClass('livingstoneManuscriptViewer-processed');
      $(base).removeData();
      $(base).off();
    }
  };

  /**
   * Models a Manuscript.
   * @constructor
   */
  var Manuscript = function (settings) {
    var that = this,
        pages = settings.pages,
        tile_sources = [],
        tile_source_mapping = {};

    // Build the list of tile sources, and mapping over them.
    $.each(pages, function (pid, page) {
      tile_source_mapping[pid] = {};
      $.each(page.token, function (dsid, token) {
        tile_source_mapping[pid][dsid] = tile_sources.length;
        tile_sources.push({
          pid: page.pid,
          dsid: dsid,
          token: token,
          width: page.width,
          height: page.height,
          maxlevel: page.levels
        });
      });
    });

    /**
     * Gets a list of tile sources from the manuscript pages data.
     */
    this.getTileSources = function () {
      return tile_sources;
    };

    /**
     * Checks if access to this manuscript is restricted.
     */
    this.getInitialTileSource = function () {
      return settings.initialPage;
    };

    /**
     * Checks if access to this manuscript is restricted.
     */
    this.getInitialSpectralTileSource = function () {
      var index = settings.initialPage;
      var page = that.getPage(index);
      var found = undefined;
      $.each(page.dsid, function (i, dsid) {
        if (!dsid.match("^COLOR")) {
          found = dsid;
          return false;
        }
      });
      return that.getTileSourceIndex(page.pid, found);
    };

    /**
     * Gets the tile source of the given pid and dsid.
     */
    this.getTileSourceIndex = function (pid, dsid) {
      if (pid in tile_source_mapping) {
        if (dsid in tile_source_mapping[pid]) {
          return tile_source_mapping[pid][dsid];
        }
        dsid = pages[pid]['dsid'][0];
        return tile_source_mapping[pid][dsid];
      }
      return false;
    };

    /**
     * Gets the tile source mapping for the given tile source index.
     */
    this.getTileSourceMapping = function (index) {
      var found = false;
      var searching = true;
      $.each(tile_source_mapping, function (pid, datastreams) {
        $.each(datastreams, function (dsid, tile_source_index) {
          if (index == tile_source_index) {
            found = {
              pid: pid,
              dsid: dsid
            };
            searching = false;
          }
          return searching;
        });
        return searching;
      });
      return found;
    };

    /**
     * Gets the tile source mapping for the given tile source index.
     */
    this.getPrevTileSourceMapping = function (index) {
      var prev_index = that.getPrevPageTileSource(index);
      return prev_index !== false ? that.getTileSourceMapping(prev_index) : false;
    };

    /**
     * Gets the tile source mapping for the given tile source index.
     */
    this.getNextTileSourceMapping = function (index) {
      var next_index = that.getNextPageTileSource(index);
      return next_index !== false ? that.getTileSourceMapping(next_index) : false;
    };

    /**
     * Gets the tile source index of the next page with the same dsid.
     */
    this.getPrevPageTileSource = function (index) {
      var current = that.getTileSourceMapping(index);
      if (current) {
        var prev = false;
        $.each(tile_source_mapping, function (pid) {
          if (pid == current.pid) {
            return false;
          }
          prev = pid;
        });
        if (prev !== false) {
          return that.getTileSourceIndex(prev, current.dsid);
        }
      }
      return false;
    };

    /**
     * Gets the tile source index of the previous page with the same dsid.
     */
    this.getNextPageTileSource = function (index) {
      var current = that.getTileSourceMapping(index);
      if (current) {
        var next = false;
        var return_next = false;
        $.each(tile_source_mapping, function (pid) {
          if (return_next) {
            next = pid;
            return false;
          }
          if (pid == current.pid) {
            return_next  = true;
          }
        });
        if (next !== false) {
          return that.getTileSourceIndex(next, current.dsid);
        }
      }
      return false;
    };

    /**
     * Fetches the given page from the tile source index.
     */
    this.getPage = function (index) {
      var mapping = that.getTileSourceMapping(index);
      return pages[mapping.pid];
    };

    /**
     * Fetches the given page from the tile source index.
     */
    this.getPageByPid = function (pid) {
      return pid in pages ? pages[pid] : false;
    };

    /**
     * Fetches the given page from the tile source index.
     */
    this.getPageByLabel = function (label) {
      var found = false;
      $.each(pages, function(pid, page) {
        if (page.label == label) {
          found = page;
          return false;
        }
      });
      return found;
    };

    /**
     * Checks if access to this manuscript is restricted.
     */
    this.hasTranscription = function () {
      return settings.hasTranscription;
    };

    /**
     * Checks if access to this manuscript is restricted.
     */
    this.isRestricted = function () {
      return tile_sources.length == 0;
    };

  };

  /**
   * Main object that manages all others.
   * @constructor
   */
  var Viewer = function (base, settings) {
    var that = this,
        element = $(base),
        manuscript = new Manuscript(settings),
        toolbar = new Toolbar('#toolbar', manuscript),
        item_details = new ItemDetails('#item-details'),
        transcription = new Transcription('#transcription', manuscript),
        main_image = $('#main-image').length ?
          new Image('#main-image', manuscript, settings.openSeaDragon.options) :
          null,
        comparison_image = $('#compare-image').length ?
          new Image('#compare-image', manuscript, settings.openSeaDragon.options) :
          null,
        images = [main_image, comparison_image].filter(function (value) { return value !== null; }),
        item_details_pane = $('.pane.item-details'),
        transcription_pane = $('.pane.transcription'),
        main_image_pane = $('.pane.main-image'),
        compare_image_pane = $('.pane.compare-image'),
        restricted_pane = $('.pane.restricted'),
        panes = [
          item_details_pane,
          transcription_pane,
          main_image_pane,
          compare_image_pane,
          restricted_pane
        ],
        center_panes = [
          main_image_pane,
          restricted_pane
        ];

    function setPage(event) {
      toolbar.setPage(event.pid);
      transcription.setPage(event.pid);
      $.each(images, function () {
        this.setPage(event.pid);
      })
    }

    function zoomTo(event) {
      toolbar.setZoomPercentage(event.zoom);
      $.each(images, function () {
        this.setZoomPercentage(event.zoom);
      });
    }

    // Zoom out.
    toolbar.on('zoom-out', function () {
      $.each(images, function () {
        this.doSingleZoomOut();
      })
    });

    // Zoom to.
    toolbar.on('zoom-to', zoomTo);
    $.each(images, function () {
      this.on('zoom-to', zoomTo);
    });

    // Zoom in.
    toolbar.on('zoom-in', function () {
      $.each(images, function () {
        this.doSingleZoomIn();
      })
    });

    // Rotate.
    toolbar.on('rotate', function () {
      $.each(images, function () {
        this.rotate();
      })
    });

    // Page change.
    toolbar.on('page-change', setPage);
    transcription.on('page-change', setPage);
    $.each(images, function () {
      this.on('page-change', setPage);
    });

    // Open Pane.
    toolbar.on('open-pane', function (event) {
      // Close and reset everything.
      $.each(panes, function () {
        this.removeClass('pane-open');
        this.removeClass('pane-left');
        this.removeClass('pane-right');
      });
      element.removeClass('compare');

      switch (event.pane) {
        case 'item details':
          item_details_pane.addClass('pane-open').addClass('pane-left');
          $.each(center_panes, function () {
            this.addClass('pane-open');
            this.addClass('pane-right');
          });
          break;
        case 'transcription':
          transcription_pane.addClass('pane-open').addClass('pane-right');
          $.each(center_panes, function () {
            this.addClass('pane-open');
            this.addClass('pane-left');
          });
          break;
        case 'compare':
          // Special case as showing both changes each.
          element.addClass('compare');
          compare_image_pane.addClass('pane-open').addClass('pane-right');
          $.each(center_panes, function () {
            this.addClass('pane-open');
            this.addClass('pane-left');
          });
          break;
      }
    });

    // Close pane.
    toolbar.on('close-pane', function (event) {
      // Close and reset everything.
      $.each(panes, function () {
        this.removeClass('pane-open');
        this.removeClass('pane-left');
        this.removeClass('pane-right');
      });
      $.each(center_panes, function () {
        this.addClass('pane-open');
      });
      element.removeClass('compare');
    });

    /**
     * Resize the viewer.
     */
    function resize() {
      var height = window.innerHeight - $('#toolbar').outerHeight();
      element.height(height);
      // Hack to get around sudden switch to mobile when displaying compare.
      if (window.innerWidth <= 568) {
        if (compare_image_pane.hasClass('pane-open')) {
          $('#toolbar .icon.compare').removeClass('depressed');
          toolbar.trigger('close-pane', { pane:'compare' });
        }
      }
    }

    $(window).resize(resize);
    $(window).on("orientationchange", resize);
    resize();

    // Show the compare pane by default.
    toolbar.togglePane('compare');

    // Remove the loading modal.
    setTimeout(function () {
      $('body').removeClass('loading');
    }, 3000);

  };

  /**
   * Wrapper for the toolbar.
   * @constructor
   */
  var Toolbar = function (selector, manuscript) {
    var that = this,
        element = $(selector),
        slider = $('.zoom-slider', element),
        zoom_out = $('.icon.zoom-out', element),
        zoom_in = $('.icon.zoom-in'),
        rotate = $('.icon.rotate'),
        pager = $('select.page-select'),
        item_details = $('.icon.item-details'),
        transcription = $('.icon.transcription'),
        compare = $('.icon.compare'),
        radios = [item_details, transcription, compare].filter(function (value) {
          return value.length > 0;
        });

    if (!manuscript.hasTranscription()) {
      transcription.addClass('disabled');
      radios = radios.filter(function (value) {
        return !transcription.is(value);
      })
    }

    // Setup Zoom.
    slider.slider({
      min: 1,
      max: 100,
      slide: function( event, ui ) {
        element.trigger(jQuery.Event('zoom-to', { zoom: ui.value / 100 }));
      }
    });

    // Zoom Out.
    zoom_out.click(function () {
      element.trigger(jQuery.Event('zoom-out'));
    });

    // Zoom In.
    zoom_in.click(function () {
      element.trigger(jQuery.Event('zoom-in'));
    });

    // Rotate.
    rotate.click(function () {
      element.trigger(jQuery.Event('rotate'));
    });

    // Page Select.
    pager.change(function () {
      element.trigger(jQuery.Event('page-change', { pid: $(this).val() }));
    });

    // Toggle the button, and send an open or close event.
    this.togglePane = function (pane) {
      var button = false;
      var was_depressed = false;
      $.each(radios, function () {
        if (this.val().toLowerCase() == pane) {
          button = this;
          was_depressed = button.hasClass('depressed');
        }
        this.removeClass('depressed');
      });
      if (button) {
        if (!was_depressed) {
          button.addClass('depressed');
          element.trigger(jQuery.Event('open-pane', { pane: pane }));
        }
        else {
          element.trigger(jQuery.Event('close-pane', { pane: pane }));
        }
      }
    };

    // Radio toggle pane buttons.
    function click_pane_radio() {
      that.togglePane($(this).val().toLowerCase());
    }
    $.each(radios, function () {
      this.click(click_pane_radio);
    });

    // Close
    $('.icon.close', element).click(function () {
      parent.window.postMessage({ event: 'close' }, "*");
    });

    /**
     * Set the tool bar zoom slider to the given zoom percentage.
     */
    this.setZoomPercentage = function (value) {
      slider.slider('value', value * 100);
    };

    /**
     * Updates the pager with the correct value for the current page.
     */
    this.setPage = function (pid) {
      pager.val(pid);
    };

    // Expose some jQuery functions via a proxy.
    this.on = $.proxy(element.on, element);
    this.trigger = $.proxy(element.trigger, element);
  };

  /**
   * Wrapper for an image viewer.
   * @constructor
   */
  var Image = function (selector, manuscript, options) {
    var that = this,
        element = $(selector),
        prev = $('.prev-icon', element),
        next = $('.next-icon', element),
        image_selector = $('select.spectral-image', element),
        page_download = $('span.page-download'),
        openseadragon = new OpenSeadragon($.extend({
          element: element.get(0),
          tileSources: manuscript.getTileSources(),
          initialPage:  selector == '#main-image' ? manuscript.getInitialTileSource() : manuscript.getInitialSpectralTileSource(),
          sequenceMode: true,
          showReferenceStrip: false,
          referenceStripPosition: 'BOTTOM',
          referenceStripSizeRatio: 0.1,
          showZoomControl: false,
          showHomeControl: false,
          showRotationControl: false,
          showFullPageControl: false,
          showSequenceControl: false,
          imageLoaderLimit: 5,
          zoomPerClick: 1.2,
          animationTime: 0,
          zoomPerScroll: 1.2,
          zoomPerSecond: 1.0,
          springStiffness: 1.0,
          viewportMargins: {
            left: 10,
            right: 10,
            top: 10,
            bottom: 30
          }
        }, options || {}));

    /**
     * Checks if the given number is a valid tile source index.
     */
    function validTileSourceIndex(index) {
      return $.isNumeric(index) && index >= 0 && index < openseadragon.tileSources.length;
    }

    /**
     * Updates the page download link.
     */
    function updatePageDownload(index) {
      var page = manuscript.getPage(index);
      page_download.html('');
      if ($.isNumeric(page.size) && page.size > 0) {
        var size = page.size / 1024 / 1024;
        var text = 'Download archival packet (' + size.toFixed(2) + ' MB)';
        var url = Drupal.settings.basePath + 'islandora/object/' + page.pid + '/datastream/ZIP/download';
        page_download.html('<a href="' + url + '">' + text + '</a>');
      }
    }

    /**
     * Updates the page download link.
     */
    function updateImageSelect(index) {
      var mapping = manuscript.getTileSourceMapping(index);
      if (mapping) {
        image_selector.val(mapping.dsid);
      }
    }

    /**
     * Zoom in a single unit.
     */
    this.doSingleZoomIn = function () {
      var viewport = openseadragon.viewport;
      if (viewport) {
        viewport.zoomBy(
        openseadragon.zoomPerClick / 1.0
        );
        viewport.applyConstraints();
      }
    };

    /**
     * Zoom out a single unit.
     */
    this.doSingleZoomOut = function () {
      var viewport = openseadragon.viewport;
      if (viewport) {
        viewport.zoomBy(
        1.0 / openseadragon.zoomPerClick
        );
        viewport.applyConstraints();
      }
    };

    /**
     * Get the current percentage of the zoom.
     */
    this.getZoomPercentage = function () {
      var viewport = openseadragon.viewport,
          min = viewport.getMinZoom(),
          max = viewport.getMaxZoom(),
          range = max - min,
          current = viewport.getZoom(true);
      return (current - min) / range;
    };

    /**
     * Sets the zoom to the given percentage.
     */
    this.setZoomPercentage = function (percentage) {
      var viewport = openseadragon.viewport,
          min = viewport.getMinZoom(),
          max = viewport.getMaxZoom(),
          range = max - min,
          zoom = range * percentage;
      viewport.zoomTo(min + zoom);
    };

    /**
     * Rotates the image 90 degrees from its current rotation.
     */
    this.rotate = function () {
      var viewport = openseadragon.viewport,
          current = viewport.getRotation();
      viewport.setRotation((current + 90) % 360);
    };

    /**
     * Sets the tile source based on the given PID.
     */
    this.setPage = function (pid, dsid) {
      var current_mapping = manuscript.getTileSourceMapping(openseadragon.currentPage());
      var index = manuscript.getTileSourceIndex(pid, dsid || current_mapping.dsid);
      that.showTileSource(index);
    };

    /**
     * Shows the given tile source.
     */
    this.showTileSource = function (index) {
      if (!validTileSourceIndex(index)) {
        return;
      }
      openseadragon._sequenceIndex = index;
      openseadragon._updateSequenceButtons( index );
      openseadragon.open( openseadragon.tileSources[ index ] );
      if( openseadragon.referenceStrip ){
        openseadragon.referenceStrip.setFocus( index );
      }
      updatePageDownload(index);
      updateImageSelect(index);
    };

    // Navigation previous page.
    prev.click(function () {
      var index = openseadragon.currentPage();
      var prev = manuscript.getPrevTileSourceMapping(index);
      if (prev !== false) {
        element.trigger(jQuery.Event( "page-change", { pid: prev.pid } ));
      }
    });

    // Navigation next page.
    next.click(function () {
      var index = openseadragon.currentPage();
      var next = manuscript.getNextTileSourceMapping(index);
      if (next !== false) {
        element.trigger(jQuery.Event( "page-change", { pid: next.pid } ));
      }
    });

    // Change the current image being displayed.
    image_selector.change(function () {
      var current_index = openseadragon.currentPage(),
          mapping = manuscript.getTileSourceMapping(current_index),
          pid = mapping.pid,
          dsid = $(this).val(),
          index = manuscript.getTileSourceIndex(pid, dsid);
      that.showTileSource(index);
      element.trigger(jQuery.Event( "image-change", { pid: pid, dsid: dsid, index: index }));
    });

    // Notify the viewer the zoom level has changed.
    openseadragon.addHandler("animation", function () {
      var value = that.getZoomPercentage();
      element.trigger(jQuery.Event("zoom-to", { zoom: value }));
    });

    // Adjust the zoom when opening an new image.
    openseadragon.addHandler('open', function () {
      openseadragon.viewport.zoomTo(openseadragon.viewport.getMinZoom(), null, true);
      openseadragon.viewport.applyConstraints();
    });

    // Zoom out before opening.
    openseadragon.viewport.zoomTo(openseadragon.viewport.getMinZoom());

    // Update the download link before display.
    updatePageDownload(openseadragon.currentPage());
    updateImageSelect(openseadragon.currentPage());

    // Expose some jQuery functions via a proxy.
    this.on = $.proxy(element.on, element);
  };

  /**
   * Wrapper for the item details pane.
   * @constructor
   */
  var ItemDetails = function (selector) {
    var that = this,
        element = $(selector),
        downloads_modal = $('#downloads');

    // Close downloads modal.
    $('.icon.close', downloads_modal).click(function () {
      downloads_modal.hide();
    });

    $('span.open-download-model', element).click(function (event) {
      event.preventDefault();
      downloads_modal.show();
      return false;
    });
  };

  /**
   * Wrapper for the transcription pane.
   * @constructor
   */
  var Transcription = function (selector, manuscript) {
    var that = this,
        element = $(selector);

    /**
     * Scrolls to the given page if possible.
     */
    this.setPage = function (pid) {
      var page = manuscript.getPageByPid(pid);
      if (typeof page.label != "undefined") {
        var iframe = jQuery('#transcription iframe');
        if (iframe.length) {
          iframe.get(0).contentWindow.postMessage({
            event: 'page',
            label: page.label
          }, "*");
        }
      }
    };

    // Listen for page events.
    function receiveMessage(event) {
      if (typeof event.data.event == "undefined") {
        return;
      }
      if (event.data.event == 'page' &&
          typeof event.data.label != "undefined") {
        var page = manuscript.getPageByLabel(event.data.label);
        if (page) {
          element.trigger(jQuery.Event('page-change', { pid: page.pid }));
        }
      }
    }
    window.addEventListener("message", receiveMessage, false);

    // Expose some jQuery functions via a proxy.
    this.on = $.proxy(element.on, element);
  };

}(jQuery));