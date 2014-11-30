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
	size_t diff;

	prev = new unsigned char(0);
	for (size = 0; size < 100; size++)
	{
		p = new unsigned char(size);
		for (i = 0; i < size; i++) p[i] = 'A';
		diff = p - prev;
		printf("%p %zu %zu\n", p, size, p - prev);
		dump(prev, diff * 2);
		prev = p;
	}
	return 0;
}
