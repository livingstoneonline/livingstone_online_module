/*jslint browser: true*/
/*global jQuery*/
/**
 * @file
 * Defines the manuscript-viewer widget.
 *
 * @todo When small number of pages the reference strip doesn't go the full width of the viewer.
 */
(function ($) {
  'use strict';
  $(document).ready(function () {
    $('button#toggle').removeClass("hidden");
    $('button#toggle').click(function(){
      $('.diplomatic').toggleClass("hidden");
      $('.edited').toggleClass("hidden");
    });
  });
}(jQuery));
