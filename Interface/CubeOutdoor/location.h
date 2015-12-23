#ifndef LOCATIONBUTTON_H
#define LOCATIONBUTTON_H

#include <QPushButton>

class Location
{
public:
    Location():latitude(0.0),longitude(0.0){ /* intentionally blank */}
    Location(double latitude, double longitude){this->latitude=latitude;this->longitude=longitude;}
    double getLongitude(){return longitude;}
    double getLatitude(){return latitude;}
    void setLocation(double latitude, double longitude){this->latitude=latitude;this->longitude=longitude;}
private:
    double latitude;  //  40°48'21.13"N => 40.482113
    double longitude; //  29°21'32.27"E => 29.213227
};

#endif // LOCATIONBUTTON_H
