<?php
/**
 * @file
 * Renders the drop downs for the date range.
 */
?>
<table>
  <tbody>
    <tr>
      <td style="text-align: left;"><?php print drupal_render($element['year']); ?></td>
      <td style="text-align: center;"><?php print drupal_render($element['from']); ?></td>
      <td style="text-align: right"><?php print drupal_render($element['to']); ?></td>
    </tr>
  </tbody>
</table>
