sources := test.c uprintf.c idiv.c
cflags  := -std=c89 -Os -Wl,--no-warn-execstack

ifeq ($(CUSTOM_DIV_FUNC), 1)
  cflags += -DUPRINTF_CUSTOM_DIV_FUNC
endif

all: test

test: test.c uprintf.c uprintf.h
	gcc $(cflags) -o test $(sources)

clean:
	rm -rf test
