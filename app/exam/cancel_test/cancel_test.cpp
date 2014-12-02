#include "vmld.h"

void first_test()
{
	delete new char;
	delete[] new char[256];
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
	delete new char;
	delete[] new char[256];
}

int main()
{
	first_test();
	list_test();
	second_test();
	return 0;
}
