#include <QtGui/QApplication>
#include "Widget.h"
#include <QTextCodec>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    if (codec) {
        QTextCodec::setCodecForTr(codec);
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
    }

    Widget w;
    w.show();

    return a.exec();
}
