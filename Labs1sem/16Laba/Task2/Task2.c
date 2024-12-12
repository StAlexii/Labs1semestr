#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

double* fille(double* ptr_array, int size) {
	for (int i = 0; i < size; i++)
		ptr_array[i] = ((double)rand() / RAND_MAX) * 2 - 1;
}

int printe(double* ptr_array, int size) {
	for (int i = 0; i < size; i++)
		printf("array[%d] = %f\n", i, ptr_array[i]);
}

int printe2(double* ptr_array, int size) {
	for (int i = 0; i < size; i++)
		if (ptr_array[i] != 9999999999)
			printf("array[%d] = %f\n", i, ptr_array[i]);
}

double* calce2(double* ptr_array, double* ptr_array2, int size, int k) {
	for (int i = 0; i < size; i++) {
		if ((i + 1) % k != 0)
			ptr_array2[i] = ptr_array[i];
		else if ((i + 1) % k == 0)
			ptr_array2[i] = 9999999999;
	}
}

double* calce3(double* ptr_array, double* ptr_array3, int size, int k) {
	for (int i = 0; i < size; i++) {
		if ((i + 1) % k != 0)
			ptr_array3[i] = ptr_array[i];
		else if ((i + 1) % k == 0)
			ptr_array3[i] = -999;
	}
}

void main() {
	setlocale(LC_ALL, "ru");
	system("color F0");

	srand(time(NULL));

	double* ptr_array;
	double* ptr_array2;
	double* ptr_array3;
	int size, k;

	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	printf("Каждый какой элемент удалить и на какое место ставить '-999'? (первый, второй, третий и т.д) ");
	scanf_s("%d", &k);

	ptr_array = (double*)malloc(size * sizeof(double));
	ptr_array2 = (double*)malloc(size * sizeof(double));
	ptr_array3 = (double*)malloc(size * sizeof(double));

	fille(ptr_array, size);
	printf("\nМассив до удалений:\n");
	printe(ptr_array, size);
	calce2(ptr_array, ptr_array2, size, k);
	printf("\nМассив после удалений:\n");
	printe2(ptr_array2, size);
	printf("\nМассив после вставок:\n");
	calce3(ptr_array, ptr_array3, size, k);
	printe(ptr_array3, size);

	free(ptr_array);
}