#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T11:33:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleImageProcessor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graylevelhistogram.cpp

HEADERS  += mainwindow.h \
    graylevelhistogram.h

FORMS    += mainwindow.ui
