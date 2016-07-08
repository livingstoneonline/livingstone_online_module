/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Defines behaviors for the Browse by Standard Catalogue page.
 */
(function ($) {
  'use strict';

  /**
   * Defines a form element that corresponds to a url parameter.
   *
   * @param string selector
   *   jQuery selector to select the form element.
   * @param string key
   *   The key of the url parameter.
   * @param default_value
   *   The value used to denote that the form element is not set.
   *
   * @constructor
   */
  function Param(selector, key, default_value) {
    var that = this;
    this.field = $(selector);
    this.isset = function() {
      return that.field.val() != default_value;
    };
    this.query = function () {
      var query = {};
      query[key] = that.field.val();
      return that.isset() ? query : null;
    };
    this.clear = function () {
      that.field.val(default_value);
    };
  }

  /**
   * Defines a checkbox form element that corresponds to a url parameter.
   *
   * @param string selector
   *   jQuery selector to select the form element.
   * @param string key
   *   The key of the url parameter.
   * @param default_value
   *   The value used to denote that the form element is not set.
   *
   * @constructor
   */
  function CheckboxParam(selector, key) {
    var that = this;
    this.field = $(selector);
    this.isset = function() {
      return that.field.is(':checked');
    };
    this.query = function () {
      var query = {};
      query[key] = 1;
      return that.isset() ? query : null;
    };
    this.clear = function () {
      that.field.attr('checked', false);
    };
  }

  /**
   * Defines a form element that corresponds to a search facet.
   *
   * @param string selector
   *   jQuery selector to select the form element.
   * @param string facet
   *   The faceted search field.
   * @param default_value
   *   The value used to denote that the form element is not set.
   *
   * @constructor
   */
  function Facet(selector, facet, default_value) {
    var that = this;
    this.field = $(selector);
    this.fields = this.field;
    default_value = default_value || 0;
    this.isset = function() {
      return that.field.val() != default_value;
    };
    this.val = function() {
      return that.field.val();
    };
    this.query = function () {
      return that.isset() ? facet + ":\"" + that.val() + "\"" : null;
    };
    this.clear = function () {
      that.field.val(default_value);
    };
  }

  /**
   * Defines a form element that corresponds to a ranged search facet.
   *
   * @param string from_selector
   *   jQuery selector to select the form element representing the from range.
   * @param string to_selector
   *   jQuery selector to select the form element representing the to range.
   * @param string  facet
   *   The faceted search field.
   * @param default_value
   *   The value used to denote that the form element is not set.
   *
   * @constructor
   */
  function RangeFacet(from_selector, to_selector, facet, default_value) {
    var that = this,
        from = new Facet(from_selector, facet, default_value),
        to = new Facet(to_selector, facet, default_value),
        unbound = '*';
    this.fields = from.field.add(to.field);
    this.isset = function () {
      return from.isset() || to.isset();
    };
    this.query = function () {
      return that.isset() ? facet + ":[" + that.from() + " TO " + that.to() + "]" : null;
    };
    this.from = function () {
      return from.isset() ? from.val() : unbound;
    };
    this.to = function () {
      return to.isset() ? to.val() : unbound;
    };
    this.clear = function () {
      from.clear();
      to.clear();
    }
  }

  /**
   * The DOM element representing the point to attach the livingstoneBrowseCatalogue behavior.
   * @type {string}
   */
  var base = '.browse-catalogue-base';

  /**
   * Initialize the Livingstone Browse by Catalogue form.
   *
   * @note This will be called after every Ajax action.
   */
  Drupal.behaviors.livingstoneBrowseCatalogue = {
    attach: function (context, settings) {
      $(base, document).once('livingstoneBrowseCatalogue', function () {
        Drupal.LivingstoneBrowseCatalogue[base] = new Drupal.LivingstoneBrowseCatalogue(base, settings.livingstoneBrowseCatalogue);
      });
    },
    detach: function (context) {
      $(base).removeClass('livingstoneBrowseCatalogue-processed');
      $(base).removeData();
      $(base).off();
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
  Drupal.LivingstoneBrowseCatalogue = function (base, settings) {
    var that = this,
        sort_links = $('th a', base),
        pager_links = $('ul.pager a', base),
        full_record = new CheckboxParam('input[name="full_record"]', 'full_record'),
        query = $('input[name="query"]'),
        submit = $('input[type="submit"].search-button'),
        sort = new Param('input[name="sort"]', 'sort', 'asc'),
        order = new Param('input[name="order"]', 'order', 'Date(s)'),
        page = new Param('input[name="page"]', 'page', 0),
        year = new Facet('select[name="year"]', settings.facets.date),
        range = new RangeFacet('select[name="from"]', 'select[name="to"]', settings.facets.date),
        creator = new Facet('select[name="creator"]', settings.facets.creator),
        addressee = new Facet('select[name="addressee"]', settings.facets.addressee),
        repository = new Facet('select[name="repository"]', settings.facets.repository),
        genre = new Facet('select[name="genre"]', settings.facets.genre),
        access = new Param('select[name="access"]', 'access', 'all'),
        params = [ full_record, sort, order, page, access ],
        facets = [ year, range, creator, addressee, repository, genre ];

    /**
     * Builds a URL based on the current url and the form settings.
     *
     * @returns string
     */
    function buildURL() {
      var uri = new URI(top.location);
      // Unset page & facets query arguments.
      uri.removeSearch(['access', 'sort', 'order', 'page', 'full_record']);
      uri.removeSearch(/f\[*/);
      params.map(function (param) { return param.query() })
          .filter(function (param) { return param != null; })
          .forEach(function (param) { uri.addSearch(param); });
      facets.map(function (facet) { return facet.query() })
          .filter(function (facet) { return facet != null; })
          .forEach(function (facet) { uri.addSearch({'f[]': facet}); });
      return uri.toString();
    }

    /**
     * Uses HTML5 states to update the URL without a page refresh.
     *
     * @param string url
     */
    function setURL(url) {
      history.replaceState({}, '', url);
    }

    /**
     * Updates the url with the given param, value pair.
     *
     * @param string param
     *   The parameter to set.
     * @param string value
     *   The value to set the parameter to.
     */
    function updateURL(param, value) {
      var uri = new URI();
      uri.setSearch(param, value);
      setURL(uri.toString());
    }

    /**
     * Triggers a form rebuild via a hidden AJAX element.
     */
    function rebuild(resetPage) {
      // Most actions should clear the current page.
      resetPage = resetPage !== undefined ? resetPage : true;
      if (resetPage) {
        page.clear();
      }
      // Always update the URL before doing a rebuild.
      setURL(buildURL());
      // Trigger hidden Ajax rebuild form element.
      $('input[name="rebuild"]').trigger('mousedown');
    }

    /**
     * Toggle the collapsible column display.
     */
    function toggleCollapsibleColumns(show) {
      if (show) {
        $('.search-results').addClass('full-record');
        $('.collapsible-column').show();
      }
      else {
        $('.search-results').removeClass('full-record');
        $('.collapsible-column').hide();
      }
    }

    /**
     * Performs a query.
     */
    function search() {
      var uri = new URI();
      uri.path('/islandora/search/' + query.val());
      setURL(uri.toString());
      rebuild();
    }

    /**
     * Initialization.
     */

    // Rebuild sort links (Ajax rebuild's can lead to an incorrect URL).
    sort_links.each(function () {
      var old = new URI($(this).attr('href'));
      var uri = new URI(top.location);
      uri.setSearch({
        sort: old.search(true).sort,
        order: old.search(true).order
      });
      $(this).attr('href', uri.toString());
    });

    // Rebuild pager links.
    pager_links.each(function () {
      var old = new URI($(this).attr('href'));
      var uri = new URI(top.location);
      uri.setSearch({
        page: old.search(true).page
      });
      $(this).attr('href', uri.toString());
    });

    // Handle events.
    submit.click(function () {
      event.preventDefault();
      search();
    });

    query.keydown(function (event) {
      if (event.keyCode == 13) {
        event.preventDefault();
      }
    });

    query.keyup(function (event) {
      if (event.keyCode == 13) {
        event.preventDefault();
        search();
      }
    });

    full_record.field.change(function (event) {
      var checked = $(this).is(':checked');
      toggleCollapsibleColumns(checked);
      updateURL('full_record', checked ? 1 : 0);
    });

    year.field.change(function (event) {
      range.clear();
      $('option:selected', this).text($(this).val());
    });

    range.fields.change(function (event) {
      year.clear();
    });

    facets.map(function (facet) {
      facet.fields.change(function () {
        rebuild();
      });
    });

    access.field.change(function (event) {
      rebuild();
    });

    sort_links.click(function (event) {
      event.preventDefault();
      var uri = new URI($(this).attr('href'));
      sort.field.val(uri.search(true).sort);
      order.field.val(uri.search(true).order);
      rebuild(false);
    });

    pager_links.click(function (event) {
      event.preventDefault();
      var uri = new URI($(this).attr('href'));
      page.field.val(uri.search(true).page);
      rebuild(false);
      $('body').animate({
        scrollTop: '0px'
      }, 1000);
    });

    toggleCollapsibleColumns(full_record.field.is(':checked'));
  };

}(jQuery));
