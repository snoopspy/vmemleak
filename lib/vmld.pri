#-------------------------------------------------
# library name
#-------------------------------------------------
VMLD_LIB_NAME=vmld
CONFIG(debug, debug|release) {
  VMLD_LIB_NAME=$${VMLD_LIB_NAME}_d
}

contains(QT, gui) {
  VMLD_LIB_NAME=$${VMLD_LIB_NAME}_gui
}

android-g++ {
  VMLD_LIB_NAME=$${VMLD_LIB_NAME}_android
}

#-------------------------------------------------
# vmld
#-------------------------------------------------
VMLD_PATH    =   $${PWD}/..
INCLUDEPATH +=   $${VMLD_PATH}/include
!CONFIG(VMLD_LIB_BUILD) {
	LIBS                       += -L$${VMLD_PATH}/lib -l$${VMLD_LIB_NAME}
	win32:PRE_TARGETDEPS       +=  $${VMLD_PATH}/lib/$${VMLD_LIB_NAME}.lib
	linux-g++:PRE_TARGETDEPS   +=  $${VMLD_PATH}/lib/lib$${VMLD_LIB_NAME}.a
	android-g++:PRE_TARGETDEPS +=  $${VMLD_PATH}/lib/lib$${VMLD_LIB_NAME}.so
}
