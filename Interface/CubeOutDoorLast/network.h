#ifndef NETWORK_H
#define NETWORK_H

#define MAX_MSG 100
#define MAX_LINE 100
#define LINE_ARRAY_SIZE (MAX_MSG+1)
#define SERVER_IP "46.101.238.174"
#define DEVICE_NAME "Device"
#define INTERFACE_NAME "Interface"

#define SERVER_PORT 8001

int checkInternetAccess();
int clientCube();
void closeSocket();

#endif
