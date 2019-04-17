QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_converter_test.cpp \
    ../Converter/PEditor.cpp

HEADERS += \
    ../Converter/PEditor.h \
    ../Converter/PEditor.h \
    ../Converter/Pnumber.h
