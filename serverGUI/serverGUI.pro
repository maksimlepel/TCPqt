#-------------------------------------------------
#
# Project created by QtCreator 2023-05-26T09:23:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serverGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    server.h

FORMS    += mainwindow.ui

RESOURCES += \
    pictures.qrc
