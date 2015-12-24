#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include "network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>
#include "mainwindow.h"
#include <QDebug>
using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

typedef boost::shared_ptr<tcp::socket> socket_ptr;
typedef boost::shared_ptr<string> string_ptr;
typedef boost::shared_ptr< queue<string_ptr> > messageQueue_ptr;

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

int clientCube()
{
    try
    {
        boost::thread_group threads;
        socket_ptr sock(new tcp::socket(service));

        string_ptr prompt( buildPrompt() );
        promptCpy = prompt;

        sock->connect(ep);
        /*if(sock->write_some(buffer("InterfaceStart", 1024)) == 0)
        {

            sock->shutdown(tcp::socket::shutdown_both);
            sock->close();
            return 0;
        }

        char readBuf[1024] = {0};
        sock->read_some(buffer(readBuf, 1024));
        cout << readBuf << endl;


        sock->shutdown(tcp::socket::shutdown_both);
        sock->close();

        return 1;
        */
        cout << "Welcome to the ChatServer\nType \"exit\" to quit" << endl;

        threads.create_thread(boost::bind(displayLoop, sock));
        threads.create_thread(boost::bind(inboundLoop, sock, prompt));
        threads.create_thread(boost::bind(writeLoop, sock, prompt));

        threads.join_all();
    }
    catch(std::exception& e)
    {
        cerr << e.what() << endl;
        return -1;
    }

    //puts("Press any key to continue...");
    //getc(stdin);
    //return EXIT_SUCCESS;
}

string* buildPrompt()
{
    const int inputSize = 256;
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
    cout << "once" << endl;
    boost::system::error_code erc;
    for(;;)
    {
        cout << "infinite loop at inboundloop" << endl;
        if(!sock->available(erc))
        {
            cout << "soc connected" << endl;
            bytesRead = sock->read_some(buffer(readBuf, inputSize));
            string_ptr msg(new string(readBuf, bytesRead));

            messageQueue->push(msg);
            cout << "\n" + *(messageQueue->front());
        }
        if(erc){
            //error.message();
            cout << erc.category().name() << ':' << erc.value() << " " << erc.message();
            cout << "asd" <<sock->available();
        }
        boost::this_thread::sleep( boost::posix_time::millisec(1000));
    }
}

void writeLoop(socket_ptr sock, string_ptr prompt)
{
    char inputBuf[inputSize] = {0};
    string inputMsg;

    for(;;)
    {
        cout << "infinite while at write" << endl;
        //cin.getline(inputBuf, inputSize);
        //inputMsg = *prompt + (string)inputBuf + '\n';
        inputMsg = "Otomatik response\n";
        cout << "yazdın baam " << inputMsg << endl;
        if(!inputMsg.empty())
        {
            cout << "scokete attı" << endl;
            sock->write_some(buffer(inputMsg, inputSize));
        }

        if(inputMsg.find("exit") != string::npos)
            exit(1);

        inputMsg.clear();
        memset(inputBuf, 0, inputSize);
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
