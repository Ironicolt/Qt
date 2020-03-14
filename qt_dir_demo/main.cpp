#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QSet>

void set_demo()
{
   QSet<int> set;
   set.insert(0);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //    QDir dir;
    //    QString filename = dir.currentPath()+"/test.txt";
    //    QFileInfo file(filename);
    //    qDebug()<<file.exists();
        QDir dir(".");
        qDebug()<<dir.absolutePath();

    return a.exec();
}
