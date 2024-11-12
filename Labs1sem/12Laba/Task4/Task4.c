#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	system("color F0");

	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11.11 };

	float* ptr_a;

	printf("%p, %p, %p\n", array, &array[0], &array);
	ptr_a = &array[0];
	printf("ptr_a[0]: %f\n", *ptr_a);
	ptr_a++;
	printf("ptr_a ++: %f\n", *ptr_a);
	ptr_a + 4;
	printf("ptr_a+4: %f\n", *ptr_a);
	ptr_a - 2;
	printf("ptr_a-2: %f\n", *ptr_a);

	printf("\n");

	ptr_a = &array[0]; //4.3
	for (int i = 0; i < 10; i += 2) {
		printf("Ёлемент %d = %f\n",i, *ptr_a);
		ptr_a += 2;
	}

	printf("\n");

	ptr_a = &array[9]; //4.4
	for (int i = 10; i > 0; i--) {
		printf("Ёлемент %d = %f\n", i, *ptr_a);
		ptr_a--;
	}

}