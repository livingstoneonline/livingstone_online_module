/**
 * Created by nbanks on 14/06/2017.
 */
(function ($) {

  /**
   * Attaches sticky table headers.
   */
  Drupal.behaviors.livingstoneTableHeader = {
    attach: function (context, settings) {
      if (!$.support.positionFixed) {
        return;
      }

      $('table.livingstone-sticky-enabled', context).once('tableheader', function () {
        $(this).data("livingstone-tableheader", new Drupal.livingstoneTableHeader(this));
      });
    }
  };

  /**
   * Constructor for the tableHeader object. Provides sticky table headers.
   *
   * @param table
   *   DOM object for the table to add a sticky header to.
   */
  Drupal.livingstoneTableHeader = function (table) {
    var self = this;

    this.originalTable = $(table);
    this.originalHeader = $(table).children('thead');
    this.originalHeaderCells = this.originalHeader.find('> tr > th');
    this.displayWeight = null;

    // React to columns change to avoid making checks in the scroll callback.
    this.originalTable.bind('columnschange', function (e, display) {
      // This will force header size to be calculated on scroll.
      self.widthCalculated = (self.displayWeight !== null && self.displayWeight === display);
      self.displayWeight = display;
    });

    // Clone the table header so it inherits original jQuery properties. Hide
    // the table to avoid a flash of the header clone upon page load.
    this.stickyTable = $('<table class="sticky-header table table-bordered"/>')
      .insertBefore(this.originalTable)
      .css({ position: 'absolute', top: '0px', 'max-width': 'none'});
    this.stickyHeader = this.originalHeader.clone(true)
      .hide()
      .appendTo(this.stickyTable);
    this.stickyHeaderCells = this.stickyHeader.find('> tr > th');

    this.stickyTable.parent().css({ position: 'relative' });
    this.originalTable.addClass('sticky-table');
    $(window)
      .bind('scroll.livingstone-tableheader', $.proxy(this, 'eventhandlerRecalculateStickyHeader'))
      .bind('resize.livingstone-tableheader', { calculateWidth: true }, $.proxy(this, 'eventhandlerRecalculateStickyHeader'))
      // Make sure the anchor being scrolled into view is not hidden beneath the
      // sticky table header. Adjust the scrollTop if it does.
      .bind('drupalDisplaceAnchor.livingstone-tableheader', function () {
        window.scrollBy(0, -self.stickyTable.outerHeight());
      })
      // Make sure the element being focused is not hidden beneath the sticky
      // table header. Adjust the scrollTop if it does.
      .bind('drupalDisplaceFocus.livingstone-tableheader', function (event) {
        if (self.stickyVisible && event.clientY < (self.stickyOffsetTop + self.stickyTable.outerHeight()) && event.$target.closest('sticky-header').length === 0) {
          window.scrollBy(0, -self.stickyTable.outerHeight());
        }
      })
      .triggerHandler('resize.livingstone-tableheader');

    $('input[name="full_record"]').bind(
      'change.livingstone-tableheader',
      { calculateWidth: true },
      $.proxy(this, 'eventhandlerRecalculateStickyHeader'));


    // We hid the header to avoid it showing up erroneously on page load;
    // we need to unhide it now so that it will show up when expected.
    this.stickyHeader.show();
  };

  /**
   * Event handler: recalculates position of the sticky table header.
   *
   * @param event
   *   Event being triggered.
   */
  Drupal.livingstoneTableHeader.prototype.eventhandlerRecalculateStickyHeader = function (event) {
    var self = this;
    var calculateWidth = event.data && event.data.calculateWidth;

    // Reset top position of sticky table headers to the current top offset.
    this.stickyOffsetTop = Drupal.settings.tableHeaderOffset ? eval(Drupal.settings.tableHeaderOffset + '()') : 0;
    this.stickyOffsetTop += $(document).scrollTop() - this.stickyTable.parent().offset().top;
    this.stickyOffsetTop += $('.region-fixed-header').height();
    this.stickyTable.css('top', this.stickyOffsetTop + 'px');

    // Save positioning data.
    var viewHeight = document.documentElement.scrollHeight || document.body.scrollHeight;
    if (calculateWidth || this.viewHeight !== viewHeight) {
      this.viewHeight = viewHeight;
      this.vPosition = this.originalTable.offset().top - 4;
      this.vPosition -= Drupal.settings.tableHeaderOffset ? eval(Drupal.settings.tableHeaderOffset + '()') : 0;
      this.vPosition -= $('.region-fixed-header').height() + 1;
      this.vLength = this.originalTable[0].clientHeight;
      calculateWidth = true;
    }

    // Track horizontal positioning relative to the viewport and set visibility.
    var vOffset = (document.documentElement.scrollTop || document.body.scrollTop) - this.vPosition;
    this.stickyVisible = vOffset > 0 && this.stickyTable.position().top < this.vLength;
    this.stickyTable.css({ visibility: this.stickyVisible ? 'visible' : 'hidden', display: this.stickyVisible ? 'table' : 'none'});
    // Add plus one to get around fractional pixels.
    this.stickyTable.css('width', this.originalTable.outerWidth() + 1);

    // Only perform expensive calculations if the sticky header is actually
    // visible or when forced.
    if (this.stickyVisible && (calculateWidth || !this.widthCalculated)) {
      this.widthCalculated = true;
      var $that = null;
      var $stickyCell = null;
      var display = null;
      var cellWidth = null;
      // Resize header and its cell widths.
      // Only apply width to visible table cells. This prevents the header from
      // displaying incorrectly when the sticky header is no longer visible.
      for (var i = 0, il = this.originalHeaderCells.length; i < il; i += 1) {
        $that = $(this.originalHeaderCells[i]);
        $stickyCell = this.stickyHeaderCells.eq($that.index());
        display = $that.css('display');
        if (display !== 'none') {
          cellWidth = $that.css('width');
          // Exception for IE7.
          if (cellWidth === 'auto') {
            cellWidth = $that[0].clientWidth + 'px';
          }
          $stickyCell.css({'width': cellWidth, 'display': display});
        }
        else {
          $stickyCell.css('display', 'none');
        }
      }
      // Add plus one to get around fractional pixels.
      this.stickyTable.css('width', this.originalTable.outerWidth() + 1);
    }
  };

})(jQuery);
