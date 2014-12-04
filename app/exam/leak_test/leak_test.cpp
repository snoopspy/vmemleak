#include "vmld.h"
#include "vmld_mgr.h"

void malloc_test()
{
	vmld_mgr_start(false);
	malloc(256);
	vmld_mgr_stop(true);
}

void calloc_test()
{
	vmld_mgr_start(false);
	calloc(4, 256);
	vmld_mgr_stop(true);
}

void realloc_test()
{
	vmld_mgr_start(false);
	void* p = malloc(256);
	realloc(p, 256000);
	vmld_mgr_stop(true);
}

int main()
{
	malloc_test();
	calloc_test();
	realloc_test();
	return 0;
}
