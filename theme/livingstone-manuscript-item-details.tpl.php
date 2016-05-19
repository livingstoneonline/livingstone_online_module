<div id="item-details" style="display:none;">
  <div class="viewer-sidebar">
    <h1>Item Details</h1>
    <dl class="inline">
      <?php if (!empty($fields['title'])): ?>
        <dt>Title</dt>
        <dd><?php print implode(' ', $fields['title']); ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['authors'])): ?>
        <dt>Authors</dt>
        <dd><?php print implode(', ', $fields['authors']); ?></dd>
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
        <dd>
          Images © National Library of Scotland.
          <a href="https://creativecommons.org/licenses/by-nc-sa/2.5/scotland/" target="_blank">Creative Commons Share-alike 2.5 UK: Scotland</a>.
          As relevant, © Dr. Neil Imray Livingstone Wilson.
          <a href="https://creativecommons.org/licenses/by-nc/3.0/" target="_blank">Creative Commons Attribution-NonCommercial 3.0 Unported</a>.
        </dd>
    </dl>
    <h2>Digital Edition</h2>
    <dl class="inline">
      <dt>Publisher</dt>
      <dd>Livingstone Online</dd>
      <dt>Directors</dt>
      <dd>Adrian S. Wisnicki, Christopher Lawrence (emeritus), Megan Ward, Anne Martin</dd>
      <dt>Project Host</dt>
      <dd>University of Maryland Libraries</dd>
      <dt>Date</dt>
      <dd><?php echo date("Y"); ?></dd>
      <?php if (!empty($transcript_team)): ?>
        <dt>Transcription Team</dt>
        <dd><?php print implode(', ', $fields['transcription_team']); ?>.</dd>
      <?php endif; ?>
      <dt>Cite Item (MLA)</dt>
      <dd>
        <?php print implode('; ', $fields['authors']); ?>.
        "<?php print implode('', $fields['title-alt']); ?>".
        Livingstone Online. Adrian S. Wisnicki, Christopher Lawrence, Megan Ward, and Anne Martin, dirs.
        University of Maryland Libraries, 2016. Web.
        <?php print $fields['accessed_date']?>
      </dd>
    </dl>
  </div>
</div>
