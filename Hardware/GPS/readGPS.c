#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rs232.h"

void readGPSData(unsigned char * buf){
	int i, n,cport_nr=22,bdrate=9600; // 22 stands for /dev/ttyAMA0 for linux systems

	char mode[]={'8','N','1',0};

	if(RS232_OpenComport(cport_nr, bdrate, mode))
	{
		printf("Can not open comport\n");
		exit(-1);
	}

	n = RS232_PollComport(cport_nr, buf, 4095);

	if(n > 0)
	{
		buf[n] = 0;   /* always put a "null" at the end of a string! */

		for(i=0; i < n; i++)
		{
			if(buf[i] < 32)  /* replace unreadable control-codes by dots */
			{
			buf[i] = '.';
			}
		}

		printf("%s\n", (char *)buf);
	}
}

