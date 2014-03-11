#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "Structure.h"
#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QHostAddress>
#include <QTimer>
#include <QCoreApplication>
#include <QList>



class IClient : QObject
{
    Q_OBJECT
public:
    explicit IClient(QObject* parent = 0);
public slots:
    virtual void read() = 0;
    virtual void write() = 0;
    virtual void connecting() = 0;
    virtual void disconnecting() = 0;

protected:
};

class TcpClient : public IClient
{
public:
   explicit TcpClient(QObject* parent = 0);
protected:
    QTcpSocket* socket;
    QString hostName;
    quint16 hostPort;
    bool checkType(qint32 inType);
public slots:
    void setSocketOption(QString host, quint16 port);
    void closeFromHost();
    void write(QByteArray arr);
signals:
    void ErrStr(QString);
    void connected();
    void disconnected();
    void sendTask(QByteArray );

};



#endif // TCPCLIENT_H
