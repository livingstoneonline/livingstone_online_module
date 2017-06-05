<div id="downloads" style="display: none;">
  <a class="close button" title="<?php print t('Close'); ?>">×</a>
  <div class="downloads-content" style="font-size: initial;">
    <h1><?php print $title; ?></h1>
    <hr/>
    <p>
      <?php print t('The large number of spectral images available for this item necessitates
      that we offer archival packets of the item page by page. Select any of the
      archival packets below to download all available spectral images for the
      given page plus supporting documentation.'); ?>
    </p>
    <hr/>
    <div class="downloads-lists">
      <div class="downloads-list">
        <?php if (!empty($downloads['archival'])): ?>
          <h2><?php print t('Archival Packets'); ?></h2>
          <ul>
            <?php foreach ($downloads['archival'] as $download): ?>
              <li>
                <a href="<?php print $download['url']; ?>" title="<?php print t('Download'); ?>">
                  <?php print $download['label']; ?>
                </a>
                <span>(<?php print $download['size']; ?>&nbsp;MB)</span>
              </li>
            <?php endforeach; ?>
          </ul>
        <?php endif; ?>cd
      </div>
      <div class="downloads-list">
        <?php if (!empty($downloads['gif'])): ?>
          <h2><?php print t('GIF Images'); ?></h2>
          <ul>
            <?php foreach ($downloads['gif'] as $download): ?>
              <li>
                <a href="<?php print $download['url']; ?>" title="<?php print t('Download'); ?>">
                  <?php print $download['label']; ?>
                </a>
                <span>(<?php print $download['size']; ?>&nbsp;MB)</span>
              </li>
            <?php endforeach; ?>
          </ul>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
