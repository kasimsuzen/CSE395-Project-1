#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hardware.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>

extern boost::mutex mainMutex;

using namespace std;

#define MICROSECOND_TO_ANGLE 700
#define RL_CENTER 1600
#define TURN_LEFT 2400
#define TURN_RIGHT 1000

/*
	microsecondValue = angle * 10 + MICROSECOND_TO_ANGLE;
*/
void servoTurnUp(char command);
int servoTurnRL(int destinationAngle,int currentAngle);

void servoController(int destinationAngle,int isFinished){
	if(isFinished == 1){
		servoTurnUp('c');
		servoTurnRL(1,1);
	}
	else{
		servoTurnUp('f');
		while(1 != servoTurnRL(destinationAngle,headingAngle())); // Warning one line loop
	}
}

int servoTurnRL(int destinationAngle,int currentAngle){
	int n,k;
	char temp1[50]="echo 0=",temp2[50],temp3[50]={"us > //dev//servoblaster "};
	n = currentAngle - destinationAngle;
	k = 360 - abs(n);
	cout << "SERVO" << destinationAngle << " " << n << " " << k<< endl;
	if( abs(n) <= 15 || k <= 15){
		sprintf(temp2,"%d",RL_CENTER);
		strcat(temp1,temp2);
		strcat(temp1,temp3);
		system(temp1);
		return 1;
	}
	else if((n < k && n > 0) || (k < n &&  n < 0) ){
		sprintf(temp2,"%d",TURN_RIGHT);
	}
	else if((n < k && n < 0) && (k < n && n > 0)){
		sprintf(temp2,"%d",TURN_LEFT);
		
	}		
	strcat(temp1,temp2);
	strcat(temp1,temp3);
	system(temp1);
	return 0;
}

void servoTurnUp(char command){
	char temp1[50]="echo 1=",temp2[50],temp3[50]={"us > //dev//servoblaster "};
	
	if(command == 'c'){
		sprintf(temp2,"%d",TURN_RIGHT);
	}
	else if(command == 'f'){
		sprintf(temp2,"%d",TURN_LEFT);
	}

	strcat(temp1,temp2);
	strcat(temp1,temp3);
	system(temp1);
}