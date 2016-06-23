#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T11:33:10
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SimpleImageProcessor
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    graylevelhistogram.cpp\
    blur.cpp \
    sharpen.cpp \
    grayscale.cpp \
    qcustomplot.cpp \
    otsu.cpp \
    displaywindow.cpp \
    leveldialog.cpp \
    imagedatabaseconnection.cpp \
    characterimage.cpp \
    ocr.cpp \
    characterselect.cpp

HEADERS  += mainwindow.h \
    graylevelhistogram.h \
    imagefilter.h \
    grayscale.h \
    blur.h \
    sharpen.h \
    qcustomplot.h \
    otsu.h \
    displaywindow.h \
    leveldialog.h \
    imagedatabaseconnection.h \
    characterimage.h \
    ocr.h \
    characterselect.h

FORMS    += mainwindow.ui \
    displaywindow.ui \
    leveldialog.ui \
    characterselect.ui

DISTFILES +=
