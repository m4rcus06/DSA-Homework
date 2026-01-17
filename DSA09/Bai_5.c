#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define MAX_FLOOR 17
#define MAX_ROOM 12

typedef struct Data {
    int floor, room;
    char name;
} Data;

int isSameData(Data a, Data b) {
    return (a.floor == b.floor && a.room == b.room && a.name == b.name);
}

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
} LinkedList;

Node* makeNode(Data data) {
    Node* newNode = malloc(sizeof(*newNode));
    memset(newNode, 0, sizeof(*newNode));
    newNode->data = data;
    return newNode;
}

void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | data = %c P%d.%d| next node address = %p\n", (void*)&(node->data),
                                                                                node->data.name,
                                                                                node->data.floor,
                                                                                node->data.room,
                                                                                (void*)node->next);
        node = node->next;
    }
    printf("\n");
}

int myHotel[MAX_FLOOR + 1][MAX_ROOM + 1];
void allocateRoom(char name, Node** node, int isHead) {
    for (int i = 0; i < MAX_FLOOR; ++i) {
        //ko phai chu doan
        if (isHead == 0 && i == 0) continue;

        for (int j = 1; j <= MAX_ROOM; ++j) {
            if (myHotel[i][j] == 0) {
                myHotel[i][j] = 1;
                Data data = {i, j, name};
                *node = makeNode(data);
                return;
            }
        }
    }
}

LinkedList groups[MAX_FLOOR * MAX_ROOM];
int groupIndex[MAX_FLOOR][MAX_ROOM];
void getGroups(int headFloor, int headRoom) {
    int index = groupIndex[headFloor][headRoom];
    printList(&groups[index]);
}

void checkIn(int groupIndex, char name) {
    LinkedList *gr = &groups[groupIndex];
    allocateRoom(name, &(gr->tail->next), 0);
    gr->tail = gr->tail->next;
}

void removeGroup(Node* head) {
    if (head == NULL) return;
    removeGroup(head->next);
    myHotel[head->data.floor][head->data.room] = 0;
    free(head);
}

Node* removeNode(Node* head, Data data) {
    if (head == NULL) return NULL;
    if (isSameData(head->data, data)) {
        Node* nxt = head->next;
        free(head);
        return nxt;
    }
    head->next = removeNode(head->next, data);
    return head;
}

void checkOut(int groupIndex, Data data) {
    LinkedList *gr = &groups[groupIndex];
    gr->head = removeNode(gr->head, data);

    if (gr->head == NULL) {
        gr->tail = NULL;
    } else {
        Node* cur = gr->head;
        while (cur != NULL) {
            gr->tail = cur;
            cur = cur->next;
        }
    }
}

void groupCheckOut(int groupIndex) {
    LinkedList *gr = &groups[groupIndex];
    removeGroup(gr->head);
    gr->head = gr->tail = NULL;

    printf("HOTEL STATUS:\n");
    for (int n = MAX_FLOOR - 1; n >= 0; --n) {
        for (int m = 1; m <= MAX_ROOM; ++m) {
            printf("%d ", myHotel[n][m]);
        }
        printf("\n");
    }
}

int main() {
    for (int n = MAX_FLOOR - 1; n >= 0; --n) {
        for (int m = 1; m <= MAX_ROOM; ++m) {
            scanf("%d", &myHotel[n][m]);
        }
    }
    //printf("HEHE\n");

    int numGroups;
    scanf("%d", &numGroups);
    while(getchar() != '\n');
    for (int i = 0; i < numGroups; ++i) {
        initLinkedList(&groups[i]);
        int numMembers;
        scanf("%d", &numMembers);

        Node** cur = &(groups[i].head);
        for (int j = 0; j < numMembers; ++j) {
            char name; scanf(" %c", &name);
            printf("%d %d %c\n", j, numMembers, name);
            allocateRoom(name, cur, j == 0);
            groups[i].tail = *cur;
            cur = &((*cur)->next);
        }
        while(getchar() != '\n');

        int headFloor = groups[i].head->data.floor;
        int headRoom = groups[i].head->data.room;
        groupIndex[headFloor][headRoom] = i;
    }
    //printf("HEHE\n");

    for (int i = 0; i < numGroups; ++i) {
        printList(&groups[i]);
    }
    return 0;
}
