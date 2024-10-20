#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.14

void drawPolygon(int a, int b, int c, int d, char symbol, double alpha, double beta) {
    int i, j;
    int startDrawingD = 0; // Флаг для начала рисования стороны d
    int overlap = (c + d) - a; // Насколько d перекрывает a

    // Рисуем сторону b
    for (i = 0; i <= b; i++) {
        printf("%c", symbol);
    }
    printf("\n");

    // Рисуем стороны a, c и d
    for (i = 0; i < a || i < c + d; i++) {
        // Рисуем сторону a с наклоном
        if (i < a) {
            for (j = 0; j < i; j++) {
                printf(" "); // Смещение для наклона стороны a
            }
            printf("%c", symbol); // Линия a
        }
        else {
            for (j = 0; j < a; j++) {
                printf(" "); // Смещение для линии d
            }
        }

        // Переходим к рисованию стороны c или d
        if (i < c) {
            // Пространство до стороны c
            for (j = 0; j < b - i; j++) {
                printf(" ");
            }
            printf("%c\n", symbol); // Линия c
        }
        else if (i >= c && !startDrawingD) {
            // Начинаем рисовать сторону d, как только c завершена
            startDrawingD = 1;
        }

        // Если флаг активен, начинаем рисовать сторону d
        if (startDrawingD && (i - c) < d) {
            if (i < a) {
                for (j = 0; j < b - c; j++) {
                    printf(" "); // Смещение для вертикальной части линии d
                }
                printf("%c\n", symbol);
            }
            else {
                for (j = 0; j < b - c + (i - a); j++) {
                    printf(" "); // Обратное смещение для наклонной части линии d (влево)
                }
                printf("%c\n", symbol);
            }
        }
    }
}

int main() {
    int a, b, c, d;
    double alpha, beta;
    char symbol;

    setlocale(LC_ALL, "RUS");

    // Ввод данных от пользователя
    printf("Введите длины сторон a, b, c, d: ");
    scanf_s("%d %d %d %d", &a, &b, &c, &d);

    printf("Введите углы alpha и beta (в градусах): ");
    scanf_s("%lf %lf", &alpha, &beta);

    printf("Введите символ для рисования: ");
    scanf_s(" %c", &symbol);

    drawPolygon(a, b, c, d, symbol, alpha, beta);

    return 0;
}
