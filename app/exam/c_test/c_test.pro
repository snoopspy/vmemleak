QT -= core gui

include(../../../lib/vmemleak.pri)

TARGET    = c_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += c_test.c
