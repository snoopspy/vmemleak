#include <stdio.h> // for printf

struct { int i;                 } i_obj_0;
struct { int i; char dummy[1];  } i_obj_1;
struct { int i; char dummy[2];  } i_obj_2;
struct { int i; char dummy[3];  } i_obj_3;

struct { int i; char dummy[6];  } i_obj_6;
struct { int i; char dummy[7];  } i_obj_7;
struct { int i; char dummy[8];  } i_obj_8;
struct { int i; char dummy[9];  } i_obj_9;

struct { int i; char dummy[14]; } i_obj_14;
struct { int i; char dummy[15]; } i_obj_15;
struct { int i; char dummy[16]; } i_obj_16;
struct { int i; char dummy[17]; } i_obj_17;

struct { long long ll;                 } ll_obj_0;
struct { long long ll; char dummy[1];  } ll_obj_1;
struct { long long ll; char dummy[2];  } ll_obj_2;
struct { long long ll; char dummy[3];  } ll_obj_3;

struct { long long ll; char dummy[6];  } ll_obj_6;
struct { long long ll; char dummy[7];  } ll_obj_7;
struct { long long ll; char dummy[8];  } ll_obj_8;
struct { long long ll; char dummy[9];  } ll_obj_9;

struct { long long ll; char dummy[14]; } ll_obj_14;
struct { long long ll; char dummy[15]; } ll_obj_15;
struct { long long ll; char dummy[16]; } ll_obj_16;
struct { long long ll; char dummy[17]; } ll_obj_17;


int main()
{
	printf("i_obj_0   %zu\n", sizeof(i_obj_0));   // 1
	printf("i_obj_1   %zu\n", sizeof(i_obj_1));   // 1
	printf("i_obj_2   %zu\n", sizeof(i_obj_2));   // 1
	printf("i_obj_3   %zu\n", sizeof(i_obj_3));   // 1

	printf("i_obj_6   %zu\n", sizeof(i_obj_6));   // 1
	printf("i_obj_7   %zu\n", sizeof(i_obj_7));   // 1
	printf("i_obj_8   %zu\n", sizeof(i_obj_8));   // 1
	printf("i_obj_9   %zu\n", sizeof(i_obj_9));   // 1

	printf("i_obj_14  %zu\n", sizeof(i_obj_14));   // 1
	printf("i_obj_15  %zu\n", sizeof(i_obj_15));   // 1
	printf("i_obj_16  %zu\n", sizeof(i_obj_16));   // 1
	printf("i_obj_17  %zu\n", sizeof(i_obj_17));   // 1

	printf("ll_obj_0   %zu\n", sizeof(ll_obj_0));   // 1
	printf("ll_obj_1   %zu\n", sizeof(ll_obj_1));   // 1
	printf("ll_obj_2   %zu\n", sizeof(ll_obj_2));   // 1
	printf("ll_obj_3   %zu\n", sizeof(ll_obj_3));   // 1

	printf("ll_obj_6   %zu\n", sizeof(ll_obj_6));   // 1
	printf("ll_obj_7   %zu\n", sizeof(ll_obj_7));   // 1
	printf("ll_obj_8   %zu\n", sizeof(ll_obj_8));   // 1
	printf("ll_obj_9   %zu\n", sizeof(ll_obj_9));   // 1

	printf("ll_obj_14  %zu\n", sizeof(ll_obj_14));   // 1
	printf("ll_obj_15  %zu\n", sizeof(ll_obj_15));   // 1
	printf("ll_obj_16  %zu\n", sizeof(ll_obj_16));   // 1
	printf("ll_obj_17  %zu\n", sizeof(ll_obj_17));   // 1
	return 0;
}
