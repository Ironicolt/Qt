#include "client.h"

#include <QDebug>

QClient::QClient(QObject* object)
    : QObject(object)
{
    client = new QTcpSocket(NULL);
    client->connectToHost(QHostAddress("127.0.0.1"), 8720);
    connect(client,SIGNAL(readyRead()),this, SLOT(readClient()));
    client->write("hello qt");
}

QClient::~QClient()
{
    client->disconnect(this);
    client->deleteLater();
}

void QClient::readClient()
{
    QString strReply = client->readAll();
    qDebug()<<"Client:"<<strReply;
}
