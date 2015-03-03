CONFIG += VMEMLEAK_BUILD
include(vmemleak.pri)

TARGET = $${VMEMLEAK_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}/lib

SOURCES += \
	$${PWD}/src/memleak/vmemleakfunc.cpp \
	$${PWD}/src/memleak/vmemleakmgr.cpp

HEADERS += \
	$${PWD}/src/memleak/vmemleak.h \
	$${PWD}/src/memleak/vmemleakcancel.h \
	$${PWD}/src/memleak/vmemleakfunc.h \
	$${PWD}/src/memleak/vmemleakmgr.h
