#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

class Obj_0
{
public:
	void* operator new(size_t size)              { printf("Obj_0::new %zu\n", size); return malloc(size); }
	void* operator new[](size_t size)            { printf("Obj_0::new %zu\n", size); return malloc(size); }
	void operator delete(void* p, size_t size)   { printf("Obj_0::delete(%p, %zu)\n", p, size); free(p); }
	void operator delete[](void* p, size_t size) { printf("Obj_0::delete(%p, %zu)\n", p, size); free(p); }
};

class Obj_1
{
public:
	char dummy[1];
	void* operator new(size_t size)              { printf("Obj_1::new %zu\n", size); return malloc(size); }
	void* operator new[](size_t size)            { printf("Obj_1::new %zu\n", size); return malloc(size); }
	void operator delete(void* p, size_t size)   { printf("Obj_1::delete(%p, %zu)\n", p, size); free(p); }
	void operator delete[](void* p, size_t size) { printf("Obj_1::delete(%p, %zu)\n", p, size); free(p); }
};

class Obj_2
{
public:
	char dummy[2];
	void* operator new(size_t size)              { printf("Obj_2::new %zu\n", size); return malloc(size); }
	void* operator new[](size_t size)            { printf("Obj_2::new %zu\n", size); return malloc(size); }
	void operator delete(void* p, size_t size)   { printf("Obj_2::delete(%p, %zu)\n", p, size); free(p); }
	void operator delete[](void* p, size_t size) { printf("Obj_2::delete(%p, %zu)\n", p, size); free(p); }
};

class Obj_3
{
public:
	//virtual ~Obj_3() {}
	char dummy[16];
	void* operator new(size_t size)              { printf("Obj_3::new %zu\n", size); return malloc(size); }
	void* operator new[](size_t size)            { printf("Obj_3::new %zu\n", size); return malloc(size); }
	void operator delete(void* p, size_t size)   { printf("Obj_3::delete(%p, %zu)\n", p, size); free(p); }
	//void operator delete[](void* p) { printf("Obj_3::delete(%p)\n", p); free(p); }
	void operator delete[](void* p, size_t size) { printf("Obj_3::delete(%p, %zu)\n", p, size); free(p); }
};

int main()
{
	delete[] new Obj_0[2];
	delete[] new Obj_1[2];
	delete[] new Obj_2[2];
	delete[] new Obj_3[2];


	return 0;
}
