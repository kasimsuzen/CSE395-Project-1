#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T19:57:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CubeOutdoor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shortestpath.cpp

HEADERS  += mainwindow.h \
    shortestpath.h \
    location.h

FORMS    += mainwindow.ui

RESOURCES += \
    myfiles.qrc
