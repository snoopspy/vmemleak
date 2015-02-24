VDream Memory Leak Detector Library
===================================

# Setup
  * For Qt user
    * Open **libvmemleak.pro**, compile and build library files(*.a).
    * Include **vmemleak.pri** in your project file(*.pro).
  * For none Qt user
    * Add all files in src folder in your project.

# Use

  * Include **VMemLeakMgr**.
  * Call **vmemleak_mgr_start()** to start memory leak detection and call **vmemleak_mgr_stop()** to stop memory leak detection.

```cpp
[main.cpp]

#include <VMemLeakMgr>

int main()
{
  vmemleak_mgr_start();
  ...
  vmemleak_mgr_stop();
}
```

  * Include **VMemLeak** before malloc, calloc, realloc, free, new and delete are used.

```cpp
[test.cpp]

#include <VMemLeak>

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

  * If compiler error occurs where other header file is included, include **VMemLeakCancel** before the header file.

```cpp
[cancel.cpp]

#include <VMemLeak>
...
... memory leak detection
...

#include <VMemLeakCancel>
#include <list>
...
... no memory leak detection
...

#include <VMemLeak>
...
... memory leak detection
...
```

# Example

  * Run the [source code](app/exam/cpp_leak_test/cpp_leak_test.cpp) and you will get the following result.

```
    # ./cpp_leak_test 
    ******************************************************************************
    memory leak 0x1b3a010(4 bytes) cpp_leak_test.cpp:7
    ******************************************************************************
    ******************************************************************************
    memory leak 0x1b3a030(1024 bytes) cpp_leak_test.cpp:14
    ******************************************************************************
    #
```

# Supported Platforms
  * Linux / g++ 4.8.2
  * Windows / mingw 4.9.1
