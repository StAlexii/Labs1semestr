#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int x;
	char c;
	printf("������� ������\n");
	scanf_s("%c", &c);
	printf("������� ������� ��� ���������\n");
	scanf_s("%d", &x);

	for (x; x > 0; x -= 1)
		printf("%c\n", c);
}