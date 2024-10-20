#include <stdio.h>
#include <locale.h>

int main() {
    long long num, temp, lastDigit, secondLastDigit, secondDigit, productNoZero = 1, productSecondAndSecondLast;
    int digit, count3 = 0, lastDigitCount = 0, evenCount = 0, greater5Count = 0;
    int sumOdd = 0, sumGreaterOrEqual7 = 0, evenSumExcludingLast = 0, totalDigits = 0;
    int prevDigit = -1, adjacentSameCount = 0, sumFirstHalf = 0, sumSecondHalf = 0;
    int oddSum = 0, evenSum = 0, index = 1, halfDigitCount;

    setlocale(LC_ALL, "RUS");

    printf("Введите число: ");
    scanf_s("%lld", &num);

    temp = num;
    lastDigit = temp % 10;
    temp /= 10;
    totalDigits = 1;

    while (temp > 0) {
        totalDigits++;
        temp /= 10;
    }

    temp = num;  // восстанавливаем значение
    halfDigitCount = totalDigits / 2;

    // Перебираем цифры числа
    while (temp > 0) {
        digit = temp % 10;
        temp /= 10;

        // 1. Количество цифр 3
        if (digit == 3) count3++;

        // 2. Число повторений последней цифры
        if (digit == lastDigit) lastDigitCount++;

        // 3. Количество четных цифр
        if (digit % 2 == 0) evenCount++;

        // 4. Количество цифр больших 5
        if (digit > 5) greater5Count++;

        // 5. Сумма нечетных цифр
        if (digit % 2 != 0) sumOdd += digit;

        // 6. Сумма цифр больше или равно 7
        if (digit >= 7) sumGreaterOrEqual7 += digit;

        // 7. Произведение всех цифр, исключая 0
        if (digit != 0) productNoZero *= digit;

        // 9. Сумма четных цифр, исключая последнюю
        if (digit % 2 == 0 && index != 1) evenSumExcludingLast += digit;

        // 10. Рядом расположенные одинаковые цифры
        if (prevDigit == digit) adjacentSameCount++;
        prevDigit = digit;

        // 11. Сумма первой и второй половины цифр
        if (index <= halfDigitCount)
            sumFirstHalf += digit;
        else
            sumSecondHalf += digit;

        // 12. Сумма цифр четных и нечетных разрядов
        if (index % 2 == 0)
            evenSum += digit;
        else
            oddSum += digit;

        // Запоминаем предпоследнюю и вторую цифры
        if (index == 2) secondDigit = digit;
        if (index == totalDigits - 1) secondLastDigit = digit;

        index++;
    }

    // 8. Произведение предпоследней и второй цифры
    productSecondAndSecondLast = secondDigit * secondLastDigit;

    printf("1. Количество цифр 3: %d\n", count3);
    printf("2. Число повторений последней цифры: %d\n", lastDigitCount);
    printf("3. Количество четных цифр: %d\n", evenCount);
    printf("4. Количество цифр больше 5: %d\n", greater5Count);
    printf("5. Сумма нечетных цифр: %d\n", sumOdd);
    printf("6. Сумма цифр больше или равно 7: %d\n", sumGreaterOrEqual7);
    printf("7. Произведение всех цифр, исключая 0: %lld\n", productNoZero);
    printf("8. Произведение предпоследней и второй цифры: %lld\n", productSecondAndSecondLast);
    printf("9. Сумма четных цифр, исключая последнюю: %d\n", evenSumExcludingLast);
    printf("10. Количество рядом расположенных одинаковых цифр: %d\n", adjacentSameCount);
    printf("11. Сумма первой половины цифр: %d, Сумма второй половины цифр: %d\n", sumFirstHalf, sumSecondHalf);
    if (sumFirstHalf == sumSecondHalf)
        printf("Суммы первой и второй половины цифр равны.\n");
    else
        printf("Суммы первой и второй половины цифр не равны.\n");
    printf("12. Произведение сумм цифр четных и нечетных разрядов: %d\n", evenSum * oddSum);

    return 0;
}
