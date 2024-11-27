#include <stdio.h>
#include <math.h>
#include<locale.h>

int find_mid_index(double* array, int n, int type) {
    int first = 123456, last;

    float s1 = 0, s2 = 0, s3 = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] > 0)
            s1++;
        if (array[i] < 0)
            s2++;
        if (array[i] == 0)
            s3++;
    }

    switch (type) {

    case 1:
    {
        if (s1 == 0) {
            printf("Положительных элементов нет");
            break;
        }

        else{
            for (int i = 0; i < n; i++) {
                if (first == 123456) {
                    first = i;
                }
                last = i;
            }
        }
        break;
    }
    case 2: {
        if (s2 == 0) {
            printf("Отрицательных элементов нет");
            break;
        }

        else{
            for (int i = 0; i < n; i++) {
                if (first == 123456) {
                    first = i;
                }
                last = i;
            }
        }
        break;
    }
    case 0:
    {
        if (s3 == 0) {
            printf("Недостаточно нулевых элементов");
            break;
        }

        else {
            for (int i = 0; i < n; i++) {
                if (first == 123456) {
                    first = i;
                }
                last = i;
            }
        }
    }
    break;
}
    
    int mid = (abs(first) + abs(last)) / 2;
    return mid;
}

double* fille(double* ptr_array, int n);

int main() {

    setlocale(LC_ALL, "RUS");

    system("color F0");

    double array[1024];
    int size;

    printf("Введите размер массива - ");
    scanf_s("%d", &size);

    fille(array, size);
    printe(array, size);


    int n = size;

    int type;

    printf("Введите тип элемента (1 = положительный, 2 = отрицательный, 0 = нулевой): ");
    scanf_s("%d", &type);

    int index = find_mid_index(array, n, type);

    if (index != -1) {
        printf("Индекс элемента в середине интервала: %d (значение: %.2f)\n", index, array[index]);
    }
    else {
        printf("Элементы заданного типа отсутствуют в массиве.\n");
    }

    return 0;
}

double* fille(double* ptr_array, int n)
{
    double z = 25;
    for (int i = 0; i < n; i++)

    {
        ptr_array[i] = z;
        //ptr_array[i] = (pow(z, 3) - 4 * pow(z, 2) + 2);
        z += 1;
    }

}

int printe(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("array[%d] = %f\n", i, ptr_array[i]);
    }
}
