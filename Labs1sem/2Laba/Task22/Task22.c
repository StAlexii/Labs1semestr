#include <stdio.h>
#include <locale.h>
int main() {
	system("color 17");
	setlocale(LC_ALL, "RUS");
	int N = 14, K = 34;
	printf("«Сейчас %d часов %d минут 00 секунд»\n", N, K);
	printf("Идёт %d минута суток\n", N * 60 + K);
	printf("До полуночи осталось %d часов и %d минут\n", 23 - N, 60 - K);
	printf("С 8.00 прошло %d секунд\n", (13 - 8) * 3600 + K * 60);
	printf("Текущий час = %d/24 суток и текущая минута = %d/60 часа\n", N % 24, K % 60);
}