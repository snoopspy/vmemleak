QT -=  gui

CONFIG += VMLD_LIB_BUILD
include (vmld.pri)

TARGET    = $${VMLD_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = ../lib

SOURCES += \
	../include/vmld_c.c \
	../include/vmld_c.cpp

HEADERS += \
	../include/vmld.h \
	../include/vmld_c.h \
	../include/vmld_cpp.h

