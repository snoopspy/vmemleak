#include <stdio.h>  // printf
#include <stdlib.h> // malloc

class Obj
{
public:
  void* operator new(size_t size) // (A)
  {
    printf("Obj::new(size=%d)\n", (int)size);
    return malloc(size);
  }

  void* operator new(size_t size, const char* file) // (B)
  {
    printf("Obj::new(size=%d file=%s)\n", (int)size, file);
    return malloc(size);
  }

  void* operator new(size_t size, const char* file, const int line) // (C)
  {
    printf("Obj::new(size=%d file=%s line=%d)\n", (int)size, file, line);
    return malloc(size);
  }

  void operator delete(void* p)
  {
    printf("Obj::delete(p=%p)\n", p);
    free(p);
  }
};

int main()
{
  new Obj;                     // (A)
  new(__FILE__) Obj;           // (B)
  new(__FILE__, __LINE__) Obj; // (C)

  return 0;
}
