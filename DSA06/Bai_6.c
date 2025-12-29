#include <stdio.h>
#include <stdlib.h>
#define MAX 1010

/*STRUCT*/
typedef struct {
    int ID;
    int active;
    int current_floor;
} User;

typedef struct {
    int head, tail;
    int size;
    int value[MAX];
} queue;

void initQueue(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void put(queue *q, int value);
int get(queue *q);
void displayQueue(queue *q);

void initQueue(queue *q) {
    q->head = 0;
    q->tail = -1;
    q->size = 0;
}

int isFull(queue *q) {
    return (q->size == MAX);
}

int isEmpty(queue *q) {
    return (q->size == 0);
}

void put(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->tail = (q->tail + 1) % MAX;
    q->size += 1;
    q->value[q->tail] = value;
}

void remove_queue(queue *q, int ID) {
    int index = q->head;
    int step = 0;
    while (step < q->size && q->value[index] != ID) {
        index = (index + 1) % MAX;
        step++;
    }

    if (step == q->size) return;

    int shifts = q->size - step - 1;
    while (shifts > 0) {
        q->value[index] = q->value[(index + 1) % MAX];
        index = (index + 1) % MAX;
        shifts--;
    }
    q->tail = (q->tail - 1 + MAX) % MAX;
    q->size -= 1;
}

int get(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int res = q->value[q->head];
    q->head = (q->head + 1) % MAX;
    q->size -= 1;
    return res;
}

void displayQueue(queue *q) {
    printf("Queue:");
    int index = q->head;
    for (int i = 0; i < q->size; ++i) {
        printf(" %d", q->value[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

/*Processing*/

int N, M;
int capacity[MAX];
queue floor_connection[MAX];
User users[MAX];

void readInput(int *n, int *m, int capacity[]) {
    scanf("%d%d", n, m);
    for (int i = 0; i < *n; ++i) {
        scanf("%d", &capacity[i]);
    }
}

/*Cac function cua wifi*/
void connect(User *u, int floor);
void disconnect(User *u);

void connect(User *u, int floor) {
    if (u->active == 1) {
        disconnect(u);
        u->active = 0;
        if (abs(u->current_floor - floor) > 1) {
            printf("Abnormal connection!\n");
            return;
        }
    }

    queue *ptr = &floor_connection[floor];
    if (ptr->size == capacity[floor]) {
        printf("Floor %d is full, please move to another\n", floor);
        return;
    }

    u->active = 1;
    u->current_floor = floor;
    put(ptr, u->ID);
    printf("User id %d connected at floor %d\n", u->ID, u->current_floor);
}

void disconnect(User *u) {
    int floor = u->current_floor;
    queue *ptr = &floor_connection[floor];
    remove_queue(ptr, u->ID);
    u->active = 0;
    printf("User id %d disconnected at floor %d\n", u->ID, u->current_floor);
}

int main() {
    N = 3;
    M = 8;
    capacity[0] = 2; capacity[1] = 1; capacity[2] = 5;

    for (int i = 0; i < N; ++i) initQueue(&floor_connection[i]);
    for (int i = 1; i <= 5; ++i) {
        users[i].active = 0;
        users[i].current_floor = -1;
        users[i].ID = i;
    }

    printf("TEST\n");
    printf("1, 2 connect to 0\n");
    connect(&users[1], 0);
    connect(&users[2], 0);
    printf("Tang 1: ");
    displayQueue(&floor_connection[0]);

    printf("3 connect to 0\n");
    connect(&users[3], 0);

    printf("1 di chuyen sang tang 1\n");
    connect(&users[1], 1);
    printf("Tang 0: ");
    displayQueue(&floor_connection[0]);
    printf("Tang 1: ");
    displayQueue(&floor_connection[1]);

    printf("2 di chuyen sang tang 2\n");
    connect(&users[2], 2);
    printf("Tang 0: ");
    displayQueue(&floor_connection[0]);
    printf("Tang 2: ");
    displayQueue(&floor_connection[2]);
    return 0;
}
