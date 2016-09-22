#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"

void *mymalloc(size_t size) {
	int s = size;
	printf("Size: %d\n", s);
}

void myfree(void *ptr) {
	printf("Freed\n");
}
