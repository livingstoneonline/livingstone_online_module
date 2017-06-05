(function ($) {
  'use strict';

  /**
   * The DOM element that represents the Singleton Instance of this class.
   * @type {string}
   */
  var base = '.slideout-menu-toggle';

  /**
   * Initialize the Livingstone Manuscript Viewer.
   */
  Drupal.behaviors.slideOutMenu = {
    attach: function (context, settings) {
      $(base, document).once('slideOutMenu', function () {
        $(this).on('click', function (event){
          event.preventDefault();
          // create menu variables.
          var slideoutMenu = $('.slideout-menu');
          var slideoutMenuWidth = $('.slideout-menu').width() + 2;

          // toggle open class.
          slideoutMenu.toggleClass("open");

          // slide menu.
          if (slideoutMenu.hasClass("open")) {
            slideoutMenu.animate({
              left: "0px"
            });
          } else {
            slideoutMenu.animate({
              left: -slideoutMenuWidth
            }, 250);
          }
        });
      });
    }
  };
}(jQuery));
