#include <stdio.h>
#include <math.h>
#include <locale.h>
int paral_round(int a, int h) {
	int s;
	s = a * h;
	return s;
}
int pain_paral(char c, int h, int a, int aa) {
	int k = 0;
	if ((aa > 0) && (aa <= 45)) {

		for (int i = 1; i < h; i++) {


			for (int j = 1; j < a; j++) {
				printf("%c", c);
			}

			printf("%c", c);

			printf("\n");

			k += 2;

			for (int z = 0; z < k; z++) {
				printf(" ");
			}

		}

	}

	else if ((aa > 45) && (aa <= 90)) {

		for (int i = 1; i < h; i++) {


			for (int j = 1; j < a; j++) {
				printf("%c", c);
			}

			printf("%c", c);

			printf("\n");

			k++;

			for (int z = 0; z < k; z++) {
				printf(" ");
			}

		}

	}

	for (int i = 1; i < a; i++)
		printf("%c", c);
	printf("%c", c);
}

int main() {
	char choice;
	do {
	int fl, s, flag = 0;;
	int h, a, z, k = 0, aa;
	char c;
	setlocale(LC_ALL, "RUS");
	system("color F0");
	printf("�������� ���� �� �����:\n");
	printf(" 1 - ������ ������� ������ \n 2 - ����������� ������ \n 3 - ���������� ������ \n");
	scanf_s("%d", &fl);
	switch (fl) {
	case 1:
		if (flag == 0) {
			printf("������� ������� ���������������:\n");
			scanf_s("%d", &a);
			printf("������� ������ ���������������:\n");
			scanf_s("%d", &h);
			flag = 1;
		}
		printf("������� ��������������� �����: %d", paral_round(a, h));
		break;
	case 2:
		printf("\n�������������� � ��� ��������������, � �������� ��������������� ������� ������� �����������.\n");
		break;
	case 3:
		printf("������� ������ ��� ���������\n");
		getchar();
		scanf_s("%c", &c);
		if (flag == 0) {
			printf("������� ������� ���������������:\n");
			scanf_s("%d", &a);
			printf("������� ������ ���������������:\n");
			scanf_s("%d", &h);
			flag = 1;
		}
		printf("������� ���� ���������������:\n");
		scanf_s("%d", &aa);
		printf("\n");
		pain_paral(c, h, a, aa);

	}
	printf("\n��������� ��������� ������? (Y/N)\n");
	getchar();
	scanf_s("%c", &choice);
	} while (choice == 'y' || choice == 'Y');

}