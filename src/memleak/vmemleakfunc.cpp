#ifdef _DEBUG

#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmemleakfunc.h"
#include "vmemleakmgr.h"

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-value"
#endif // __GNUC__

#define _debug

// ----------------------------------------------------------------------------
// function for c
// ----------------------------------------------------------------------------
void* vmemleak_malloc(size_t size, const char* file, const int line)
{
	void* res;

  _debug("vmemleak_malloc(%d, %s, %d)\n", (int)size, file, line);
	res = malloc(size);
  res = vmemleak_mgr_add(res, size, file, line);
	return res;
}

void* vmemleak_calloc(size_t nmemb, size_t size, const char* file, const int line)
{
	void* res;

  _debug("vmemleak_calloc(%d, %d, %s, %d)\n", (int)nmemb, (int)size, file, line);
	res = calloc(nmemb, size);
  res = vmemleak_mgr_add(res, size, file, line);
	return res;
}

void* vmemleak_realloc(void *ptr, size_t size, const char* file, const int line)
{
	void* res;

  _debug("vmemleak_realloc(%p, %d, %s, %d)\n", ptr, (int)size, file, line);
	res = realloc(ptr, size);
	if (res != ptr)
	{
    vmemleak_mgr_del(ptr);
    res = vmemleak_mgr_add(res, size, file, line);
	}
	return res;
}

void vmemleak_free(void *ptr, const char* file, const int line)
{
  _debug("vmemleak_free(%p, %s, %d)\n", ptr, file, line);
  vmemleak_mgr_del(ptr);
	free(ptr);
}

// ----------------------------------------------------------------------------
// function for cpp
// ----------------------------------------------------------------------------
void* operator new(size_t size, const char* file, const int line) throw(std::bad_alloc)
{
    _debug("new(%d, %s, %d)\n", (int)size, file, line);
    void* res = malloc(size);
    res = vmemleak_mgr_add(res, size, file, line);
    return res;
}

void* operator new[](size_t size, const char* file, const int line) throw(std::bad_alloc)
{
    _debug("new[](%d, %s, %d)\n", (int)size, file, line);
    void* res = malloc(size);
    res = vmemleak_mgr_add(res, size, file, line);
    return res;
}

void operator delete(void* ptr) throw()
{
    _debug("delete(%p)\n", ptr);
    vmemleak_mgr_del(ptr);
    free(ptr);
}

void operator delete[](void* ptr) throw()
{
    _debug("delete[](%p)\n", ptr);
    vmemleak_mgr_del(ptr);
    free(ptr);
}

#endif // _DEBUG
