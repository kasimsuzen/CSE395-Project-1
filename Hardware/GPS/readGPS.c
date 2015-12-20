#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rs232.h"

void readGPSData(char * buffer){
	int i, n=0,
      cport_nr=22,        // /dev/ttyAMA0
      bdrate=9600;       // 9600 baud

  unsigned char buf[4096];

  char mode[]={'8','N','1',0};


  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");

    exit(-1);
  }

  while(n < 90)
  {
    n = RS232_PollComport(cport_nr, buf, 4095);

    if(n > 0)
    {
      buf[n] = 0;   /* always put a "null" at the end of a string! */

      /*for(i=0; i < n; i++)
      {
        if(buf[i] < 32)  // replace unreadable control-codes by dots
        {
          buf[i] = '.';
        }
      }*/

    }
    usleep(1000000);  /* sleep for 100 milliSeconds */
}
    
    
	for(i=0; buf[i] != '\0';++i)
		buffer[i] = buf[i];
	buffer[n]='\n';
	buffer[n+1]='\0';
	RS232_CloseComport(cport_nr);
}