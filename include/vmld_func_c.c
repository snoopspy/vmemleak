#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func_c.h"

void *vmld_malloc(size_t size, const char* file, const int line)
{
	printf("vmld_malloc(%d, %s, %d)\n", (int)size, file, line);
	return malloc(size);
}

void *vmld_calloc(size_t nmemb, size_t size, const char* file, const int line)
{
	printf("vmld_calloc(%d, %d, %s, %d)\n", (int)nmemb, (int)size, file, line);
	return calloc(nmemb, size);
}

void *vmld_realloc(void *ptr, size_t size, const char* file, const int line)
{
	printf("vmld_realloc(%p, %d, %s, %d)\n", ptr, (int)size, file, line);
	return realloc(ptr, size);
}

void vmld_free(void *ptr, const char* file, const int line)
{
	printf("vmld_free(%p, %s, %d)\n", ptr, file, line);
	free(ptr);
}
