#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#define GARB 30052006

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} stack;

void init(stack* s);
int isEmpty(stack* s);
void push(int value, stack* s);
int pop(stack* s);
void displayStack(stack* s);

void init(stack* s) {
    s->top = NULL;
}

int isEmpty(stack* s) {
    return (s->top == NULL);
}

void push(int value, stack* s) {
    Node* newNode = malloc(sizeof(*newNode));
    newNode->next = s->top;
    newNode->data = value;
    s->top = newNode;
}

int pop(stack* s) {
    if (s->top == NULL) return GARB;
    Node* tmp = s->top;
    s->top = s->top->next;

    int value = tmp->data;
    free(tmp);
    return value;
}

void displayStack(stack* s) {
    Node* cur = s->top;
    printf("STACK:");
    while (cur != NULL) {
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n\n");
}

int main() {
    stack myStack;
    init(&myStack);

    printf("--- Kiem tra Push ---\n");
    printf("10 20 30");
    push(10, &myStack);
    push(20, &myStack);
    push(30, &myStack);
    displayStack(&myStack);

    printf("--- Kiem tra isEmpty ---\n");
    if (!isEmpty(&myStack)) {
        printf("Stack hien tai dang co du lieu.\n\n");
    }

    printf("--- Kiem tra Pop ---\n");
    printf("Pop lan 1: %d\n", pop(&myStack));
    printf("Pop lan 2: %d\n", pop(&myStack));
    displayStack(&myStack);

    printf("--- Kiem tra Pop den khi rong ---\n");
    printf("Pop lan 3: %d\n", pop(&myStack));
    int result = pop(&myStack);
    if (result == GARB) {
        printf("Pop lan 4: Stack da rong (Tra ve GARB)\n");
    }

    return 0;
}
