#include <stdio.h>
#include <stdlib.h>
#include "metalloc.h"

int main(int argc, char *argv[]) {
	if (atexit(delall) != 0)
		exit(1);

	char *c = new(9);
	printf("%d\n%d\n", len(c), cap(c));
}
