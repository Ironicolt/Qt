#-------------------------------------------------
#
# Project created by QtCreator 2020-05-30T21:30:32
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = qt_socket_server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


HEADERS += server.h

SOURCES += main.cpp \
           server.cpp
