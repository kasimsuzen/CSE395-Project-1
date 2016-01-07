#ifndef LOCATIONBUTTON_H
#define LOCATIONBUTTON_H

#include <QPushButton>

class Location
{
public:
    Location():latitude(0.0),longitude(0.0){ /* intentionally blank */}
    Location(double latitude, double longitude){this->latitude=latitude;this->longitude=longitude;}
    const char* getLongitude(){
        sprintf(sLongitude,"%lf",longitude);
        return sLongitude;
    }
    const char* getLatitude(){
        sprintf(sLatitude,"%lf",latitude);
        return sLatitude;
    }
    void setLocation(double latitude, double longitude){this->latitude=latitude;this->longitude=longitude;}
public:
    double latitude;  //  40°48'21.13"N => 40.482113
    double longitude; //  29°21'32.27"E => 29.213227
    char sLatitude[50];
    char sLongitude[50];
};

#endif // LOCATIONBUTTON_H
