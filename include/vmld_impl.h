#ifndef __VMLD_IMPL_H__
#define __VMLD_IMPL_H__

#include <stddef.h> // size_t

void *vmld_malloc(size_t size, const char* file, const int line);
void *vmld_calloc(size_t nmemb, size_t size, const char* file, const int line);
void *vmld_realloc(void *ptr, size_t size, const char* file, const int line);
void vmld_free(void *ptr, const char* file, const int line);

#endif // __VMLD_IMPL_H__
