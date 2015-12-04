#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T18:59:33
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cube
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    shortestpath.cpp

HEADERS  += mainwindow.h \
    client.h \
    shortestpath.h

FORMS    += mainwindow.ui

RESOURCES += \
    indoordesign.qrc
