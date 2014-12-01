#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_func.h"

void *vmld_malloc(size_t size, const char* file, const int line)
{
	printf("vmld_malloc(%zu, %s, %d)\n", size, file, line);
	return malloc(size);
}

void *vmld_calloc(size_t nmemb, size_t size, const char* file, const int line)
{
	printf("vmld_calloc(%zu, %zu, %s, %d)\n", nmemb, size, file, line);
	return calloc(nmemb, size);
}

void *vmld_realloc(void *ptr, size_t size, const char* file, const int line)
{
	printf("vmld_realloc(%p, %zu, %s, %d)\n", ptr, size, file, line);
	return realloc(ptr, size);
}

void vmld_free(void *ptr, const char* file, const int line)
{
	printf("vmld_free(%p, %s, %d)\n", ptr, file, line);
	free(ptr);
}
