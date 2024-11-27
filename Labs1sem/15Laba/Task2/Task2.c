#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7


void fillArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

void printArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

void transposeArray(int arr[SIZE][SIZE], int transposed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transposed[j][i] = arr[i][j];
        }
    }
}

int countElementsLessThanMinusFiveInSecondCol(int arr[SIZE][SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i][1] < -5) {
            count++;
        }
    }
    return count;
}

int countEqualPairs(int arr[SIZE][SIZE], int direction) {
    int count = 0;

    if (direction == 1) {
        //� ����� ������
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                if (arr[i][j] == arr[i][j + 1]) {
                    count++;
                }
            }
        }
    }
    else if (direction == 2) {
        //� ����� �������
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE - 1; i++) {
                if (arr[i][j] == arr[i + 1][j]) {
                    count++;
                }
            }
        }
    }
    else if (direction == 3) {
        //� ����� ������ � � ����� �������
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                if (arr[i][j] == arr[i + 1][j + 1]) {
                    count++;
                }
            }
        }
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE - 1; i++) {
                if (arr[i][j] == arr[i + 1][j]) {
                    count++;
                }
            }
        }
    }

    return count;
}

void findMaxElementCoordinates(int arr[SIZE][SIZE], int coordinates[SIZE][2]) {
    for (int j = 0; j < SIZE; j++) {
        int maxVal = arr[0][j];
        int maxRow = 0;
        for (int i = 1; i < SIZE; i++) {
            if (arr[i][j] >= maxVal) {
                maxVal = arr[i][j];
                maxRow = i;
            }
        }
        coordinates[j][0] = maxRow;
        coordinates[j][1] = j;
    }
}

int main() {

	setlocale(LC_ALL, "ru");
	system("color F0");

    double array1[SIZE][SIZE];
    double array2[SIZE][SIZE];
    int maxCoordinates[SIZE][2]; // ������ ��� �������� ��������� ������������ ���������

    fillArray(array1);

    printf("�������� ������:\n");
    printArray(array1);

    transposeArray(array1, array2);

    printf("\n����������������� ������:\n");
    printArray(array2);

    int countLessThanMinusFive = countElementsLessThanMinusFiveInSecondCol(array1);
    printf("\n���������� ��������� ������� �������, ������� -5: %d\n", countLessThanMinusFive);

    int countRowPairs = countEqualPairs(array1, 1);
    int countColumnPairs = countEqualPairs(array1, 2);
    int countRowAndColumnPairs = countEqualPairs(array1, 3);

    printf("\n���������� ��� ���������� �������� ��������� � �������: %d\n", countRowPairs);
    printf("���������� ��� ���������� �������� ��������� � ��������: %d\n", countColumnPairs);
    printf("���������� ��� ���������� �������� ��������� � ������� � ��������: %d\n", countRowAndColumnPairs);

    findMaxElementCoordinates(array1, maxCoordinates);

    printf("\n���������� ������������ ��������� � ������ �������:\n");
    for (int j = 0; j < SIZE; j++) {
        printf("������� %d: (%d, %d)\n", j, maxCoordinates[j][0], maxCoordinates[j][1]);
    }

}