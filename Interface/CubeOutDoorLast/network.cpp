#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>

#include "network.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

typedef boost::shared_ptr<tcp::socket> socket_ptr;
typedef boost::shared_ptr<string> string_ptr;
typedef boost::shared_ptr< queue<string_ptr> > messageQueue_ptr;

string sendMessage = "";
string recvMessage = "";
boost::mutex mainMutex;
extern int __serverStatus;

io_service service;
socket_ptr sock(new tcp::socket(service));
messageQueue_ptr messageQueue(new queue<string_ptr>);
tcp::endpoint ep(ip::address::from_string(SERVER_IP), SERVER_PORT);
const int inputSize = 256;
string_ptr promptCpy;

boost::thread_group threads;

// Function Prototypes
bool isOwnMessage(string_ptr);
void displayLoop(socket_ptr);
void inboundLoop(socket_ptr, string_ptr);
void writeLoop(socket_ptr, string_ptr);
string* buildPrompt();
int clientCube();
// End of Function Prototypes

int clientCube()
{
    try
    {
        string_ptr prompt( buildPrompt() );
        promptCpy = prompt;

        sock->connect(ep);

        cerr << "Server connected." << endl;

        string inputMsg = *prompt + "yes";
        sock->write_some(buffer(inputMsg, inputSize));

        threads.create_thread(boost::bind(displayLoop, sock));
        threads.create_thread(boost::bind(inboundLoop, sock, prompt));
        threads.create_thread(boost::bind(writeLoop, sock, prompt));
    }
    catch(std::exception& e)
    {
        cerr << e.what() << endl;
        __serverStatus = 0;
        return -1;
    }
    __serverStatus = 1;
    return 0;
}

string* buildPrompt()
{
    const int inputSize = 256;
    char nameBuf[inputSize] = {0};
    string* prompt = new string(": ");

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
    char readBuf[inputSize] = {0};

    for(;;)
    {
        if(sock->available())
        {
            bytesRead = sock->read_some(buffer(readBuf, inputSize));
            string_ptr msg(new string(readBuf, bytesRead));

            messageQueue->push(msg);
        }

        boost::this_thread::sleep( boost::posix_time::millisec(50));
    }
}

void writeLoop(socket_ptr sock, string_ptr prompt)
{
    string inputMsg;
    int i = 1;
    for(;;)
    {
        inputMsg = *prompt;
        mainMutex.lock();
        if(!sendMessage.empty())
        {
            cerr << "Message sent:" << sendMessage <<":\n";
            inputMsg += sendMessage;
            sock->write_some(buffer(inputMsg, inputSize));
            //sendMessage.clear();
            if(i==10)
            {
                sendMessage.clear();
                i=1;
            }else
                ++i;
        }
        mainMutex.unlock();

        if(inputMsg.find("exit") != string::npos)
            return;

        inputMsg.clear();
        boost::this_thread::sleep( boost::posix_time::millisec(1000));
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
                string strTemp = *(messageQueue->front());
                cerr << "message received:" << strTemp.c_str() << ":\n";
                mainMutex.lock();
                recvMessage.clear();
                recvMessage.append(strTemp.c_str());
                mainMutex.unlock();
            }

            messageQueue->pop();
        }
        boost::this_thread::sleep( boost::posix_time::millisec(50));
    }
}

bool isOwnMessage(string_ptr message)
{
    if(message->find(*promptCpy) != string::npos)
        return true;
    else
        return false;
}

void closeSocket()
{
    threads.interrupt_all();
    sock->shutdown(tcp::socket::shutdown_both);
    sock->close();
    boost::system::error_code ec;
    if(ec)
        cerr << ec.message().c_str();
}
