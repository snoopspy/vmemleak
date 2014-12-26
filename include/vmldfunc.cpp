#ifdef _DEBUG

#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmldfunc.h"
#include "vmldmgr.h"

#define _debug printf

// ----------------------------------------------------------------------------
// function for c
// ----------------------------------------------------------------------------
void* vmld_malloc(size_t size, const char* file, const int line)
{
	void* res;

	_debug("vmld_malloc(%d, %s, %d)\n", (int)size, file, line);
	res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* vmld_calloc(size_t nmemb, size_t size, const char* file, const int line)
{
	void* res;

	_debug("vmld_calloc(%d, %d, %s, %d)\n", (int)nmemb, (int)size, file, line);
	res = calloc(nmemb, size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* vmld_realloc(void *ptr, size_t size, const char* file, const int line)
{
	void* res;

	_debug("vmld_realloc(%p, %d, %s, %d)\n", ptr, (int)size, file, line);
	res = realloc(ptr, size);
	if (res != ptr)
	{
		vmld_mgr_del(ptr);
		res = vmld_mgr_add(res, size, file, line);
	}
	return res;
}

void vmld_free(void *ptr, const char* file, const int line)
{
	_debug("vmld_free(%p, %s, %d)\n", ptr, file, line);
	vmld_mgr_del(ptr);
	free(ptr);
}

// ----------------------------------------------------------------------------
// function for cpp
// ----------------------------------------------------------------------------
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
