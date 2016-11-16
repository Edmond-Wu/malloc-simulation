CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -std=c11
OBJS = memgrind.o mymalloc.o
DEPS = mymalloc.h

all: memgrind
	rm *.o

memgrind: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o memgrind

memgrind.o: memgrind.c
	$(CC) $(CFLAGS) -c memgrind.c

mymalloc.o: mymalloc.c mymalloc.h
	$(CC) $(CFLAGS) -c mymalloc.c

clean:
	rm memgrind
