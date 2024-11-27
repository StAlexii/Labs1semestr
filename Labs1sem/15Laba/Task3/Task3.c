#include <stdio.h>
#include <locale.h>
#include <time.h>
#define s 12
#define m 18

void fillArray(int arr[m][s]) {
    //int z = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            arr[i][j] = 30000 + rand() % (60000 - 30000 + 1);
            //z += 5000;
        }
    }
}

int main() {

	setlocale(LC_ALL, "ru");
	system("color F0");

	int arr[m][s];
    double avg[s] = { 0 };

    fillArray(arr);

    srand(time(NULL));

    printf("»сходный массив зарплат:\n");

    for (int j = 1; j < s+1; j++) {
        printf("%5d ", j);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < s; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int j = 0; j < s; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += arr[i][j];
        }
        avg[j] = (double)sum / m;
    }


    for (int j = 0; j < s; j++) {
        printf("—редн€€ зарплата за мес€ц %d: %.2f\n", j + 1, avg[j]);
    }
}