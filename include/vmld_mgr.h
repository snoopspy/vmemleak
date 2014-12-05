#ifndef __VMLD_MGR_H__
#define __VMLD_MGR_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
  #include <stddef.h> // size_t
#endif // __GNUC__

void  vmld_mgr_start(void);
void  vmld_mgr_stop(void);
void* vmld_mgr_add(void* ptr, size_t size, const char* file, const int line);
void  vmld_mgr_del(void* ptr);

#ifdef __cplusplus
}
#endif


#endif // __VMLD_MGR_H__
