#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//strtok для разделения строки на слова.

#define MAX_LEN 256

int main() {
    system("color F0");
    setlocale(LC_ALL, "ru");
    char input[MAX_LEN];
    char* shortest_word = 0;
    char* second_shortest_word = 0;
    size_t shortest_length = MAX_LEN;
    size_t second_shortest_length = MAX_LEN;

    printf("Введите строку: ");

    fgets(input, MAX_LEN, stdin);
     
    input[strcspn(input, "\n")] = '\0';

    char* token = strtok(input, " ");
    while (token != NULL) {
        size_t length = strlen(token);

        if (length < shortest_length) {
            second_shortest_word = shortest_word;
            second_shortest_length = shortest_length;

            shortest_word = token;
            shortest_length = length;
        }
        else if (length < second_shortest_length) {
            second_shortest_word = token;
            second_shortest_length = length;
        }

        token = strtok(NULL, " ");
    }

    if (second_shortest_word != NULL) {
        printf("Слово, меньше которого только самое короткое: %s\n", second_shortest_word);
    }
    else {
        printf("Нет такого слова\n");
    }

    return 0;
}
