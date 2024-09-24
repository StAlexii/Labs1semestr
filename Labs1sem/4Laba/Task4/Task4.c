#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");

    double L1, L2, V1, V2;

    printf("¬ведите длину первого поезда (L1): ");
    scanf_s("%lf", &L1);

    printf("¬ведите длину второго поезда (L2): ");
    scanf_s("%lf", &L2);

    printf("¬ведите скорость первого поезда (V1): ");
    scanf_s("%lf", &V1);

    printf("¬ведите скорость второго поезда (V2): ");
    scanf_s("%lf", &V2);

    double time;

    time = (L1 + L2) / (V1 + V2);

    printf("¬рем€ прохождени€ поездов друг мимо друга: %.2f секунд\n", time);

    return 0;
}