#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func_cpp.h"

void* operator new(size_t size, const char* file, const int line) throw(VMLD_NEW_THROW)
{
	printf("new(%d, %s, %d)\n", (int)size, file, line);
	return malloc(size);
}

void* operator new[](size_t size, const char* file, const int line) throw(VMLD_NEW_THROW)
{
	printf("new[](%d, %s, %d)\n", (int)size, file, line);
	return malloc(size);
}

void operator delete(void* ptr) throw()
{
	printf("delete(%p)\n", ptr);
	free(ptr);
}

void operator delete[](void* ptr) throw()
{
	printf("delete[](%p)\n", ptr);
	free(ptr);
}
