#-------------------------------------------------
#
# Project created by QtCreator 2020-06-25T23:10:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = process_server
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin/debug
} else {
    DESTDIR = $$PWD/bin/release
}

DEFINES += IPC_SERVER

SOURCES += main.cpp\
        $$PWD/process_server/mainwindow.cpp

HEADERS  += $$PWD/process_server/mainwindow.h

FORMS    += $$PWD/process_server/mainwindow.ui
