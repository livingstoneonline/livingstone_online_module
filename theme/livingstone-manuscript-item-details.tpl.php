<div id="item-details" style="display:none;">
  <div class="viewer-sidebar">
    <h1>Item Details</h1>
    <dl class="inline">
      <?php if (!empty($fields['title'])): ?>
        <dt>Title</dt>
        <dd><?php print $fields['title']; ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['authors'])): ?>
        <dt>Author</dt>
        <dd><?php print $fields['authors']; ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['repository'])): ?>
        <dt>Repository</dt>
        <dd><?php print $fields['repository']; ?></dd>
      <?php endif; ?>
      <?php if (!empty($fields['shelfmark'])): ?>
        <dt>Shelfmark</dt>
        <dd><?php print $fields['shelfmark']; ?></dd>
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
      <dt>Directors</dt>
      <dd>Adrian S. Wisnicki, Christopher Lawrence</dd>
      <dt>Publication Authority</dt>
      <dd>Livingstone Online</dd>
      <dt>Publisher</dt>
      <dd>University Libraries, University of Maryland</dd>
      <dt>Publication Place</dt>
      <dd>7649, Library Lane, College Park, MD 20742, United States</dd>
      <dt>Date</dt>
      <dd><?php echo date("Y"); ?></dd>
      <dt>Transcription</dt>
      <dd>Adrian S. Wisnicki, Christopher Lawrence, Megan Ward, Heather F. Ball, Kate Simpson, Angela Aliff, Ashanka Kumari</dd>
      <dt>Text Credits</dt>
      <dd>
        All materials are licencsed for use under the <a href="https://creativecommons.org/licenses/by-nc/2.0/legalcode">Creative
        Commons Attribution-Noncommercial 2.0 Unported License</a> © Dr. Niel Imray Livingstone Wilson, 2015.
      </dd>
      <dt>Cite Item</dt>
      <dd>
        <?php print $fields['title']?>.
        <?php print $fields['repository']; ?>,
        <?php print $fields['shelfmark']?>.
        <i>Livingstone Online,</i> University Libraries, University of Maryland, MD, USA.
        [accessed <?php print $fields['accessed_date']?>].
      </dd>
    </dl>
  </div>
</div>
