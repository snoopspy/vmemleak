#include "vmld.h"

void first_test()
{
	delete new int;
	delete[] new int[256];
}

#include "vmld_cancel.h"
void cancel_test()
{
	delete new int;
	delete[] new int[256];
}

#include "vmld.h"
void second_test()
{
	delete new int;
	delete[] new int[256];
}

int main()
{
	first_test();
	cancel_test();
	second_test();
	return 0;
}
