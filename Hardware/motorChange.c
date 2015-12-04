#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "hardware.h"

#define MICROSECOND_TO_ANGLE 700
#define DEGREE_90 1600
#define TURN_LEFT 2050
#define TURN_RIGHT 1150
/*
		microsecondValue = angle * 10 + MICROSECOND_TO_ANGLE;
*/
pthread_cond_t calculateSignal;
pthread_mutex_t mutex;
serverMessage messageFromServer;
clientMessage message;

void * servoTurnByAngle(void * p){
	int i,j,microsecondValue=0;
	char temp1[50],temp2[50],temp3[50]={"us > //dev//servoblaster "};
	
	while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&calculateSignal,&mutex);
		
		if(messageFromServer.angleToEngine1 == 'r'){
			sprintf(temp1,"echo %d=",0);
			sprintf(temp2,"%d",TURN_RIGHT);
		}
		else if(messageFromServer.angleToEngine1 == 'l'){
			sprintf(temp1,"echo %d=",0);
			sprintf(temp2,"%d",TURN_LEFT);
		}
		else if(messageFromServer.angleToEngine1 == 'f'){
			sprintf(temp1,"echo %d=",0);
			sprintf(temp2,"%d",DEGREE_90);
		}
		if(messageFromServer.angleToEngine2 == 'u'){
			sprintf(temp1,"echo %d=",1);
			sprintf(temp2,"%d",TURN_LEFT);
		}
		else if(messageFromServer.angleToEngine2 == 'd'){
			sprintf(temp1,"echo %d=",1);
			sprintf(temp2,"%d",DEGREE_90);
		}
			
		strcat(temp1,temp2);
		strcat(temp1,temp3);
		system(temp1);
		pthread_mutex_unlock(&mutex);
	}

}
