#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char material[20];
    int length;
    int ceilingWidth;
    int wallHeight;
} cornice_t;

typedef struct node {
    cornice_t data;
    struct node* next;
} node;

node* arrayToList(cornice_t* array, int size) {
    node* head = NULL;
    node* tail = NULL;

    for (int i = 0; i < size; i++) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = array[i];
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void merge(node** headRef) {
    node* head = *headRef;
    if (!head || !head->next) return;

    node* mid = head;
    node* fast = head->next;

    while (fast && fast->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    merge(&left);
    merge(&right);

    node* merged = NULL;
    node** tail = &merged;

    while (left && right) {
        if (left->data.length <= right->data.length) {
            *tail = left;
            left = left->next;
        }
        else {
            *tail = right;
            right = right->next;
        }
        tail = &(*tail)->next;
    }

    *tail = left ? left : right;
    *headRef = merged;
}

void printList(node* head) {
    while (head) {
        printf("Материал: %s, Длина: %d, Ширина: %d, Высота: %d\n",
            head->data.material, head->data.length, head->data.ceilingWidth, head->data.wallHeight);
        head = head->next;
    }
}
void main(){
    system("color F0");
    setlocale(LC_ALL, "ru");

    cornice_t array[] = {
    {"Wood",10,5,3},
    {"Aluminium",8,4,2},
    {"Plastic", 12,5,4 },
    {"Steel", 6,3,2 },
    {"Metal", 9,6,3}
    };
    int size = sizeof(array) / sizeof(array[0]);

    node* list = arrayToList(array, size);
    merge(&list);

    printf("Отсортированный список:\n");
    printList(list);

    return 0;
}