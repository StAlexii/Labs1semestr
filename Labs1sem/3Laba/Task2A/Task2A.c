#include <stdio.h>
#include <locale.h>
#define mm 0.001852
#define sm 1.609
#define rm 1.475
#define cm 7.468
#define gm 7412.6

int main() {
	setlocale(LC_ALL, "RUS");
	int dano;
	float res;
	puts("������� ���������� ���������� ��� �����������\n");
	scanf_s("%d", &dano);
	float result1 = mm * dano, result2 = sm * dano, result3 = rm * dano, result4 = cm * dano, result5 = gm * dano;
	printf("%d ������� ���� � ��� % .2f ����������\n", dano, result1);
	printf("%d ���������� ���� � ��� % .2f ����������\n", dano, result2);
	printf("%d ������� ���� � ��� % .2f ����������\n", dano, result3);
	printf("%d ������������ ���� � ��� % .2f ����������\n", dano, result4);
	printf("%d �������������� ���� � ��� % .2f ����������", dano, result5);

}