#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int x;
	char c;
	printf("¬ведите символ\n");
	scanf_s("%c", &c);
	printf("¬ведите сколько раз повторить\n");
	scanf_s("%d", &x);

	for (x; x > 0; x -= 1)
		printf("%c\n", c);
}