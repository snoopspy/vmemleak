QT      -= core gui
TARGET   = placement_delete
CONFIG  += console
CONFIG  -= app_bundle
TEMPLATE = app
DESTDIR  = $${PWD}/../../../bin

SOURCES += placement_delete.cpp

OTHER_FILES += \
	readme.md
