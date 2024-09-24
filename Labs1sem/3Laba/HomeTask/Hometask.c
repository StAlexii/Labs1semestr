#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	puts("");
	puts("");
	puts("");
	system("color F0");
	setlocale(LC_ALL, "RUS");
	printf("  ¬ариант 18, поиск гипотенузы по сторонам треугольника\n\n");
	float a, b;
	double result;
	printf("  ¬ведите первую сторону треугольника:\n\t");
	scanf_s("%f", &a);
	printf("  ¬ведите вторую сторону треугольника:\n\t");
	scanf_s("%f", &b);
	result = sqrt((a * a) + (b * b));
	printf("  √ипотенуза равна: %g", result);
	puts("");
	puts("");
	puts("");

}