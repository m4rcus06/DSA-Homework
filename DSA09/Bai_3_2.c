#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#define GARB 30052006

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* end;
} queue;

void init(queue* q) {
    q->front = q->end = NULL;
}

int isEmpty(queue* q) {
    return q->front == NULL;
}

void put(int value, queue* q) {
    Node* newNode = malloc(sizeof(*newNode));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->end = newNode;
    } else {
        q->end->next = newNode;
        q->end = newNode;
    }
}

int get(queue* q) {
    if (isEmpty(q)) return GARB;
    Node* tmp = q->front;
    int value = tmp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->end = NULL;
    }
    free(tmp);
    return value;
}

void displayQueue(queue* q) {
    Node* cur = q->front;
    printf("QUEUE:");
    while (cur != NULL) {
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    queue q;
    init(&q);

    printf("PUT 10 20 30");
    put(10, &q);
    put(20, &q);
    put(30, &q);
    displayQueue(&q);

    printf("Get: %d\n", get(&q));
    displayQueue(&q);

    printf("PUT 40");
    put(40, &q);
    displayQueue(&q);

    return 0;
}
