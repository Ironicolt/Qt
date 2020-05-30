#include <QApplication>
#include "circlebutton.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    CircleButton *btn = new CircleButton("Circle Windows",QPoint(40,40),40);
    btn->show();
    return app.exec();
}

