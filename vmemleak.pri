#-------------------------------------------------
# debug and release
#-------------------------------------------------
CONFIG(debug,   debug|release) DEFINES += _DEBUG
CONFIG(release, debug|release) DEFINES += _RELEASE
message($${DEFINES})

#-------------------------------------------------
# vmemleak
#-------------------------------------------------
VMEMLEAK_PATH = $${PWD}
INCLUDEPATH += $${VMEMLEAK_PATH}/src
mingw:DEFINES += __USE_MINGW_ANSI_STDIO=1 # gilgil temp 2015.02.24

SOURCES += \
  $${VMEMLEAK_PATH}/src/memleak/vmemleakfunc.cpp \
  $${VMEMLEAK_PATH}/src/memleak/vmemleakmgr.cpp

HEADERS += \
  $${VMEMLEAK_PATH}/src/memleak/vmemleak.h \
  $${VMEMLEAK_PATH}/src/memleak/vmemleakcancel.h \
  $${VMEMLEAK_PATH}/src/memleak/vmemleakfunc.h \
  $${VMEMLEAK_PATH}/src/memleak/vmemleakmgr.h
