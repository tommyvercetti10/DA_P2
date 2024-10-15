#include <cmath>
#include <iostream>
#include "Coordinates.h"

Coordinates::Coordinates() = default;

Coordinates::Coordinates(const double& latitude, const double& longitude) : latitude(latitude), longitude(longitude) {}

double Coordinates::getLongitude() const {
    return longitude;
}

double Coordinates::getLatitude() const {
    return latitude;
}

void Coordinates::setLongitude(const double& val) {
    this->longitude = val;
}

void Coordinates::setLatitude(const double& val) {
    this->latitude = val;
}

double Coordinates::toRadians(const double& degree) {
    return degree * (M_PI / 180.0);
}

double Coordinates::getDistance(Coordinates& other) const {
    double dlat = other.latitude - latitude;
    double dlon = other.longitude - longitude;
    double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(latitude) * cos(other.latitude) * sin(dlon / 2.0) * sin(dlon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    return 6371.0 * c;
}