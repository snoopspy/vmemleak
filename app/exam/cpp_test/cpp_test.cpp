#include "vmld.h"

void new_delete_test()
{
	char* p = new char;
	delete p;
}

void new_delete_arr_test()
{
	char* p = new char[256];
	delete[] p;
}

int main()
{
	new_delete_test();
	new_delete_arr_test();
	return 0;
}
