package org.geobuild.MapFeatures;

import org.json.simple.JSONObject;

public class Point {
    private double latitude;
    private double longitude;

    public Point(double latitude, double longitude) {
        this.latitude = latitude;
        this.longitude = longitude;
    }

    @SuppressWarnings("unchecked")
    public Point(JSONObject json) {
        this.latitude = (double) json.getOrDefault("lat", 0);
        this.longitude = (double) json.getOrDefault("lon", 0);
    }

    public double getLatitude() { return this.latitude; }
    public double getLongitude() { return this.longitude; }
    public void setLatitude(double lat) { this.latitude = lat; }
    public void setLongitude(double lon) { this.longitude = lon; }
}
