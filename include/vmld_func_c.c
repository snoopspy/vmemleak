#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func_c.h"
#include "vmld_mgr.h"

#define debug printf

void* vmld_malloc(size_t size, const char* file, const int line)
{
	debug("vmld_malloc(%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* vmld_calloc(size_t nmemb, size_t size, const char* file, const int line)
{
	debug("vmld_calloc(%d, %d, %s, %d)\n", (int)nmemb, (int)size, file, line);
	void* res = calloc(nmemb, size);
	res = vmld_mgr_add(res, size, file, line);
	return res;
}

void* vmld_realloc(void *ptr, size_t size, const char* file, const int line)
{
	debug("vmld_realloc(%p, %d, %s, %d)\n", ptr, (int)size, file, line);
	void* res = realloc(ptr, size);
	if (res != ptr)
	{
		vmld_mgr_del(ptr);
		res = vmld_mgr_add(res, size, file, line);
	}
	return res;
}

void vmld_free(void *ptr, const char* file, const int line)
{
	debug("vmld_free(%p, %s, %d)\n", ptr, file, line);
	vmld_mgr_del(ptr);
	free(ptr);
}
