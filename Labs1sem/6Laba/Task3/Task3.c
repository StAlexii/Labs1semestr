#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int n, n1, n2, n3;
	printf("Введите число N, N < 1000\n");
	scanf_s("%d", &n);
	n1 = n / 100;
	n2 = (n / 10) % 10;
	n3 = n % 10;
	if ((abs(n1 + n2 + n3) % 3 == 0) && n < 1000)
		printf("\nСумма цифр(%d) числа %d кратна трём.\n", n1 + n2 + n3, n);
	else if ((abs(n1 + n2 + n3) % 3 != 0) && n < 1000)
		printf("\nСумма цифр(%d) числа %d не кратна трём\n.", n1 + n2 + n3, n);
	else
		printf("Число %d не входит в диапазон N < 1000", n);

}