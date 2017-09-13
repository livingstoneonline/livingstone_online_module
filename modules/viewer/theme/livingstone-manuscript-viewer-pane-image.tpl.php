<div id="<?php print $identifier; ?>"  oncontextmenu="return false;" unselectable="on" onselectstart="return false;">
  <?php if ($is_spectral): ?>
    <div class="image-toolbar">
      <!--<span title="<?php print t('Select spectral image type'); ?>">-->
        <select class="spectral-image selectpicker" data-mobile="true">
          <?php $page = reset($pages); ?>
          <?php foreach ($page['dsid'] as $dsid): ?>
            <option value="<?php print $dsid; ?>"><?php print substr($dsid, 0, strlen($dsid)-4); ?></option>
          <?php endforeach; ?>
        </select>
      <!--</span>-->
      <?php print $processing_details; ?>
      <?php print $download; ?>
    </div>
  <?php endif; ?>
  <div class="prev-icon" title="<?php print t('View previous image'); ?>">
    <div class="arrow-left"></div>
  </div>
  <div class="next-icon" title="<?php print t('View next image'); ?>">
    <div class="arrow-right"></div>
  </div>
</div>
