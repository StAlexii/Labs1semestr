#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define MMM 1000

typedef struct {
    int number;
} print_c_t;

int addNum(print_c_t duck[], int* count) {
    printf("Введите число для записи в файл: ");
    scanf("%d", &duck[*count].number);
    (*count)++;
}

int saveToTextFile(print_c_t duck[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 2;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", duck[i].number);

    }
    fclose(file);
    return 1;
}

void main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    int count = 0, choise = 1, result;
    char filename[] = "number.txt";
    print_c_t duck[MMM];

    do {
        addNum(duck, &count);
        printf("Всё? (0 для завершения)\n");
        scanf_s("%d", &choise);
 
    } while (choise != 0);
    
    saveToTextFile(duck, count, filename);
}