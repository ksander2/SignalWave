QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Processing/release/ -lProcessing
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Processing/debug/ -lProcessing
else:unix: LIBS += -L$$OUT_PWD/../Processing/ -lProcessing

INCLUDEPATH += $$PWD/../Processing
DEPENDPATH += $$PWD/../Processing

TEMPLATE = app

SOURCES +=  tst_correctsignaltest.cpp \
    tst_ffttest.cpp


