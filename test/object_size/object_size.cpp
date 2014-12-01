#include <stddef.h> // size_t
#include <stdio.h>  // printf
#include <stdlib.h> // malloc

void* operator new(size_t size)   { printf("new(size=%zu)\n", size);   return malloc(size); }
void* operator new[](size_t size) { printf("new[](size=%zu)\n", size); return malloc(size); }

class Obj
{
public:
	char dummy[16];
};

class Obj_dtor
{
public:
	~Obj_dtor() {}
	char dummy[16];
};

class VObj_dtor
{
public:
	virtual ~VObj_dtor() {}
	char dummy[16];
};


int main()
{
	delete new Obj;             // 16
	delete[] new Obj[10];       // 160

	delete new Obj_dtor;        // 16
	delete[] new Obj_dtor[10];  // 168

	delete new VObj_dtor;       // 24
	delete[] new VObj_dtor[10]; // 248
	return 0;
}
