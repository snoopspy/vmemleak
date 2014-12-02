#include <stdio.h>  // printf
#include <stdlib.h> // malloc

class Obj
{
public:
	void* operator new(size_t size) // (A)
	{
		printf("Obj::new(size=%zu)\n", size);
		return malloc(size);
	}

	void* operator new(size_t size, const char* file) // (B)
	{
		printf("Obj::new(size=%zu file=%s)\n", size, file);
		return malloc(size);
	}

	void* operator new(size_t size, const char* file, const int line) // (C)
	{
		printf("Obj::new(size=%zu file=%s line=%d)\n", size, file, line);
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
	// new() Obj;                   // (A) // gilgil temp 2014.12.02
	new(__FILE__) Obj;           // (B)
	new(__FILE__, __LINE__) Obj; // (C)

	return 0;
}
