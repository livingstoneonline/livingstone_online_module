<div id="downloads" style="display: none;">
  <a class="close icon">×</a>
  <div class="downloads-content" style="font-size: initial;">
    <h1><?php print $title; ?></h1>
    <hr/>
    <p>
      The large number of spectral images available for this item necessitates
      that we offer archival packets of the item page by page. Select any of the
      archival packets below to download all available spectral images for the
      given page plus supporting documentation.
    </p>
    <hr/>
    <ul>
      <?php foreach ($downloads as $download): ?>
        <li>
          <a href="<?php print $download['url']; ?>">
            <?php print $download['label']; ?>
          </a>
          <span>(<?php print $download['size']; ?>&nbsp;MB)</span>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</div>
