CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -std=c99
DEPS = mymalloc.h

memgrind : memgrind.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm memgrind
