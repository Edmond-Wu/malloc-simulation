#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"

void *malloc(size_t size) {
	int s = size;
	printf("Size: %d\n", s);
}

void free(void *ptr) {
	printf("Freed\n");
}
