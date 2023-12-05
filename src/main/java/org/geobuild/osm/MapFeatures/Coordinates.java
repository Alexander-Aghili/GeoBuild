package org.geobuild.osm.MapFeatures;

public class Coordinates {
    private double southernLat;
    private double northernLat;
    private double westernLong;
    private double easternLong;

    public Coordinates(double southernLat, double westernLong, double northernLat,  double easternLong) {
        this.southernLat = southernLat;
        this.northernLat = northernLat;
        this.westernLong = westernLong;
        this.easternLong = easternLong;
    }

    public Coordinates(Point southwest, Point northEast) {
        this.southernLat = southwest.getLatitude();
        this.westernLong = southwest.getLongitude();
        this.northernLat = northEast.getLatitude();
        this.easternLong = northEast.getLongitude();
    }

    public double getSouthernLat() {
        return southernLat;
    }

    public void setSouthernLat(double southernLat) {
        this.southernLat = southernLat;
    }

    public double getNorthernLat() {
        return northernLat;
    }

    public void setNorthernLat(double northernLat) {
        this.northernLat = northernLat;
    }

    public double getWesternLong() {
        return westernLong;
    }

    public void setWesternLong(double westernLong) {
        this.westernLong = westernLong;
    }

    public double getEasternLong() {
        return easternLong;
    }

    public void setEasternLong(double easternLong) {
        this.easternLong = easternLong;
    }



}
