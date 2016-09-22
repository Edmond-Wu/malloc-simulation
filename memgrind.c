#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mymalloc.h"
#include "mymalloc.c"

int main(int argc, char *argv[]) {
	malloc(atoi(argv[1]));
	//free(100);
  	return 0;
}
