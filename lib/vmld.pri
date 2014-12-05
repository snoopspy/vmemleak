#-------------------------------------------------
# debug and release
#-------------------------------------------------
CONFIG(debug, debug|release) {
	DEFINES += _DEBUG
}
CONFIG(release, debug|release) {
	DEFINES += _RELEASE
}

#-------------------------------------------------
# library name
#-------------------------------------------------
VMLD_LIB_NAME = vmld
CONFIG(debug, debug|release) {
	VMLD_LIB_NAME = $${VMLD_LIB_NAME}_d
}
contains(QT, gui) {
	VMLD_LIB_NAME = $${VMLD_LIB_NAME}_gui
}
android-g++ {
	VMLD_LIB_NAME = $${VMLD_LIB_NAME}_android
}

#-------------------------------------------------
# vmld
#-------------------------------------------------
VMLD_PATH    = $${PWD}/..
INCLUDEPATH += $${VMLD_PATH}/include
!CONFIG(VMLD_LIB_BUILD) {
	win32-msvc*:PRE_TARGETDEPS +=  $${VMLD_PATH}/lib/$${VMLD_LIB_NAME}.lib
	gcc:PRE_TARGETDEPS         +=  $${VMLD_PATH}/lib/lib$${VMLD_LIB_NAME}.a
	LIBS                       += -L$${VMLD_PATH}/lib
	LIBS                       += -l$${VMLD_LIB_NAME}
}
mingw:DEFINES += __USE_MINGW_ANSI_STDIO=1
