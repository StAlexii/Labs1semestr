#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int l = 7333, n = 3, k = 3, m = 1;
	float result = n/l;
	printf("������� 18\n\n");
	printf("����:\n\t %5d\n %13d\n", n, l);
	puts("        __________");
	printf("\n�����:\n\t+%05.1f", result); //0 � ��������� ������, ���� ���������� ������ ������, ��� �������. 5 � ����� ���������� �������� ��� ����� � ������� �����(������� �����). 1 � ���������� ������ ����� �������.


}