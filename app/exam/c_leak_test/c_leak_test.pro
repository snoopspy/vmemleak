QT -= core gui

include(../../../vmemleak.pri)

TARGET    = c_leak_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += c_leak_test.c
