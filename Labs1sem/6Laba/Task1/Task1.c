#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int year;
	printf("Введите год для проверки на високосность:\n");
	scanf_s("%d", &year);
	if ((year % 4 == 0) * (year % 100 != 0))
		printf("Год %d високосный", year);
	else if (year % 400 == 0)
		printf("Год %d високосный", year);
	else
		printf("Год не високосный");

}