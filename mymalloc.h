#ifndef MYMALLOC_H
#define MYMALLOC_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

typedef struct MetaBlock {
	size_t size;
	int free;
	struct MetaBlock *next;
} MetaBlock;

void *my_malloc(size_t size);

void my_free(void *ptr);

void allocate(int start, int size);

int enough_space(int start, int size);

char* get_heap();

void initialize_heap();

void print_heap();
#endif
