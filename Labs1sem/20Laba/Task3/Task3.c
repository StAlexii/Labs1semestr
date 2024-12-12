#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_LINE_LENGTH 1024

void remove_last_word(char* line) {
    size_t len = strlen(line);

    if (line[len - 1] == '\n') {
        line[--len] = '\0';
    }

    for (size_t i = len; i > 0; --i) {
        if (line[i - 1] == ' ' || line[i - 1] == '\t') {
            line[i - 1] = '\0';
            return;
        }
    }

    line[0] = '\0';
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    FILE* input_file = fopen("winter.txt", "r");

    char output_filename[256];
    printf("Введите имя выходного файла: ");
    if (!fgets(output_filename, sizeof(output_filename), stdin)) {
        perror("Ошибка ввода имени файла");
        fclose(input_file);
        return 1;
    }

    output_filename[strcspn(output_filename, "\n")] = '\0'; //удаление пеерноса из имени файла

    FILE* output_file = fopen(output_filename, "w");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input_file)) {
        remove_last_word(line);
        fprintf(output_file, "%s\n", line);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Результат сохранён в файле %s.\n", output_filename);
    return 0;
}