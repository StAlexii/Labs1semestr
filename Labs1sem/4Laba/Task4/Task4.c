#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");

    double L1, L2, V1, V2;

    printf("������� ����� ������� ������ (L1): ");
    scanf_s("%lf", &L1);

    printf("������� ����� ������� ������ (L2): ");
    scanf_s("%lf", &L2);

    printf("������� �������� ������� ������ (V1): ");
    scanf_s("%lf", &V1);

    printf("������� �������� ������� ������ (V2): ");
    scanf_s("%lf", &V2);

    double time;

    time = (L1 + L2) / (V1 + V2);

    printf("����� ����������� ������� ���� ���� �����: %.2f ������\n", time);

    return 0;
}