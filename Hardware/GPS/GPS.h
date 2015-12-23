#include <vector>
#include <string>
#include <cstring>

using namespace std;

#ifndef GPS_H
#define GPS_H

vector<string> split(string str, char delimiter);
void parseGPGGA(string arg1, float* latitude, float* longitude);
void readGPSData(char * buf);

#endif