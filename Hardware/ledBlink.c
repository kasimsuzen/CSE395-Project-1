#include <WiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIN_1 23
#define PIN_2 24
#define PIN_3 25


int ledErrorOutput(int errorCode){
	
	if(WiringPiSetup() == -1)
		return -1;
	
	pinMode(PIN_1, OUTPUT);
	pinMode(PIN_2, OUTPUT);
	pinMode(PIN_3, OUTPUT);
	
	if(errorCode == 1){
		digitalWrite(PIN_1, 0);
	}
	else if(errorCode == 2){
		digitalWrite(PIN_2, 0);
	}
	else if(errorCode == 3){
		digitalWrite(PIN_3, 0);
	}
	else if(errorCode == -1){
		digitalWrite(PIN_1, 1);
		digitalWrite(PIN_2, 1);
		digitalWrite(PIN_3, 1);
	}
	
	return 0;
}