#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> //25 50 0

#define N 100 
#define R 50 

void generate_random_array(int array[], int size, int min_value, int max_value) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max_value - min_value + 1) + min_value;
    }
}

void print_histogram(int counter[], int size, int max_count) {
    for (int i = 0; i < size; i++) {
        int normalized_count = (counter[i] * R) / max_count;
        printf("%2d: ", i + 1);
        for (int j = 0; j < normalized_count; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    srand(time(NULL));

    int min_value, max_value, type;
    printf("¬ведите минимальное значение: ");
    scanf("%d", &min_value);
    printf("¬ведите максимальное значение: ");
    scanf("%d", &max_value);
    printf("¬ведите тип сдвига (0 - от минимального, 1 - от максимального): ");
    scanf("%d", &type);

    int array[N];
    int K = max_value - min_value + 1;
    int* counter = (int*)malloc(K * sizeof(int));
    if (counter == NULL) {
        fprintf(stderr, "ќшибка выделени€ пам€ти\n");
        return 1;
    }

    for (int i = 0; i < K; i++) {
        counter[i] = 0;
    }

    generate_random_array(array, N, min_value, max_value);

    for (int i = 0; i < N; i++) {
        if (type == 0) {
            counter[array[i] - min_value]++;
        }
        else {
            counter[max_value - array[i]]++;
        }
    }

    int max_count = 0;
    for (int i = 0; i < K; i++) {
        if (counter[i] > max_count) {
            max_count = counter[i];
        }
    }

    print_histogram(counter, K, max_count);

    free(counter);

    return 0;
}

