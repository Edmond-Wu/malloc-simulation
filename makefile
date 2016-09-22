CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -std=c99

memgrind : memgrind.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm memgrind
