#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func_cpp.h"

//#ifdef __cplusplus
//extern "C" {
//#endif

void* operator new(size_t size, const char* file, const int line)
{
	printf("new(%zu, %s, %d)\n", size, file, line);
	return malloc(size);
}

void* operator new[](size_t size, const char* file, const int line)
{
	printf("new[](%zu, %s, %d)\n", size, file, line);
	return malloc(size);
}

void operator delete(void* ptr)
{
	printf("delete(%p)\n", ptr);
	free(ptr);
}

void operator delete[](void* ptr)
{
	printf("delete[](%p)\n", ptr);
	free(ptr);
}

void foo(void) // gilgil temp
{
	printf("foo\n");
}

//#ifdef __cplusplus
//}
//#endif
