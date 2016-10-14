#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "mymalloc.h"
#define malloc(x) my_malloc(x)
#define free(x) my_free(x)
#define RUNS 100


//4951 is the max amount that can be allocated in one shot

int main(int argc, char *argv[]) {
	double average_a = 0.0, average_b = 0.0, average_c = 0.0, average_d = 0.0, average_e = 0.0, average_f = 0.0;
	for (int i = 0; i < RUNS; i++) {
		average_a += workload_a();
		average_b += workload_b();
		average_c += workload_c();
		average_d += workload_d();
		average_e += workload_e();
		average_f += workload_f();
	}
	average_a /= RUNS;
	average_b /= RUNS;
	average_c /= RUNS;
	average_d /= RUNS;
	average_e /= RUNS;
	average_f /= RUNS;
	printf("Average time for A: %f\n", average_a);
	printf("Average time for B: %f\n", average_b);
	printf("Average time for C: %f\n", average_c);
	printf("Average time for D: %f\n", average_d);
	printf("Average time for E: %f\n", average_e);
	printf("Average time for F: %f\n", average_f);
  	return 0;
}
