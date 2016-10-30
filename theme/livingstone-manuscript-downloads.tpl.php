<div id="downloads" style="display: none;">
  <a class="close icon">×</a>
  <div class="downloads-content" style="font-size: initial;">
    <h1><?php print $title; ?></h1>
    <hr/>
    <p>
      The large number of spectral images available for this item necessitates
      that we offer archival packets of the item page by page. Select any of the
      pages below to download all available spectral images for that page plus
      supporting documentation.
    </p>
    <hr/>
    <h2>Archival packets for download</h2>
    <ul>
      <?php foreach ($downloads as $download): ?>
        <li>
          <a href="<?php print $download['url']; ?>">
            <?php print $download['label']; ?>
          </a>
          <span>(<?php print $download['size']; ?> MB)</span>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</div>
