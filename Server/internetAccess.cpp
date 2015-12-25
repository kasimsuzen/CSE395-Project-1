#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int checkInternetAccess(){

    int socketDescriptor;
    unsigned short int serverPort = 80;
    struct sockaddr_in serverAddress;
    struct hostent *hostInfo;
    char buf[20]={"www.google.com"}; // We assume google.com will be up

    hostInfo = gethostbyname(buf);
    if (hostInfo == NULL) {
        cerr << "No access to DNS" << "\n";
        return -1;
    }
    
    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0) {
        cerr << "cannot create socket\n";
        return -1;
    }
    
    serverAddress.sin_family = hostInfo->h_addrtype;

    memcpy((char *) &serverAddress.sin_addr.s_addr,hostInfo->h_addr_list[0], hostInfo->h_length);

    serverAddress.sin_port = htons(serverPort);
				
    if (connect(socketDescriptor,(struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0) {
        cerr << "cannot connect to internet\n";
        return -1;
    }

    close(socketDescriptor);
    return 0;
}