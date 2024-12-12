#include <stdio.h>
#include <math.h>
#include <locale.h>
//1 3 0,2 1

void tabulate_function(double start, double end, double step, const char* mode) {
    FILE* file = fopen("temp.txt", mode);

    fprintf(file, "Результаты табуляции функции f(x) = x^3 - 4x^2 + 2\n");
    fprintf(file, "Интервал: [%.2f, %.2f], шаг: %.2f\n\n", start, end, step);

    for (double i = start; i <= end; i += step) {
        double result = pow(i, 3) - 4 * pow(i, 2) + 2;
        fprintf(file, "x = %.2f, f(x) = %.2f\n", i, result);
    }

    fclose(file);
}

int main() {
    double start, end, step;
    int action;
    setlocale(LC_ALL, "ru");
    system("color F0");

    printf("Начало интервала: ");
    scanf_s("%lf", &start);

    printf("Конец интервала: ");
    scanf_s("%lf", &end);

    printf("Шаг табуляции: ");
    scanf_s("%lf", &step);

    printf("Выберите действие:\n");
    printf("1) Запись в новый файл\n");
    printf("2) Дозапись в существующий файл\n");
    scanf_s("%d", &action);

    if (action == 1) 
        tabulate_function(start, end, step, "w");
    else if (action == 2)
        tabulate_function(start, end, step, "a");

}
