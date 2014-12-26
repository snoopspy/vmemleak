#include "vmld.h"
#include "vmldmgr.h"

void new_test()
{
	vmld_mgr_start();
	new int;
	vmld_mgr_stop();
}

void new_arr_test()
{
	vmld_mgr_start();
	new int[256];
	vmld_mgr_stop();
}

int main()
{
	new_test();
	new_arr_test();
	return 0;
}
