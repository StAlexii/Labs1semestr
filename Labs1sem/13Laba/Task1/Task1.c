#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main() {
	//setlocale(LC_ALL, "rus");
	system("color F0");

    char snew[48] = "������, ";
    char name[40];  

    printf("������� ���� ���: ");
    getchar();
    scanf_s("%s", name);

    strcat(snew, name);

    printf("%s\n", snew);

}