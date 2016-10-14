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
	for (int i = 0; i < 100; i++) {
		average_a += workload_a();
		average_b += workload_b();
		average_c += workload_c();
		average_d += workload_d();
		average_e += workload_e();
		average_f += workload_f();
	}
	average_a /= 100;
	average_b /= 100;
	average_c /= 100;
	average_d /= 100;
	average_e /= 100;
	average_f /= 100;

	printf("Average time for A: %f\n", average_a);
	printf("Average time for B: %f\n", average_b);
	printf("Average time for C: %f\n", average_c);
	printf("Average time for D: %f\n", average_d);
	printf("Average time for E: %f\n", average_e);
	printf("Average time for F: %f\n", average_f);

  	return 0;
}
