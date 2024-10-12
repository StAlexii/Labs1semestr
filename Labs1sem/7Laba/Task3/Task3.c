#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {
	system("color F0");

	setlocale(LC_ALL, "RUS");

	float v, z;

    printf("введите степень 2, от 0 до 63\n");
    scanf_s("%f", &z);

    v = pow(2, z);

    printf("%f ^ %f = %f, Степень:", 2, z, v);

    if (v < 1024)
        printf("");
    else if (v < 1048576)
        printf("K");
    else if (v < 1073741824)
        printf("M");
    else if (v < 1099511627776)
        printf("G");
    else if (v < 1125899906842624)
        printf("T");
    else if (v < 1152921504606846976)
        printf("P");
    else
        printf("E");


    
}

