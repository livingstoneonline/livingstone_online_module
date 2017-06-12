<div id="<?php print $identifier; ?>"  oncontextmenu="return false;" unselectable="on" onselectstart="return false;">
  <?php if ($is_spectral): ?>
    <div class="image-toolbar">
      <span title="<?php print t('Select Spectral Image Type'); ?>">
        <select class="spectral-image selectpicker" data-mobile="true">
          <?php $page = reset($pages); ?>
          <?php foreach ($page['dsid'] as $dsid): ?>
            <option value="<?php print $dsid; ?>"><?php print substr($dsid, 0, strlen($dsid)-4); ?></option>
          <?php endforeach; ?>
        </select>
      </span>
      <?php print $processing_details; ?>
      <span class="download">
        <?php print $download; ?>
      </span>
    </div>
  <?php endif; ?>
  <div class="prev-icon" title="<?php print t('View Previous Image'); ?>">
    <div class="arrow-left"></div>
  </div>
  <div class="next-icon" title="<?php print t('View Next Image'); ?>">
    <div class="arrow-right"></div>
  </div>
</div>
