#ifndef _DEBUG
extern "C" void vmemleak_mgr_start(void) {}
extern "C" void vmemleak_mgr_stop(void) {}
#endif // _DEBUG

#ifdef _DEBUG

#include <map>
#include <stdio.h>  // fprintf
#include "vmemleakmgr.h"

typedef struct
{
  size_t size;
  char* file;
  int line;
} vmemleak_mgr_item_t;

typedef std::map<void*, vmemleak_mgr_item_t> vmemleak_mgr_t;

static vmemleak_mgr_t _vmemleak_mgr;

extern "C" void vmemleak_mgr_start(void)
{
  _vmemleak_mgr.clear();
}

extern "C" void vmemleak_mgr_stop(void)
{
  if (_vmemleak_mgr.size() <= 0) return;
  fprintf(stderr, "******************************************************************************\n");
  for (vmemleak_mgr_t::iterator it = _vmemleak_mgr.begin(); it != _vmemleak_mgr.end(); it++)
  {
    void* ptr = it->first;
    vmemleak_mgr_item_t& item = it->second;
    fprintf(stderr, "memory leak %p(%d bytes) %s:%d\n", ptr, (int)item.size, item.file, item.line);
  }
  fprintf(stderr, "******************************************************************************\n");
}

extern "C" void* vmemleak_mgr_add(void* ptr, size_t size, const char* file, const int line)
{
  vmemleak_mgr_t::iterator it = _vmemleak_mgr.find(ptr);
  if (it != _vmemleak_mgr.end())
  {
    fprintf(stderr, "ptr(%p) is already added size=%d file=%s line=%d\n", ptr, (int)size, file, line);
    return NULL;
  }
  vmemleak_mgr_item_t item;
  item.size = size;
  item.file = (char*)file;
  item.line = line;
  _vmemleak_mgr[ptr] = item;
  return ptr;
}

extern "C" void vmemleak_mgr_del(void* ptr)
{
  if (ptr == NULL)
  {
    fprintf(stderr, "ptr is null\n");
    return;
  }
  vmemleak_mgr_t::iterator it = _vmemleak_mgr.find(ptr);
  if (it == _vmemleak_mgr.end()) return;
  _vmemleak_mgr.erase(it);
}

#endif // _DEBUG
