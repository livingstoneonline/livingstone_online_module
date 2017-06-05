/*jslint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Search selector.
 */
(function ($) {
  'use strict';

  /**
   * Represents the search form.
   * @type {string}
   */
  var base = '.form-search a[href="#"]';

  /**
   * Initialize the Livingstone Manuscript Viewer.
   */
  Drupal.behaviors.livingstoneSearchForm = {
    attach: function (context, settings) {
      $(base, document).once('livingstoneSearchForm', function () {
        $(this).click(function (e) {
          return e.stopPropagation();
        });
      });
    },
    detach: function (context) {
      $(base).removeClass('livingstoneSearchForm-processed');
      $(base).removeData();
      $(base).off();
    }
  };
}(jQuery));
