package org.geobuild.osm;
import hu.supercluster.overpasser.library.output.OutputModificator;
import hu.supercluster.overpasser.library.output.OutputOrder;
import hu.supercluster.overpasser.library.output.OutputVerbosity;
import hu.supercluster.overpasser.library.query.OverpassQuery;
import org.geobuild.osm.MapFeatures.Coordinates;
import org.json.simple.*;
import org.json.simple.parser.JSONParser;

import static hu.supercluster.overpasser.library.output.OutputFormat.JSON;
import static org.geobuild.osm.OverpassRequest.*;

public class Main {

    public static void main(String[] args) {
        Coordinates coordinates = new Coordinates(36.954953, -122.078479, 37.003569, -122.003725);
        String query = new OverpassQuery()
                .format(JSON)
                .timeout(30)
                .filterQuery()
                .way()
                .tagRegex("highway", "motorway|trunk|primary|secondary|tertiary|unclassified|residential|living_street|service|road")
                .boundingBox(
                        coordinates
                )
                .end()
                .output(OutputVerbosity.BODY, OutputModificator.GEOM, OutputOrder.ASC, Integer.MAX_VALUE)
                .build();
        System.out.println(query);
        String output = makeRequest(query);
        JSONParser parser = new JSONParser();
        JSONObject json;
        try {
            json = (JSONObject) parser.parse(output);
        } catch (Exception e) {
            System.out.println(output);
            return;
        }
        System.out.println(json);
        new GeoJson(json).saveToFile(query, true);
    }
}