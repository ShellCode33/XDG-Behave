obj-m += xdg-behave.o
xdg-behave-objs += src/xdg-behave.o src/hooks.o src/ftrace_helper.o

ccflags-y = -I$(PWD)/include/

.PHONY: all
all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f compile_commands.json
