#-------------------------------------------------
#
# Project created by QtCreator 2014-02-26T13:16:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DCSIAS-client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp \
    logger.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    Structure.h \
    logger.h \
    qtemplatethread.h

FORMS    += mainwindow.ui
