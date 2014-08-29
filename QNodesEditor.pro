#-------------------------------------------------
#
# Project created by QtCreator 2014-08-22T14:55:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QNodesEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

QMAKE_CXXFLAGS += -std=c++0x
