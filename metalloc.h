#define nil (void *)(0)
#define pint size_t

typedef struct {
	void *blk;
	pint len, cap;
} Alloc;

void *new(pint);
void delete(void *);
void delall(void);
pint len(void *);
pint cap(void *);
