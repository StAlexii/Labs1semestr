#include<stdio.h>
#include<locale.h>
#include<math.h>
//50 3
#define N 100;

double* fille(double* ptr_array, int n);
int pute(double* ptr_array, int n);
double* calce(double* ptr_array, int n);


void main()
{
	setlocale(LC_ALL, "RUS");

	system("color F0");

	double array[1024];
	int size;

	int ff2;

	printf("Введите размер массива - ");
	scanf_s("%d", &size);

	printf("Введите чему кратны элементы - ");
	scanf_s("%d", &ff2);
	//printf("FF = %d", ff2);
	fille(array, size);
	calce(array, size);
	pute(array, size);
	int min_index = find_min_index(array, size, ff2);

	printf("Минимальный элемент, кратный %d, находится по индексу %d и равен %.2f\n", ff2, min_index, array[min_index]);
}

double* fille(double* ptr_array, int n)
{
	double z = 1;
	for (int i = 0; i < n; i++)

	{
		ptr_array[i] = (pow(z, 3) - 4 * pow(z, 2) + 2);
		z += 0.02;
	}

}


int pute(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("array[%d] = %f\n", i, ptr_array[i]);
	}
}

double* calce(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = -1 * (ptr_array[i]);
	}
	return ptr_array;
}

int find_min_index(double* ptr_array, int n, int k) {
	int min_index = -1;
	double min_value = 999999.9;
	int ff = k;

	for (int i = 0; i < n; i++) {
		if ((int)ptr_array[i] % ff == 0) {
			if (ptr_array[i] < min_value) {
				min_value = ptr_array[i];
				min_index = i;
			}
		}
	}
	return min_index;
}