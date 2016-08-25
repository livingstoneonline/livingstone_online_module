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
    var base = '#edit-search-block-form--2';

    /**
     * Initialize the Livingstone Manuscript Viewer.
     */
    Drupal.behaviors.livingstoneSearchForm = {
        attach: function (context, settings) {
            // Attach to links.
            $(base, document).once('livingstoneSearchForm', function () {
                $(this).click(function() {
                    $('.search-type').show();
                });
                $(document).click(function(event) {
                    if (!$(event.target).closest(base).length &&
                        !$(event.target).closest('.search-type').length) {
                        $('.search-type').hide();
                    }
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
