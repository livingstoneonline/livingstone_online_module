<?php
/**
 * @file
 * Renders the drop downs for the date range.
 */
?>
<table>
  <tbody>
    <tr style="font-size: 0;">
      <td style="text-align: left;"><?php print drupal_render($element['year']); ?></td>
      <td style="text-align: center; width: 1em; font-size: initial;">or</td>
      <td style="text-align: right;"><?php print drupal_render($element['from']); ?></td>
      <td style="text-align: right"><?php print drupal_render($element['to']); ?></td>
    </tr>
  </tbody>
</table>
