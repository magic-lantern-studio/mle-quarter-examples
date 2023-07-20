#if QT_VERSION >= 0x060000
QT += core gui opengl openglwidgets help
#else
QT += core gui opengl help
#endif

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

LIBS += -lCoin -lQuarter

SOURCES += \
    HelloCone.cpp
