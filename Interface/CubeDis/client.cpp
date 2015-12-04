#include "client.h"
#include <string>

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

bool Client::connectToHost(QString host, int port)
{
    socket->connectToHost(host, port);
    return socket->waitForConnected();
}

bool Client::writeData(const char* data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(data, strlen(data)+1);
        return socket->waitForBytesWritten();
    }
    else
        return false;
}


