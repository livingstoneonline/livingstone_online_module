// requires jquery, leaflet, leaflet.markercluster


function main(){
    // instantiate the map on document ready
        jQuery(document).ready(function () {

        var mymap = map("map");

    });
}



function map(mapid) {
    // template for creating marker popup html. It would be better to use some javascript templating system
    var popup_template = function(attributes) {
        var html = '<div class="gmap-popup">';
        // add place created content
        if (attributes.hasOwnProperty('place')) {
            html += '<div class="views-field views-field-field-manuscript-places-created"><div class="field-content">';
            html += attributes.place;
            html += '</div></div>';
        }
        // add title and link content
        if (attributes.hasOwnProperty('title')) {
            html += '<div class="views-field views-field-title"><span class="field-content">Title:&nbsp;<a href="';
            html += '/in-his-own-words/catalogue?query=%22' + attributes.pid + '%22&view_pid=' + attributes.pid;
            html += '" target="_blank">' + attributes.title + '</a></span></div>';
        }
        // add creator content
        if (attributes.hasOwnProperty('creator')) {
            html += '<div class="views-field views-field-field-manuscript-creators">';
            html += '<span class="views-label views-label-field-manuscript-creators">Creator(s): </span>';
            html += '<span class="field-content">' + attributes.creator.join('; <br/>') + '</span></div>';
        }
        // add date content
        if (attributes.hasOwnProperty('date')) {
            html += '<div class="views-field views-field-field-manuscript-dates">';
            html += '<span class="views-label views-label-field-manuscript-dates">Date(s): </span>';
            html += '<span class="field-content">' + attributes.date.join('; <br/>') + '</span></div>';
        }
        html += '<div class="views-field views-field-edit-node"><span class="field-content"></span></div></div>';
        return html;
    };

    function setMapHeight() {
      var height = window.innerHeight;
      // Subtract 2 for the borders.
      jQuery('#' + mapid).height(Math.min(height - 2, 550));
    }

    // Leaflet needs a defined height for its container
    setMapHeight();

    // instantiate Leaflet map
    var mymap = L.map(mapid, {zoomDelta: 0.5, zoomSnap: 0.5});


    // create the tile layer with correct attribution
    var CartoDB_Voyager = L.tileLayer('https://cartodb-basemaps-{s}.global.ssl.fastly.net/rastertiles/voyager/{z}/{x}/{y}{r}.png', {
        attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a> &copy; <a href="http://cartodb.com/attributions">CartoDB</a>',
        subdomains: 'abcd',
        maxZoom: 19
    });

    // center and set zoom
    mymap.setView([0, 0], 2);

    // add basemap
    mymap.addLayer(CartoDB_Voyager);

    // handler to resize map on page resize
    jQuery( window ).resize(function() {
        setMapHeight();
        mymap.invalidateSize();
    });

    // all of the markers have been loaded into the global variable global_markers from the markers.js file.
    function getMarkers(){
        var markers = [];

        global_markers.forEach(function(item, index){
            try {
                // create a Leaflet marker for each object
                var coords = L.latLng(item.coordinates[0].split(",")[0], item.coordinates[0].split(",")[1]);
                var mark = L.marker(coords);
                // bind a popup to each marker
                mark.bindPopup(popup_template(item));
                markers.push(mark);
            }
            catch {
                console.log("Failed to plot item:");
                console.log(item);
            }
        });

        return markers;
    }
    // create the cluster group (see https://github.com/Leaflet/Leaflet.markercluster)
    var markers = L.markerClusterGroup();
    markers.addLayers(getMarkers());
    mymap.addLayer(markers);

    // zoom to data bounds
    mymap.fitBounds(markers.getBounds());


    // export these functions
    return {'map': mymap };
}



main();
