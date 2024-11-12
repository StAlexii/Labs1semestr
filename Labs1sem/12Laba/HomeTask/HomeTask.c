#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	system("color F0");
    char c;
    short int si;
    unsigned short int usi;
    int i;
    unsigned char uc;
    wchar_t wc;
    long long int lli;
    size_t sz;
    float f;
    double d;
    signed int si2;

    printf("Размер char: %lu байт\n", (unsigned long)(&c + 1) - (unsigned long)&c);

    printf("Размер short int: %lu байт\n", (unsigned long)(&si + 1) - (unsigned long)&si);

    printf("Размер unsigned short int: %lu байт\n", (unsigned long)(&usi + 1) - (unsigned long)&usi);

    printf("Размер int: %lu байт\n", (unsigned long)(&i + 1) - (unsigned long)&i);

    printf("Размер unsigned char: %lu байт\n", (unsigned long)(&uc + 1) - (unsigned long)&uc);

    printf("Размер wchar_t: %lu байт\n", (unsigned long)(&wc + 1) - (unsigned long)&wc);

    printf("Размер long long int: %lu байт\n", (unsigned long)(&lli + 1) - (unsigned long)&lli);

    printf("Размер size_t: %lu байт\n", (unsigned long)(&sz + 1) - (unsigned long)&sz);

    printf("Размер float: %lu байт\n", (unsigned long)(&f + 1) - (unsigned long)&f);

    printf("Размер double: %lu байт\n", (unsigned long)(&d + 1) - (unsigned long)&d);

    printf("Размер signed int: %lu байт\n", (unsigned long)(&si2 + 1) - (unsigned long)&si2);

}