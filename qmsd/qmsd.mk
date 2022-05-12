CSRCS += $(shell find -L $(TOPDIR)/qmsd -name \*.c -exec basename {} \;)

DEPPATH += --dep-path $(TOPDIR)/qmsd
VPATH += :$(TOPDIR)/qmsd
CFLAGS += "-I$(TOPDIR)/qmsd"

