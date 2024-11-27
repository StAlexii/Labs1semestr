#include <stdio.h>
#include <locale.h>

double* fille(double* ptr_array, int n)
{
	double z = 1;
	for (int i = 0; i < n; i++)

	{
		ptr_array[i] = (pow(z, 3) - 4 * pow(z, 2) + 2);
		z += 0.02;
	}

}

double* calce(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = -1 * (ptr_array[i]);
	}
	return ptr_array;
}

int printe(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("array[%d] = %f\n", i, ptr_array[i]);
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	system("color F0");

	double* ptr_array;
	int size;

	printf("¬ведите размер массива: ");
	scanf_s("%d", &size);

	double* fille(double* ptr_array, int size);
	double* calce(double* ptr_array, int size);
	int printe(double* ptr_array, int size);

	ptr_array = (double*)malloc(size * sizeof(double));

	if (ptr_array == NULL) {

		puts("error");

		return -1;

	}

	

	

}