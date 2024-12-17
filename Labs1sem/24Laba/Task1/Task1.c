#include <stdio.h>
#include <string.h>
#include <locale.h>

#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct Stack {
    int top;
    TYPE data[NMAX];
} stack;

// ���������, ���� ���� ����
int isempty(stack* s) {
    return s->top == 0;
}

// ���������, ���� ���� �����
int isfull(stack* s) {
    return s->top == NMAX - 1;
}

// �������� ������� � ����
int push(stack* s, TYPE a) {
    if (isfull(s)) {
        printf("���� �����, ���������� �������� ������� '%c'\n", a);
        return 0;
    }
    s->data[++(s->top)] = a;
    return 1;
}

// ������� ������� �� �����
TYPE pop(stack* s) {
    if (isempty(s)) {
        printf("���� ����, ���������� ������� �������\n");
        return 0;
    }
    return s->data[(s->top)--];
}

// ������� ������� �� ������� �����
TYPE top(stack* s) {
    if (isempty(s)) {
        printf("���� ����, ������� ���\n");
        return 0;
    }
    return s->data[s->top];
}

// ������� ���������� ����� (��� ���������)
void display(stack* s) {
    int i = s->top;
    while (i > 0)
        printf(FTYPE, s->data[i--]);
    printf("\n");
}

int main() {
    stack s;
    s.top = 0; // ������������� �����
    setlocale(LC_ALL, "ru");
    system("color F0");

    char input[NMAX];
    printf("������� ������");
    fgets(input, NMAX, stdin);

    // ���������� �������� � ����
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        push(&s, input[i]);
    }

    printf("���������� �����: \n");
    display(&s);

    return 0;
}
