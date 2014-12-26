#ifndef __VMLD_FUNC_CPP_H__
#define __VMLD_FUNC_CPP_H__

#ifdef _DEBUG

#include <new>      // bad_alloc
#include <stddef.h> // size_t

void* operator new     (size_t size, const char* file, const int line) throw(std::bad_alloc);
void* operator new[]   (size_t size, const char* file, const int line) throw(std::bad_alloc);
void  operator delete  (void* ptr) throw();
void  operator delete[](void* ptr) throw();

#endif // _DEBUG

#endif // __VMLD_FUNC_CPP_H__
