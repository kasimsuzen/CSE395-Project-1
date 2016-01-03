//
//  gpsDataParser.cpp
//
//  Created by Ali Kürşat Şahin on 29.11.2015.
//  Copyright © 2015 Ali Kürşat Şahin. All rights reserved.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "GPS.h"
#include "../hardware.h"
#include <unistd.h>

using namespace std;

vector<string> split(string str, char delimiter) {

	vector<string> internal;

	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

void parseGPGGA(string arg1, float* latitude, float* longitude) {

	vector<string> sep = split(arg1, ',');

	// 2- Latitude 4- Longitude 6- gps quality indicator (0-invalid, 1-fix, 2-diff fix)
	if (sep.size() >= 14) {
		if (0 <= strstr(sep[0].c_str(), "GPGGA")) {

			if (sep[6]== "2" || sep[6] == "1") {

				*latitude = (int)(atof(sep[2].c_str()))/100 + strtod(&sep[2].c_str()[2],NULL)/60.0;
				*longitude = (int)(atof(sep[4].c_str()))/100 + strtod(&sep[4].c_str()[3],NULL)/60.0;
			}
		}
	}

}

int parseGPSData(float * latitude,float* longitude,int limit/*=1*/) {
	char buffer[4096], *bufferptr;
	float tempLat=*latitude,tempLong=*longitude;
	int count=limit;
	string line = "$GPGGA,092750.000,5321.6802,N,00630.3372,W,2,8,1.03,61.7,M,55.2,M,,*76";
	while(count > 0){
		
		memset(buffer,'\0',4095);
		readGPSData(buffer);
		//cout << buffer << endl;// << tempLat << tempLong << endl;
		bufferptr = strtok(buffer,"\n");
		while(bufferptr != NULL)
		{
			parseGPGGA(bufferptr,latitude,longitude);
			bufferptr = strtok(NULL,"\n");
		}
		if(tempLat != *latitude || *longitude != tempLong)
			break;
		if(limit != 1)
			--count;
		usleep(50000);
	}
	//cout << longitude << latitude << endl;
}
/*
int main(){
	float lat,lo;
	parseGPSData(&lat,&lo,60);
}*/