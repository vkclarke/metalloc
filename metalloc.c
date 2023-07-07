#include <stdlib.h>
#include "metalloc.h"

#define MAX_ALLOCS 65536
static Alloc allocs[MAX_ALLOCS];
static int allocnum;

Alloc *find(void *blk)
{
	pint i;

	for (i = 0; i < MAX_ALLOCS; i++) {
		if (allocs[i].blk == blk)
			return &allocs[i];
	}
	return nil;
}

void *new(pint len)
{
	Alloc *a;
	pint cap, mod;

	a = find(nil);
	if (a == nil)
		return nil;

	cap = len;
	mod = len % 8;
	if (mod > 0) {
		cap -= mod;
		cap += 8;
	}

	a->blk = malloc(cap);
	a->len = len;
	a->cap = cap;
	allocnum++;
	return a->blk;
}

void delete(void *blk)
{
	Alloc *a;

	a = find(blk);
	if (a == nil)
		return;
	free(a->blk);
	a->blk = nil;
	allocnum--;
}

void delall(void)
{
	pint i;

	for (i = 0; i < MAX_ALLOCS; i++) {
		if (allocs[i].blk != nil)
			free(allocs[i].blk);
		allocs[i].len = 0;
		allocs[i].cap = 0;
	}
	allocnum = 0;
}

pint len(void *blk)
{
	Alloc *a;

	if ((a = find(blk)) == nil)
		return 0;
	return a->len;
}

pint cap(void *blk)
{
	Alloc *a;

	if ((a = find(blk)) == nil)
		return 0;
	return a->cap;
}
