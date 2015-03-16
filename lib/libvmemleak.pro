QT -= gui

include(libvmemleak.pri)

TARGET = $${VMEMLEAK_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}
