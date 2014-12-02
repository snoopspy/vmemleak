#ifndef __VMLD_FUNC_CPP_H__
#define __VMLD_FUNC_CPP_H__

#include <stddef.h> // size_t

//#ifdef __cplusplus
//extern "C" {
//#endif

#include <new>

void* operator new     (size_t size, const char* file, const int line) throw(std::bad_alloc);
void* operator new[]   (size_t size, const char* file, const int line);
void  operator delete  (void* ptr) throw();
void  operator delete[](void* ptr) throw();
void  foo(void); // gilgil temp

//#ifdef __cplusplus
//}
//#endif

#endif // __VMLD_FUNC_CPP_H__
