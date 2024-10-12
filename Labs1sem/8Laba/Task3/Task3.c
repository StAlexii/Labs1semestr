#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	float func, z, a1, a2, x;
	printf("¬ведите шаг дл€ x\n");
	scanf_s("%f", &x);
	printf(" ________________________\n");
	char b = 'x', v = 'f';
	printf("| %-9c |%9c(x)|\n",b,v);
	printf("|___________|____________|\n");
	for (float i = 1; i <= 3.1; i += x) {
		printf("| %8.2f  |%12.2f|\n", i, pow(i, 3) - 4 * pow(i, 2) + 2);
		printf("|___________|____________|\n");
		
	}
}