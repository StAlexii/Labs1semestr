#include <stdio.h>
#include <locale.h>
//m = 2, c = 3

int main() {

	setlocale(LC_ALL, "ru");
	system("color F0");

	int m = 1 + rand() % 10;

	int k;
	printf("������� ����� �� 1 �� 10: ");
	scanf_s("%d", &k);

	if (k == m)
		printf("�� ������� �����!\n");
	else
		printf("�� �� ������� �����.\n");

	int c = rand() % 3 + 1;
	int z;
	int fl = 0;

	
	do {

		printf("��������: \n������ = 1\n������� = 2\n������ = 3\n");
		scanf_s("%d", &z);

		switch (z) {

		case 1:
		{
			printf("��������� ������ ������, �� ���������, ���������� ��� ���.\n"); \
				break;
		}

		case 2:
		{
			printf("��������� ������ ������, �� ��������\n");
			fl = 1;
			break;
		}


		case 3:
		{
			printf("��������� ���� ������ ������, �����, ���������� ��� ���.\n");
			break;
		}

		}

	} while (fl != 1);
}