#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

double Y(double x) {
    if (x > 0) {
        return log(sqrt(fabs(pow(x, 3))));
    }
    else {
        printf("Y(x) �� ���������� ��� x <= 0\n");
        return NAN;
    }
}

double V(double x) {
    if (x > 1) {
        return sqrt(tan(pow(x, 2) - 1));
    }
    else if (x >= 0 && x <= 1) {
        return -2 * x;
    }
    else {
        return exp(cos(x));
    }
}

double S(double x) {
    double term = (x - 1) / (x + 1);
    double sum = term;
    for (int i = 1; i <= 7; i += 2) {
        sum += (1.0 / i) * pow(term, i);
    }
    return sum;
}

// ������� ��� ������ �������
void print_table(double (*func)(double), double start, double end, double step) {
    printf("\n   x         f(x)\n");
    printf("------------------\n");
    for (double x = start; x <= end; x += step) {
        double result = func(x);
        if (!isnan(result)) {
            printf("%7.2f   %10.5f\n", x, result);
        }
        else {
            printf("%7.2f        N/A\n", x);
        }
    }
}

void calculate_from_file(double (*func)(double), const char* filename) {
    FILE* file = fopen(filename, "r");

    printf("\n   x         f(x)\n");
    printf("------------------\n");
    double x;
    while (fscanf(file, "%lf", &x) == 1) {
        double result = func(x);
        if (!isnan(result)) {
            printf("%7.2f   %10.5f\n", x, result);
        }
        else {
            printf("%7.2f        ����\n", x);
        }
    }

    fclose(file);
}

bool is_sign_alternating(double (*func)(double), double start, double end, double step) {
    double prev_value = func(start);
    for (double x = start + step; x <= end; x += step) {
        double current_value = func(x);
        if (isnan(current_value) || isnan(prev_value)) {
            continue;
        }
        if (prev_value * current_value > 0) {
            return false;
        }
        prev_value = current_value;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    int choice;
    double start, end, step, x;

    while (1) {
        printf("\n����:\n");
        printf("1. ��������� ��������\n");
        printf("2. ������������ �������\n");
        printf("3. ��������� ������ �� �����\n");
        printf("4. ��������� �����������������\n");
        printf("5. �����\n");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("����� �� ���������.\n");
            break;
        }

        printf("�������� �������:\n");
        printf("1. Y(x)\n");
        printf("2. V(x)\n");
        printf("3. S(x)\n");
        int func_choice;
        scanf("%d", &func_choice);

        double (*selected_func)(double);
        switch (func_choice) {
        case 1:
            selected_func = Y;
            break;
        case 2:
            selected_func = V;
            break;
        case 3:
            selected_func = S;
            break;
        default:
            printf("�������� ����� �������.\n");
            continue;
        }

        switch (choice) {
        case 1:
            printf("������� �������� x: ");
            scanf("%lf", &x);
            printf("���������: %10.5f\n", selected_func(x));
            break;

        case 2:
            printf("������� ��������� �������� x: ");
            scanf("%lf", &start);
            printf("������� �������� �������� x: ");
            scanf("%lf", &end);
            printf("������� ��� ���������: ");
            scanf("%lf", &step);
            print_table(selected_func, start, end, step);
            break;

        case 3:
            calculate_from_file(selected_func, "dat.txt");
            break;

        case 4:
            printf("������� ��������� �������� x: ");
            scanf("%lf", &start);
            printf("������� �������� �������� x: ");
            scanf("%lf", &end);
            printf("������� ���: ");
            scanf("%lf", &step);
            if (is_sign_alternating(selected_func, start, end, step)) {
                printf("������� �������� ��������������� �� �������� ���������.\n");
            }
            else {
                printf("������� �� �������� ��������������� �� �������� ���������.\n");
            }
            break;

        default:
            printf("�������� ����� ��������.\n");
        }
    }
}
