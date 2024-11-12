#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	system("color F0");
	int* pi, i = 5;

	float* pf, f = 2.1f;

	printf("%lu\n", sizeof(pi));

	printf("%lu\n", sizeof(pf));
}