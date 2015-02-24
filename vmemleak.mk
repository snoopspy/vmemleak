#
# vmemleak
#
VMEMLEAK_PATH := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CPPFLAGS += -I$(VMEMLEAK_PATH)/src -D_DEBUG

SOURCES += \
	$(VMEMLEAK_PATH)/src/memleak/vmemleakfunc.cpp \
	$(VMEMLEAK_PATH)/src/memleak/vmemleakmgr.cpp

