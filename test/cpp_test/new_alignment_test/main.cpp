#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

void dump(unsigned char* p, size_t size)
{
	size_t i;
	for (i = 0; i < size;)
	{
		printf("%02x ", *p++);
		i++;
		if (i % 16 == 0) printf("\n");
	}
	printf("\n");
}

int main()
{
	unsigned char* p;
	unsigned char* prev = NULL;
	size_t size;
	size_t i;

	prev = (unsigned char*)malloc(0);
	for (size = 0; size < 100; size++)
	{
		p = (unsigned char*)malloc(size);
		for (i = 0; i < size; i++) p[i] = 'A';
		printf("%p %zu %zu\n", p, size, p - prev);
		dump(p - 16, p - prev + 16);
		prev = p;
	}
	return 0;
}
