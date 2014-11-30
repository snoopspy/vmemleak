#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc and free

void* my_malloc(size_t size, const char* file, const int line)
{
	void* ptr = malloc(size);
	printf("my_malloc %p %s %d %zu \n", ptr, file, line, size);
	return ptr;
}

void my_free(void* ptr, const char* file, const int line)
{
	printf("my_free   %p %s %d\n", ptr, file, line);
	free(ptr);
}

//
// use my_malloc and my_free directly
//
void test1()
{
	void* p1 = my_malloc(100, __FILE__, __LINE__);
	my_free(p1, __FILE__, __LINE__);
}

//
// define malloc and free
//
#define malloc(A) my_malloc((A), __FILE__, __LINE__)
#define free(A)   my_free((A), __FILE__, __LINE__)

void test2()
{
	void* p1 = malloc(256);
	free(p1);
}

//
// rollback define
//
#undef malloc
#undef free

void test3()
{
	void* p1 = malloc(256);
	free(p1);
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}
