#ifndef __VMLD_MGR_H__
#define __VMLD_MGR_H__

#include <stdbool.h> // bool

void vmld_mgr_start(bool del_check);
void vmld_mgr_stop(bool auto_free);

bool vmld_mgr_add(void* ptr, size_t size, const char* file, const int line);
bool vmld_mgr_del(void* ptr);

#endif // __VMLD_MGR_H__

