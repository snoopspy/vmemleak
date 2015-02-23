QT -= core gui

include(../../../vmemleak.pri)

TARGET    = c_leak_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
DESTDIR   = $${PWD}/../../../bin

SOURCES  += c_leak_test.c
