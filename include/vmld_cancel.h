#ifndef __VMLD_CANCEL_H__
#define __VMLD_CANCEL_H__

// ----------------------------------------------------------------------------
// macro for c
// ----------------------------------------------------------------------------
#undef malloc
#undef calloc
#undef realloc
#undef free

// ----------------------------------------------------------------------------
// macro for cpp
// ----------------------------------------------------------------------------
#ifdef __cplusplus

#undef vmld_new
#undef new

#endif // __cplusplus

#endif // __VMLD_H__
