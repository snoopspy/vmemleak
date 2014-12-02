#include "vmld.h"

void malloc_free_test()
{
	void* p = malloc(256);
	free(p);
}

void calloc_free_test()
{
	void* p = calloc(4, 256);
	free(p);
}

void realloc_free_test()
{
	void* p = malloc(256);
	p = realloc(p, 256);
	free(p);
}

int main()
{
	malloc_free_test();
	calloc_free_test();
	realloc_free_test();

	return 0;
}
