#include <stdio.h>
#include <math.h>

double F(double x, double y) {
    return (exp(pow(x, 3)) + pow(cos(x - 4), 2)) / (atan(x) + 5.2 * y);
}

int main() {
    double result1 = F(2 .1e-3, 10);
    double result2 = F(1.9, -1);

    printf("F(2 * 10^-3, 10) = %.6f\n", result1);
    printf("F(1, 9, -1) = %.6f\n", result2);

    return 0;
}