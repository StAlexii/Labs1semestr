#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int n;
	float x, res, k = 0;

	printf("¬ведите x\n");
	scanf_s("%f", &x);
	printf("¬ведите конечную степень\n");
	scanf_s("%d", &n);

	for (int i = 0; i <= n; i++) {
		res = cos(pow(x, i));
		k += res;
		printf("cos(%.2f)^%d = %.2f\n", x, i, res);
		
	}
	printf("—умма значений: %.2f", k);
}