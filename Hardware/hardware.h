#include <vector>
#include <string>
#ifndef HARDWARE_H
#define HARDWARE_H
#define INTERNET_ACCESS_ERROR 1
#define RESPOND_ERROR 2
	void servoController(int destinationAngle,int isFinished);
	double headingAngle();
	int parseGPSData(float * latitude,float* longitude,int limit=1);
	int findLocal();
	std::vector<std::string> split(std::string str, char delimiter) ;
	int ledErrorOutput(int errorCode);
#endif