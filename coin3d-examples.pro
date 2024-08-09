win32 {
QT += core gui opengl help
}
unix {
equals(QT_MAJOR_VERSION, 6) {
QT += core gui opengl openglwidgets help
}
equals(QT_MAJOR_VERSION, 5) {
QT += core gui opengl help
}
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += \
    HelloCone.cpp

win32 {
    INCLUDEPATH += C:\Coin3D\include
CONFIG(debug, debug|release) {
    LIBS += -L"C:\Coin3D\lib" -lCoin4d -lQuarter1d
}
CONFIG(release, debug|release) {
    LIBS += -L"C:\Coin3D\lib" -lCoin4 -lQuarter1
}
    DEFINES += QUARTER_NOT_DLL
}
unix {
    LIBS += -lCoin -lQuarter
}
