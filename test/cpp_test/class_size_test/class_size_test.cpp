#include <stdio.h> // for printf

class Obj_0   {                                       };
class Obj_1   {                       char dummy[1];  };
class Obj_2   {                       char dummy[2];  };
class Obj_3   {                       char dummy[3];  };
class Obj_15  {                       char dummy[15]; };
class Obj_16  {                       char dummy[16]; };
class Obj_17  {                       char dummy[17]; };
class Obj_18  {                       char dummy[18]; };

class VObj_0  { virtual ~VObj_0()  {}                 };
class VObj_1  { virtual ~VObj_1()  {} char dummy[1];  };
class VObj_2  { virtual ~VObj_2()  {} char dummy[2];  };
class VObj_3  { virtual ~VObj_3()  {} char dummy[3];  };
class VObj_15 { virtual ~VObj_15() {} char dummy[15]; };
class VObj_16 { virtual ~VObj_16() {} char dummy[16]; };
class VObj_17 { virtual ~VObj_17() {} char dummy[17]; };
class VObj_18 { virtual ~VObj_18() {} char dummy[18]; };

int main()
{
	printf("Obj_0   %zu\n", sizeof(Obj_0));   // 1
	printf("Obj_1   %zu\n", sizeof(Obj_1));   // 1
	printf("Obj_2   %zu\n", sizeof(Obj_2));   // 2
	printf("Obj_3   %zu\n", sizeof(Obj_3));   // 3
	printf("Obj_15  %zu\n", sizeof(Obj_15));  // 15
	printf("Obj_16  %zu\n", sizeof(Obj_16));  // 16
	printf("Obj_17  %zu\n", sizeof(Obj_17));  // 17
	printf("Obj_18  %zu\n", sizeof(Obj_18));  // 18

	printf("VObj_0  %zu\n", sizeof(VObj_0));  // 8
	printf("VObj_1  %zu\n", sizeof(VObj_1));  // 16
	printf("VObj_2  %zu\n", sizeof(VObj_2));  // 16
	printf("VObj_3  %zu\n", sizeof(VObj_3));  // 16
	printf("VObj_15 %zu\n", sizeof(VObj_15)); // 24
	printf("VObj_16 %zu\n", sizeof(VObj_16)); // 24
	printf("VObj_17 %zu\n", sizeof(VObj_17)); // 32
	printf("VObj_18 %zu\n", sizeof(VObj_18)); // 32

	return 0;
}
