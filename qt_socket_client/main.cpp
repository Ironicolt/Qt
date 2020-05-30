#include <QCoreApplication>
#include <QtNetwork>

#include <QDebug>

#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QClient client(NULL);

    return a.exec();
}
