#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	char c;
	int i;
	float f;
	double d;
	puts("������� ������:");
	scanf_s("%c", &c);
	puts("������� ����� �����:");
	scanf_s("%d", &i);
	puts("������� ������������ �����:");
	scanf_s("%f", &f);
	puts("������� ������� ������������ �����");
	scanf_s("%g", &d);
	double ff = d * -1;
	printf("�� �����:\n ������: %c\n ����� �����: %d \n ������������ �����: %f \n Double: %e\n", c, i, f, ff);
	int intpf = (int)f;
	float ostat = f - intpf;
	printf(" ������� 1�. ����� �����: %d, ������� �����: %f\n", intpf, ostat);
	printf(" ������� 1�. ���������� ��� ������� %c: %d\n", c, c);
	printf(" ������� 1�. ����������������� ��� ������� %c: %x\n", c, c);
	float z = 1 / i;
	printf(" ������� 1�. ���������� �����, �������������� 1/%d: %f", i, z);


}