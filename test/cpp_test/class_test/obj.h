#ifndef OBJ_H
#define OBJ_H

#include <stddef.h> // for size_t

class Obj
{
public:
	char dummy1;

public:
	Obj();
	virtual ~Obj();

public:
	static void* operator new(size_t size);										// new_1
	static void* operator new(size_t size, const char* file);                   // new_2
	static void* operator new(size_t size, const char* file, const int line);   // new_3

	static void* operator new[](size_t size);                                   // new[]_1
	static void* operator new[](size_t size, const char* file);                 // new[]_2
	static void* operator new[](size_t size, const char* file, const int line); // new[]_3

	//static void operator delete(void* p);                                       // delete_1
	static void operator delete(void* p, size_t size);                          // delete_2

	static void operator delete[](void* p);                                     // delete[]_1
	static void operator delete[](void* p, size_t size);                        // delete[]_2
};

#endif // OBJ_H
