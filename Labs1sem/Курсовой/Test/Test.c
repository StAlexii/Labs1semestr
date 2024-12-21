#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
typedef struct Notebook {
    char fabricator[10];
    char OS[10];
    int RAM;
    char CPU[20];
    float screenDiagonal;
}notebook_t;


void fill_notebooks(notebook_t* notebooks, int size) {
    for (int i = 0; i < size; i++) {
        printf("Производитель ноутбука: ");
        scanf("%s", notebooks[i].fabricator);
        getchar();

        printf("Операционная система: ");
        scanf("%s", notebooks[i].OS);
        getchar();
        printf("Оперативная память(в ГБ): ");
        scanf("%d", &notebooks[i].RAM);
        getchar();
        printf("Модель процессора: ");
        scanf("%s", notebooks[i].CPU);
        getchar();
        printf("Диагональ экрана(в дюймах): ");
        scanf("%f", &notebooks[i].screenDiagonal);
    }
}


void print_notebook(notebook_t* notebook) {
    printf("Производитель ноутбука: %s\n", notebook->fabricator);
    printf("Операционная система: %s\n", notebook->OS);
    printf("Оперативная память(в ГБ): %d\n", notebook->RAM);
    printf("Модель процессора: %s\n", notebook->CPU);
    printf("Диагональ экрана(в дюймах): %f\n", notebook->screenDiagonal);
}


int** search_notebook(notebook_t* notebooks, int size, char* CPU, int RAM, int* countOfSeeked) {
    if (CPU != NULL && RAM != NULL) {
        for (int i = 0; i < size; i++) {
            if (strcmp(notebooks[i].CPU, CPU) == 0 && notebooks[i].RAM == RAM) countOfSeeked[i] = i;
        }
    }
    else if (CPU != NULL && RAM == NULL) {
        for (int i = 0; i < size; i++) {
            if (strcmp(notebooks[i].CPU, CPU) == 0) countOfSeeked[i] = i;
        }
    }
    else for (int i = 0; i < size; i++) {
        if (notebooks[i].RAM == RAM) countOfSeeked[i] = i;
    }
    return countOfSeeked;
}

void Sort(notebook_t* notebooks, int size, int n) {
    if (n == 3) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].fabricator, notebooks[j + 1].fabricator) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].OS, notebooks[j + 1].OS) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
    }
    else if (n == 1) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].fabricator, notebooks[j + 1].fabricator) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
    }
    else for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(notebooks[j].OS, notebooks[j + 1].OS) > 0) {
                notebook_t temp = notebooks[j];
                notebooks[j] = notebooks[j + 1];
                notebooks[j + 1] = temp;
            }
        }
    }

}

void WriteFile(notebook_t* notebooks, int size) {
    FILE* fp;
    fp = fopen("Coursework.txt", "w");
    for (int i = 0; i < size; i++) {
        fprintf(fp, "Производитель ноутбука: %s\n", notebooks[i].fabricator);
        fprintf(fp, "Операционная система: %s\n", notebooks[i].OS);
        fprintf(fp, "Оперативная память(в ГБ): %d\n", notebooks[i].RAM);
        fprintf(fp, "Модель процессора: %s\n", notebooks[i].CPU);
        fprintf(fp, "Диагональ экрана(в дюймах): %f\n", notebooks[i].screenDiagonal);
        fprintf(fp, "\n");
    }
    fclose(fp);
}
void ReadFile(notebook_t* notebooks, int size) {
    FILE* fp = fopen("Coursework.txt", "r");
    if (fp == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        // Считывание с пробелами в строках
        if (fscanf(fp, "Производитель ноутбука: %[^\n]\n", notebooks[i].fabricator) != 1) {
            printf("Ошибка при считывании производителя ноутбука для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Операционная система: %[^\n]\n", notebooks[i].OS) != 1) {
            printf("Ошибка при считывании операционной системы для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Оперативная память(в ГБ): %d\n", &notebooks[i].RAM) != 1) {
            printf("Ошибка при считывании оперативной памяти для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Модель процессора: %[^\n]\n", notebooks[i].CPU) != 1) {
            printf("Ошибка при считывании процессора для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Диагональ экрана(в дюймах): %f\n", &notebooks[i].screenDiagonal) != 1) {
            printf("Ошибка при считывании диагонали экрана для записи %d\n", i);
            break;
        }
        fscanf(fp, "%*[\n]");
    }

    fclose(fp);
}



void main() {
    int a = 1;
    while (a) {
        setlocale(LC_ALL, "Rus");
        int num = 0;
        notebook_t notebooks[SIZE];
        int* countOfSeeked[SIZE];
        for (int i = 0; i < SIZE; i++) { countOfSeeked[i] = -1; }
        int size;
        printf("**********************************************\n");
        printf("*                     Menu                   *\n");
        printf("**********************************************\n");
        printf("* 1. Создать запись файла.                   *\n");
        printf("* 2. Выполнить поиск по файлу.               *\n");
        printf("* 3. Запись и чтение файла.                  *\n");
        printf("* 4. Сортировать данные файла.               *\n");
        printf("* 5. Завершить работу                        *\n");
        printf("**********************************************\n");
        scanf("%d", &num);

        switch (num) {
        case 1: printf("Сколько ноутбуков вы хотите записать? ");
            scanf("%d", &size);
            fill_notebooks(notebooks, size);
            WriteFile(notebooks, size);
        case 2:ReadFile(notebooks, SIZE);
            char searchProc[20];
            char searchRAM[20];
            printf("**********************************************\n");
            printf("*                    Поиск по                *\n");
            printf("**********************************************\n");
            printf("* 1. Процессору.                             *\n");
            printf("* 2. Оперативной памяти.                     *\n");
            printf("* 3. Процессору и оперативной памяти.        *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num) {
            case 1:
                printf("Введите название процессора: ");
                scanf("%s", searchProc);
            case 2:
                printf("Введите название объем оперативной памяти: ");
                scanf("%s", searchRAM);
            case 3:
                printf("Введите название процессора: ");
                scanf("%s", searchProc);
                printf("Введите название объем оперативной памяти: ");
                scanf("%s", searchRAM);
            }
            search_notebook(notebooks, size, searchProc, searchRAM, countOfSeeked);
        case 5:
            a = 0;
        }









        //Поиск элементов
        /*search_notebook(notebooks, SIZE, "Intel core i5", 8, countOfSeeked);
        for (int i = 0; i < SIZE; i++) {
            if (countOfSeeked[i] != -1)print_notebook(&notebooks[i]);
        }*/


        /* Sort(notebooks, SIZE,2);*/


         /*for (int i = 0; i < SIZE; i++) {
             print_notebook(&notebooks[i]);
         }



         WriteFile(notebooks, SIZE);*/

         /*ReadFile(notebooks, SIZE);
         for (int i = 0; i < SIZE; i++) {
             print_notebook(&notebooks[i]);
         }*/


    }
}
