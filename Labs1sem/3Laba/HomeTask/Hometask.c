#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	puts("");
	puts("");
	puts("");
	system("color F0");
	setlocale(LC_ALL, "RUS");
	printf("  ������� 18, ����� ���������� �� �������� ������������\n\n");
	int a, b;
	double result;
	printf("  ������� ������ ������� ������������:\n\t");
	scanf_s("%d", &a);
	printf("  ������� ������ ������� ������������:\n\t");
	scanf_s("%d", &b);
	result = sqrt((a * a) + (b * b));
	printf("  ���������� �����: %g", result);
	puts("");
	puts("");
	puts("");

}