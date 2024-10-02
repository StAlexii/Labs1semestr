#include <stdio.h>
#include <math.h>

double F(double x, double y) {
    double numerator = exp(pow(x, 3)) + pow(cos(x - 4), 2);
    double denominator = atan(x) + 5.2 * y;

    return numerator / denominator;
}

int main() {
    double result1 = F(2.1e-3, 10);
    double result2 = F(1.9, -1);

    printf("F(2, 1e-3) = %f\n", result1);
    printf("F(1.9, -1) = %f\n", result2);

    return 0;
}
