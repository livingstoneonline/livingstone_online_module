<div id="<?php print $identifier; ?>" unselectable="on" onselectstart="return false;">
  <?php if ($is_spectral): ?>
    <div class="image-toolbar">
      <select class="spectral-image icon button select">
          <?php $page = reset($pages); ?>
          <?php foreach ($page['dsid'] as $dsid): ?>
            <option value="<?php print $dsid; ?>"><?php print substr($dsid, 0, strlen($dsid)-4); ?></option>
          <?php endforeach; ?>
      </select>
      <?php print $processing_details; ?>
      <span class="download">
        <?php print $download; ?>
      </span>
    </div>
  <?php endif; ?>
  <div class="prev-icon">
    <div class="arrow-left"></div>
  </div>
  <div class="next-icon">
    <div class="arrow-right"></div>
  </div>
</div>
