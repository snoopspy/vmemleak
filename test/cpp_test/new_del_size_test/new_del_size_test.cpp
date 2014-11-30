#include <stdio.h>
#include <stdlib.h>

class Obj
{
public:
	virtual ~Obj() {}
	char dummy[16];

	void* operator new[](size_t s)
	{
		void* res = malloc(s);
		printf("Obj::new[](s=%zu) > %p\n", s, res);
		return res;
	}
	void operator delete[](void* p)
	{
		printf("Obj::delete[](p=%p)\n", p);
		free(p);
	}
};

int main()
{
	Obj* obj = new Obj[1];
	printf("obj=%p\n", obj);
	delete[] obj;
}
