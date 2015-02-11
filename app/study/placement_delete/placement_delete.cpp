#include <stdio.h>  // printf
#include <stdlib.h> // malloc

class Obj
{
public:
  virtual ~Obj() // (A)
  {
    printf("Obj::~Obj()\n");
  }

  void* operator new(size_t size) // (B)
  {
    printf("Obj::new(size=%d)\n", (int)size);
    return malloc(size);
  }

  void operator delete(void* p) // (C)
  {
    printf("Obj::delete(p=%p)\n", p);
    free(p);
  }

  void operator delete(void* p, const char* file, const int line) // (D)
  {
    printf("Obj::delete(p=%p file=%s line=%d)\n", p, file, line);
    free(p);
  }
};

int main()
{
  Obj* obj1 = new Obj;                            // (B)
  delete obj1;                                    // (A), (C)

  Obj* obj2 = new Obj;                            // (B)
  obj2->~Obj();                                   // (A)
  Obj::operator delete(obj2, __FILE__, __LINE__); // (D)

  return 0;
}
