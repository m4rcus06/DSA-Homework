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

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int index = i;
        int value = arr[i];
        while (index > 0 && arr[index - 1] > value) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
}

int main() {
    int N, K;
    int arr[MAX];
    scanf("%d%d", &K, &N);
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    insertionSort(arr, N);

    int totalTime[MAX] = {};
    queue q;
    initQueue(&q);
    for (int i = 0; i < N; ++i) {
        if (isFull(&q)) {
            int index = get(&q);
            totalTime[index % K] -= arr[index];
        }
        put(&q, i);
        totalTime[i % K] += arr[i];
    }

    int maxTime = 0;
    for (int i = 0; i < K; ++i) {
        if (totalTime[i] > maxTime) maxTime = totalTime[i];
    }
    printf("%d\n", maxTime);
    return 0;
}
