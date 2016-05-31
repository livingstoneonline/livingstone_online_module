<?php
/**
 * @file
 * Template file for the Livingstone Manuscript Viewer.
 */
?>
<div id="toolbar" unselectable="on" onselectstart="return false;">
  <span class="close">
    <a class="close icon">×</a>
  </span>
  <span class="col-xs-12 col-sm-4 col-md-3">
    <span class="side-menu">
      <a href="#" class="slideout-menu-toggle icon">
        <i class="fa fa-bars"></i>
      </a>
    </span>
    <span class="share">
      <a href="/">
        <span class="home"></span>
      </a>
      <span class='st_email_large' displayText='Email'></span>
      <span class='st_facebook_large' displayText='Facebook'></span>
      <span class='st_twitter_large' displayText='Tweet'></span>
      <span class='st_pinterest_large' displayText='Pinterest'></span>
      <script type="text/javascript">var switchTo5x=true;</script>
      <script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
      <script type="text/javascript">stLight.options({publisher: "eaee7a62-d3e0-4e7d-bb34-6eb5073f5839", doNotHash: false, doNotCopy: false, hashAddressBar: false});</script>
    </span>
  </span>
  <span class="col-xs-12 col-sm-8 col-md-4">
    <span class="zoom">
      <a class="zoom-out icon"><i class="fa fa-search-minus"></i></a>
      <span id="zoom-slider"></span>
      <a class="zoom-in icon"><i class="fa fa-search-plus"></i></a>
    </span>
    <span class="rotate">
      <a class="rotate icon"><i class="fa fa-rotate-right"></i></a>
    </span>
    <span class="page-select">
      <select class="page-select" value="<?php print $display_page; ?>">
        <?php foreach ($pages as $num => $data): ?>
          <option value="<?php print $num; ?>"><?php printf("%04d", $num+1); ?></option>
        <?php endforeach; ?>
      </select>
    </span>
  </span>
  <span class="col-xs-12 col-md-5">
    <span class="item-details">
      <input type="button" class="item-details icon" value="Item Details"/>
    </span>
    <span class="transcription">
      <input type="button" class="transcription icon" value="Transcription"/>
    </span>
    <span class="search">
      <?php print $search_form; ?>
    </span>
  </span>
</div>
<div id="livingstone-manuscript-viewer">
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
