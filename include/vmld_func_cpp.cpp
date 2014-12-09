#ifdef _DEBUG

#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func_cpp.h"

#define _debug printf

extern "C" void* vmld_mgr_add(void* ptr, size_t size, const char* file, const int line);
extern "C" void  vmld_mgr_del(void* ptr);

void* operator new(size_t size, const char* file, const int line) throw(std::bad_alloc)
{
	_debug("new(%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* operator new[](size_t size, const char* file, const int line) throw(std::bad_alloc)
{
	_debug("new[](%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void operator delete(void* ptr) throw()
{
	_debug("delete(%p)\n", ptr);
	vmld_mgr_del(ptr);
	free(ptr);
}

void operator delete[](void* ptr) throw()
{
	_debug("delete[](%p)\n", ptr);
	vmld_mgr_del(ptr);
	free(ptr);
}

#endif // _DEBUG
