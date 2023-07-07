#include <stdio.h>
#include "metalloc.h"

int main(int argc, char *argv[])
{
	char *c;

	c = new(9);
	printf("%d\n%d\n", len(c), cap(c));

	delall();
}
