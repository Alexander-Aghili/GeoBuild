#include <Point.h>

Point::Point(uint32_t r, uint32_t alpha, uint32_t omega){
    spdlog::info("Creating Point from spherical input");

    _x = r*cos(omega)*sin(alpha);
    _y = r*cos(omega)*cos(alpha);
    _z = r*sin(omega);
}

Point::Point(uint32_t x, uint32_t y, uint32_t z) {
    spdlog::info("Creating point from cartesian input");

    _x = x;
    _y = y;
    _z = z;
}

Point::~Point() {}