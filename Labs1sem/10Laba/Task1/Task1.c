#include <stdio.h>
#include <locale.h>
#include <math.h>

float f1(float x) {
	float y;
	if (x <= 3)
		y = pow(x, 2) - 3 * x + 9;
	else
		y = 1 / (pow(x, 3) + 3);
	return y;
}

float f2(float x) {
	float y, h1, h2, h3;
	h1 = x * x;
	h2 = sin(h1);
	h3 = exp(h2);
	y = x * h3;
	return y;
}

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");

	float x, g1, g2, g3, g4, g5;
	printf("������� x\n");
	scanf_s("%f", &x);
	
	g1 = f1(x);
	g2 = f2(x);
	g3 = g1 * g2; //������������
	g4 = abs(pow(g1, 2) - pow(g2, 2)); //���� ��� ������
	g5 = (g1 + g2) * 2; //��� ��� ����
	printf("����������\n ������� 1: %f\n ������� 2: %f\n ������������ �������� �������: %f\n �������� ��������� �������� �������: %f\n ��������� ����� �������� �������: %f\n", g1, g2, g3, g4, g5);
}