#include <stdio.h>
#include <math.h>
#include <locale.h>
#define a 3
#define b 52
#define c 510
int main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");
	int if1 = ((a % 2 == 0) ^ (b % 2 == 0));
	int if2 = (a % 3 == 0) * (b % 3 == 0) * (c % 3 == 0);
	printf("������� 1: %d, 52 ������� �� 2, 3 �� �������.\n������� 2: %d, 52 �� ������� �� 3.\n\n\n", if1, if2);

}