#include <stdio.h>
#include <locale.h>

int main() {
    long long num, temp, lastDigit, secondLastDigit, secondDigit, productNoZero = 1, productSecondAndSecondLast;
    int digit, count3 = 0, lastDigitCount = 0, evenCount = 0, greater5Count = 0;
    int sumOdd = 0, sumGreaterOrEqual7 = 0, evenSumExcludingLast = 0, totalDigits = 0;
    int prevDigit = -1, adjacentSameCount = 0, sumFirstHalf = 0, sumSecondHalf = 0;
    int oddSum = 0, evenSum = 0, index = 1, halfDigitCount;

    setlocale(LC_ALL, "RUS");

    printf("������� �����: ");
    scanf_s("%lld", &num);

    temp = num;
    lastDigit = temp % 10;
    temp /= 10;
    totalDigits = 1;

    while (temp > 0) {
        totalDigits++;
        temp /= 10;
    }

    temp = num;  // ��������������� ��������
    halfDigitCount = totalDigits / 2;

    // ���������� ����� �����
    while (temp > 0) {
        digit = temp % 10;
        temp /= 10;

        // 1. ���������� ���� 3
        if (digit == 3) count3++;

        // 2. ����� ���������� ��������� �����
        if (digit == lastDigit) lastDigitCount++;

        // 3. ���������� ������ ����
        if (digit % 2 == 0) evenCount++;

        // 4. ���������� ���� ������� 5
        if (digit > 5) greater5Count++;

        // 5. ����� �������� ����
        if (digit % 2 != 0) sumOdd += digit;

        // 6. ����� ���� ������ ��� ����� 7
        if (digit >= 7) sumGreaterOrEqual7 += digit;

        // 7. ������������ ���� ����, �������� 0
        if (digit != 0) productNoZero *= digit;

        // 9. ����� ������ ����, �������� ���������
        if (digit % 2 == 0 && index != 1) evenSumExcludingLast += digit;

        // 10. ����� ������������� ���������� �����
        if (prevDigit == digit) adjacentSameCount++;
        prevDigit = digit;

        // 11. ����� ������ � ������ �������� ����
        if (index <= halfDigitCount)
            sumFirstHalf += digit;
        else
            sumSecondHalf += digit;

        // 12. ����� ���� ������ � �������� ��������
        if (index % 2 == 0)
            evenSum += digit;
        else
            oddSum += digit;

        // ���������� ������������� � ������ �����
        if (index == 2) secondDigit = digit;
        if (index == totalDigits - 1) secondLastDigit = digit;

        index++;
    }

    // 8. ������������ ������������� � ������ �����
    productSecondAndSecondLast = secondDigit * secondLastDigit;

    printf("1. ���������� ���� 3: %d\n", count3);
    printf("2. ����� ���������� ��������� �����: %d\n", lastDigitCount);
    printf("3. ���������� ������ ����: %d\n", evenCount);
    printf("4. ���������� ���� ������ 5: %d\n", greater5Count);
    printf("5. ����� �������� ����: %d\n", sumOdd);
    printf("6. ����� ���� ������ ��� ����� 7: %d\n", sumGreaterOrEqual7);
    printf("7. ������������ ���� ����, �������� 0: %lld\n", productNoZero);
    printf("8. ������������ ������������� � ������ �����: %lld\n", productSecondAndSecondLast);
    printf("9. ����� ������ ����, �������� ���������: %d\n", evenSumExcludingLast);
    printf("10. ���������� ����� ������������� ���������� ����: %d\n", adjacentSameCount);
    printf("11. ����� ������ �������� ����: %d, ����� ������ �������� ����: %d\n", sumFirstHalf, sumSecondHalf);
    if (sumFirstHalf == sumSecondHalf)
        printf("����� ������ � ������ �������� ���� �����.\n");
    else
        printf("����� ������ � ������ �������� ���� �� �����.\n");
    printf("12. ������������ ���� ���� ������ � �������� ��������: %d\n", evenSum * oddSum);

    return 0;
}
