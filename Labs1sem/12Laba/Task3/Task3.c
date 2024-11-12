#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	system("color F0");

	printf("int\n");
	int* pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%d\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%d\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%d\n", pa, *pa);

	printf("\n");
	printf("double\n");

	double* pa2, x2 = 5;
	pa2 = &x2;
	printf("По адресу %p хранится *ptr=%g\n", pa2, *pa2);
	pa2++;
	printf("По адресу %p хранится *ptr=%g\n", pa2, *pa2);
	pa2--;
	printf("По адресу %p хранится *ptr=%g\n", pa2, *pa2);

	printf("\n");
	printf("char\n");

	char* pa3, x3 = 5;
	pa3 = &x3;
	printf("По адресу %p хранится *ptr=%c\n", pa3, *pa3);
	pa3++;
	printf("По адресу %p хранится *ptr=%c\n", pa3, *pa3);
	pa3--;
	printf("По адресу %p хранится *ptr=%c\n", pa3, *pa3);


	printf("\n");
	printf("long double\n");

	long double* pa4, x4 = 5;
	pa4 = &x4;
	printf("По адресу %p хранится *ptr=%g\n", pa4, *pa4);
	pa4++;
	printf("По адресу %p хранится *ptr=%g\n", pa4, *pa4);
	pa4--;
	printf("По адресу %p хранится *ptr=%g\n", pa4, *pa4);

	printf("\n");
	printf("short unsigned int\n");

	short unsigned int* pa5, x5 = 5;
	pa5 = &x5;
	printf("По адресу %p хранится *ptr=%d\n", pa5, *pa5);
	pa5++;
	printf("По адресу %p хранится *ptr=%d\n", pa5, *pa5);
	pa5--;
	printf("По адресу %p хранится *ptr=%d\n", pa5, *pa5);

	printf("\n");
	printf("_Bool\n");

	_Bool* pa6, x6 = 5;
	pa6 = &x6;
	printf("По адресу %p хранится *ptr=%d\n", pa6, *pa6);
	pa6++;
	printf("По адресу %p хранится *ptr=%d\n", pa6, *pa6);
	pa6--;
	printf("По адресу %p хранится *ptr=%d\n", pa6, *pa6);



}