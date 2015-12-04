#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include "hardware.h"
#include "../Server/network.h"
#include "GPS/GPS.h"
#include "compassController/compass.h"


int main(int argc,char **argv){
	int control,i;
	pthread_t threads[4];

	control = pthread_create(&threads[0],NULL,clientCube,NULL); // client connection
	if(control != 0)
		perror("Error at creating thread");
	
	control = pthread_create(&threads[1],NULL,parseGPSData,NULL); // gps parser thread
	if(control != 0)
		perror("Error at creating thread");

	control = pthread_create(&threads[2],NULL,headingAngle,NULL); // heading angle finder
	if(control != 0)
		perror("Error at creating thread");
	
	control = pthread_create(&threads[3],NULL,servoTurnByAngle,NULL); // servo control
	if(control != 0)
		perror("Error at creating thread");

	for (i = 0; i < 3; i++) {
		pthread_join(threads[i], NULL);
  	}
	return 0;
}