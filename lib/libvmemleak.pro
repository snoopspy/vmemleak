QT += core
QT -= gui

CONFIG += VMEMLEAK_BUILD
include(../vmemleak.pro)

TARGET = $${VMEMLEAK_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}
