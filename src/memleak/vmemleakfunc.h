// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_MEM_LEAK_FUNC_H__
#define __V_MEM_LEAK_FUNC_H__

#ifdef _DEBUG

#include <stddef.h> // size_t

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// ----------------------------------------------------------------------------
// function for c
// ----------------------------------------------------------------------------
void* vmemleak_malloc (              size_t size, const char* file, const int line);
void* vmemleak_calloc (size_t nmemb, size_t size, const char* file, const int line);
void* vmemleak_realloc(void *ptr,    size_t size, const char* file, const int line);
void  vmemleak_free   (void *ptr,                 const char* file, const int line);

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus

#include <new> // bad_alloc

// ----------------------------------------------------------------------------
// function for cpp
// ----------------------------------------------------------------------------
void* operator new     (size_t size, const char* file, const int line) throw(std::bad_alloc);
void* operator new[]   (size_t size, const char* file, const int line) throw(std::bad_alloc);
void  operator delete  (void* ptr) throw();
void  operator delete[](void* ptr) throw();

#endif // __cplusplus

#endif // _DEBUG

#endif // __V_MEM_LEAK_FUNC_H__
