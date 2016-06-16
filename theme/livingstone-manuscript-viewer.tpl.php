<?php
/**
 * @file
 * Template file for the Livingstone Manuscript Viewer.
 */
?>
<div id="toolbar" unselectable="on" onselectstart="return false;">
  <a class="close icon">×</a>
  <span class="icon-big-group">
    <span class="icon-group">
      <a href="#" class="slideout-menu-toggle icon fa fa-bars"></a>
      <span class="share">
        <a class="home" href="/">&nbsp;</a>
        <span class='st_email_large' displayText='Email'></span>
        <span class='st_facebook_large' displayText='Facebook'></span>
        <span class='st_twitter_large' displayText='Tweet'></span>
        <span class='st_pinterest_large' displayText='Pinterest'></span>
        <script type="text/javascript">var switchTo5x=true;</script>
        <script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
        <script type="text/javascript">stLight.options({publisher: "eaee7a62-d3e0-4e7d-bb34-6eb5073f5839", doNotHash: false, doNotCopy: false, hashAddressBar: false});</script>
      </span>
    </span>
    <span class="icon-group">
      <a class="zoom-out icon fa fa-search-minus"></a><span id="zoom-slider"></span><a class="zoom-in icon fa fa-search-plus"></a><a class="rotate icon fa fa-rotate-right"></a>
    </span>
  </span>
  <span class="icon-big-group">
    <span class="icon-group">
      <select class="page-select" value="<?php print $display_page; ?>">
        <?php foreach ($pages as $num => $data): ?>
          <option value="<?php print $num; ?>"><?php printf("%04d", $num+1); ?></option>
        <?php endforeach; ?>
      </select>
    </span><span class="icon-group"><input type="button" class="item-details icon" value="Item Details"/><input type="button" class="transcription icon" value="Transcription"/></span><span class="icon-group"><?php print $search_form; ?></span>
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
    <div class="prev-icon">
      <div class="arrow-left"></div>
    </div>
    <div class="next-icon">
      <div class="arrow-right"></div>
    </div>
    <div id="restricted-message-wrapper">
      <div id="restricted-message">
        <h1>Restricted Item</h1>
        <hr/>
        <p>
          Livingstone Online has images of the item you have selected, but we do
          not have permission to post them online or otherwise share them.
          Time permitting, we may be able to consult the item for individuals with
          legitimate research needs or questions. Please
          <a href="mailto:awisnicki@yahoo.com">email us</a> to inquire further.
        </p>
      </div>
    </div>
  </div>
</div>
