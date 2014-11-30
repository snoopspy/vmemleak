# VDream Memory Leak Detector version 9.1

## How to use
  * include "vmld.h"
  * link vmld.c, vmldmgr.c in your project.

## Example
```cpp
#include "vmld.h"
int main()
{
    void* p = malloc(256);
    free p;
}
```

