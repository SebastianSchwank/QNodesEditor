#-------------------------------------------------
#
# Project created by QtCreator 2014-08-22T14:55:14
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QNodesEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qnodemodel.cpp \
    qnodewidget.cpp \
    qnodeview.cpp \
    qconnectorblob.cpp \
    qhandle.cpp \
    qxmlwriter.cpp \
    qxmlparser.cpp \
    qnodeobjectfactory.cpp

HEADERS  += mainwindow.h \
    qnodemodel.h \
    qnodewidget.h \
    qnodeview.h \
    qconnectorblob.h \
    qhandle.h \
    qnodeconnectortuple.h \
    qxmlwriter.h \
    qxmlparser.h \
    qnodeobjectfactory.h

FORMS    += mainwindow.ui \
    qnodewidget.ui \
    qhandle.ui

CONFIG += mobility
MOBILITY = 

QMAKE_CXXFLAGS += -std=c++0x
