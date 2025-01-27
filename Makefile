all: test

test: test.c uprintf.c uprintf.h
	gcc -std=c89 -Os -DUPRINTF_CUSTOM_DIV_FUNC -o test test.c uprintf.c idiv.c

clean:
	rm -rf test
