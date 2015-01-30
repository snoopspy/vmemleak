#ifndef _DEBUG
extern "C" void vmld_mgr_start(void) {}
extern "C" void vmld_mgr_stop(void) {}
#endif // _DEBUG

#ifdef _DEBUG

#include <map>
#include <stdio.h>  // fprintf
#include "vmldmgr.h"

typedef struct
{
  size_t size;
	char* file;
	int line;
} vmld_mgr_item_t;

typedef std::map<void*, vmld_mgr_item_t> vmld_mgr_t;

static vmld_mgr_t _vmld_mgr;

extern "C" void vmld_mgr_start(void)
{
  _vmld_mgr.clear();
}

extern "C" void vmld_mgr_stop(void)
{
  if (_vmld_mgr.size() <= 0) return;
  fprintf(stderr, "******************************************************************************\n");
  for (vmld_mgr_t::iterator it = _vmld_mgr.begin(); it != _vmld_mgr.end(); it++)
  {
    void* ptr = it->first;
    vmld_mgr_item_t& item = it->second;
    fprintf(stderr, "memory leak %p(%d bytes) %s:%d\n", ptr, (int)item.size, item.file, item.line);
  }
  fprintf(stderr, "******************************************************************************\n");
}

extern "C" void* vmld_mgr_add(void* ptr, size_t size, const char* file, const int line)
{
  vmld_mgr_t::iterator it = _vmld_mgr.find(ptr);
  if (it != _vmld_mgr.end())
  {
    fprintf(stderr, "ptr(%p) is already added size=%d file=%s line=%d\n", ptr, (int)size, file, line);
    return NULL;
  }
  vmld_mgr_item_t item;
  item.size = size;
  item.file = (char*)file;
  item.line = line;
  _vmld_mgr[ptr] = item;
  return ptr;
}

extern "C" void vmld_mgr_del(void* ptr)
{
  if (ptr == NULL)
  {
    fprintf(stderr, "ptr is null\n");
    return;
  }
  vmld_mgr_t::iterator it = _vmld_mgr.find(ptr);
  if (it == _vmld_mgr.end()) return;
  _vmld_mgr.erase(it);
}

#endif // _DEBUG
