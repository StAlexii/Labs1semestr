#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	char c;
	int i;
	float f;
	double d;
	puts("Введите символ:");
	scanf_s("%c", &c);
	puts("Введите целое число:");
	scanf_s("%d", &i);
	puts("Введите вещественное число:");
	scanf_s("%f", &f);
	puts("Введите большое вещественное число");
	scanf_s("%g", &d);
	double ff = d * -1;
	printf("Вы ввели:\n Символ: %c\n Целое число: %d \n Вещественное число: %f \n Double: %e\n", c, i, f, ff);
	int intpf = (int)f;
	float ostat = f - intpf;
	printf(" Задание 1а. Целая часть: %d, дробная часть: %f\n", intpf, ostat);
	printf(" Задание 1б. Десятичный код символа %c: %d\n", c, c);
	printf(" Задание 1б. Шестнадцатеричный код символа %c: %x\n", c, c);
	float z = 1 / i;
	printf(" Задание 1в. Десятичное число, соотвествующее 1/%d: %f", i, z);


}