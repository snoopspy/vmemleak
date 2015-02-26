CONFIG += VMEMLEAK_BUILD
include(vmemleak.pri)

SOURCES += \
	$${PWD}/src/memleak/vmemleakfunc.cpp \
	$${PWD}/src/memleak/vmemleakmgr.cpp

HEADERS += \
	$${PWD}/vmemleak.h \
	$${PWD}/vmemleakcancel.h \
	$${PWD}/vmemleakfunc.h \
	$${PWD}/vmemleakmgr.h
