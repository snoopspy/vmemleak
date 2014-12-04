#include "vmld.h"

void new_test()
{
	int* p = new int;
	delete p;
}

void new_arr_test()
{
	int* p = new int[256];
	delete[] p;
}

int main()
{
	new_test();
	new_arr_test();
	return 0;
}
