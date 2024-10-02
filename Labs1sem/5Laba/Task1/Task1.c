#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");
	float gr;
	printf("¬ведите величину угла:\n");
	scanf_s("%f", &gr);
	double radians = gr * M_PI / 180.0;
	double sinv = sin(radians);
	printf("\nsin(%.2f град) = %.6f\n\n\n\n", gr, sinv);

}