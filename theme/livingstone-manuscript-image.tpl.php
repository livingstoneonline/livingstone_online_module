<div id="<?php print $identifier; ?>" unselectable="on" onselectstart="return false;">
  <?php if ($spectral): ?>
    <div class="spectral-image-toolbar">
      <span>
        <select class="spectral-image">
          <?php $page = reset($pages); ?>
          <?php foreach ($page['dsid'] as $dsid): ?>
            <option value="<?php print $dsid; ?>"><?php print substr($dsid, 0, strlen($dsid)-4); ?></option>
          <?php endforeach; ?>
        </select>
      </span>
      <span class="page-download">
        <?php
        $page = reset($pages);
        $size = isset($page['size']) ?
          number_format($page['size'] / 1024 / 1024, 2) :
          FALSE;
        $url = url("islandora/object/{$page->pid}/datastreams/ZIP/download");
        ?>
        <?php if ($size != FALSE): ?>
          <a href="<?php print $url ?>">Download archival packet (<?php print $size; ?> MB)</a>
        <?php endif; ?>
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
