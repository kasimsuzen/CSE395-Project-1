#ifndef HARDWARE_H
#define HARDWARE_H
	void servoController(int destinationAngle,int isFinished);
	double headingAngle();
	int parseGPSData();
	extern float latitude,longitude,heading;

#endif