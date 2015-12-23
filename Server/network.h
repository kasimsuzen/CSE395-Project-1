#ifndef NETWORK_H
#define NETWORK_H

#define MAX_MSG 100
#define MAX_LINE 100
#define LINE_ARRAY_SIZE (MAX_MSG+1)
#define SERVER_IP "46.101.238.174"
#define THREAD_NUMBER 2
#define DEVICE_NAME "Device"
#define INTERFACE_NAME "Interface"

#ifdef GROUP8
#define SERVER_PORT 8001
#endif

#ifdef GROUP1
#define SERVER_PORT 6161
#endif

int checkInternetAccess();
void* clientCube(void *p);

#endif
