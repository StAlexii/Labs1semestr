#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");

	char c;

	printf("¬ведите букву (a/b/c/d/e) или символ (!@#$%):\n ");

	scanf_s("%c", &c);

	switch (c)
	{
	case 'a':
		printf("¬ведено 'a'.\n");
		break;
	case 'b':
		printf("¬ведено 'b'.\n");
		break;
	case 'c':
		printf("¬ведено 'c'.\n");
		break;
	case 'd':
		printf("¬ведено 'd'.\n");
		break;
	case 'e':
		printf("¬ведено 'e'.\n");
		break;
	case '!':
		printf("¬ведено '!'.\n");
		break;
	case '@':
		printf("¬ведено '@'.\n");
		break;
	case '#':
		printf("¬ведено '#'.\n");
		break;
	case '$':
		printf("¬ведено '$'.\n");
		break;
	case '%':
		printf("¬ведено '%'.\n");
		break;
	default:
		printf("Ќеизвестный символ\n");
	}
	return 0;

}

