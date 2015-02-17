QT -= core gui

CONFIG += VMEMLEAK_LIB_BUILD
include (vmemleak.pri)

TARGET    = $${VMEMLEAK_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = $${PWD}/lib

SOURCES += \
  src/memleak/vmemleakfunc.cpp \
  src/memleak/vmemleakmgr.cpp

HEADERS += \
  src/memleak/vmemleak.h \
  src/memleak/vmemleakcancel.h \
  src/memleak/vmemleakfunc.h \
  src/memleak/vmemleakmgr.h

DISTFILES += \
  src/VMemLeak \
  src/VMemLeakCancel \
  src/VMemLeakMgr
