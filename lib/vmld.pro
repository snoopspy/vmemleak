QT -=  gui

CONFIG += VMLD_LIB_BUILD
include (vmld.pri)

TARGET    = $${VMLD_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = ../lib

SOURCES += \
    ../include/vmld_func.c

HEADERS += \
	../include/vmld.h \
    ../include/vmld_func.h
