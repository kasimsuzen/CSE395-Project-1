#-------------------------------------------------
#
# Project created by QtCreator 2015-12-21T00:42:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cube_Project
TEMPLATE = app

#INCLUDEPATH += C:/boost_1_60_0

#LIBS += -LC:/boost_1_60_0/stage/lib/ \
 #   -lboost_system-mgw48-1_60 \
  #  -lboost_date_time-mgw48-mt-1_60 \
   # -lboost_thread-mgw48-mt-1_60

#LIBS += C:\MinGW\lib\libws2_32.a
#LIBS += C:\MinGW\lib\libwsock32.a


SOURCES += main.cpp\
        mainwindow.cpp \
    cubein.cpp \
    cubeout.cpp \
    shortestpath.cpp \
    network.cpp

HEADERS  += mainwindow.h \
    cubein.h \
    cubeout.h \
    shortestpath.h \
    network.h \
    location.h

FORMS    += mainwindow.ui \
    cubein.ui \
    cubeout.ui

RESOURCES += \
    resource.qrc \
