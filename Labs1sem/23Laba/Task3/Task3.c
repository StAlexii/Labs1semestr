#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Cornice {
    int length;
    int ceilingWidth;
    int wallHeight;
    char material[20];
} cornice_t;

// Convert array of cornices to linked list
void array_to_list(cornice_t* array, int size, List* list) {
    for (int i = 0; i < size; i++) {
        insertback(list, array[i]);
    }
}

// Display the list of cornices
void display_cornices(List list) {
    while (list != NULL) {
        printf("Material: %s, Length: %d, Ceiling Width: %d, Wall Height: %d\n",
            list->data.material, list->data.length,
            list->data.ceilingWidth, list->data.wallHeight);
        list = list->next;
    }
}

// Find a cornice by material name
List find_by_material(List list, const char* material) {
    while (list != NULL) {
        if (strcmp(list->data.material, material) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

// Merge function for merge sort
List merge(List left, List right) {
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

// Split the list into two halves
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

// Merge sort for the linked list
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

int main() {
    cornice_t cornices[] = {
        {"Wood", 200, 30, 40},
        {"Metal", 150, 25, 35},
        {"Plastic", 180, 28, 38},
    };

    int size = sizeof(cornices) / sizeof(cornices[0]);

    List cornice_list;
    initlist(&cornice_list);

    // Convert array to linked list
    array_to_list(cornices, size, &cornice_list);

    printf("Original List:\n");
    display_cornices(cornice_list);

    // Sort the list
    cornice_list = merge_sort(cornice_list);
    printf("\nSorted List by Length:\n");
    display_cornices(cornice_list);

    // Find an element by material
    const char* search_material = "Metal";
    List found = find_by_material(cornice_list, search_material);
    if (found != NULL) {
        printf("\nFound Cornice: Material: %s, Length: %d, Ceiling Width: %d, Wall Height: %d\n",
            found->data.material, found->data.length,
            found->data.ceilingWidth, found->data.wallHeight);
    }
    else {
        printf("\nCornice with material '%s' not found.\n", search_material);
    }

    // Free the list
    while (!isempty(cornice_list)) {
        destroyItem(&cornice_list, cornice_list);
    }

    return 0;
}
