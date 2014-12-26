QT -= core gui

CONFIG += VMLD_LIB_BUILD
include (vmld.pri)

TARGET    = $${VMLD_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = $${PWD}

SOURCES += \
    ../include/vmldmgr.c \
    ../include/vmldfunc_cpp.cpp \
    ../include/vmldfunc_c.c

HEADERS += \
	../include/vmld.h \
    ../include/vmldcancel.h \
    ../include/vmldfunc_c.h \
    ../include/vmldfunc_cpp.h \
    ../include/vmldmgr.h
