all: test

test: test.c uprintf.c uprintf.h
	gcc -std=c99 -Os -m32 -o test test.c uprintf.c

clean:
	rm -rf test
