<?php
/**
 * @file
 * Returns the a full HTML document.
 *
 * It's meant only for use within an iFrame. This is meant to be used as a
 * #theme_wrapper for #theme page, it replaces html.tpl.php.
 *
 * Complete documentation of the variables this inherits from html.tpl.php
 * is available online.
 * @see https://drupal.org/node/1728208
 */
?>
<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-type" content="text/html;charset=UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=Edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">

    <script src="https://code.jquery.com/jquery-3.3.1.min.js"
        integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="
        crossorigin="anonymous"></script>

    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/8.0.0/normalize.min.css" />

    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.3.2/dist/leaflet.css"
          integrity="sha512-Rksm5RenBEKSKFjgI3a41vrjkw4EVPlJ3+OiI65vTjIdo9brlAacEuKOiQ5OFh7cOI1bkDwLqdLw3Zg0cRJAAQ=="
          crossorigin=""/>

    <link rel="stylesheet" href="https://unpkg.com/leaflet.markercluster@1.3.0/dist/MarkerCluster.css"/>
    <link rel="stylesheet" href="https://unpkg.com/leaflet.markercluster@1.3.0/dist/MarkerCluster.Default.css"/>

    <link rel="stylesheet" href="/sites/all/modules/custom/livingstone_online_module/css/map.css"/>

    <script src="https://unpkg.com/leaflet@1.3.2/dist/leaflet.js"
            integrity="sha512-2fA79E27MOeBgLjmBrtAgM/20clVSV8vJERaW/EcnnWCVGwQRazzKtQS1kIusCZv1PtaQxosDZZ0F1Oastl55w=="
            crossorigin=""></script>

    <script src="https://unpkg.com/leaflet.markercluster@1.3.0/dist/leaflet.markercluster.js"></script>

  </head>
  <body>
      <main>
          <div id="map"></div>
      </main>
      <script src="/sites/default/files/markers.js"></script>
      <script src="/sites/all/modules/custom/livingstone_online_module/js/map.js"></script>
  </body>
</html>
