#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");

	char c;

	printf("������� ����� (a/b/c/d/e) ��� ������ (!@#$%):\n ");

	scanf_s("%c", &c);

	switch (c)
	{
	case 'a':
		printf("������� 'a'.\n");
		break;
	case 'b':
		printf("������� 'b'.\n");
		break;
	case 'c':
		printf("������� 'c'.\n");
		break;
	case 'd':
		printf("������� 'd'.\n");
		break;
	case 'e':
		printf("������� 'e'.\n");
		break;
	case '!':
		printf("������� '!'.\n");
		break;
	case '@':
		printf("������� '@'.\n");
		break;
	case '#':
		printf("������� '#'.\n");
		break;
	case '$':
		printf("������� '$'.\n");
		break;
	case '%':
		printf("������� '%'.\n");
		break;
	default:
		printf("����������� ������\n");
	}
	return 0;

}

