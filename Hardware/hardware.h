#ifndef HARDWARE_H
#define HARDWARE_H
	boost::mutex mainMutex;
	void servoController(int destinationAngle,int isFinished);

	extern float latitude,longitude,heading;

#endif