#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T18:59:33
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CubeIndoor
TEMPLATE = app

#CONFIG      += no_keywords # so Qt won't #define any non-all-caps `keywords'
INCLUDEPATH += . /usr/include/boost/
QMAKE_CXXFLAGS += -std=c++11 -D INTERFACE -D GROUP8
QMAKE_LFLAGS += -lboost_system -lboost_date_time -lboost_thread -lm

FORMS    += mainwindow.ui

SOURCES += main.cpp\
        mainwindow.cpp \
    shortestpath.cpp \
    network.cpp

HEADERS  += mainwindow.h \
    shortestpath.h \
    network.h

RESOURCES += \
    resource.qrc

LIBS += -L/usr/include/boost/ -lboost_system -lboost_date_time -lboost_thread -lm

#LIBS += C:\MinGW\lib\libws2_32.a
#LIBS += C:\MinGW\lib\libwsock32.a
