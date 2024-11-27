#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция для заполнения массива значениями
double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)i + 1; // Пример заполнения значениями от 1 до size
    }
    return ptr_array;
}

// Функция для преобразования элементов массива
double* calc_elements(double* ptr_array, int size) {
    double* new_array = (double*)malloc(size * sizeof(double));
    if (new_array == NULL) {
        puts("error");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        new_array[i] = ptr_array[i] * 2; // Пример преобразования: умножение на 2
    }
    return new_array;
}

// Функция для печати элементов массива
int put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf \n", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

int main() {

    setlocale(LC_ALL, "ru");
    system("color F0");

    double* ptr_array;
    int size;

    // Ввод размера массива с клавиатуры
    printf("Введите размер массива: ");
    scanf("%d", &size);

    // Выделение памяти под массив
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    // Заполнение массива значениями
    ptr_array = full_elements(ptr_array, size);

    // Вывод исходного массива
    printf("Исходный массив: \n");
    put_elements(ptr_array, size);

    // Преобразование элементов массива
    double* new_array = calc_elements(ptr_array, size);
    if (new_array == NULL) {
        free(ptr_array);
        return -1;
    }

    // Вывод нового массива
    printf("Новый массив: \n");
    put_elements(new_array, size);

    // Освобождение памяти
    free(ptr_array);
    free(new_array);

    return 0;
}
