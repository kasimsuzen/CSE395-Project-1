#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include "network.h"
#include "../Hardware/hardware.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

typedef boost::shared_ptr<tcp::socket> socket_ptr;
typedef boost::shared_ptr<string> string_ptr;
typedef boost::shared_ptr< queue<string_ptr> > messageQueue_ptr;

extern string sendMessage;
extern string recvMessage;
extern boost::mutex mainMutex;
io_service service;
messageQueue_ptr messageQueue(new queue<string_ptr>);
tcp::endpoint ep(ip::address::from_string(SERVER_IP), SERVER_PORT);
const int inputSize = 256;
string_ptr promptCpy;

// Function Prototypes
bool isOwnMessage(string_ptr);
void displayLoop(socket_ptr);
void inboundLoop(socket_ptr, string_ptr);
void writeLoop(socket_ptr, string_ptr);
string* buildPrompt();
// End of Function Prototypes
/*
int main(){
    clientCube();
}*/

int clientCube()
{
    try
    {
        boost::thread_group threads;
        socket_ptr sock(new tcp::socket(service));

        string_ptr prompt( buildPrompt() );
        promptCpy = prompt;

        sock->connect(ep);

        cout << "Welcome to the ChatServer\nType \"exit\" to quit" << endl;

        threads.create_thread(boost::bind(displayLoop, sock));
        threads.create_thread(boost::bind(inboundLoop, sock, prompt));
        threads.create_thread(boost::bind(writeLoop, sock, prompt));

        threads.join_all();
    }
    catch(std::exception& e)
    {
        cerr << e.what() << endl;
    }

    puts("Press any key to continue...");
    getc(stdin);
    return EXIT_SUCCESS;
}

string* buildPrompt()
{
    const int inputSize = 256;
    char inputBuf[inputSize] = {0};
    char nameBuf[inputSize] = {0};
    string* prompt = new string(": ");

    //cout << "Please input a new username: ";
    //cin.getline(nameBuf, inputSize);
    #ifdef DEVICE
        strcpy(nameBuf,DEVICE_NAME);
    #endif

    #ifdef INTERFACE
        strcpy(nameBuf,INTERFACE_NAME);
    #endif
    *prompt = (string)nameBuf + *prompt;
    boost::algorithm::to_lower(*prompt);

    return prompt;
}

void inboundLoop(socket_ptr sock, string_ptr prompt)
{
    int bytesRead = 0;
    char readBuf[1024] = {0};

    for(;;)
    {
        if(sock->available())
        {
            bytesRead = sock->read_some(buffer(readBuf, inputSize));
            string_ptr msg(new string(readBuf, bytesRead));

            messageQueue->push(msg);
        }

        boost::this_thread::sleep( boost::posix_time::millisec(1000));
    }
}

void writeLoop(socket_ptr sock, string_ptr prompt)
{
    char inputBuf[inputSize] = {0};

    for(;;)
    {
        //cin.getline(inputBuf, inputSize);
        //inputMsg = *prompt + (string)inputBuf + '\n';
	mainMutex.lock();
	
	
        if(!sendMessage.empty())
        {
		sendMessage = *prompt + sendMessage + '\n';
		cout << sendMessage << sendMessage.empty() << endl;
            //sock->write_some(buffer(inputMsg, inputSize));
		sock->write_some(buffer(sendMessage, inputSize));
        }

        if(sendMessage.find("exit") != string::npos){
            mainMutex.unlock();
		exit(1);
	}
        sendMessage.clear();
	memset(inputBuf,0,inputSize);
	mainMutex.unlock();
    }
}

void displayLoop(socket_ptr sock)
{
    for(;;)
    {
        if(!messageQueue->empty())
        {
            if(!isOwnMessage(messageQueue->front()))
            {
                cout << "\n" + *(messageQueue->front());
		mainMutex.lock();
		recvMessage.insert(0,*(messageQueue->front()));
		mainMutex.unlock();
            }
		
            messageQueue->pop();
        }

        boost::this_thread::sleep( boost::posix_time::millisec(1000));
    }
}

bool isOwnMessage(string_ptr message)
{
    if(message->find(*promptCpy) != string::npos)
        return true;
    else
        return false;
}
