#include <stdio.h>
#include <math.h>
#include <locale.h>
#define p 3

int main() {
	float x, a, b, y;
	system("color F0");
	setlocale(LC_ALL, "RUS");
	printf("������� �������� x:\n");
	scanf_s("%f", &x);
	a = sqrt(p * x);
	b = p * (x * x) + sqrt(a);
	y = pow(log(pow(b, 2)), 3) + a * x;
	printf("�������� �������� x: %.1f\n ���������� �������� a: %.1f\n ���������� �������� b: %.1f\n ���������� �������� y: %.1f", x, a, b, y);

}