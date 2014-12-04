#include <errno.h>  // errno
#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <string.h> // strerror

#include "vmld_func_c.h"
#include "vmld_mgr.h"

void* vmld_malloc(size_t size, const char* file, const int line)
{
	printf("vmld_malloc(%d, %s, %d)\n", (int)size, file, line);
	void* res = malloc(size);
	if (res == NULL)
	{
		printf("failed to call malloc(%d) %d:%s\n",
			(int)size, errno, strerror(errno));
		return NULL;
	}
	if (!vmld_mgr_add(res, size, file, line))
	{
		printf("failed to call vmld_mgr_add(%p, %d, %s, %d) %d:%s\n",
			res, (int)size, file, line, errno, strerror(errno));
		return NULL;
	}
	return res;
}

void* vmld_calloc(size_t nmemb, size_t size, const char* file, const int line)
{
	printf("vmld_calloc(%d, %d, %s, %d)\n", (int)nmemb, (int)size, file, line);
	void* res = calloc(nmemb, size);
	if (res == NULL)
	{
		printf("failed to call calloc(%d, %d) %d:%s\n",
			(int)nmemb, (int)size, errno, strerror(errno));
		return NULL;
	}
	if (!vmld_mgr_add(res, size, file, line))
	{
		printf("failed to call vmld_mgr_add(%p, %d, %s, %d) %d:%s\n",
			res, (int)size, file, line, errno, strerror(errno));
	}
	return res;
}

void* vmld_realloc(void *ptr, size_t size, const char* file, const int line)
{
	printf("vmld_realloc(%p, %d, %s, %d)\n", ptr, (int)size, file, line);
	void* res = realloc(ptr, size);
	if (res == NULL)
	{
		printf("failed to call realloc(%p, %d) %d:%s\n",
			ptr, (int)size, errno, strerror(errno));
		return NULL;
	}
	if (!vmld_mgr_add(res, size, file, line))
	{
		printf("failed to call vmld_mgr_add(%p, %d, %s, %d) %d:%s\n",
			res, (int)size, file, line, errno, strerror(errno));
	}
	return res;
}

void vmld_free(void *ptr, const char* file, const int line)
{
	printf("vmld_free(%p, %s, %d)\n", ptr, file, line);
	free(ptr);
	vmld_mgr_del(ptr);
}
