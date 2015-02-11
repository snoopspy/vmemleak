#include <VMemLeak>
#include <VMemLeakMgr>

void new_test()
{
  vmemleak_mgr_start();
	new int;
  vmemleak_mgr_stop();
}

void new_arr_test()
{
  vmemleak_mgr_start();
	new int[256];
  vmemleak_mgr_stop();
}

int main()
{
	new_test();
	new_arr_test();
	return 0;
}
