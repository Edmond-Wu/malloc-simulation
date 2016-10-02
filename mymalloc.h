#ifndef MYMALLOC_H
#define MYMALLOC_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void *mymalloc(size_t size, char *file, int line);

void myfree(void *ptr, char *file, int line);

void allocate(int start, int size);

int enough_space(int start, int size);

char* get_heap();

void initialize_heap();

void print_heap();
#endif
