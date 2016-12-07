#pragma once
namespace ltd_mapview{

class LTD{

};

class Coordinate{
public:
    double latitude;
    double longitude;
    double altitude;
    Coordinate(double lat, double lon, double altitude = 0){
        latitude = lat;
        longitude =lon;
        this->altitude = altitude;
    }
};

typedef struct {
    Coordinate coord;
    double heading;
    double gpsTime;
    double horizontalVelocity;
    double verticalVelocity;
    double horizontalUncertainty;
    double verticalUncertainty;
}GPSFix;

}
