#ifndef __VMLD_FUNC_CPP_H__
#define __VMLD_FUNC_CPP_H__


#ifdef __GNUC___
  #include <new>      // bad_alloc
  #include <stddef.h> // size_t
  #define VMLD_NEW_THROW std::bad_alloc
#endif // __GNUC__
#ifdef _MSC_VER
  #define VMLD_NEW_THROW
#endif // __MS_VER

void* operator new     (size_t size, const char* file, const int line) throw(VMLD_NEW_THROW);
void* operator new[]   (size_t size, const char* file, const int line) throw(VMLD_NEW_THROW);
void  operator delete  (void* ptr) throw();
void  operator delete[](void* ptr) throw();
void  foo(void); // gilgil temp

#endif // __VMLD_FUNC_CPP_H__
