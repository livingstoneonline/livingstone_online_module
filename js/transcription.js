(function ($) {
  'use strict';
  $(document).ready(function(){
    $('button#toggle').removeClass("hidden");
    $('button#toggle').click(function(){
      $('.diplomatic').toggleClass("hidden");
      $('.edited').toggleClass("hidden");
      $(this).toggleClass('show-unedited');
      if ($(this).hasClass('show-unedited')) {
        $(this).text('Show edited text');
      }
      else {
        $(this).text('Show unedited text');
      }
    });
  });
}(jQuery));
