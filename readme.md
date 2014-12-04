# VDream Memory Leak Detector version 9.1

## How to use
  * Include "vmld.h" where malloc, calloc, realloc, free, new and delete are used.

```cpp
[test.cpp]
#include <vmdl.h>

void foo()
{
  malloc(4);
  calloc(256, 4);
  ...
  new int;
  new int[256];
  ...
}
```

  * Call vmld_mgr_start() to start memory leak detection and call vmld_mgr_stop() to stop memory leak detection.

```cpp
[main.cpp]
#include <vmld_hdr.h>

int main()
{
  vmld_mgr_start();
  ...
  vmld_mgr_stop();
}
```
  * If compiler error occurs when other header file is included, include "vmld_cancel.h" before the header file.

```cpp
#include <vmld.h>
...
... memory leak detection
...

#include <vmld_cancel.h>
#include <list>
...
... no memory leak detection
...

#include <vmld.h>
...
... memory leak detection
...
```
