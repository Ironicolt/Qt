#include <QCoreApplication>

#include "server.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QServer server(NULL);

    return a.exec();
}
