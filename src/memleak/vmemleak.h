// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifdef _DEBUG

// ----------------------------------------------------------------------------
// macro for c
// ----------------------------------------------------------------------------
#include "vmemleakfunc.h"

#undef  malloc
#define malloc(SIZE)        vmemleak_malloc ((SIZE),          __FILE__, __LINE__)
#undef  calloc
#define calloc(NMEMB, SIZE) vmemleak_calloc ((NMEMB), (SIZE), __FILE__, __LINE__)
#undef  realloc
#define realloc(PTR, SIZE)  vmemleak_realloc((PTR), (SIZE),   __FILE__, __LINE__)
#undef  free
#define free(PTR)           vmemleak_free   ((PTR),           __FILE__, __LINE__)

// ----------------------------------------------------------------------------
// macro for cpp
// ----------------------------------------------------------------------------
#ifdef __cplusplus

#undef  vmemleak_new
#define vmemleak_new new(__FILE__, __LINE__)
#undef  new
#define new vmemleak_new

#endif // __cplusplus

#endif // _DEBUG
