#-------------------------------------------------
#
# Project created by QtCreator 2019-01-15T13:48:40
#
#-------------------------------------------------

QT       -= core gui

TARGET = Processing
TEMPLATE = lib

DEFINES += PROCESSING_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QMAKE_CXXFLAGS -= -O1
QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS -= -O3
QMAKE_CXXFLAGS += -O0

SOURCES += \
        processing.cpp \
    Signals/sinesignal.cpp \
    Signals/sinesignal_p.cpp \
    Signals/squaresignal.cpp \
    Signals/basesignal_p.cpp


HEADERS += \
        processing.h \
    Signals/sinesignal.h \
    Signals/sinesignal_p.h \
    Signals/squaresignal.h \
    Signals/basesignal_p.h \
    Signals/basesignal.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
