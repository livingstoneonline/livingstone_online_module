<div id="toolbar" unselectable="on" onselectstart="return false;">
  <script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
  <script type="text/javascript">stLight.options({publisher: "eaee7a62-d3e0-4e7d-bb34-6eb5073f5839", doNotHash: false, doNotCopy: false, hashAddressBar: false});</script>
  <a class="close icon button">×</a>
  <a href="#" class="slideout-menu-toggle icon button fa fa-bars"></a>
  <ul class="links icon-group">
    <li class="icon-group-item"><a href="/" title="Home" displayText="Home" class="fa home icon">&#xf015;</a></li>
    <li class="icon-group-item"><a href="#" title="Email" displayText="Email" class="st_email_custom fa email icon">&#xf0e0;</a></li>
    <li class="icon-group-item"><a href="#" title="Facebook" displayText="Facebook" class="st_facebook_custom fa facebook icon">&#xf09a;</a></li>
    <li class="icon-group-item"><a href="#" title="Twitter" displayText="Twitter" class="st_twitter_custom fa twitter icon">&#xf099;</a></li>
    <li class="icon-group-item"><a href="#" title="Pinterest" displayText="Pinterest" class="st_pinterest_custom fa pinterest icon">&#xf231;</a></li>
  </ul>
  <?php if ($is_viewable): ?>
    <ul class="zoom icon-group">
      <li class="icon-group-item"><a class="zoom-out icon button fa">&#xf010;</a></li>
      <li class="icon-group-item"><span class="zoom-slider"></span></li>
      <li class="icon-group-item"><a class="zoom-in icon button fa">&#xf00e;</a></li>
      <li class="icon-group-item"><a class="rotate icon button fa">&#xf01e;</a></li>
    </ul>
  <?php endif; ?>
  <span class="icon-group-group">
  <?php if ($is_viewable): ?>
    <span class="icon-group">
      <select class="pager icon button">
        <?php foreach ($pager_options as $pager_option): ?>
          <option value="<?php print $pager_option['pid']; ?>"><?php print $pager_option['label']; ?></option>
        <?php endforeach; ?>
      </select>
    </span>
  <?php endif; ?>
    <ul class="icon-group">
      <li class="icon-group-item"><a href="#" data-pane="item details" class="item-details icon button">Item Details</a></li>
      <li class="icon-group-item"><a href="#" data-pane="transcription" class="transcription icon button <?php if (!$has_transcription): print 'disabled'; endif ?>">Transcription</a></li>
      <?php if ($is_spectral && $is_viewable): ?>
        <li class="icon-group-item"><a href="#" data-pane="compare" class="compare icon button"><span class="fa">&#xf0e7;</span>&nbsp;Compare&nbsp;<span class="fa">&#xf0e7;</span></a></li>
      <?php endif; ?>
    </ul>
    <span class="icon-group">
      <?php print $search; ?>
    </span>
  </span>
</div>
