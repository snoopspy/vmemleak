#include <stdio.h>
#include <stdlib.h>

class Obj
{
public:
	char dummy[16];
	void* operator new(size_t s)   { printf("Obj::new        (s=%zu)\n", s); return malloc(s); }
	void* operator new[](size_t s) { printf("Obj::new[]      (s=%zu)\n", s); return malloc(s); }
};

class Obj_dtor
{
public:
	~Obj_dtor() {}
	char dummy[16];
	void* operator new(size_t s)   { printf("Obj_dtor::new   (s=%zu)\n", s); return malloc(s); }
	void* operator new[](size_t s) { printf("Obj_dtor::new[] (s=%zu)\n", s); return malloc(s); }
};

class Obj_vdtor
{
public:
	virtual ~Obj_vdtor() {}
	char dummy[16];
	void* operator new(size_t s)   { printf("Obj_vdtor::new  (s=%zu)\n", s); return malloc(s); }
	void* operator new[](size_t s) { printf("Obj_vdtor::new[](s=%zu)\n", s); return malloc(s); }
};


int main()
{
	delete new Obj;             // 16
	delete[] new Obj[10];       // 160

	delete new Obj_dtor;        // 16
	delete[] new Obj_dtor[10];  // 168

	delete new Obj_vdtor;       // 24
	delete[] new Obj_vdtor[10]; // 248
}
