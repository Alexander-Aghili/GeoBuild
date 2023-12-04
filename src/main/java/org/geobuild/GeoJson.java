package org.geobuild;

import org.json.simple.JSONObject;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class GeoJson {
    JSONObject json;

    /**
     * Constructs a GeoJson object with the provided JSON content.
     *
     * @param json The JSON content representing geographic data.
     */
    public GeoJson(JSONObject json) {
        this.json = json;
    }

    /**
     * Saves the JSON content to a file with the specified filename.
     * If the file already exists, it will be overwritten.
     *
     * @param filename The name of the file to which the JSON content will be saved.
     * @throws IOException If an I/O error occurs while writing to the file.
     */
    public void saveToFile(String filename) {
        this.saveToFile(filename, false);
    }

    /**
     * Saves the JSON content to a file with the specified filename.
     *
     * @param filename The name of the file to which the JSON content will be saved.
     * @param temp     A boolean indicating whether to save the file to a temporary location.
     *                If true, the file will be saved to "/tmp/GeoBuild/" directory; otherwise, it will be saved to the current location.
     * @throws IOException If an I/O error occurs while writing to the file.
     */
    public void saveToFile(String filename, boolean temp) {
        try {
            // Determine the file path based on the temp parameter
            String filePath = temp ? "/tmp/GeoBuild/" + filename : filename;

            // Create necessary directories if saving to a temp location
            if (temp) {
                new File("/tmp/GeoBuild/").mkdirs();
            }

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
                // Write the JSON content to the file
                writer.write(json.toString());
            }
        } catch (IOException e) {
            e.printStackTrace(); // Handle the exception appropriately (e.g., log it or throw a custom exception)
        }
    }

}
