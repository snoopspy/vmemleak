#ifndef __VMLD_FUNC_CPP_H__
#define __VMLD_FUNC_CPP_H__

#ifdef _DEBUG

#ifdef __GNUC__
	#include <new>      // bad_alloc
	#include <stddef.h> // size_t
	#define VMLD_NEW_THROW throw(std::bad_alloc)
	#define VMLD_DEL_THROW throw()
#endif // __GNUC__
#ifdef _MSC_VER
	#define VMLD_NEW_THROW throw()
	#define VMLD_DEL_THROW throw()
#endif // __MS_VER

void* operator new     (size_t size, const char* file, const int line) VMLD_NEW_THROW;
void* operator new[]   (size_t size, const char* file, const int line) VMLD_NEW_THROW;
void  operator delete  (void* ptr) VMLD_DEL_THROW;
void  operator delete[](void* ptr) VMLD_DEL_THROW;

#endif // _DEBUG

#endif // __VMLD_FUNC_CPP_H__
