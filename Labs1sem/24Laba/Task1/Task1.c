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

// Проверить, если стек пуст
int isempty(stack* s) {
    return s->top == 0;
}

// Проверить, если стек полон
int isfull(stack* s) {
    return s->top == NMAX - 1;
}

// Добавить элемент в стек
int push(stack* s, TYPE a) {
    if (isfull(s)) {
        printf("Стек полон, невозможно добавить элемент '%c'\n", a);
        return 0;
    }
    s->data[++(s->top)] = a;
    return 1;
}

// Извлечь элемент из стека
TYPE pop(stack* s) {
    if (isempty(s)) {
        printf("Стек пуст, невозможно извлечь элемент\n");
        return 0;
    }
    return s->data[(s->top)--];
}

// Вернуть элемент на вершине стека
TYPE top(stack* s) {
    if (isempty(s)) {
        printf("Стек пуст, вершины нет\n");
        return 0;
    }
    return s->data[s->top];
}

// Вывести содержимое стека (без изменения)
void display(stack* s) {
    int i = s->top;
    while (i > 0)
        printf(FTYPE, s->data[i--]);
    printf("\n");
}

int main() {
    stack s;
    s.top = 0; // Инициализация стека
    setlocale(LC_ALL, "ru");
    system("color F0");

    char input[NMAX];
    printf("Введите строку");
    fgets(input, NMAX, stdin);

    // Добавление символов в стек
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        push(&s, input[i]);
    }

    printf("Содержимое стека: \n");
    display(&s);

    return 0;
}
