#ifndef __VMLD_MGR_H__
#define __VMLD_MGR_H__

#include <stdbool.h> // bool

#ifdef __cplusplus
extern "C" {
#endif

void  vmld_mgr_start(bool del_check);
void  vmld_mgr_stop(void);
void* vmld_mgr_add(void* ptr, size_t size, const char* file, const int line);
bool  vmld_mgr_del(void* ptr);

#ifdef __cplusplus
}
#endif

#endif // __VMLD_MGR_H__
