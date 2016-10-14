#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "mymalloc.h"
#define malloc(x) my_malloc(x)
#define free(x) my_free(x)

int main(int argc, char *argv[]) {
	//test case A
	double average_a = 0.0, average_b = 0.0, average_c = 0.0, average_d = 0.0, average_e = 0.0, average_f = 0.0;
	for (int i = 0; i < 100; i++)
		average_a += workload_a();
	average_a /= 100;
	printf("Average time for A: %f\n", average_a);

  	return 0;
}
