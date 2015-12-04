#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <signal.h> // sigterm,sigint
#include <stdio.h>
#include <pthread.h>
#include "network.h"
#include "../Hardware/hardware.h"


void handle_signal(int signal);

using namespace std;

void* clientCube(void *p){
    int socketDescriptor;
    static int isConnected = 0;
    struct sockaddr_in serverAddress;
    struct hostent *hostInfo;
    char buf[LINE_ARRAY_SIZE], c;

    struct sigaction sa;
    // Setup the sighub handler
    sa.sa_handler = &handle_signal;

    // Restart the system call, if at all possible
    sa.sa_flags = SA_RESTART;

    // Block every signal during the handler
    sigfillset(&sa.sa_mask);

    // Intercept SIGHUP and SIGINT
    if (sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGHUP"); // Should not happen
    }

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGINT"); // Should not happen
    }

    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGTERM"); // Should not happen
    }

    if(checkInternetAccess() < 0){
        exit(-1);
    }
    
    // gethostbyname() takes a host name or ip address in "numbers and
    // dots" notation, and returns a pointer to a hostent structure,
    // which we'll need later.  It's not important for us what this
    // structure is actually composed of.
    hostInfo = gethostbyname(SERVER_IP);
    if (hostInfo == NULL) {
        cout << "problem interpreting host: " << SERVER_IP << "\n";
        exit(1);
    }
    
    // Create a socket.  "AF_INET" means it will use the IPv4 protocol.
    // "SOCK_STREAM" means it will be a reliable connection (i.e., TCP;
    // for UDP use SOCK_DGRAM), and I'm not sure what the 0 for the last
    // parameter means, but it seems to work.
    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0) {
        cerr << "cannot create socket\n";
        exit(1);
    }
    
    // Connect to server.  First we have to set some fields in the
    // serverAddress structure.  The system will assign me an arbitrary
    // local port that is not in use.
    serverAddress.sin_family = hostInfo->h_addrtype;
    memcpy((char *) &serverAddress.sin_addr.s_addr,
           hostInfo->h_addr_list[0], hostInfo->h_length);
    serverAddress.sin_port = htons(SERVER_PORT);
				
    if (connect(socketDescriptor,
                (struct sockaddr *) &serverAddress,
                sizeof(serverAddress)) < 0) {
        cerr << "cannot connect\n";
        exit(1);
    }
    
    while (1) {
        // Send the line to the server.
        if(isConnected == 0){
            if (send(socketDescriptor, "Device", strlen("Device")+1, 0) < 0) { // there was +1 at size
            cerr << "cannot send data ";
            close(socketDescriptor);
            exit(1);
            }
            ++isConnected;

            if (recv(socketDescriptor, buf, MAX_LINE, 0) < 0) { // takes "DeviceOK" from server
                cerr << "didn't get response from server?";
                close(socketDescriptor);
                exit(1);
            }
        }

        if (send(socketDescriptor,&message, 1, 0) < 0) { // there was +1 at size
            cerr << "cannot send data ";
            close(socketDescriptor);
            exit(1);
        }

        // Zero out the buffer.
        memset(buf, 0x0, LINE_ARRAY_SIZE);
        
        // Read the modified line back from the server.
        if (recv(socketDescriptor, buf, MAX_LINE, 0) < 0) {
            cerr << "didn't get response from server?";
            close(socketDescriptor);
            exit(1);
        }
        pthread_cond_signal(&calculateSignal);
    
    }
    
    close(socketDescriptor);
    return 0;
}

void handle_signal(int signal) {

    // Find out which signal we're handling
    switch (signal) {
        case SIGHUP:
            cerr << "Caught SIGHUP exiting now" << endl;
            break;
        case SIGINT:
            cerr << "Caught SIGINT, exiting now" << endl;
            break;
        case SIGTERM:
            cerr << "Caught SIGTERM exiting now" << endl;
        default:
            cerr << "Caught wrong signal" << signal << endl;
            return;
    }
    exit(-1);
}