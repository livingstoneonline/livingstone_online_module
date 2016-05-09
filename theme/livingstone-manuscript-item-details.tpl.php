<div id="item-details" style="display:none;">
  <div class="viewer-sidebar">
    <h1>Item Details</h1>
    <dl class="inline">
      <dt>Title</dt>
      <dd><?php print $fields['title']; ?></dd>
      <dt>Author</dt>
      <dd><?php print $fields['authors']; ?></dd>
      <dt>Repository</dt>
      <dd><?php print $fields['repository']; ?></dd>
      <dt>Shelfmark</dt>
      <dd><?php print $fields['shelfmark']; ?></dd>
      <dt>Image Credits</dt>
      <dd><?php print $fields['image_credits']; ?></dd>
    </dl>
    <h2>Publication</h2>
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
      <dd>2016</dd>
    </dl>
    <h2>Digital Edition</h2>
    <dl class="inline">
      <dt>Transcription</dt>
      <dd>Adrian S. Wisnicki, Christopher Lawrence, Megan Ward, Heather F. Ball, Kate Simpson, Angela Aliff, Ashanka Kumari</dd>
      <dt>Text Credits</dt>
      <dd>
        <p>All materials are licencsed for use under the <a href="https://creativecommons.org/licenses/by-nc/2.0/legalcode">Creative
          Commons Attribution-Noncommercial 2.0 Unported License</a> &copy;Dr. Niel Imray Livingstone Wilson, 2015.<p>
      </dd>
      <dt>Cite Item</dt>
      <dd>
        <p><?php print $fields['title']?>. <?php print $fields['repository']; ?>, <?php print $fields['shelfmark']?>.
          <i>Livingstone Online,</i> University Libraries, University of Maryland, MD, USA. [accessed <?php print $fields['accessed_date']?>].
        </p>
      </dd>
    </dl>
  </div>
</div>
