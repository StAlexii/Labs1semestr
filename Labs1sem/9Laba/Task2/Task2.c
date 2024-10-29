#include <stdio.h>
#include <locale.h>

int main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");

	int num, temp, lastDig, secLasDig, secDig, prod = 1, prodSecAndSecLastDig;
	int digit, count3 = 0, lastDigCnt = 0, evenCount = 0, More5Cnt = 0;
	int sumOdd = 0, sumMoreOrEql7 = 0, sumEven_last = 0, totDig = 0;
	int SameDig = -1, SameCnt = 0, sumFirstHalf = 0, sumSecHalf = 0;
	int oddSum = 0, evenSum = 0, index = 1, halfDigCnt; //индекс последней = 1
	printf("Введите число:\n");
	scanf_s("%d", &num);
	temp = num;

	lastDig = temp % 10;
	temp /= 10;
	totDig = 1;

	while (temp > 0) {
		totDig++;
		temp /= 10;
	}
	halfDigCnt = totDig / 2;
	while (num > 0) {
		digit = num % 10;
		num /= 10;
		if (digit == 3) count3++;
		if (digit == lastDig) lastDigCnt++;
		if (digit % 2 == 0) evenCount++;
		if (digit > 5) More5Cnt++;
		if (digit % 2 != 0) sumOdd += digit;
		if (digit >= 7) sumMoreOrEql7 += digit;
		if (digit != 0) prod *= digit;
		if (digit % 2 == 0 && index != 1) sumEven_last += digit;
			if (SameDig == digit) SameCnt++;
			SameDig = digit;
		if (index <= halfDigCnt)
			sumSecHalf += digit;
		else
			sumFirstHalf += digit;
		if (index % 2 == 0)
			evenSum += digit;
		else
			oddSum += digit;
		if (index == 2) secDig = digit;
		if (index == totDig - 1) secLasDig = digit;
		index++;
	}
	prodSecAndSecLastDig = secDig * secLasDig;
	printf("1. Количество цифр 3: %d\n", count3);
	printf("2. Число повторений последней цифры: %d\n", lastDigCnt);
	printf("3. Количество четных цифр: %d\n", evenCount);
	printf("4. Количество цифр больше 5: %d\n", More5Cnt);
	printf("5. Сумма нечетных цифр: %d\n", sumOdd);
	printf("6. Сумма цифр больше или равно 7: %d\n", sumMoreOrEql7);
	printf("7. Произведение всех цифр, исключая 0: %lld\n", prod);
	printf("8. Произведение предпоследней и второй цифры: %lld\n", prodSecAndSecLastDig);
	printf("9. Сумма четных цифр, исключая последнюю: %d\n", sumEven_last);
	printf("10. Количество рядом расположенных одинаковых цифр: %d\n", SameCnt);
	printf("11. Сумма первой половины цифр: %d, Сумма второй половины цифр: %d\n", sumFirstHalf, sumSecHalf);
	if (sumFirstHalf == sumSecHalf)
		printf("Суммы первой и второй половины цифр равны.\n");
	else
		printf("Суммы первой и второй половины цифр не равны.\n");
	printf("12. Произведение сумм цифр четных и нечетных разрядов: %d\n", evenSum * oddSum);
}