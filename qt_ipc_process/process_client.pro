#-------------------------------------------------
#
# Project created by QtCreator 2020-06-25T22:58:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = process_client
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin/debug
} else {
    DESTDIR = $$PWD/bin/release
}

DEFINES += IPC_CLIENT

SOURCES += main.cpp\
        $$PWD/process_client/mainwindow.cpp

HEADERS  += $$PWD/process_client/mainwindow.h

FORMS    += $$PWD/process_client/mainwindow.ui
