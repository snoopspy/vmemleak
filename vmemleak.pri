#-------------------------------------------------
# debug and release
#-------------------------------------------------
CONFIG(debug,   debug|release) DEFINES += _DEBUG
CONFIG(release, debug|release) DEFINES += _RELEASE
message($${DEFINES})

#-------------------------------------------------
# library name
#-------------------------------------------------
VMEMLEAK_LIB_NAME = vmemleak
android-g++:                 VMEMLEAK_LIB_NAME = $${VMEMLEAK_LIB_NAME}_android
contains(QT, gui)            VMEMLEAK_LIB_NAME = $${VMEMLEAK_LIB_NAME}_gui
CONFIG(debug, debug|release) VMEMLEAK_LIB_NAME = $${VMEMLEAK_LIB_NAME}_d
message($${VMEMLEAK_LIB_NAME})

#-------------------------------------------------
# vmemleak
#-------------------------------------------------
VMEMLEAK_PATH = $${PWD}
INCLUDEPATH += $${VMEMLEAK_PATH}/src
!CONFIG(VMEMLEAK_LIB_BUILD) {
  PRE_TARGETDEPS +=  $${VMEMLEAK_PATH}/lib/lib$${VMEMLEAK_LIB_NAME}.a
  LIBS           += -L$${VMEMLEAK_PATH}/lib
  LIBS           += -l$${VMEMLEAK_LIB_NAME}
}
mingw:DEFINES += __USE_MINGW_ANSI_STDIO=1
