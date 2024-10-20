#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.14

void drawPolygon(int a, int b, int c, int d, char symbol, double alpha, double beta) {
    int i, j;
    int startDrawingD = 0; // ���� ��� ������ ��������� ������� d
    int overlap = (c + d) - a; // ��������� d ����������� a

    // ������ ������� b
    for (i = 0; i <= b; i++) {
        printf("%c", symbol);
    }
    printf("\n");

    // ������ ������� a, c � d
    for (i = 0; i < a || i < c + d; i++) {
        // ������ ������� a � ��������
        if (i < a) {
            for (j = 0; j < i; j++) {
                printf(" "); // �������� ��� ������� ������� a
            }
            printf("%c", symbol); // ����� a
        }
        else {
            for (j = 0; j < a; j++) {
                printf(" "); // �������� ��� ����� d
            }
        }

        // ��������� � ��������� ������� c ��� d
        if (i < c) {
            // ������������ �� ������� c
            for (j = 0; j < b - i; j++) {
                printf(" ");
            }
            printf("%c\n", symbol); // ����� c
        }
        else if (i >= c && !startDrawingD) {
            // �������� �������� ������� d, ��� ������ c ���������
            startDrawingD = 1;
        }

        // ���� ���� �������, �������� �������� ������� d
        if (startDrawingD && (i - c) < d) {
            if (i < a) {
                for (j = 0; j < b - c; j++) {
                    printf(" "); // �������� ��� ������������ ����� ����� d
                }
                printf("%c\n", symbol);
            }
            else {
                for (j = 0; j < b - c + (i - a); j++) {
                    printf(" "); // �������� �������� ��� ��������� ����� ����� d (�����)
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

    // ���� ������ �� ������������
    printf("������� ����� ������ a, b, c, d: ");
    scanf_s("%d %d %d %d", &a, &b, &c, &d);

    printf("������� ���� alpha � beta (� ��������): ");
    scanf_s("%lf %lf", &alpha, &beta);

    printf("������� ������ ��� ���������: ");
    scanf_s(" %c", &symbol);

    drawPolygon(a, b, c, d, symbol, alpha, beta);

    return 0;
}
