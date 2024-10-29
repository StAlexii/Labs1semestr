#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.14

double fucktorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double sin2(double x, int N) {
    double result = 0.0;
    for (int k = 0; k < N; k++) {
        int posl = 2 * k + 1;
        double term = pow(-1, k) * pow(x, posl) / fucktorial(posl);
        result += term;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    double x;
    int N;

    printf("¬ведите x\n");
    scanf_s("%lf", &x);
    printf("¬ведите n\n");
    scanf_s("%d", &N);

    x = x * M_PI / 180.0;

    double result = sin2(x, N);
    double result2 = sin(x);

    printf("sin(%lf) = %lf\n", x, result);
    printf("sin2(%lf) = %lf\n", x, result2);

    return 0;
}