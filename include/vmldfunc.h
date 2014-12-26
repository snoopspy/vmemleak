#ifndef __VMLD_FUNC_C_H__
#define __VMLD_FUNC_C_H__

#ifdef _DEBUG

#include <stddef.h> // size_t

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// ----------------------------------------------------------------------------
// function for c
// ----------------------------------------------------------------------------
void* vmld_malloc (              size_t size, const char* file, const int line);
void* vmld_calloc (size_t nmemb, size_t size, const char* file, const int line);
void* vmld_realloc(void *ptr,    size_t size, const char* file, const int line);
void  vmld_free   (void *ptr,                 const char* file, const int line);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _DEBUG

#endif // __VMLD_FUNC_C_H__
