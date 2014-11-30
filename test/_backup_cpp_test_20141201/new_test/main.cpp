#include <stddef.h> // size_t
#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc

void* operator new(size_t size)
{
	void* ptr = malloc(size);
	printf("new    %p %zu \n", ptr, size);
	return ptr;
}

void* operator new(size_t size, const char* file, const int line)
{
	void* ptr = malloc(size);
	printf("new    %p %s %d %zu \n", ptr, file, line, size);
	return ptr;
}

void operator delete(void* ptr)
{
	printf("delete %p\n", ptr);
	free(ptr);
}

void operator delete(void* ptr, size_t size)
{
	printf("delete %p %zu\n", ptr, size);
	free(ptr);
}

void operator delete(void* ptr, const char* file, const int line)
{
	printf("delete %p %s %d\n", ptr, file, line);
	free(ptr);
}

void test1()
{
	void* p1 = operator new(256, __FILE__, __LINE__);
	operator delete(p1, __FILE__, __LINE__);

	void* p2 = operator new(256);
	operator delete(p2);

	char* p3 = new (__FILE__, __LINE__)char;
	operator delete (p3, __LINE__);
}

int main()
{
	test1();
	return 0;
}
