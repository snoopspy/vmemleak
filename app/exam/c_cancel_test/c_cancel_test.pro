QT -= core gui

include(../../../lib/vmemleak.pri)

TARGET    = c_cancel_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += c_cancel_test.c
