#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int a = 11, b = 3, x;
	float y;
	double z;
	x = a / b;
	y = a / b;
	z = a / b;
	printf("Int x: %d, Float y: %f, Double z: %e\n\n", x, y, z);

	printf("a / b (float) = %.3f\n", (float)a / b);
	printf("a / b (double) = %.3f\n\n", (double)a / b);

	printf("(float)(a / b) = %3.f\n", (float)(a / b)); //даст результат 3.0, потому что сначала произойдет целочисленное деление.

}