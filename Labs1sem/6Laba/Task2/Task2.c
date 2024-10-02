#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	float x;
	printf("введите значение x:\n");
	scanf_s("%f", &x);
	
	//if (x >= 3)
		//res = -pow(x, 2) - 3 * x + 9;
	//else
		//res = x / (pow(x, 3) - 6);

	printf("F(%f) = %f\n", x, (x >= 3) ? (-pow(x, 2) + 3 * x + 9) : (x / (pow(x, 3) - 6)));
       
		//при вводе x = 10, функция принимает значение -61

}