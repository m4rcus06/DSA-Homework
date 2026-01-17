#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void init(LinkedList *list) {
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

void insert(LinkedList *list, int data) {
    if (list->head == NULL) {
        list->head = makeNode(data);
        return;
    }

    Node *newNode = makeNode(data);
    if (list->head->data <= data) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *cur = list->head;
        while (cur->next != NULL && cur->next->data > data) {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void delete(LinkedList *list, int value) {
    if (list->head == NULL) return;
    if (list->head->data > value) return;
    if (list->head->data == value) {
        Node *cur = list->head;
        list->head = list->head->next;
        free(cur);
        return;
    }

    Node *cur = list->head;
    while (cur->next != NULL && cur->next->data < value) cur = cur->next;
    //cur->next == NULL || cur->next >= data

    if (cur->next != NULL) {
        if (cur->next->data == value) {
            Node *del = cur->next;
            cur->next = cur->next->next;
            free(del);
        }
    }
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
    LinkedList list;
    init(&list);
    printf("--- INSERT (GIAM DAN) ---\n");
    insert(&list, 5);
    insert(&list, 10);
    insert(&list, 7);
    insert(&list, 12);
    insert(&list, 2);

    printList(&list);

    LinkedList list2;
    init(&list2);
    printf("--- REMOVE (TANG DANG) ---\n");
    insertHead(7, &list2);
    insertHead(2, &list2);
    insertHead(1, &list2);

    printList(&list2);
    delete(&list2, 2);
    printList(&list2);
    return 0;
}
