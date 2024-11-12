#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 100

int main() {
	system("color F0");
	setlocale(LC_ALL, "ru");
	float sminus = 0;
	int cntm = 0, cntp = 0, chet = 0, srr = 0;
	double arr[N];
	double z = 1;
	float splus = 0, sump = 0, smin = 0, sred = 0;
	float f;
	for (int i = 0; i < N; i++) {
		f = (pow(z, 3) - 4 * pow(z, 2) + 2);
		arr[i] = f;
		if (f > 0) {
			splus += f;
			cntp++;
		}

		else {
			sminus += f;
			cntm++;
		}

		if ((chet % 2 == 0) && (chet != 0)) {
			sred += f;
			srr++;
		}

		chet++;
		z += 0.02;
	}	
	for (int i = 0; i < N; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	printf("Имя массива: arr[N]\n");
	printf("Сумма положительных: %f\n", splus);
	printf("Сумма отрицытельных: %f\n", sminus);
	printf("Количество отрицательных: %d\n", cntm);
	printf("Количество положительных: %d\n", cntp);
	printf("Среднее положительных: %f\n", splus / 100);
	printf("Среднее отрицытельных: %f\n", sminus / 100);
	printf("Среднее значение элементов порядковые номера, которых четные (за исключением нулевого): %f", sred / srr);
	
}

