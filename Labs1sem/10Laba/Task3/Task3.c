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
	printf("Выберите одну из опций:\n");
	printf(" 1 - расчёт площади фигуры \n 2 - определение фигуры \n 3 - нарисовать фигуру \n");
	scanf_s("%d", &fl);
	switch (fl) {
	case 1:
		if (flag == 0) {
			printf("Введите сторону параллелограмма:\n");
			scanf_s("%d", &a);
			printf("Введите высоту параллелограмма:\n");
			scanf_s("%d", &h);
			flag = 1;
		}
		printf("Площадь параллелограмма равна: %d", paral_round(a, h));
		break;
	case 2:
		printf("\nПараллелограмм — это четырёхугольник, у которого противоположные стороны попарно параллельны.\n");
		break;
	case 3:
		printf("Введите символ для рисования\n");
		getchar();
		scanf_s("%c", &c);
		if (flag == 0) {
			printf("Введите сторону параллелограмма:\n");
			scanf_s("%d", &a);
			printf("Введите высоту параллелограмма:\n");
			scanf_s("%d", &h);
			flag = 1;
		}
		printf("Введите угол параллелограмма:\n");
		scanf_s("%d", &aa);
		printf("\n");
		pain_paral(c, h, a, aa);

	}
	printf("\nЗапустить программу заново? (Y/N)\n");
	getchar();
	scanf_s("%c", &choice);
	} while (choice == 'y' || choice == 'Y');

}