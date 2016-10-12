#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "mymalloc.h"

static char heap[10000];
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
	if (enough_space(start, size) == 1) {
		for (int i = start; i < size + start; i++)
			heap[i] = 'b';
		free_space -= size;
	}
}

int enough_space(int start, int size) {
	if (size + start > 5000)
		return 0;
	else {
		for (int i = start; i < start + size; i++) {
			if (heap[i] == 'b')
				return 0;
		}
		return 1;
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
	for (int i = 0; i < 5000; i++)
		printf("%c ", heap[i]);
	printf("\n");
}
