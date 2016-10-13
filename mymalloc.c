#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "mymalloc.h"

static char heap[5000];
MetaBlock *free_blocks = (void*)heap;

void initialize_heap() {
	free_blocks -> size = 5000 - sizeof(MetaBlock);
	free_blocks -> free = 1;
	free_blocks -> next = NULL;
}

void merge() {
	MetaBlock *curr;
	curr = free_blocks;
	while (curr -> next != NULL) {
		if (curr -> free == 1 && curr -> next -> free == 1) {
			curr -> size += curr -> next -> size + sizeof(MetaBlock);
			curr -> next = curr -> next -> next;
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
	void *result;

	//initialize heap if not initialized
	if (!free_blocks -> size) {
		initialize_heap();
		printf("Memory initialized\n");
	}

	//start of metadata blocks
	curr = free_blocks;

	while ((curr -> size < size || curr -> free == 0) && curr -> next != NULL)
		curr = curr -> next;

	//exact fit
	if (curr -> size == size) {
		curr -> free = 0;
		result = (void*)(++curr);
		printf("Memory allocated with exact fit\n");
	}

	//block bigger than requested
	else if (curr -> size > size + sizeof(MetaBlock)) {
		split(curr, size);
		result = (void*)(++curr);
		printf("Memory allocated and split\n");
	}

	//not enough
	else {
		result = NULL;
		printf("Not enough space to be allocated\n");
	}
	return result;
}

void my_free(void *ptr) {
	if (ptr == NULL)
		fprintf(stderr, "Null pointer\n");
	if ((void*)heap <= ptr && ptr <= (void*)(heap + 5000)) {
		MetaBlock *curr = ptr;
		--curr;
		curr -> free = 1;
		merge();
		printf("Memory block freed\n");
	}
	else
		fprintf(stderr, "Invalid pointer to be freed\n");
}

char* get_heap() {
	return heap;
}
