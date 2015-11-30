#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int checkInternetAccess()
{
    int socketDescriptor;
    unsigned short int serverPort = 80;
    struct sockaddr_in serverAddress;
    struct hostent *hostInfo;
    char buf[20]={"www.google.com"}; // We assume google.com will be up
    
    // gethostbyname() takes a host name or ip address in "numbers and
    // dots" notation, and returns a pointer to a hostent structure,
    // which we'll need later.  It's not important for us what this
    // structure is actually composed of.
    hostInfo = gethostbyname(buf);
    if (hostInfo == NULL) {
        cerr << "No access to DNS" << "\n";
        return -1;
    }
    
    // Create a socket.  "AF_INET" means it will use the IPv4 protocol.
    // "SOCK_STREAM" means it will be a reliable connection (i.e., TCP;
    // for UDP use SOCK_DGRAM), and I'm not sure what the 0 for the last
    // parameter means, but it seems to work.
    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0) {
        cerr << "cannot create socket\n";
        return -1;
    }
    
    // Connect to server.  First we have to set some fields in the
    // serverAddress structure.  The system will assign me an arbitrary
    // local port that is not in use.
    serverAddress.sin_family = hostInfo->h_addrtype;

    memcpy((char *) &serverAddress.sin_addr.s_addr,hostInfo->h_addr_list[0], hostInfo->h_length);

    serverAddress.sin_port = htons(serverPort);
				
    if (connect(socketDescriptor,(struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0) {
        cerr << "cannot connect\n";
        return -1;
    }

    close(socketDescriptor);
    return 0;
}