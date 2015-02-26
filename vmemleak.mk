#
# vmemleak
#
VMEMLEAK_PATH := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CPPFLAGS += -I$(VMEMLEAK_PATH)/src
LDFLAGS += -L$(VMEMLEAK_PATH)/lib -lvmemleak
