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

    printf("������ char: %lu ����\n", (unsigned long)(&c + 1) - (unsigned long)&c);

    printf("������ short int: %lu ����\n", (unsigned long)(&si + 1) - (unsigned long)&si);

    printf("������ unsigned short int: %lu ����\n", (unsigned long)(&usi + 1) - (unsigned long)&usi);

    printf("������ int: %lu ����\n", (unsigned long)(&i + 1) - (unsigned long)&i);

    printf("������ unsigned char: %lu ����\n", (unsigned long)(&uc + 1) - (unsigned long)&uc);

    printf("������ wchar_t: %lu ����\n", (unsigned long)(&wc + 1) - (unsigned long)&wc);

    printf("������ long long int: %lu ����\n", (unsigned long)(&lli + 1) - (unsigned long)&lli);

    printf("������ size_t: %lu ����\n", (unsigned long)(&sz + 1) - (unsigned long)&sz);

    printf("������ float: %lu ����\n", (unsigned long)(&f + 1) - (unsigned long)&f);

    printf("������ double: %lu ����\n", (unsigned long)(&d + 1) - (unsigned long)&d);

    printf("������ signed int: %lu ����\n", (unsigned long)(&si2 + 1) - (unsigned long)&si2);

}