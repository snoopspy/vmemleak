#include <stddef.h> // size_t
#include <stdio.h>  // printf
#include <stdlib.h> // malloc

class Obj_p
{
public:
	void operator delete(void* p) // (A)
	{
		printf("Obj_p::delete(p=%p)\n", p);
		free(p);
	}
};

class Obj_ps
{
public:
	void operator delete(void* p, size_t size) // (B)
	{
		printf("Obj_ps::delete[](p=%p size=%d)\n", p, (int)size);
		free(p);
	}
};

class Obj_both
{
public:
	void operator delete(void* p) // (A)
	{
		printf("Obj_both::delete(p=%p)\n", p);
		free(p);
	}

	void operator delete(void* p, size_t size) // (B)
	{
		printf("Obj_both::delete[](p=%p size=%d)\n", p, (int)size);
		free(p);
	}
};

int main()
{
	delete new Obj_p;    // (A)
	delete new Obj_ps;   // (B)
	delete new Obj_both; // (A)
}
