#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void *mymalloc(size_t size);

void myfree(void *ptr);

char* get_heap();

void initialize_heap();

void print_heap();
