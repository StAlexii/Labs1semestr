#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <locale.h>


void initlist(List* list) {
    *list = NULL;
}

void array_to_list(cornice_t* array, int size, List* list) {
    for (int i = 0; i < size; i++) {
        insertback(list, array[i]);
    }
}

void insertback(List* list, cornice_t item) {
    List new_node = (List)malloc(sizeof(struct listitem));

    new_node->data = item;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    }
    else {
        List temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int isempty(List list) {
    return list == NULL;
}

void display_cornices(List list) {
    while (list != NULL) {
        printf("Материал: %s, Длина: %d, Ширина: %d, Высота: %d\n",
            list->data.material, list->data.length,
            list->data.ceilingWidth, list->data.wallHeight);
        list = list->next;
    }
}

List find_by_material(List list, const char* material) {
    while (list != NULL) {
        if (strcmp(list->data.material, material) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

List merge(List left, List right) { //параметры сортировки
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data.length <= right->data.length) {
        left->next = merge(left->next, right);
        return left;
    }
    else {
        right->next = merge(left, right->next);
        return right;
    }
}

//деление для сортировки
void split(List head, List* left, List* right) {
    List slow = head;
    List fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

List merge_sort(List head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    List left = NULL, right = NULL;
    split(head, &left, &right);

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

void destroyItem(List* list, List node) {
    if (*list == NULL || node == NULL) return;

    if (*list == node) {
        *list = node->next;
        free(node);
        return;
    }

    List prev = *list;
    while (prev->next != NULL && prev->next != node) {
        prev = prev->next;
    }

    if (prev->next == node) {
        prev->next = node->next;
        free(node);
    }
}

int length(List list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

int main() {
    system("color F0");
    setlocale(LC_ALL, "ru");

    char material[40];

    cornice_t cornices[] = {
        {"Wood", 200, 30, 40},
        {"Metal", 150, 25, 35},
        {"Plastic", 180, 28, 38},
    };

    int size = sizeof(cornices) / sizeof(cornices[0]);

    List cornice_list;
    initlist(&cornice_list);

    array_to_list(cornices, size, &cornice_list);

    printf("Начальный лист:\n");
    display_cornices(cornice_list);

    cornice_list = merge_sort(cornice_list);
    printf("\nОтсортированный по высоте:\n");
    display_cornices(cornice_list);

    printf("Введите материал для поиска: ");
    scanf("%s", material);

    List found = find_by_material(cornice_list, material);
    if (found != NULL) {
        printf("\nНайден карниз: Материал: %s, Длина: %d, Ширина: %d, Высота: %d\n",
            found->data.material, found->data.length,
            found->data.ceilingWidth, found->data.wallHeight);
    }
    else {
        printf("\nКарниз с материалом '%s' не найден.\n", material);
    }

    while (!isempty(cornice_list)) {
        destroyItem(&cornice_list, cornice_list);
    }

}
