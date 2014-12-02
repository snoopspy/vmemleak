#include "vmld.h"

void malloc_free_test()
{
	void* p = malloc(256);
	free(p);
}

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
	malloc_free_test();
	new_delete_test();
	new_delete_arr_test();

	return 0;
}
