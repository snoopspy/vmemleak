QT -= core gui

include(../../../lib/vmld.pri)

TARGET    = example1
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE  = app
SOURCES  += c_test.c
