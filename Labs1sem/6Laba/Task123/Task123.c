#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float x, y;

	system("color F0");

	setlocale(LC_ALL, "RUS");
	printf("введите значение x:\n");
	scanf_s("%f", &x);
	printf("введите значение y:\n");
	scanf_s("%f", &y);


	if ((x == 0) && (y <= 6 || y >= -6))
		printf("Точка внутри фигуры");
	else if ((x >= 0 && x <= 1) && (y <= 6 || y >= -5.5))
		printf("Точка внутри фигуры");
	else if ((x >= 1 && x <= 2) && (y <= 6 || y >= -5))
		printf("Точка внутри фигуры");
	else if ((x >= 2 && x <= 3) && (y <= 5.8 || y >= -4.5))
		printf("Точка внутри фигуры");
	else if ((x >= 3 && x <= 4) && (y <= 5.7 || y >= -4))
		printf("Точка внутри фигуры");
	else if ((x >= 4 && x <= 5) && (y <= 5.6 || y >= -3.5))
		printf("Точка внутри фигуры");
	else if ((x >= 5 && x <= 6) && (y <= 5.2 || y >= -3))
		printf("Точка внутри фигуры");
	else if ((x >= 6 && x <= 7) && (y <= 4.9 || y >= -2.5))
		printf("Точка внутри фигуры");
	else if ((x >= 7 && x <= 8) && (y <= 4.5 || y >= -2))
		printf("Точка внутри фигуры");
	else if ((x >= 8 && x <= 9) && (y <= 4 || y >= -1.5))
		printf("Точка внутри фигуры");
	else if ((x >= 9 && x <= 10) && (y <= 3.5 || y >= -1))
		printf("Точка внутри фигуры");
	else if ((x >= 10 && x <= 11) && (y <= 2.5 || y >= -0.5))
		printf("Точка внутри фигуры");
	else if ((x >= 11 && x <= 12) && (y == 0))
		printf("Точка внутри фигуры");
	else
		printf("Точка вне фигуры");

}