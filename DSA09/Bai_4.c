#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    int size;
    Node* head;
} LinkedList;

void init(LinkedList* list) {
    list->size = 0;
    list->head = NULL;
}

Node* makeNode(int data) {
    Node* node = malloc(sizeof(*node));
    memset(node, 0, sizeof(*node));
    node->data = data;
    return node;
}

Node* insertRecursive(Node* cur, int data, int k) {
    if (k == 1) {
        Node* newNode = makeNode(data);
        newNode->next = cur;
        return newNode;
    }
    cur->next = insertRecursive(cur->next, data, k - 1);
    return cur;
}

void insertAt(int data, int k, LinkedList* list) {
    if (k < 1 || k > list->size + 1) return;
    list->head = insertRecursive(list->head, data, k);
    list->size += 1;
}

Node* removeRecursive(Node* head, int k) {
    if (k == 1) {
        Node* nxt = head->next;
        free(head);
        return nxt;
    }
    head->next = removeRecursive(head->next, k - 1);
    return head;
}

void removeAt(int k, LinkedList* list) {
    if (k < 1 || k > list->size) return;
    list->head = removeRecursive(list->head, k);
    list->size -= 1;
}

void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | data = %d| next node address = %p\n", (void*)&(node->data), node->data, (void*)node->next);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList myList;
    init(&myList);

    int arr[] = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 6; ++i) {
        insertAt(arr[i], i + 1, &myList);
    }

    printf("Before delete:\n");
    printList(&myList);

    removeAt(2, &myList);

    printf("After delete:\n");
    printList(&myList);

    return 0;
}
