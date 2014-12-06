#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#ifdef _DEBUG

#include "vmld_func_cpp.h"
#include "vmld_mgr.h"

#define _debug printf

extern "C" void* vmld_mgr_add(void* ptr, size_t size, const char* file, const int line);
extern "C" void  vmld_mgr_del(void* ptr);

void* operator new(size_t size, const char* file, const int line) VMLD_NEW_THROW
{
	_debug("new(%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* operator new[](size_t size, const char* file, const int line) VMLD_NEW_THROW
{
	_debug("new[](%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void operator delete(void* ptr) VMLD_DEL_THROW
{
	_debug("delete(%p)\n", ptr);
	vmld_mgr_del(ptr);
	free(ptr);
}

void operator delete[](void* ptr) VMLD_DEL_THROW
{
	_debug("delete[](%p)\n", ptr);
	vmld_mgr_del(ptr);
	free(ptr);
}

#endif // _DEBUG
