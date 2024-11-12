#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 100

int main() {
	system("color F0");
	setlocale(LC_ALL, "ru");
	float sminus = 0;
	int cntm = 0, cntp = 0, chet = 0, srr = 0;
	double arr[N];
	double z = 1;
	float splus = 0, sump = 0, smin = 0, sred = 0;
	float f;
	for (int i = 0; i < N; i++) {
		f = (pow(z, 3) - 4 * pow(z, 2) + 2);
		arr[i] = f;
		if (f > 0) {
			splus += f;
			cntp++;
		}

		else {
			sminus += f;
			cntm++;
		}

		if ((chet % 2 == 0) && (chet != 0)) {
			sred += f;
			srr++;
		}

		chet++;
		z += 0.02;
	}	
	for (int i = 0; i < N; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	printf("��� �������: arr[N]\n");
	printf("����� �������������: %f\n", splus);
	printf("����� �������������: %f\n", sminus);
	printf("���������� �������������: %d\n", cntm);
	printf("���������� �������������: %d\n", cntp);
	printf("������� �������������: %f\n", splus / 100);
	printf("������� �������������: %f\n", sminus / 100);
	printf("������� �������� ��������� ���������� ������, ������� ������ (�� ����������� ��������): %f", sred / srr);
	
}

