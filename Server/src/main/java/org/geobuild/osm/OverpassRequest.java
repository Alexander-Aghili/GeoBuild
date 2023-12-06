package org.geobuild.osm;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;

public class OverpassRequest {
    public static final String OVERPASS_API = "https://overpass-api.de/api/interpreter";

    public static String makeRequest(String query) {
        try {
            String queryParameters = "data=" + URLEncoder.encode(query, StandardCharsets.UTF_8) + "\n";
            HttpURLConnection connection = getHttpURLConnection(queryParameters);
            return getResponse(connection);
        } catch (Exception e) {
            return e.getMessage();
        }
    }
    private static HttpURLConnection getHttpURLConnection(String queryParameters) throws Exception {
        byte[] postData = queryParameters.getBytes(StandardCharsets.UTF_8);
        URL url = new URL(OVERPASS_API);

        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("POST");
        connection.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
        connection.setRequestProperty("charset", "UTF-8");
        connection.setRequestProperty("Content-Length", Integer.toString(postData.length));
        connection.setDoOutput(true);
        try(DataOutputStream wr = new DataOutputStream(connection.getOutputStream())) {
            wr.write( postData );
        }

        if (connection.getResponseCode() != HttpURLConnection.HTTP_OK) {
            throw new Exception();
        }
        return connection;
    }

    private static String getResponse(HttpURLConnection connection) throws IOException {
        String data = "";
        try (BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()))) {
            String inputLine;
            StringBuilder response = new StringBuilder();

            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
            }

            data = response.toString();
        }
        return data;
    }
}
