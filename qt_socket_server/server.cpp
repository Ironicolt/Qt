#include "server.h"

#include <QDebug>

QServer::QServer(QObject* object)
    : QObject(object)
{
    qint64 id = QCoreApplication::instance()->applicationPid();
    qDebug()<<"App id:"<<id;

    server = new QTcpServer();
    server->listen(QHostAddress("127.0.0.1"), id);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

QServer::~QServer()
{
    server->disconnect(this);
    server->deleteLater();
}

void QServer::acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
    clientConnection->write("test");
}

void QServer::readClient()
{
    QString strReply = clientConnection->readAll();
    qDebug()<<"Client:"<<strReply;
}

