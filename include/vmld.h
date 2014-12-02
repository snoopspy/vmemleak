#ifndef __VMLD_H__
#define __VMLD_H__

// #include <stdlib.h> // gilgil temp 2014.12.01

#include "vmld_func_c.h"

#define malloc(SIZE)        vmld_malloc ((SIZE),          __FILE__, __LINE__)
#define calloc(NMEMB, SIZE) vmld_calloc ((NMEMB), (SIZE), __FILE__, __LINE__)
#define realloc(PTR, SIZE)  vmld_realloc((PTR), (SIZE),   __FILE__, __LINE__)
#define free(PTR)           vmld_free   ((PTR),           __FILE__, __LINE__)

#ifdef __cplusplus

#include "vmld_func_cpp.h"
#define vmld_new new(__FILE__, __LINE__)
#define new      vmld_new

#endif // __cplusplus

#endif // __VMLD_H__
