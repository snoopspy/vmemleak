#include <stdio.h>

#include "obj.h"

#define ARRAY 2

//::(optional) new (placement_params)(optional) ( type ) initializer(optional)
//::(optional) new (placement_params)(optional) type initializer(optional)
void direct_new_test()
{
	new Obj;                      // new_1
	new () Obj;                   // new_1
	new (__FILE__) Obj;           // new_2
	new (__FILE__, __LINE__) Obj; // new_3

	new Obj[ARRAY];                      // new[]_1
	new () Obj[ARRAY];                   // new[]_1
	new (__FILE__) Obj[ARRAY];           // new[]_2
	new (__FILE__, __LINE__) Obj[ARRAY]; // new[]_3
}

void define_new_test()
{
#undef new
	new Obj;        // new_1
	new Obj[ARRAY]; // new[]_1

#undef new
#define new new ()
	new Obj;        // new_1
	new Obj[ARRAY]; // new[]_1

#undef  new
#define new new (__FILE__)
	new Obj;        // new_2
	new Obj[ARRAY]; // new[]_2

#undef  new
#define new new (__FILE__, __LINE__)
	new Obj;        // new_3
	new Obj[ARRAY]; // new[]_3
}

//::(optional)    delete    expression
//::(optional)    delete [] expression
void delete_test()
{
	Obj* obj = new Obj;
	delete obj;         // delete_1

	//Obj* obj2 = new Obj[2];
	//delete[] obj2;      // delete[]_1
}

int main()
{
	//printf("direct_new_test()\n"); direct_new_test();
	// printf("define_new_test()\n"); define_new_test();
	printf("delete_test()\n"); delete_test();
}
