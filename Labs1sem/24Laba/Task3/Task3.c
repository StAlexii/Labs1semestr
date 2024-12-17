#include <stdio.h>
#include <locale.h>
//5 10
void process_file(FILE* input, FILE* output, int a, int b) {
    int num;

    while (fscanf(input, "%d", &num) != EOF) {
        if (num < a) {
            fprintf(output, "%d ", num);
        }
        else if (num >= a && num <= b) {
            fprintf(output, "%d ", num);
        }
    }

    // чтение файла для записи чисел, которые больше b
    fseek(input, 0, SEEK_SET);  // в начало файла
    while (fscanf(input, "%d", &num) != EOF) {
        if (num > b) {
            fprintf(output, "%d ", num);  // число больше b
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    int a, b;
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка при открытии файлов!\n");
        return 1;
    }

    printf("Введите диапазон [a, b]: ");
    scanf_s("%d %d", &a, &b);

    process_file(input_file, output_file, a, b);

    fclose(input_file);
    fclose(output_file);

    printf("Результат записан в output.txt\n");
    return 0;
}
