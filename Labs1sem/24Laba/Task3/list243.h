#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, const char* value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = (char*)malloc(strlen(value) + 1);
    strcpy(temp->data, value);
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

char* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;

    Node* temp = q->front;
    char* item = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return item;
}

void processLine(const char* line, char* result) {
    char digits[256] = { 0 };
    int pos = 0, digitPos = 0;

    for (const char* ptr = line; *ptr; ptr++) {
        if (isdigit(*ptr)) {
            digits[digitPos++] = *ptr;
        }
        else {
            result[pos++] = *ptr;
        }
    }
    strcat(result, digits);
}

void processFile(const char* inputFile, const char* outputFile) {
    FILE* file = fopen(inputFile, "r");
    if (!file) return;

    Queue* q = createQueue();
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        enqueue(q, line);
    }

    fclose(file);

    FILE* outFile = fopen(outputFile, "w");
    char result[512];

    char* item;
    while ((item = dequeue(q)) != NULL) {
        memset(result, 0, sizeof(result));
        processLine(item, result);
        fprintf(outFile, "%s\n", result);
        free(item);
    }

    fclose(outFile);
    free(q);
}








#endif