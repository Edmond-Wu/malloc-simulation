#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "mymalloc.h"
#define malloc(x) my_malloc(x)
#define free(x) my_free(x)

int main(int argc, char *argv[]) {
	//detectable errors
	//testcase A
	int x;
	free(&x);

	//testcase B
	char *p;
	p = (char *)malloc(200);
	free(p + 10);
  	return 0;
}
