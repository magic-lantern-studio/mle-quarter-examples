win32 {
QT += core gui opengl help
}
unix {
#if QT_VERSION >= 0x060000
QT += core gui opengl openglwidgets help
#else
QT += core gui opengl help
#endif
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += \
    HelloCone.cpp

win32 {
    INCLUDEPATH += C:\Coin3D\include
    LIBS += -L"C:\Coin3D\lib" -lCoin4 -lQuarter1
    DEFINES += QUARTER_NOT_DLL
}
unix {
    LIBS += -lCoin -lQuarter
}
