#ifndef HARDWARE_H
#define HARDWARE_H
	
	void * servoTurnByAngle(void * p);
	
	extern pthread_cond_t calculateSignal;
	extern pthread_mutex_t mutex;
	
	extern float latitude,longitude,heading;

	struct clientMessage{
		float latitude,longitude,heading;
	};

	struct serverMessage{
		char angleToEngine1,angleToEngine2;
	};
	extern clientMessage message;
	extern serverMessage messageFromServer;

#endif