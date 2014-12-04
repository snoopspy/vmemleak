#include "vmld.h"
#include "vmld_mgr.h"

void malloc_test()
{
	vmld_mgr_start(false);
	malloc(256);
	vmld_mgr_stop();
}

void calloc_test()
{
	vmld_mgr_start(false);
	calloc(4, 256);
	vmld_mgr_stop();
}

void realloc_test()
{
	void* p;

	vmld_mgr_start(false);
	p = malloc(256);
	realloc(p, 256);
	vmld_mgr_stop();

	vmld_mgr_start(false);
	p = malloc(256);
	realloc(p, 256000);
	vmld_mgr_stop();
}

int main()
{
	malloc_test();
	calloc_test();
	realloc_test();
	return 0;
}
