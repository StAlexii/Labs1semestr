#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int num, a;
	puts("������� ����� A");
	scanf_s("%d", &num);
	puts("������� ����� B");
	scanf_s("%d", &a);
	printf("������� �����: %d � %d\n", num, a);
	printf("����� ����� A + B: %d\n", num + a);
	printf("�������� ����� A - B: %d\n", num - a);
	printf("������������ ����� A * B: %d\n", num * a);
	printf("������� �� ������� ������� ����� B �� ����� A: %d\n", a%num);
}