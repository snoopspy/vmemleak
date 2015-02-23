QT -= core gui

include(../../../vmemleak.pri)

TARGET    = cpp_cancel_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
DESTDIR   = $${PWD}/../../../bin

SOURCES  += cpp_cancel_test.cpp
