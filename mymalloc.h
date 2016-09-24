#ifndef MYMALLOC_H
#define MYMALLOC_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void *mymalloc(size_t size);

void myfree(void *ptr);

void allocate(int start, int size);

char* get_heap();

void initialize_heap();

void print_heap();
#endif
