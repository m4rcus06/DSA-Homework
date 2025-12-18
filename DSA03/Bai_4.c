#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

void deleteArray(int a[], int *n, int index, int *steps) {
    if (index < 0 || index >= (*n)) return;
    for (int i = index; i + 1 < (*n); ++i) {
        a[i] = a[i + 1];
        (*steps)++;
    }
    (*n)--;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            (*steps)++;
            if (arr[j - 1] > arr[j]) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

void caseA(int arr[], int *n, int k, int *steps) {
    *steps = 0;
    int index = 0;
    while (index < (*n)) {
        (*steps)++;
        if (arr[index] >= k) {
            deleteArray(arr, n, index, steps);
        } else {
            index++;
        }
    }
}

void caseB(int arr[], int *n, int k, int *steps) {
    *steps = 0;
    bubbleSort(arr, *n, steps);
    int startPos = 0;
    while (startPos < (*n) && arr[startPos] < k) {
        startPos++;
        (*steps)++;
    }
    *n = startPos;
}

void generateArr(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void copy(int from[], int to[], int n) {
    for (int i = 0; i < n; ++i) to[i] = from[i];
}

void compare(int arrSize, int k, int loopTimes) {
    int arr[MAX], tmpArr[MAX];
    int avgStepsA = 0, avgStepsB = 0;
    for (int i = 0; i < loopTimes; ++i) {
        generateArr(tmpArr, arrSize, 1998, 2023);

        copy(tmpArr, arr, arrSize);
        int n = arrSize;
        int curStepsA = 0;
        caseA(arr, &n, k, &curStepsA);
        avgStepsA += curStepsA;

        copy(tmpArr, arr, arrSize);
        n = arrSize;
        int curStepsB = 0;
        caseB(arr, &n, k, &curStepsB);
        avgStepsB += curStepsB;
    }
    avgStepsA /= loopTimes;
    avgStepsB /= loopTimes;

    printf("---- Loop Times = %d ----\n", loopTimes);
    printf("case A: %d\n", avgStepsA);
    printf("case B: %d\n", avgStepsB);
    printf("\n");
}

int main() {
    time_t t;
    srand((unsigned)time(&t));

    compare(100, 2016, 100000);
    printf("Thuat toan A toi uu hon thuat toan B dua tren so buoc trung binh\n");
    printf("Thuat toan B luon mat ~ 4950 buoc de sort, trong khi thuat toan A linh hoat hon voi bo du lieu ngau nhien\n");
    return 0;
}
