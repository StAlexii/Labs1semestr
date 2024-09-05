#include <locale.h>
#include <stdio.h>
void main()
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
	getchar();
	return 0;
}
