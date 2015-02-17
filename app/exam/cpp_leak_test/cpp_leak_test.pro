QT -= core gui

include(../../../vmemleak.pri)

TARGET    = cpp_leak_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += cpp_leak_test.cpp
