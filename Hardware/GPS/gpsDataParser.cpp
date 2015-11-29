//
//  main.cpp
//  gpsParser
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

			if (sep[6]== "2") {

				*latitude = atof(sep[2].c_str());

				*longitude = atof(sep[4].c_str());
			}
		}
	}

}

int main(int argc, char **argv) {

	float latitude = 0, longitude = 0;
	string line = "$GPGGA,092750.000,5321.6802,N,00630.3372,W,2,8,1.03,61.7,M,55.2,M,,*76";

	ifstream myfile("gps.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			parseGPGGA(line, &latitude, &longitude);
		}

		myfile.close();

	}
	cout << "latitude = " << latitude << endl << "longitude = " << longitude;

}