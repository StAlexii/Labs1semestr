#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* list) {
    *list = NULL;
}

void insertfront(List* list, int val) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = val;
    strcpy(new_item->name, ""); // Clear name field
    new_item->next = *list;
    *list = new_item;
}

void insertback(List* list, int val) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = val;
    strcpy(new_item->name, ""); // Clear name field
    new_item->next = NULL;

    if (*list == NULL) {
        *list = new_item;
    }
    else {
        struct listitem* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_item;
    }
}

void insertfront_name(List* list, char* str) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = 0; // Default number
    strncpy(new_item->name, str, sizeof(new_item->name) - 1);
    new_item->name[sizeof(new_item->name) - 1] = '\0'; // Null-terminate
    new_item->next = *list;
    *list = new_item;
}

void insertback_name(List* list, char* str) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = 0; // Default number
    strncpy(new_item->name, str, sizeof(new_item->name) - 1);
    new_item->name[sizeof(new_item->name) - 1] = '\0'; // Null-terminate
    new_item->next = NULL;

    if (*list == NULL) {
        *list = new_item;
    }
    else {
        struct listitem* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_item;
    }
}

bool isempty(List* list) {
    return *list == NULL;
}

int length(List list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

void destroyItem(List* list, List node) {
    if (*list == NULL || node == NULL) {
        return;
    }

    if (*list == node) {
        *list = node->next;
        free(node);
        return;
    }

    struct listitem* current = *list;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
        free(node);
    }
}

struct listitem* getitem_number(List list, int n) {
    while (list != NULL) {
        if (list->number == n) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

struct listitem* getitem_name(List list, char* str) {
    while (list != NULL) {
        if (strcmp(list->name, str) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}
