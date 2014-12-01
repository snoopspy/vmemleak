#ifndef __VMLD_C_H__
#define __VMLD_C_H__

#include <stddef.h> // size_t

#ifdef __cplusplus
extern "C" {
#endif

void *vmld_malloc (             size_t size,  const char* file, const int line);
void *vmld_calloc (size_t nmemb, size_t size, const char* file, const int line);
void *vmld_realloc(void *ptr,    size_t size, const char* file, const int line);
void  vmld_free   (void *ptr,                 const char* file, const int line);

#ifdef __cplusplus
}
#endif

#endif // __VMLD_C_H__
