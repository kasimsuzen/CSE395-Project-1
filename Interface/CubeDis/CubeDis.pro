#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T23:42:47
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CubeDis
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
    dismap.qrc
