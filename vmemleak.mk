#
# vmemleak
#
VMEMLEAK_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CPPFLAGS += -I$(VMEMLEAK_DIR)/src
LDFLAGS += -L$(VMEMLEAK_DIR)/lib -lvmemleak
