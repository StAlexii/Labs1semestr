#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");

	char c, x;

	printf("¬ведите букву (a/b/c/d/e) или символ (!@#$%):\n ");

	scanf_s("%c", &c);

	switch (c)
	{
	case 'a':
		x = 'a';
		break;
	case 'b':
		x = 'b';
		break;
	case 'c':
		x = 'c';
		break;
	case 'd':
		x = 'd';
		break;
	case 'e':
		x = 'e';
		break;
	case '!':
		x = '!';
		break;
	case '@':
		x = '@';
		break;
	case '#':
		x = '#';
		break;
	case '$':
		x = '$';
		break;
	case '%':
		x = '%';
		break;
	
	}

	printf("¬ведено %c", x);

	return 0;

}
