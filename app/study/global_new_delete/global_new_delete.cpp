#include <new>      // std::bad_alloc
#include <stddef.h> // size_t
#include <stdio.h>  // printf
#include <stdlib.h> // malloc

void* operator new(size_t size)
{
	printf("new(size=%zu)\n", size);
	// ::operator new(size); // stack overflow
	return malloc(size);
}

void* operator new[](size_t size)
{
	printf("new[](size=%zu)\n", size);
	// ::operator new[](size); // stack overflow
	return malloc(size);
}

void operator delete(void* p)
{
	printf("delete(p=%p)\n", p);
	// ::operator delete(p); // stack overflow
	free(p);
}

void operator delete[](void* p)
{
	printf("delete[](p=%p)\n", p);
	// ::operator delete[](p); // stack overflow
	free(p);
}

int main()
{
	delete new int;
	delete[] new int[10];
	return 0;
}
