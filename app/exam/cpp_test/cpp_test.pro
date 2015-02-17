QT -= core gui

include(../../../vmemleak.pri)

TARGET    = cpp_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += cpp_test.cpp
