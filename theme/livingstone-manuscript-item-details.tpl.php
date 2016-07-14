<div id="item-details" style="display:none;">
  <div class="item-details-content" style="font-size: initial;">
    <h1>Item Details</h1>
    <hr/>
    <dl>
      <?php if (!empty($fields['title'])): ?>
        <dt>Title</dt>
        <dd><?php print implode(' ', $fields['title']); ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['date'])): ?>
        <dt>Date</dt>
        <dd><?php print implode(' ', $fields['date']); ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['authors'])): ?>
        <dt>Creator(s)</dt>
        <dd><?php print implode('; ', $fields['authors']); ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['repository'])): ?>
        <dt>Repository</dt>
        <dd><?php print implode(' ', $fields['repository']); ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['shelfmark'])): ?>
        <dt>Shelfmark</dt>
        <dd><?php print implode(' ', $fields['shelfmark']); ?></dd>
      <?php endif; ?>
        <dt>Image Credits</dt>
        <dd><?php print implode(' ', $fields['credits']); ?></dd>
    </dl>
    <h1>Digital Edition</h1>
    <hr/>
    <dl>
      <dt>Publisher</dt>
      <dd>Livingstone Online</dd>
      <dt>Directors</dt>
      <dd>Adrian S. Wisnicki (director), Christopher Lawrence (director emeritus), Megan Ward (associate director), Anne Martin (associate director)</dd>
      <dt>Project Host</dt>
      <dd>University of Maryland Libraries</dd>
      <dt>Date</dt>
      <dd><?php echo date("Y"); ?></dd>
      <?php if (!empty($transcript_team)): ?>
        <dt>Transcription Team</dt>
        <dd><?php print implode(', ', $fields['transcription_team']); ?>.</dd>
      <?php endif; ?>
      <?php if (!empty($fields['download'])): ?>
        <dt class="download">Download item</dt>
        <dd class="download"><?php print $fields['download']; ?></dd>
      <?php endif; ?>
      <dt>Cite Item (MLA)</dt>
      <dd>
        <?php if (!empty($fields['authors'])): ?>
          <?php print implode('; ', $fields['authors']); ?>.
        <?php endif; ?>
        "<?php print implode('', $fields['title-alt']); ?>."
        <i>Livingstone Online</i>. Adrian S. Wisnicki, Christopher Lawrence, Megan Ward, and Anne Martin, dirs.
        University of Maryland Libraries, 2016. Web.
        <?php print $fields['accessed_date']?>.
      </dd>
    </dl>
  </div>
</div>
