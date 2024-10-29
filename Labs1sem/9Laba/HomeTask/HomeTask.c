#include <stdio.h>
#include <locale.h>

//45 и 75!!!

int main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");

	int h, a, z, k = 0, aa;
	char c;

	printf("¬ведите символ дл€ рисовани€\n"); 
	scanf_s("%c", &c);
	printf("¬ведите сторону параллелограмма:\n");
	scanf_s("%d", &a);
	printf("¬ведите высоту параллелограмма:\n");
	scanf_s("%d", &h);
	printf("¬ведите угол параллелограмма:\n");
	scanf_s("%d", &aa);


	
	printf("\n");

	if ((aa > 0) && (aa <= 45)) {

		for (int i = 1; i < h; i++) {
		

			for (int j = -1; j < a; j++) {
				printf("*");
			}

			printf("%c", c);

			printf("\n");

			k+=2;

			for (int z = 0; z < k; z++) {
				printf(" ");
			}

		}

	}

	else if ((aa > 45) && (aa <= 90)) {

		for (int i = 1; i < h; i++) {
		

			for (int j = -1; j < a; j++) {
				printf("*");
			}

			printf("%c", c);

			printf("\n");

			k++;

			for (int z = 0; z < k; z++) {
				printf(" ");
			}

		}

	}


	for (int i = 0; i <= a; i++)
		printf("%c", c);
}

 