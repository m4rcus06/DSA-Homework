#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    int size;
    Node *head;
} LinkedList;

void init(LinkedList *list) {
    list->size = 0;
    list->head = NULL;
}

Node *makeNode(int data) {
    Node *node = malloc(sizeof(*node));
    memset(node, 0, sizeof(*node));
    node->data = data;
    return node;
}

void insertHead(int data, LinkedList *list) {
    Node *newNode = makeNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

void insertAt(int data, int k, LinkedList *list) {
    if (k < 1 || list->size < k - 1) return;
    if (k == 1) {
        insertHead(data, list);
    } else {
        Node *cur = list->head;
        for (int i = 1; i + 1 < k; ++i) cur = cur->next;

        Node *newNode = makeNode(data);
        newNode->next = cur->next;
        cur->next = newNode;
    }
    list->size += 1;
}

void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList myList;
    init(&myList);

    int n = 6;
    int arr[] = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 6; ++i) {
        insertAt(arr[i], i + 1, &myList);
    }
    printf("Before insert:\n");
    printList(&myList);
    insertAt(1, 2, &myList);
    printf("After insert:\n");
    printList(&myList);
    return 0;
}
