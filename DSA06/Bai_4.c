#include <stdio.h>
#define MAX 1010

typedef struct {
    int head, tail;
    int size;
    int value[MAX];
} queue;

void initQueue(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void put(queue *q, int id);
int get(queue *q);
void cancelRegistration(queue *q, int id);
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

void put(queue *q, int id) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->tail = (q->tail + 1) % MAX;
    q->size += 1;
    q->value[q->tail] = id;
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

void cancelRegistration(queue *q, int id) {
    int pos = q->head;
    int step = 0;
    while (step < q->size && q->value[pos] != id) {
        pos = (pos + 1) % MAX;
        step++;
    }

    if (step == q->size) {
        printf("ID not found!\n");
        return;
    }

    int shifts = q->size - step - 1;
    while (shifts > 0) {
        q->value[pos] = q->value[(pos + 1) % MAX];
        pos = (pos + 1) % MAX;
        shifts -= 1;
    }
    q->tail = (q->tail - 1 + MAX) % MAX;
    q->size -= 1;
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

int main() {
    queue q;
    initQueue(&q);

    printf("Put 101 102 103\n");
    put(&q, 101);
    put(&q, 102);
    put(&q, 103);
    displayQueue(&q);

    printf("Get: %d\n", get(&q));
    displayQueue(&q);

    printf("Cancel 103\n");
    cancelRegistration(&q, 103);
    displayQueue(&q);

    printf("Put 104 105 106\n");
    put(&q, 104);
    put(&q, 105);
    put(&q, 106);
    displayQueue(&q);

    printf("Cancel 105\n");
    cancelRegistration(&q, 105);
    displayQueue(&q);

    printf("Test delete ID 999\n");
    cancelRegistration(&q, 999);

    return 0;
}
