#-------------------------------------------------
#
# Project created by QtCreator 2011-10-08T21:51:23
#
#-------------------------------------------------

QT       += core gui network
CONFIG   += debug
TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    app.cpp

HEADERS  += mainwindow.h \
    app.h

FORMS    += mainwindow.ui

INCLUDEPATH += ..
LIBS += -L.. -lLibQTube


