ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m  := hello1.o hello2.o
ccflags-y := -I$(src)/inc
else
# normal makefile
KDIR := /home/parallels/linux-4.11.12

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif

