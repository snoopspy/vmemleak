#include <stdio.h>
#include <stdlib.h>

class Obj
{
public:
	virtual ~Obj() {}

public:
	void* operator new(size_t size, const char* file, const int line) // new_3
	{
		printf("new_3(%zu, %s, %d)\n", size, file, line);
		return malloc(size);
	}

	void operator delete(void* p, size_t size) // delete_size
	{
		printf("new_3(%p, %zu)\n", p, size);
		free(p);
	}

	void operator delete(void* p, const char* file, const int line) // delete_3
	{
		printf("new_3(%p, %s, %d)\n", p, file, line);
		free(p);
	}
};


int main()
{
	Obj* obj = new (__FILE__, __LINE__) Obj;
	delete obj;
}
