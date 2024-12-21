#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include <locale.h>
//10
void initlist(List* list) {
    *list = NULL;
}

void insertfront(List* list, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = val;
    strcpy(newNode->name, "");
    newNode->next = *list;
    *list = newNode;
}

void insertback(List* list, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = val;
    strcpy(newNode->name, "");
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
    }
    else {
        List temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertfront_by_name(List* list, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = 0;
    strcpy(newNode->name, str);
    newNode->next = *list;
    *list = newNode;
}

void insertback_by_name(List* list, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = 0;
    strcpy(newNode->name, str);
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
    }
    else {
        List temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool isempty(List list) {
    return list == NULL;
}

int length(List list) {
    int len = 0;
    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

void destroyItem(List* list, List node) {
    if (*list == NULL || node == NULL) return;

    if (*list == node) {
        *list = node->next;
        free(node);
        return;
    }

    List temp = *list;
    while (temp->next != NULL && temp->next != node) {
        temp = temp->next;
    }

    if (temp->next == node) {
        temp->next = node->next;
        free(node);
    }
}

List getitem_by_number(List list, int n) {
    while (list != NULL) {
        if (list->number == n) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

List getitem_by_name(List list, char* str) {
    while (list != NULL) {
        if (strcmp(list->name, str) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

int main() {
    List myList;
    initlist(&myList);
    system("color F0");
    setlocale(LC_ALL, "ru");
    int d1, d2, d3, d4, d5;

    printf("���� ������? %s\n", isempty(myList) ? "���" : "��");

    insertfront(&myList, 10);
    insertback(&myList, 20);
    insertfront_by_name(&myList, "������");
    insertback_by_name(&myList, "���������");

    
    printf("������� ����� ��������\n");
    scanf_s("%d", &d1);

    List foundByNumber = getitem_by_number(myList, d1);
    if (foundByNumber) {
        printf("������� ���� � ������: %d\n", foundByNumber->number);
    }
    else {
        printf("������� � ������� %d �� ������.\n", d1);
    }

    List foundByName1 = getitem_by_name(myList, "���������");
    List foundByName2 = getitem_by_name(myList, "������");
    if (foundByName1) {
        printf("������� � ������ %s ���� � ������\n", foundByName1->name);
    }
    else {
        printf("������� � ������ '���������' �� ������.\n");
    }

    printf("������ �����: %d\n", length(myList));

    printf("������� �� ������ ��� �����?");
    scanf_s("%d", &d4);

    if (d4 == 1) {
        destroyItem(&myList, foundByNumber);
        printf("����� ����� �������� �������� � ������� %d: %d\n", d1, length(myList));
    }
    else {
        printf("������� ������ ��� ���������?");
        scanf_s("%d", &d5);
        if (d5 == 1) {
            destroyItem(&myList, foundByName2);
            printf("����� ����� �������� �������� � ������ %s: %d\n", "������", length(myList));
        }
        else {
            destroyItem(&myList, foundByName1);
            printf("����� ����� �������� �������� � ������ %s: %d\n", "���������", length(myList));
        }

    }

    List temp = myList;
    while (temp != NULL) {
        printf("������� ����� = %d, ��� = %s\n", temp->number, temp->name);
        temp = temp->next;
    }

    while (!isempty(myList)) {
        destroyItem(&myList, myList);
    }

    printf("���� �������");
}