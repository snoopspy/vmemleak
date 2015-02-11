#include <stdlib.h>
#include <VMemLeak>

void malloc_test()
{
  void* p = malloc(4);
  free(p);
}

void calloc_test()
{
  void* p = calloc(256, 4);
  free(p);
}

void realloc_test()
{
  void* p = malloc(4);
  p = realloc(p, 4);
  free(p);

  p = malloc(4);
  p = realloc(p, 400000);
  free(p);
}

int main()
{
  malloc_test();
  calloc_test();
  realloc_test();
  return 0;
}
