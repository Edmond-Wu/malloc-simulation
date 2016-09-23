#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"
#include "mymalloc.c"
#define malloc(x) mymalloc(x, _FILE_, _LINE_)
#define free(x) myfree(x, _FILE_, _LINE_)

int main(int argc, char *argv[]) {
	mymalloc(atoi(argv[1]));
	myfree(100);
	initialize_heap();
	print_heap();
  	return 0;
}
