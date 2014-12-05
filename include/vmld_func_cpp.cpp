#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#ifdef _DEBUG

#include "vmld_func_cpp.h"
#include "vmld_mgr.h"

#define debug printf

void* operator new(size_t size, const char* file, const int line) throw(VMLD_NEW_THROW)
{
	debug("new(%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* operator new[](size_t size, const char* file, const int line) throw(VMLD_NEW_THROW)
{
	debug("new[](%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void operator delete(void* ptr) throw()
{
	debug("delete(%p)\n", ptr);
	vmld_mgr_del(ptr);
	free(ptr);
}

void operator delete[](void* ptr) throw()
{
	debug("delete[](%p)\n", ptr);
	vmld_mgr_del(ptr);
	free(ptr);
}

#endif // _DEBUG
