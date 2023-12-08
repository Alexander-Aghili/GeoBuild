#pragma once

#include <math.h>
#include <cstdint>

#include <spdlog/spdlog.h>

class Point {
private:
    uint32_t _x;
    uint32_t _y;
    uint32_t _z;

public:
    /**
     * Constructs a Point object using cartesian coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param z The z-coordinate.
     */
    Point(uint32_t x, uint32_t y, uint32_t z);
    
    /**
     * Constructs a Point object using spherical coordinates.
     *
     * @param r The radial distance from the origin.
     * @param alpha The azimuthal angle in radians.
     * @param omega The polar angle in radians.
     */
    Point(uint32_t r, uint32_t alpha, uint32_t omega);
    
    
    ~Point();


};

class TimePoint {
private:
    Point point;
    uint32_t microsecond; //Value since top of hour ranging from 0 - (3x10^{9} - 1)

public:

};