#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int num, a;
	puts("Введите число A");
	scanf_s("%d", &num);
	puts("Введите число B");
	scanf_s("%d", &a);
	printf("Введены числа: %d и %d\n", num, a);
	printf("Сумма чисел A + B: %d\n", num + a);
	printf("Разность чисел A - B: %d\n", num - a);
	printf("Произведение чисел A * B: %d\n", num * a);
	printf("остаток от деления второго числа B на число A: %d\n", a%num);
}