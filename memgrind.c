#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"
#define malloc(x) mymalloc(x, _FILE_, _LINE_)
#define free(x) myfree(x, _FILE_, _LINE_)

int main(int argc, char *argv[]) {
	initialize_heap();
	//mymalloc(atoi(argv[1]));
	//myfree(100);
	//print_heap();
  	return 0;
}
