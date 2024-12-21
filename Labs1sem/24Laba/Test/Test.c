// Числа меньше Z пишутся сразу, в [A, B] - в первую очередь, > [A, B] - во вторую очередь 
//8 10 14
#include <stdio.h>
#include<locale.h>
#include <stdlib.h>
#include "stack.h"
#include "list2.h"

void initQueue(queue_list* que) {
    que->queue = NULL;
    que->front = NULL;
    que->back = NULL;
}
//запись элемента в конец очереди
void enQueue(queue_list* que, TYPE element) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = NULL;
    if (que->back == NULL) {
        que->front = que->back = temp;
        return;
    }
    que->back->next = temp;
    que->back = temp;
}
//извлечение элемента из начала очереди
TYPE deQueue(queue_list* que) {
    if (que->front == NULL)
        return -1;
    struct Node* temp = que->front;
    TYPE data = temp->data;
    que->front = que->front->next;
    if (que->front == NULL)
        que->back = NULL;
    free(temp);
    return data;
}

int isEmpty(queue_list* que) {
    return que->front == NULL;
}

void processFile(const char* inputFileName, const char* outputFileName, int z, int a, int b) {
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");

    queue_list queue1, queue2, queue3;
    initQueue(&queue1);
    initQueue(&queue2);
    initQueue(&queue3);

    int num;
    while (fscanf(inputFile, "%d", &num) != EOF) {
        if (num < z) {
            enQueue(&queue1, num);
        }
        else if (num >= a && num <= b) {
            enQueue(&queue2, num);
        }
        else {
            enQueue(&queue3, num);
        }
    }

    // Запись чисел, меньших z
    while (!isEmpty(&queue1)) {
        fprintf(outputFile, "%d ", deQueue(&queue1));
    }

    // Запись чисел из диапазона [a, b]
    while (!isEmpty(&queue2)) {
        fprintf(outputFile, "%d ", deQueue(&queue2));
    }

    // Запись всех остальных чисел
    while (!isEmpty(&queue3)) {
        fprintf(outputFile, "%d ", deQueue(&queue3));
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    int z, a, b;
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";

    printf("Введите число, меньше которого другие\n");
    scanf_s("%d", &z);

    printf("Введите диапазон [a, b]: ");
    scanf_s("%d %d", &a, &b);

    processFile(inputFileName, outputFileName, z, a, b);
}