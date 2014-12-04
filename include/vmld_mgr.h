#ifndef __VMLD_MGR_H__
#define __VMLD_MGR_H__

#include <stdbool.h> // bool

void vmld_mgr_start(bool del_check);
void vmld_mgr_stop(bool auto_free);

#endif // __VMLD_MGR_H__

