#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func_cpp.h"

#define debug printf

void* operator new(size_t size, const char* file, const int line) throw(VMLD_NEW_THROW)
{
	debug("new(%d, %s, %d)\n", (int)size, file, line);
	return malloc(size);
}

void* operator new[](size_t size, const char* file, const int line) throw(VMLD_NEW_THROW)
{
	debug("new[](%d, %s, %d)\n", (int)size, file, line);
	return malloc(size);
}

void operator delete(void* ptr) throw()
{
	debug("delete(%p)\n", ptr);
	free(ptr);
}

void operator delete[](void* ptr) throw()
{
	debug("delete[](%p)\n", ptr);
	free(ptr);
}
