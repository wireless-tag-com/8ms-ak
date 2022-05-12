
CC = arm-anykav500-linux-uclibcgnueabi-gcc
STRIP = arm-anykav500-linux-uclibcgnueabi-strip

LVGL_DIR := .
LVGL_DIR_NAME := lvgl

TOPDIR := ${shell pwd}


OPTIMIZATION ?= -O3 -std=gnu99 -DLV_CONF_INCLUDE_SIMPLE

CFLAGS ?= -I$(LVGL_DIR)/ $(OPTIMIZATION)
CFLAGS += -I$(TOPDIR)/include/lvgl/ \
	  -I$(LVGL_DIR)/$(LVGL_DIR_NAME)/ \
          -I$(LVGL_DIR)/lv_drivers/ \
	  -I$(TOPDIR)/extra/include/ \
          -I$(TOPDIR)/extra/include/ak/platform/

LDFLAGS += -L $(LVGL_DIR)/lib/ -llvgl -L $(TOPDIR)/extra/lib \
           -L $(TOPDIR)/extra/lib/ak/platform/ -lplat_osal -lplat_log -lplat_common -lplat_thread -lplat_mem \
                        -lplat_dbg -lplat_tde -lmpi_vdec -lakv_decode -lplat_vo -lplat_ao \
                        -lmpi_adec -lplat_vqe -lplat_osal -lakaudiofilter -lakaudiocodec \
           -L $(TOPDIR)/extra/lib/tslib/ -lts

LLDFLAGS := -L $(TOPDIR)/extra/lib/ak/platform/ -lplat_osal -lplat_log -lplat_common -lplat_thread -lplat_mem \
                        -lplat_dbg -lplat_tde -lmpi_vdec -lakv_decode -lplat_vo -lplat_ao \
                        -lmpi_adec -lplat_vqe -lplat_osal -lakaudiofilter -lakaudiocodec \
           -L $(TOPDIR)/extra/lib/tslib/ -lts

MSRCS += $(shell find . -maxdepth 1 -name \*.c)

include $(LVGL_DIR)/$(LVGL_DIR_NAME)/lvgl.mk
include $(LVGL_DIR)/qmsd/qmsd.mk
include $(LVGL_DIR)/main/main.mk

OBJEXT ?= .o
LIBOBJEXT ?= .lo
UIOBJEXT ?= .uo
CLOBJEXT ?= .co
LIBOBJS = $(CSRCS:.c=$(LIBOBJEXT))
MOBJS = $(MSRCS:.c=$(OBJEXT))


all: prepare qmsd-demo

prepare:
	@mkdir -p build bin

%.o: %.c
	@$(CC) $(CFLAGS) -c -o build/$@ $^
	@echo "CC $^"

qmsd-demo: $(MOBJS)
	@$(CC) -o bin/$@ build/*.o $(LDFLAGS)
	cp bin/$@ bin/$@_debug
	$(STRIP) --strip-all bin/$@

clean:
	rm -rf build bin

