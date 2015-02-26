#------------------------------------------------------------------------------
# debug and release
#------------------------------------------------------------------------------
CONFIG(debug, debug|release)   DEFINES += _DEBUG
CONFIG(release, debug|release) DEFINES += _RELEASE NDEBUG

#------------------------------------------------------------------------------
# library name
#------------------------------------------------------------------------------
VMEMLEAK_NAME = vmemleak
android-g++:                 VMEMLEAK_NAME = $${VMEMLEAK_NAME}_android
CONFIG(debug, debug|release) VMEMLEAK_NAME = $${VMEMLEAK_NAME}_d

#------------------------------------------------------------------------------
# vmemleak
#------------------------------------------------------------------------------
VMEMLEAK_PATH  = $${PWD}
INCLUDEPATH += $${VMEMLEAK_PATH}/src
!CONFIG(VMEMLEAK_BUILD) {
  PRE_TARGETDEPS +=  $${VMEMLEAK_PATH}/lib/lib$${VMEMLEAK_NAME}.a
  LIBS           += -L$${VMEMLEAK_PATH}/lib -l$${VMEMLEAK_NAME}
}
