#include <stdio.h>
#include <stdlib.h>

class Obj_p
{
	char dummy[16];
public:
	void* operator new(size_t size)
	{
		printf("Obj_p::new_s(%zu)\n", size);
		return malloc(size);
	}

	void operator delete(void* ptr)
	{
		printf("Obj_p::delete_p(%p)\n", ptr);
		free(ptr);
	}
};

class Obj_ps
{
	char dummy[16];
public:
	void* operator new(size_t size)
	{
		printf("Obj_ps::new_s(%zu)\n", size);
		return malloc(size);
	}

	void operator delete(void* ptr, size_t size)
	{
		printf("Obj_ps::delete_ps(%p, %zu)\n", ptr, size);
		free(ptr);
	}
};

class Obj_both
{
	char dummy[16];
public:
	~Obj_both() {}
	void* operator new(size_t size)
	{
		printf("Obj_both::new_s(%zu)\n", size);
		return malloc(size);
	}

	void* operator new[](size_t size)
	{
		printf("Obj_both::new_s[](%zu)\n", size);
		return malloc(size);
	}

	void operator delete(void* ptr)
	{
		printf("Obj_both::delete_p(%p)\n", ptr);
		free(ptr);
	}

	void operator delete(void* ptr, size_t size)
	{
		printf("Obj_both::delete_ps(%p, %zu)\n", ptr, size);
		free(ptr);
	}

	void operator delete[](void* ptr)
	{
		printf("Obj_both::delete_p[](%p)\n", ptr);
		free(ptr);
	}

	void operator delete[](void* ptr, size_t size)
	{
		printf("Obj_both::delete_ps[](%p, %zu)\n", ptr, size);
		free(ptr);
	}
};


int main()
{
	//delete new Obj_p;
	//delete new Obj_ps;
	//delete new Obj_both;

	//delete[] new Obj_ps[2];
	delete[] new Obj_both[10];
}
