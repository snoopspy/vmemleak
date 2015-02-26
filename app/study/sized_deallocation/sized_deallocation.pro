QT      -= core gui
TARGET   = sized_deallocation
CONFIG  += console
CONFIG  -= app_bundle
TEMPLATE = app
DESTDIR  = $${PWD}/../../../bin

SOURCES += sized_deallocation.cpp

OTHER_FILES += \
	readme.md
