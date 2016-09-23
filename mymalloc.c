#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"

static char heap[5000];

void *mymalloc(size_t size) {
	int s = size;
	printf("Size: %d\n", s);
}

void myfree(void *ptr) {
	printf("Freed\n");
}

char* get_heap() {
	return heap;
}

void initialize_heap() {
	for (int i = 0; i < 5000; i++) {
		heap[i] = 'a';
	}
}

void print_heap() {
	for (int i = 0; i < 10; i++) {
		printf("%c ", heap[i]);
	}
	printf("\n");
}

