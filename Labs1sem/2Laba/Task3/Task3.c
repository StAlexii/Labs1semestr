#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int l = 7333, n = 3, k = 3, m = 1;
	float result = n/l;
	printf("¬ариант 18\n\n");
	printf("ƒано:\n\t %5d\n %13d\n", n, l);
	puts("        __________");
	printf("\nќтвет:\n\t+%05.1f", result); //0 Ч заполн€ть нул€ми, если количество знаков меньше, чем указано. 5 Ч общее количество символов дл€ целой и дробной части(включа€ точку). 1 Ч количество знаков после зап€той.


}