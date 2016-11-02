<?php
/**
 * @file
 * Template file for the Livingstone Manuscript Viewer.
 */
?>
<?php print $downloads; ?>
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
      <?php if (!$restricted): ?>
      <a class="zoom-out icon fa fa-search-minus"></a><span class="zoom-slider"></span><a class="zoom-in icon fa fa-search-plus"></a><a class="rotate icon fa fa-rotate-right"></a>
      <?php endif; ?>
    </span>
  </span>
  <span class="icon-big-group">
    <span class="icon-group">
      <?php if (!$restricted): ?>
        <select class="page-select" value="<?php print $display_page; ?>">
          <?php foreach ($select_pages as $select_page): ?>
            <option value="<?php print $select_page['value']; ?>"><?php print $select_page['label']; ?></option>
          <?php endforeach; ?>
        </select>
      <?php endif; ?>
    </span>
    <span class="icon-group">
      <input type="button" class="item-details icon" value="Item Details"/>
      <input type="button" class="transcription icon" value="Transcription"/>
      <?php if ($spectral && !$restricted): ?>
        <input type="button" class="compare icon" value="Compare"/>
        <span class="fa fa-bolt"></span>
      <?php endif; ?>
    </span>
    <span class="icon-group"><?php print $search_form; ?></span>
  </span>
</div>
<div id="viewer">
  <div class="pane item-details">
    <?php print $item_details; ?>
  </div>
  <div class="pane transcription">
    <div id="transcription">
      <?php if ($has_transcription) : ?>
        <iframe src="<?php print url("livingstone-tei/{$manuscript}/{$display_page}");?>"></iframe>
      <?php endif; ?>
    </div>
  </div>
  <?php if (!$restricted): ?>
    <div class="pane main-image pane-open">
      <?php print $main_image; ?>
    </div>
    <div class="pane compare-image">
      <?php print $compare_image; ?>
    </div>
  <?php endif; ?>
  <?php if ($restricted): ?>
    <div class="pane restricted pane-open">
      <div id="restricted-message-wrapper">
        <div id="restricted-message">
          <h1>Restricted Item</h1>
          <hr/>
          <p>
            Livingstone Online has images of the item you have selected, but we are either still preparing them for publication or do
            not have permission to post them online.
            Time permitting, we may be able to consult the images for individuals with
            legitimate research needs or questions. Please
            <a href="mailto:awisnicki@yahoo.com">email us</a> to inquire further.
          </p>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>
