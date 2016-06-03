#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T22:25:10
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinigolfSimulator3000
TEMPLATE = app


SOURCES += main.cpp\
    ball.cpp \
    level_1.cpp \
    soundengine.cpp \
    arrow.cpp \
    arrowstartitem.cpp \
    court.cpp \
    startwindow.cpp \
    game.cpp \
    score.cpp \
    strike.cpp

HEADERS  += \
    ball.h \
    borderline.h \
    courtelement.h \
    groundmaterial.h \
    level_1.h \
    soundengine.h \
    arrow.h \
    arrowstartitem.h \
    court.h \
    startwindow.h \
    game.h \
    score.h \
    strike.h \
    borderlinecurvedrawer.h

FORMS    += \
    court.ui \
    startwindow.ui

CONFIG += c++14
CONFIG -= x86_64

#INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt"

#LIBS += -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10240.0\ucrt\x64"

RESOURCES += \
    ressources.qrc
