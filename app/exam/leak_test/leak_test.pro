QT -= core gui

include(../../../lib/vmld.pri)

TARGET    = leak_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += leak_test.cpp
