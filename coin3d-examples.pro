
QT += core gui opengl help

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

LIBS += -lCoin -lQuarter

SOURCES += \
    HelloCone.cpp
