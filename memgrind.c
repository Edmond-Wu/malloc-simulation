#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "mymalloc.h"
#define malloc(x) my_malloc(x)
#define free(x) my_free(x)

int main(int argc, char *argv[]) {
	char *p;
	for (int i = 0; i < 3000; i++)
		p = malloc(1);
  	return 0;
}
