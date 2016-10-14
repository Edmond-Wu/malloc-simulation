#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <time.h>
#include "mymalloc.h"
#define malloc(x) my_malloc(x)
#define free(x) my_free(x)

const int MAX_SIZE = 4951;
static char heap[5000];
MetaBlock *free_blocks = (void*)heap;

void initialize_heap() {
	free_blocks -> size = 5000 - sizeof(MetaBlock);
	free_blocks -> free = 1;
	free_blocks -> next = NULL;
}

void merge() {
	if (free_blocks == NULL) {
		fprintf(stderr, "Nothing to be freed; %s, %d\n", __FILE__, __LINE__);
		return;
	}
	MetaBlock *curr;
	curr = free_blocks;
	while (curr) {
		if (curr -> next == NULL)
			return;
		else {
			if (curr -> free == 1 && curr -> next -> free == 1) {
				curr -> size += curr -> next -> size + sizeof(MetaBlock);
				curr -> next = curr -> next -> next;
			}
		}
		curr = curr -> next;
	}
}

void split(MetaBlock *too_big, size_t size){
	MetaBlock *new = (void*)((void*)too_big + size + sizeof(MetaBlock));
	new -> size = (too_big -> size) - size - sizeof(MetaBlock);
	new -> free = 1;
	new -> next = too_big -> next;
	too_big -> size = size;
	too_big -> free = 0;
	too_big -> next = new;
}

void *my_malloc(size_t size) {
	MetaBlock *curr;
	void *result = NULL;
	if (size == 0) {
		printf("Null pointer returned; %s, %d\n", __FILE__, __LINE__);
		return result;
	}

	//initialize heap if not initialized
	if (!free_blocks -> size)
		initialize_heap();

	//start of metadata blocks
	curr = free_blocks;

	while ((curr -> size < size || curr -> free == 0) && curr -> next != NULL)
		curr = curr -> next;

	//exact fit
	if (curr -> size == size) {
		curr -> free = 0;
		result = (void*)(++curr);
		printf("Memory allocated with exact fit; %s, %d\n", __FILE__, __LINE__);
	}

	//block bigger than requested
	else if (curr -> size > size + sizeof(MetaBlock)) {
		split(curr, size);
		result = (void*)(++curr);
		printf("Memory allocated and split; %s, %d\n", __FILE__, __LINE__);
	}

	//not enough
	else
		printf("Not enough space to be allocated; %s, %d\n", __FILE__, __LINE__);

	return result;
}

void my_free(void *ptr) {
	if (ptr == NULL) {
		fprintf(stderr, "Invalid pointer to be freed; %s, %d\n", __FILE__, __LINE__);
		return;
	}
	if ((void*)heap <= ptr && ptr <= (void*)(heap + 5000)) {
		MetaBlock *curr = ptr;
		--curr;

		//if it's already free just exit
		if (curr -> free == 1) {
			fprintf(stderr, "Block already freed; %s, %d\n", __FILE__, __LINE__);
			return;
		}
		curr -> free = 1;
		void *next_pointer = curr -> next;
		if (next_pointer != NULL)
			merge();
		printf("Memory block freed; %s, %d\n", __FILE__, __LINE__);
	}
	else
		fprintf(stderr, "Invalid free; %s, %d\n", __FILE__, __LINE__);
}

double workload_a() {
	clock_t begin = clock();

	void* arr[3000];

	for (int i = 0; i < 3000; i++) {
		arr[i] = malloc(1);
	}
	for (int j = 0; j < 3000; j++) {
		free(arr[j]);
	}

	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double workload_b() {
	clock_t begin = clock();

	char *p = malloc(1);
	for (int i = 0; i < 3000; i++)
		free(p);

	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double workload_c() {
	clock_t begin = clock();

	void* arr[6000];
	int num_mallocs = 0;
	for (int i = 0; i < 6000; i++) {
		int flip = rand() % 2;
		if (flip == 1 && num_mallocs < 3000) {
			arr[i] = malloc(1);
			num_mallocs++;
		}
		else
			free(arr[i]);
	}
	//ensure that all pointers are free
	for (int j = 0; j < 6000; j++) {
		if (arr[j] != NULL)
			free(arr[j]);
	}

	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double workload_d() {
	clock_t begin = clock();
	void* arr[6000];
	int num_mallocs = 0;
	int capacity = MAX_SIZE;

	for (int i = 0; i < 6000; i++) {
		int flip = rand() % 2;
		if (flip == 1 && num_mallocs < 3000 && capacity > 0) {
			int random_memory = rand() % 4951 + 1;
			arr[i] = malloc(random_memory);
			num_mallocs++;
			capacity -= (random_memory + sizeof(MetaBlock));
		}
		else
			free(arr[i]);
	}
	for (int j = 0; j < 6000; j++) {
		if (arr[j] != NULL)
			free(arr[j]);
	}

	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double workload_e() {
	clock_t begin = clock();
	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double workload_f() {
	clock_t begin = clock();
	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}
