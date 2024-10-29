#include <stdio.h>
#include <locale.h>


int main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");

	int h, a, z, k = 6, aa, ff = 1, k2 = 0;
	char c;
	// * 3 4 40
	printf("Введите символ для рисования\n");
	scanf_s("%c", &c);
	printf("Введите сторону хуёмбоида:\n");
	scanf_s("%d", &a);
	printf("Введите вторую сторону хуёмбоида:\n");
	scanf_s("%d", &h);
	printf("Идите нахуй(угол?):\n");
	scanf_s("%d", &aa);

	int zz = (a + h);

	printf("\n");

	if ((aa > 0) && (aa <= 45)) {

		for (int i = 1; i < (a+h); i++) {

			for (int z = k; z > 0; z--)
				printf(" ");   


			for (int g = 0; g < ff; g++)
				printf("%c", c);

			printf("\n");
			k -= 1;
			ff += 2;

		}

		printf("\n");

}

