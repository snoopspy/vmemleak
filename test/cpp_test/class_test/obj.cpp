#include "obj.h"

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

Obj::Obj()
{
	printf("Obj::Obj()\n");
}

Obj::~Obj()
{
	printf("Obj::~Obj()\n");
}

void* Obj::operator new(size_t size)
{
	printf("Obj::operator new_1(%zu)\n", size);
	return malloc(size);
}

void* Obj::operator new(size_t size, const char* file)
{
	printf("Obj::operator new_2(%zu, %s)\n", size, file);
	return malloc(size);
}

void* Obj::operator new(size_t size, const char* file, const int line)
{
	printf("Obj::operator new_3(%zu, %s, %d)\n", size, file, line);
	return malloc(size);
}

void* Obj::operator new[](size_t size)
{
	printf("Obj::operator new[]_1(%zu)\n", size);
	return malloc(size);
}
void* Obj::operator new[](size_t size, const char* file)
{
	printf("Obj::operator new[]_2(%zu, %s)\n", size, file);
	return malloc(size);
}

void* Obj::operator new[](size_t size, const char* file, const int line)
{
	printf("Obj::operator new[]_3(%zu, %s, %d)\n", size, file, line);
	return malloc(size);
}

/*
void Obj::operator delete(void* p)
{
	printf("Obj::operator delete_1(%p)\n", p);
	free(p);
}
*/

void Obj::operator delete(void* p, size_t size)
{
	printf("Obj::operator delete_2(%p, %zu)\n", p, size);
	free(p);
}

void Obj::operator delete[](void* p)
{
	printf("Obj::operator delete[]_1(%p)\n", p);
	free(p);
}

void Obj::operator delete[](void* p, size_t size)
{
	printf("Obj::operator delete[]_2(%p, %zu)\n", p, size);
	free(p);
}
