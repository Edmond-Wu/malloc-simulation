#ifndef MYMALLOC_H
#define MYMALLOC_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <time.h>

//Struct for block linked list that contains data about the memory blocks
typedef struct MetaBlock {
	size_t size;
	int free;
	struct MetaBlock *next;
} MetaBlock;

/**
 * Initializes the heap
 */
void initialize_heap();

/**
 * Checks if the pointer is in the heap
 * @param  ptr [pointer to check]
 * @return     [1 if it is, 0 if it isn't]
 */
int in_heap(void * ptr);

/**
 * Splits memory blocks if the fit is too big
 * @param too_big [pointer to the block]
 * @param size   [size to split]
 */
void split(MetaBlock *too_big, size_t size);

/**
 * Merges free blocks to combat defragmentation
 */
void merge();

/**
 * Malloc simulation
 * @param  size [size to be allocated]
 * @return      [pointer to memory allocated]
 */
void *my_malloc(size_t size);

/**
 * Free simulation
 * @param ptr [pointer to memory to be freed]
 */
void my_free(void *ptr);

double workload_a();

double workload_b();

double workload_c();

double workload_d();

double workload_e();

double workload_f();
#endif
