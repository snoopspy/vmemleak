#include <stdlib.h>
#include "vmld.h"

void first_test()
{
	void *p = malloc(4);
	free(p);

	p = calloc(256, 4);
	free(p);

	p = malloc(4);
	p = realloc(p, 4);
	free(p);

	p = malloc(4);
	p = realloc(p, 400000);
	free(p);
}

#include "vmld_cancel.h"
void cancel_test()
{
	void *p = malloc(4);
	free(p);

	p = calloc(256, 4);
	free(p);

	p = malloc(4);
	p = realloc(p, 4);
	free(p);

	p = malloc(4);
	p = realloc(p, 400000);
	free(p);
}

#include "vmld.h"
void second_test()
{
	void *p = malloc(4);
	free(p);

	p = calloc(256, 4);
	free(p);

	p = malloc(4);
	p = realloc(p, 4);
	free(p);

	p = malloc(4);
	p = realloc(p, 400000);
	free(p);
}

int main()
{
	first_test();
	cancel_test();
	second_test();
	return 0;
}
