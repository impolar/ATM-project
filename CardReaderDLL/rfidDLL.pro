#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T08:38:55
#
#-------------------------------------------------

QT       += core serialport
QT -= qui

TARGET = rfidDLL
TEMPLATE = lib

DEFINES += RFIDDLL_LIBRARY

SOURCES += rfiddll.cpp \
    moottorirfiddll.cpp

HEADERS += rfiddll.h\
        rfiddll_global.h \
    moottorirfiddll.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = C:\Users\Henkka\Documents\Projekti2\build-pankkiautomaattiEXE-Desktop_Qt_5_8_0_MinGW_32bit-Release\release
