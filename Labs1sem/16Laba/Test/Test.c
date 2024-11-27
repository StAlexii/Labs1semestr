#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ������� ��� ���������� ������� ����������
double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)i + 1; // ������ ���������� ���������� �� 1 �� size
    }
    return ptr_array;
}

// ������� ��� �������������� ��������� �������
double* calc_elements(double* ptr_array, int size) {
    double* new_array = (double*)malloc(size * sizeof(double));
    if (new_array == NULL) {
        puts("error");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        new_array[i] = ptr_array[i] * 2; // ������ ��������������: ��������� �� 2
    }
    return new_array;
}

// ������� ��� ������ ��������� �������
int put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf \n", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

int main() {

    setlocale(LC_ALL, "ru");
    system("color F0");

    double* ptr_array;
    int size;

    // ���� ������� ������� � ����������
    printf("������� ������ �������: ");
    scanf("%d", &size);

    // ��������� ������ ��� ������
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    // ���������� ������� ����������
    ptr_array = full_elements(ptr_array, size);

    // ����� ��������� �������
    printf("�������� ������: \n");
    put_elements(ptr_array, size);

    // �������������� ��������� �������
    double* new_array = calc_elements(ptr_array, size);
    if (new_array == NULL) {
        free(ptr_array);
        return -1;
    }

    // ����� ������ �������
    printf("����� ������: \n");
    put_elements(new_array, size);

    // ������������ ������
    free(ptr_array);
    free(new_array);

    return 0;
}
