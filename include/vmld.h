#ifndef __VMLD_H__
#define __VMLD_H__

// #include <stdlib.h> // gilgil temp 2014.12.01

#include "vmld_impl.h"

#define malloc(SIZE)        vmld_malloc((SIZE), __FILE__, __LINE__)
#define calloc(NMEMB, SIZE) vmld_calloc((NMEMB), (SIZE), __FILE__, __LINE__)
#define realloc(PTR, SIZE)  vmld_realloc((PTR), (SIZE), __FILE__, __LINE__)
#define free(PTR)           vmld_free((PTR), __FILE__, __LINE__)

#endif // __VMLD_H__
