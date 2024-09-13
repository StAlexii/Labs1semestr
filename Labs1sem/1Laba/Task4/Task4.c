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
	puts("          * тема: Разработка консольного приложения *");
	puts("          *                                         *");
	puts("          * Выполнили: Стадник и Ледовской          *");
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
	puts("                   ____     __      __      ");
	puts("                /| |     | |  |    |  |   / ");
	puts("               / | |     | |  |    |  |  /  ");
	puts("                 | |___  | |  |    |  | /__ ");
	puts("                 |    |  | |  |    |  | |  |");
	puts("                 | ___| *| |__|  * |__| |__|");
	getchar();
	return 0;
}

void main() {
	name();
	date();
	return 0;
}