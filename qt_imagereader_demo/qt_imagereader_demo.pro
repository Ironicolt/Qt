#-------------------------------------------------
#
# Project created by QtCreator 2020-01-21T13:50:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_imagereader_demo
TEMPLATE = app


SOURCES += $$PWD/src/main.cpp\
        $$PWD/src/mainwindow.cpp

HEADERS  += $$PWD/src/mainwindow.h

FORMS    += $$PWD/src/mainwindow.ui

OTHER_FILES += \
    res/image_10.gif

RESOURCES += \
    src/qt_res.qrc
