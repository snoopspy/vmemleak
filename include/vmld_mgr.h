#ifndef __VMLD_MGR_H__
#define __VMLD_MGR_H__

#include <stdbool.h> // bool

typedef struct vmld_mgr vmld_mgr_t;

vmld_mgr_t* vmld_mgr_instance();
vmld_mgr_t* vmld_mgr_create();
void vmld_mgr_destroy(vmld_mgr_t* vmld_mgr);
void vmld_mgr_start(vmld_mgr_t* vmld_mgr, bool del_check, int count);
void vmld_mgr_stop(vmld_mgr_t* vmld_mgr, bool auto_free);

#endif // __VMLD_MGR_H__

