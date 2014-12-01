#ifndef __VMLD_CPP_H__
#define __VMLD_CPP_H__

#include <stddef.h> // size_t

void* operator new      (size_t size, const char* file, const int line);
void* operator new[]    (size_t size, const char* file, const int line);
void  operator delete   (void* p);
void  operator delete[] (void* p);

#endif // __VMLD_CPP_H__
