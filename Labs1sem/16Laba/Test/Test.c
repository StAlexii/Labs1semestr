#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


double genrandouble(double min, double max) {
    return min + (max - min) * rand() / RAND_MAX;
}

void generate_array(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = genrandouble(-100, 100);
    }
}

int find_max_index(float* arr, int size) {
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

float* create_new_array(float* a, int n, float* c, int l, int* new_size) {
    int max_index = find_max_index(c, l);

    int positive_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            positive_count++;
        }
    }

    *new_size = l + positive_count;
    float* d = (float*)malloc(*new_size * sizeof(float));

    for (int i = 0; i < max_index; i++) {
        d[i] = c[i];
    }

    int index = max_index;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            d[index++] = a[i];
        }
    }

    for (int i = max_index; i < l; i++) {
        d[index++] = c[i];
    }

    return d;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    system("color F0");

    int n = 10 + rand() % 1;
    int m = 10 + rand() % 1;
    int l = 10 + rand() % 1;

    float* a = (float*)malloc(n * sizeof(float));
    float* b = (float*)malloc(m * sizeof(float));
    float* c = (float*)malloc(l * sizeof(float));

    generate_array(a, n);
    generate_array(b, m);
    generate_array(c, l);

    printf("Массив A:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", a[i]);
    }
    printf("\n\n");

    printf("Массив B:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f\n", b[i]);
    }
    printf("\n\n");

    printf("Массив C:\n");
    for (int i = 0; i < l; i++) {
        printf("%.2f\n", c[i]);
    }
    printf("\n\n");

    int new_size;
    float* d = create_new_array(a, n, c, l, &new_size);

    printf("Массив D:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%.2f\n", d[i]);
    }
    printf("\n");

    free(a);
    free(b);
    free(c);
    free(d);
}
