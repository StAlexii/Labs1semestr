#include <locale.h>
#include <stdio.h>
void name()
{
	setlocale(LC_ALL, "RUS");
	system("color 2");
	puts("");
	puts("");
	puts("          * * * * * * * * * * * * * * * * * * * * * *");
	puts("          *                                         *");
	puts("          * ����: ���������� ����������� ���������� *");
	puts("          *                                         *");
	puts("          * ���������: ������� � ���������          *");
	puts("          *                                         *");
	puts("          * * * * * * * * * * * * * * * * * * * * * *");
	
}

void date()
{
	system("color 2");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("                 | --    | |--|    |--|   / ");
	puts("                 | |     | |  |    |  |  /  ");
	puts("                 | --    | |  |    |  | /__");
	puts("                 |  |    | |  |    |  | |  |");
	puts("                 | __  * | |__|  * |__| |__|");
	getchar();
	return 0;
}

void main() {
	name();
	date();
	return 0;
}