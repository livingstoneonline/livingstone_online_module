<script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
<script type="text/javascript">stLight.options({publisher: "eaee7a62-d3e0-4e7d-bb34-6eb5073f5839", doNotHash: false, doNotCopy: false, hashAddressBar: false});</script>
<div id="toolbar" unselectable="on" onselectstart="return false;">
  <span class="item-group">
    <?php print theme('livingstone_slide_out_menu'); ?>
    <span class="links">
      <a href="/" title="Home" displayText="Home" class="fa home">&#xf015;</a>
      <a href="#" title="Email" displayText="Email" class="st_email_custom fa email">&#xf0e0;</a>
      <a href="#" title="Facebook" displayText="Facebook" class="st_facebook_custom fa facebook ">&#xf09a;</a>
      <a href="#" title="Twitter" displayText="Twitter" class="st_twitter_custom fa twitter">&#xf099;</a>
      <a href="#" title="Pinterest" displayText="Pinterest" class="st_pinterest_custom fa pinterest">&#xf231;</a>
    </span>
    <?php if ($is_viewable): ?>
      <span class="zoom">
        <a class="zoom-out fa" title="<?php print t('Zoom Out'); ?>">&#xf010;</a>
        <span class="zoom-slider" title="<?php print t('Zoom'); ?>"></span>
        <a class="zoom-in fa" title="<?php print t('Zoom In'); ?>">&#xf00e;</a>
        <a class="rotate fa" title="<?php print t('Rotate Image'); ?>">&#xf01e;</a>
      </span>
    <?php endif; ?>
  </span>
  <span class="item-group">
    <?php if ($is_viewable): ?>
      <span title="<?php print t('Select Image'); ?>">
        <select class="page-select selectpicker" data-mobile="true">
        <?php foreach ($pager_options as $pager_option): ?>
          <option value="<?php print $pager_option['pid']; ?>"><?php print $pager_option['label']; ?></option>
        <?php endforeach; ?>
        </select>
      </span>
    <?php endif; ?>
    <span class="panes">
      <a href="#" data-pane="item details" class="item-details" title="<?php print t('Display Item Details'); ?>">Item Details</a>
      <a href="#" data-pane="transcription" class="transcription <?php if (!$has_transcription): print 'disabled'; endif ?>" title="<?php print t('Display Transcription'); ?>">Transcription</a>
        <?php if ($is_spectral && $is_viewable): ?>
          <a href="#" data-pane="compare" class="compare" title="<?php print t('Compare Spectral Images'); ?>"><span class="fa">&#xf0e7;</span>&nbsp;Compare&nbsp;<span class="fa">&#xf0e7;</span></a>
        <?php endif; ?>
    </span>
    <span class="search">
      <?php print $search; ?>
    </span>
  </span>
  <a class="close" title="<?php print t('Close'); ?>">×</a>
</div>
