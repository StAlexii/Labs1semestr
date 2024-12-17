#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <time.h>

double genrandouble(double min, double max) {
    return min + (max - min) * rand() / RAND_MAX;
}

void genarr(double* array, int size, double min, double max) {
    for (int i = 0; i < size; i++) {
        array[i] = genrandouble(min, max);
    }
}
void printe(double* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
        printf("\n");
    }
    printf("\n");
}

double* darr(double* a, int n, double* c, int l, int* d_size) {
    double max_c = c[0];
    int max_index = 0;
    for (int i = 1; i < l; i++) {
        if (c[i] > max_c) {
            max_c = c[i];
            max_index = i;
        }
    }

    int positive_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            positive_count++;
        }
    }

    *d_size = l + positive_count;
    double* d = (double*)malloc(*d_size * sizeof(double));

    for (int i = 0; i <= max_index; i++) {
        d[i] = c[i];
    }

    int d_index = max_index + 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            d[d_index++] = a[i];
        }
    }

    for (int i = max_index + 1; i < l; i++) {
        d[d_index++] = c[i];
    }

    return d;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    system("color F0");

    srand(time(NULL));

    int n = 10 + rand() % 1;
    int m = 10 + rand() % 1;
    int l = 10 + rand() % 1;

    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* c = (double*)malloc(l * sizeof(double));

    genarr(a, n, -100.0, 100.0);
    genarr(b, m, -100.0, 100.0);
    genarr(c, l, -100.0, 100.0);

    printf("Массив a, размер: %d символов\n", n);
    printe(a, n);
    printf("Массив b, размер: %d символов\n", m);
    printe(b, m);
    printf("Массив c, размер: %d символов\n", l);
    printe(c, l);

    int d_size;
    double* d = darr(a, n, c, l, &d_size);

    printf("Массив d, размер: %d символов\n", d_size);
    printe(d, d_size);

    free(a);
    free(b);
    free(c);
    free(d);
}