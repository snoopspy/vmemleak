#include <stdlib.h>
#include <VMemLeak>
#include <VMemLeakMgr>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#endif // __GNUC__

void malloc_test()
{
  vmemleak_mgr_start();
  malloc(256);
  vmemleak_mgr_stop();
}

void calloc_test()
{
  vmemleak_mgr_start();
  calloc(4, 256);
  vmemleak_mgr_stop();
}

void realloc_test()
{
  void *p;

  vmemleak_mgr_start();
  p = malloc(4);
  realloc(p, 4);
  vmemleak_mgr_stop();

  vmemleak_mgr_start();
  p = malloc(4);
  realloc(p, 400000);
  vmemleak_mgr_stop();
}

int main()
{
  malloc_test();
  calloc_test();
  realloc_test();
  return 0;
}
