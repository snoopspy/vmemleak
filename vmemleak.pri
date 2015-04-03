QT += core

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
VMEMLEAK_DIR = $${PWD}
INCLUDEPATH += $${VMEMLEAK_DIR}/src
!CONFIG(VMEMLEAK_BUILD) {
	PRE_TARGETDEPS +=  $${VMEMLEAK_DIR}/lib/lib$${VMEMLEAK_NAME}.a
	LIBS           += -L$${VMEMLEAK_DIR}/lib -l$${VMEMLEAK_NAME}
}
