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
	puts("          * ����: ���������� ����������� ���������� *");
	puts("          *                                         *");
	puts("          * ���������: ������� � ���������          *");
	puts("          *                                         *");
	puts("          * * * * * * * * * * * * * * * * * * * * * *");
	getchar();
	return 0;
}
