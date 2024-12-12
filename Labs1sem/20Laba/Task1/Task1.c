#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "ru");
	system("color F0");

	int sum = 0, a, n = 0;
	FILE* file;

	file = fopen("temp.txt", "r");

	while (!feof(file)) {
		fscanf(file, "%d", &a);
		sum += a;
		n++;
	}

	fclose(file);

	printf("Среднее арифмитическое: %d", sum/n);
}

