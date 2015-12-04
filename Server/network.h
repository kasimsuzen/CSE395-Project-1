#ifndef NETWORK_H
#define NETWORK_H

#define MAX_MSG 100
#define MAX_LINE 100
#define LINE_ARRAY_SIZE (MAX_MSG+1)
#define SERVER_IP "46.101.113.151"
#define SERVER_PORT 6667
#define THREAD_NUMBER 2

int checkInternetAccess();
void* clientCube(void *p);

#endif
