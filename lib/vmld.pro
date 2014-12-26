QT -= core gui

CONFIG += VMLD_LIB_BUILD
include (vmld.pri)

TARGET    = $${VMLD_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = $${PWD}

SOURCES += \
    ../include/vmldfunc.cpp \
    ../include/vmldmgr.cpp

HEADERS += \
    ../include/vmld.h \
    ../include/vmldcancel.h \
    ../include/vmldfunc.h \
    ../include/vmldmgr.h
