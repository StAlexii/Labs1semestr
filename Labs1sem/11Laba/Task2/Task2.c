#include <stdio.h>
#include <locale.h>
#define N 100

int main() {
	system("color F0");
	setlocale(LC_ALL, "ru");

	double arr[N];
	double z = 1;
	int splus = 0, sump = 0, smin = 0;
	float f;
	for (int i = 0; i < N; i++) {
		f = (pow(z, 3) - 4 * pow(z, 2) + 2);
		arr[i] = f;
		z += 0.02;
		printf("Z = %f\n", z);
		printf("func = %f\n", f);
		printf("I = %d\n", i);
	}	
}

