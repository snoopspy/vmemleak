#include <stdio.h> // for printf

class Obj_0  {                                        };
class Obj_1  {                        char dummy[1];  };
class Obj_2  {                        char dummy[2];  };
class Obj_3  {                        char dummy[3];  };
class Obj_14  {                       char dummy[14]; };
class Obj_15  {                       char dummy[15]; };
class Obj_16  {                       char dummy[16]; };
class Obj_17  {                       char dummy[17]; };

class VObj_0  { virtual ~VObj_0()  {}                 };
class VObj_1  { virtual ~VObj_1()  {} char dummy[1];  };
class VObj_2  { virtual ~VObj_2()  {} char dummy[2];  };
class VObj_3  { virtual ~VObj_3()  {} char dummy[3];  };
class VObj_14 { virtual ~VObj_14() {} char dummy[14]; };
class VObj_15 { virtual ~VObj_15() {} char dummy[15]; };
class VObj_16 { virtual ~VObj_16() {} char dummy[16]; };
class VObj_17 { virtual ~VObj_17() {} char dummy[17]; };

int main()
{
	printf("Obj_0   %zu\n", sizeof(Obj_0));
	printf("Obj_1   %zu\n", sizeof(Obj_1));
	printf("Obj_2   %zu\n", sizeof(Obj_2));
	printf("Obj_3   %zu\n", sizeof(Obj_3));
	printf("Obj_14  %zu\n", sizeof(Obj_14));
	printf("Obj_15  %zu\n", sizeof(Obj_15));
	printf("Obj_16  %zu\n", sizeof(Obj_16));
	printf("Obj_17  %zu\n", sizeof(Obj_17));

	printf("VObj_0  %zu\n", sizeof(VObj_0));
	printf("VObj_1  %zu\n", sizeof(VObj_1));
	printf("VObj_2  %zu\n", sizeof(VObj_2));
	printf("VObj_3  %zu\n", sizeof(VObj_3));
	printf("VObj_14 %zu\n", sizeof(VObj_14));
	printf("VObj_15 %zu\n", sizeof(VObj_15));
	printf("VObj_16 %zu\n", sizeof(VObj_16));
	printf("VObj_17 %zu\n", sizeof(VObj_17));

	return 0;
}
