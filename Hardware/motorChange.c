#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MICROSECOND_TO_ANGLE 700
/*
*/
int servoTurnByAngle(int motorNumber,int angle){
	int i,j,microsecondValue=0;
	char temp1[50],temp2[50],temp3[50]={"us > //dev//servoblaster "};
	
	sprintf(temp1,"echo %d=",motorNumber);

	microsecondValue = angle * 10 + MICROSECOND_TO_ANGLE;

	sprintf(temp2,"%d",microsecondValue);
	strcat(temp1,temp2);
	strcat(temp1,temp3);
	system(temp1);

return 0;
}
