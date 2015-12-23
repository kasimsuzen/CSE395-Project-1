#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hardware.h"
#include <boost/thread.hpp>

using namespace std;

#define MICROSECOND_TO_ANGLE 700
#define RL_CENTER 1600
#define TURN_LEFT 2000
#define TURN_RIGHT 1200

/*
	microsecondValue = angle * 10 + MICROSECOND_TO_ANGLE;
*/


void servoController(int destinationAngle,int isFinished){
	if(isFinished == 1){
		servoTurnUp('c');
	}
	else{
		servoTurnUp('c');
		while(1 != servoTurnRL()); // Warning one line loop
		servoTurnUp('f');
	}
}

int servoTurnRL(int destinationAngle,int currentAngle){
	int i,j,microsecondValue=0,n,k;
	char temp1[50],temp2[50],temp3[50]={"us > //dev//servoblaster "};
	n = currentAngle - destinationAngle;
	k = 360 - abs(n);
	if( abs(n) <= 15 && k <= 15){
		sprintf(temp1,"echo %d=",0);
		sprintf(temp2,"%d",RL_CENTER);
		return 1;
	}
	else if((n < k && n > 0) || (k < n &&  n < 0) ){
		sprintf(temp1,"echo %d=",0);
		sprintf(temp2,"%d",TURN_RIGHT);
	}
	else if((n < k && n < 0) && (k < n && n > 0)){
		sprintf(temp1,"echo %d=",0);
		sprintf(temp2,"%d",TURN_LEFT);
		
	}		
	strcat(temp1,temp2);
	strcat(temp1,temp3);
	system(temp1);
	return 0;
}

void servoTurnUp(char command){
	int i,j,microsecondValue=0;
	char temp1[50],temp2[50],temp3[50]={"us > //dev//servoblaster "};
	
	if(messageFromServer.angleToEngine1 == 'c'){
		sprintf(temp1,"echo %d=",0);
		sprintf(temp2,"%d",TURN_RIGHT);
	}
	else if(messageFromServer.angleToEngine2 == 'f'){
		sprintf(temp1,"echo %d=",1);
		sprintf(temp2,"%d",TURN_LEFT);
	}

	strcat(temp1,temp2);
	strcat(temp1,temp3);
	system(temp1);
}