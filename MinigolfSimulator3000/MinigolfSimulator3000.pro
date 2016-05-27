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
        court.cpp \
    ball.cpp \
    level_1.cpp \
    soundengine.cpp

HEADERS  += court.h \
    ball.h \
    borderline.h \
    courtelement.h \
    groundmaterial.h \
    level_1.h \
    soundengine.h

FORMS    += court.ui

CONFIG += c++14

#INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt"

#LIBS += -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10240.0\ucrt\x64"

RESOURCES += \
    ressources.qrc
