#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	system("color F0");

	setlocale(LC_ALL, "RUS");

	float x, y;

	char c;
	
	printf("Введите два числа и знак опреации ( +-/*^) \n");

	scanf_s("%f %c %f", &x, &c, 1, &y);

	switch (c)
	{
	case '+':
		printf("%g + %g = %g", x, y, x + y);
		break;

	case '-':
		printf("%g - %g = %g", x, y, x - y);
		break;

	case '*':
		printf("%g * %g = %g", x, y, x * y);
		break;

	case '/':
		printf("%g / %g = %g", x, y, x / y);
		break;

	case '^':
		printf("%g ^ %g = %g", x, y, pow(x, y));
		break;

	default:
		printf("Неизвестный оператор\n");

	}
	return 0;
}