#include <stdio.h>
#include <locale.h>
int main() {
	system("color 17");
	setlocale(LC_ALL, "RUS");
	int N = 14, K = 34;
	printf("������� %d ����� %d ����� 00 ������\n", N, K);
	printf("��� %d ������ �����\n", N * 60 + K);
	printf("�� �������� �������� %d ����� � %d �����\n", 23 - N, 60 - K);
	printf("� 8.00 ������ %d ������\n", (13 - 8) * 3600 + K * 60);
	printf("������� ��� = %d/24 ����� � ������� ������ = %d/60 ����\n", N % 24, K % 60);
}