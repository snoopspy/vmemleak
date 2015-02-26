QT      -= core gui
TARGET   = global_new_delete
CONFIG  += console
CONFIG  -= app_bundle
TEMPLATE = app
DESTDIR  = $${PWD}/../../../bin

SOURCES += global_new_delete.cpp

OTHER_FILES += \
	readme.md
