#include <arpa/inet.h>
#include <signal.h> // sigterm,sigint
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "network.h"

using namespace std;

void handle_signal(int signal);


int main()
{
    int listenSocket, connectSocket;
    socklen_t clientAddressLength;
    struct sockaddr_in clientAddress, serverAddress;
    char line[LINE_ARRAY_SIZE];
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

    // Create socket for listening for client connection requests.
    listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket < 0) {
        cerr << "cannot create listen socket";
        exit(1);
    }
    
    // Bind listen socket to listen port.  First set various fields in
    // the serverAddress structure, then call bind().
    // htonl() and htons() convert long integers and short integers
    // (respectively) from host byte order (on x86 this is Least
    // Significant Byte first) to network byte order (Most Significant
    // Byte first).
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(SERVER_PORT);
    
    if (bind(listenSocket,
             (struct sockaddr *) &serverAddress,
             sizeof(serverAddress)) < 0) {
        cerr << "cannot bind socket";
        exit(1);
    }
    
    // Wait for connections from clients.
    // This is a non-blocking call; i.e., it registers this program with
    // the system as expecting connections on this socket, and then
    // this thread of execution continues on.
    listen(listenSocket, 5);
    
    while (1) {
        cout << "Waiting for TCP connection on port " << SERVER_PORT << " ...\n";
        
        // Accept a connection with a client that is requesting one.  The
        // accept() call is a blocking call; i.e., this thread of
        // execution stops until a connection comes in.
        // connectSocket is a new socket that the system provides,
        // separate from listenSocket.  We *could* accept more
        // connections on listenSocket, before connectSocket is closed,
        // but this program doesn't do that.
        clientAddressLength = sizeof(clientAddress);
        connectSocket = accept(listenSocket,
                               (struct sockaddr *) &clientAddress,
                               &clientAddressLength);
        if (connectSocket < 0) {
            cerr << "cannot accept connection ";
            exit(1);
        }
        
        // Show the IP address of the client.
        // inet_ntoa() converts an IP address from binary form to the
        // standard "numbers and dots" notation.
        cout << "  connected to " << inet_ntoa(clientAddress.sin_addr);
        
        // Show the client's port number.
        // ntohs() converts a short int from network byte order (which is
        // Most Significant Byte first) to host byte order (which on x86,
        // for example, is Least Significant Byte first).
        cout << ":" << ntohs(clientAddress.sin_port) << "\n";
        
        // Read lines from socket, using recv(), storing them in the line
        // array.  If no messages are currently available, recv() blocks
        // until one arrives.
        // First set line to all zeroes, so we'll know where the end of
        // the string is.
        memset(line, 0x0, LINE_ARRAY_SIZE);
        while (recv(connectSocket, line, MAX_MSG, 0) > 0) {
            cout << "  --  " << line << "\n";
        
            //server send message to client 
            char xx[LINE_ARRAY_SIZE];
            cout << "enter string" << endl;
            cin >> xx;
            
            // Send converted line back to client.
            if (send(connectSocket, xx, strlen(xx) + 1, 0) < 0)
                cerr << "Error: cannot send modified data";
            
            memset(line, 0x0, LINE_ARRAY_SIZE);  // set line to all zeroes
        }
    }
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