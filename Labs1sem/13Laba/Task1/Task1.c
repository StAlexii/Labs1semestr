﻿#include <stdio.h>
#include <string.h>

int main() {
    char Snew[40] = "Hello, ", Snew3[40] = "Hello, ";
    char Name[40], Name2[40], Name3[40];
    system("color F0");

    printf("Your name: ");

    scanf("%s", Name);

    strcat(Snew, Name);

    printf("1.1\n");
    printf("%s!\n\n", Snew); //1.1

    for (int i = 0; Snew[i] != '\0'; i++)
        Snew[i] = toupper(Snew[i]);

    for (int i = 0; Name[i] != '\0'; i++)
        Name[i] = toupper(Name[i]);

    printf("1.2\n");
    printf("%s!\n\n", Snew); //1.2


    char Snew2[40] = "Hello, ";

    for (int i = 1; Snew[i] != '\0'; i++) {
        Snew[i] = tolower(Snew[i]);
        if (i == 7)
            Snew[i] = toupper(Snew[i]);
    }

    int len = strlen(Snew);

    while (len < 39) {
        Snew[len] = '!';
        len++;
    }

    Snew[len] = '\0';

    printf("1.3\n");
    printf("%s!\n\n", Snew); //1.3

    for (int i = 0; i < 40; i++) {
        if (i == 8)
            Snew[i] = ' ';
    }

    for (int i = 8; i < 41; i++)
        Snew[i] = Snew[i + 1];

    for (int i = 41; i > 10; i--)
        if (Snew[i] == '!')
            Snew[i] = ' ';

    printf("2\n");
    printf("%s\n\n", Snew); //2

}
