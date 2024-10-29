#include <stdio.h>
#include <math.h>
#include <locale.h>
#define a 7.1 * pow(10, -9)
#define M_PI 3.14159265358979323846
// 0,000037

int main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");
	float x, y, res, z;
	printf("¬ведите значение x:\n");
	scanf_s("%f", &x);
	printf("¬ведите значение y:\n");
	scanf_s("%f", &y);

	res = (cos(pow(x, 3) + 6) - sin(y - a)) / (log(pow(x, 4)) - 2 * pow(sin(x), 5));
	
	printf("–езультат расчЄта: %f\n", res);

	return 0;//
	x = 0.71 * pow(10, -4)
}