#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"

static char heap[5000];
int free_space = 5000;

void *mymalloc(size_t size, char *file, int line) {
	if (size > free_space) {
		fprintf(stderr, "Not enough space\n");
		return NULL;
	}
	else {
		int s = size;
		int first_open = 0;
		for (int i = 0; i < 5000; i++) {
			if (heap[i] == 'a') {
				first_open = i;
				allocate(first_open, s);
				break;
			}
		}
		printf("Size: %d\n", s);
		return &heap[first_open];
	}
}

void myfree(void *ptr, char *file, int line) {
	if (ptr == NULL)
		fprintf(stderr, "Invalid free\n");
}

void allocate(int start, int size) {
	if (size + start > 5000)
		fprintf(stderr, "Not enough space\n");
	else {
		for (int i = start; i < size + start; i++)
			heap[i] = 'b';
		free_space -= size;
	}
}

char* get_heap() {
	return heap;
}

void initialize_heap() {
	//a for unused, b for used
	for (int i = 0; i < 5000; i++)
		heap[i] = 'a';
}

void print_heap() {
	for (int i = 0; i < 10; i++)
		printf("%c ", heap[i]);
	printf("\n");
}
