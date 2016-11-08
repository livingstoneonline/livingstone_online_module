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
    var base = 'form input[name="search_block_form"]';

    /**
     * Initialize the Livingstone Manuscript Viewer.
     */
    Drupal.behaviors.livingstoneSearchForm = {
        attach: function (context, settings) {
            // Attach to links.
            $(base, document).once('livingstoneSearchForm', function () {
                $(this).click(function() {
                    $('.search-type').show();
                    setTimeout(function () {
                        $('.search-type').hide();
                    }, 10000);
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
