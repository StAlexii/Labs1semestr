#include <stdio.h>
#include <locale.h>
#define ROW 9
#define COL 9

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int row, col;
	printf("\n");
	for (row = 1; row <= ROW; row++) {
		for (col = 1; col < COL; col++)
			printf("%5d", col * row);
			printf("\n");
	}

	printf("\n");

	int n = 9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%5d ", i * j);
		}
		printf("\n");
	}

	printf("\n");

	printf("; 5 5 5 5 5\n");

	int z = 3, j = 6;
	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= 6; j++) {
			printf("5 ");
		}
		printf("\n");
	}
}