#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int year;
	printf("������� ��� ��� �������� �� ������������:\n");
	scanf_s("%d", &year);
	if ((year % 4 == 0) * (year % 100 != 0))
		printf("��� %d ����������", year);
	else if (year % 400 == 0)
		printf("��� %d ����������", year);
	else
		printf("��� �� ����������");

}