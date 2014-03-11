#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket;
    connect(socket,SIGNAL(connected()),this,SIGNAL(connected()));
    connect(socket,SIGNAL(disconnected()),this,SIGNAL(disconnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(closeFromHost()));
}

void TcpClient::write()
{
    /*Define for overload virtual method*/

}


void TcpClient::write(QByteArray arr)
{
    if(socket->state() != QTcpSocket::ConnectedState) return;
    int size = arr.size();
    if(size != socket->write(arr)) emit ErrStr(QString("Network failure. Cann't send data to server"));
    return;
}

void TcpClient::connecting()
{
    if(socket->state() != QTcpSocket::ConnectedState)
        socket->connectToHost(hostName,hostport);
    return;
}

void TcpClient::disconnecting()
{
    if(socket->state() == QTcpSocket::ConnectedState)
        socket->disconnectFromHost();
    return;
}

void TcpClient::read()
{
    while(socket->bytesAvailable() >= 8)
    {
        QByteArray header = socket->read(8);
        QDataStream hStream(&header);
        QDataStream.setByteOrder(QDataStream::BigEndian);
        qint32 type = 0, len = 0;
        hStream >> type >> len;
        if(checkType(type))
        {
            if(socket->bytesAvailable() >= len)
            {

            }
            else
            {

            }

        }
        else emit ErrStr(QString("Unccorect type %1 in packets. Skip header").arg(type));



    }
    return;
}
