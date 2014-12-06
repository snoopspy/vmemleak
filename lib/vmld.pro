QT -= core gui

CONFIG += VMLD_LIB_BUILD
include (vmld.pri)

TARGET    = $${VMLD_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = $${PWD}

SOURCES += \
	../include/vmld_impl_c.c \
	../include/vmld_impl_cpp.cpp \
	../include/vmld_mgr.c

HEADERS += \
	../include/vmld.h \
	../include/vmld_cancel.h \
	../include/vmld_impl_c.h \
	../include/vmld_impl_cpp.h \
	../include/vmld_mgr.h
