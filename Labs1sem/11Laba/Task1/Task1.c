#include <stdio.h>
#include <locale.h>
#define N 10

int main() {
    system("color F0");
    setlocale(LC_ALL, "ru");
 
	float a[N], b[N];
    float temp, s1 = 0, s2 = 0;
    int in = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &temp);
        a[i] = temp;
    }
    for (int i = 0; i < N; i++)
      b[i] = a[i] * (-1);

    printf(" _____________________________________________\n");
    printf("| индекс | исходное значение | новое значение |\n");
    for (int i = 0; i < N; i++)
        printf("|%8d|%19g|%16g|\n", in, a[i], b[i]);
    printf("|________|___________________|________________|\n");

    for (int i = 0; i < N; i++)
        s1 += a[i];
    for (int i = 0; i < N; i++)
        s2 += b[i];

    printf("\n");

    s1 = s1 / N;
    s2 = s2 / N;
    printf("Среднее арифмитическое изначального массива: %f\n", s1);
    printf("Среднее арифмитическое изменённого массива: %f\n", s2);
}