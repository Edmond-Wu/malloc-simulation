#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"

static char heap[5000];

void *mymalloc(size_t size) {
	if (size > 5000) {
		fprintf(stderr, "Not enough space\n");
		return NULL;
	}
	int s = size;
	printf("Size: %d\n", s);
}

void myfree(void *ptr) {
	if (ptr == NULL) {
		fprintf(stderr, "Invalid free\n");
	}
}

void allocate(int start, int size) {
	if (size + start > 5000) {
		fprintf(stderr, "Not enough space\n");
	}
	for (int i = start; i < size + start; i++) {
		heap[i] = 'b';
	}
}

char* get_heap() {
	return heap;
}

void initialize_heap() {
	//a for unused, b for used
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
