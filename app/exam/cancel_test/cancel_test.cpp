#include "vmld.h"

void first_test()
{
	delete new char;
}

#include "vmld_cancel.h"
#include <list>
void list_test()
{
	std::list<int>* intList = new std::list<int>;
	delete intList;
}

void second_test()
{
	delete[] new char[256];
}

void cancel_test()
{
	first_test();
	list_test();
	second_test();
}

int main()
{
	first_test();
	list_test();
	cancel_test();
	return 0;
}
