all: test

test: test.c uprintf.c uprintf.h
	gcc -std=c89 -Os -o test test.c uprintf.c

clean:
	rm -rf test
