<?php
/**
 * @file
 * Template file for the Livingstone Manuscript Viewer.
 */
?>
<div id="livingstone-manuscript-viewer">
  <div id="toolbar" unselectable="on" onselectstart="return false;">
    <span>
      <a href="#" class="slideout-menu-toggle"><i class="fa fa-bars"></i></a>
    </span>
    <span class="logo">
      <a href="http://www.livingstoneonline.org">
        <img class="fixedheaderlogo" src="<?php print base_path() . drupal_get_path('theme', 'lo') . '/images/lo-sm-30.jpg'; ?>"/>
      </a>
    </span>
    <span class="share">
      <span class='st_twitter_large' displayText='Tweet'></span>
      <span class='st_facebook_large' displayText='Facebook'></span>
      <span class='st_email_large' displayText='Email'></span>
      <script type="text/javascript">var switchTo5x=true;</script>
      <script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
      <script type="text/javascript">
       stLight.options({publisher: "eaee7a62-d3e0-4e7d-bb34-6eb5073f5839", doNotHash: false, doNotCopy: false, hashAddressBar: false});
      </script>
    </span>
    <span class="zoom">
      <a class="zoom-out icon"><i class="fa fa-search-minus"></i></a>
      <span id="zoom-slider"></span>
      <a class="zoom-in icon"><i class="fa fa-search-plus"></i></a>
    </span>
    <span class="rotate">
      <a class="rotate icon"><i class="fa fa-rotate-right"></i></a>
    </span>
    <span class="item-details">
      <a class="item-details icon">Item Details</a>
    </span>
    <span class="transcription">
      <a class="transcription icon">Transcription</a>
    </span>
    <span class="page-select">
      <select class="page-select" value="<?php print $display_page; ?>">
        <?php foreach ($pages as $num => $data): ?>
          <option value="<?php print $num; ?>"><?php printf("%04d", $num+1); ?></option>
        <?php endforeach; ?>
      </select>
    </span>
    <span class="search">
      <?php print $search_form; ?>
    </span>
    <span class="close">
      <a class="close icon">×</a>
    </span>
  </div>
  <div id="text-overlay">
    <?php print $item_details; ?>
    <div id="transcription" style="display:none;">
      <?php print $transcript; ?>
    </div>
  </div>
  <div id="openseadragon" unselectable="on" onselectstart="return false;">
    <div id="side-nav">
      <div class="prev-icon">
        <div class="arrow-left"></div>
      </div>
      <div class="next-icon">
        <div class="arrow-right"></div>
      </div>
    </div>
    <div id="reference-nav" style="display:none">
      <div class="prev-icon">
        <div class="arrow-left"></div>
      </div>
      <div class="next-icon">
        <div class="arrow-right"></div>
      </div>
    </div>
  </div>
</div>
