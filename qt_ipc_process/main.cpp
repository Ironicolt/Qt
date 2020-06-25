#ifdef IPC_CLIENT
#include "process_client/mainwindow.h"
#else
#include "process_server/mainwindow.h"
#endif
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
