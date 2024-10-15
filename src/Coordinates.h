#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates {
    private:
        double longitude{};
        double latitude{};
    public:
        Coordinates();
        Coordinates(const double& latitude, const double& longitude);
        double getLongitude() const;
        double getLatitude() const;
        void setLongitude(const double& val);
        void setLatitude(const double& val);
        static double toRadians(const double& degree);
        double getDistance(Coordinates& other) const;
};


#endif
