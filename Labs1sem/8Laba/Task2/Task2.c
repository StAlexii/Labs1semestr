#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	int n, m, sum = 0, k = 0, z;
	printf("������� � ������ ����� ������\n");
	scanf_s("%d", &n);
	printf("������� �������� �����\n");
	scanf_s("%d", &m);

	for (int i = m; i >= n; i--) {
		sum += i;
		k += 1;
	}
	float sus = 0;
	for (int i = 0; i <= n; i++) {
		z = pow(2, i);
		printf("2 ^ %d = %10d\n", i, z);
		sus += z;
	}

	printf("\n�����: %d, ��������: %d\n", sum, k);
	if (sus > 1024)
		printf("����� �������� 2 %f: %.1fK\n", sus, sus / 1024);
	else
		printf("����� �������� 2 %f: %.1f\n", sus);
	

}