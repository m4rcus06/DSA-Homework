#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

int findNext(int arr[], int n, int start, int value, int *steps) {
    for (int i = start; i < n; ++i) {
        (*steps)++;
        if (arr[i] == value) return i;
    }
    return -1;
}

void deleteArray(int arr[], int *n, int position, int *steps) {
    for (int i = position; i + 1 < (*n); ++i) {
        (*steps)++;
        arr[i] = arr[i + 1];
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

void copy(int n, int from[], int to[]) {
    for (int i = 0; i < n; ++i) to[i] = from[i];
}

void firstOpt(int arr[], int *n, int *steps) {
    for (int i = 0; i < (*n); ++i) {
        int value = arr[i];
        int p = findNext(arr, *n, i + 1, value, steps);
        while (p != -1) {
            deleteArray(arr, n, p, steps);
            p = findNext(arr, *n, i + 1, value, steps);
        }
    }
}

void secondOpt(int arr[], int *n, int *steps) {
    bubbleSort(arr, *n, steps);

    int resultArr[MAX];
    int newSize = 1;
    resultArr[0] = arr[0];
    for (int i = 1; i < (*n); ++i) {
        (*steps)++;
        if (arr[i] != arr[i - 1]) {
            resultArr[newSize++] = arr[i];
        }
    }

    *n = newSize;
    copy(newSize, resultArr, arr);
    *steps += newSize;
}

void generateArr(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void benchMark(int arrSize, int numLoops) {
    int arr[MAX], brr[MAX];

    int avgA = 0, avgB = 0;
    for (int t = 0; t < numLoops; ++t) {
        generateArr(arr, arrSize, 1, 100);
        copy(arrSize, arr, brr);

        int stepsA = 0;
        int a_size = arrSize;
        firstOpt(arr, &a_size, &stepsA);
        avgA += stepsA;

        int stepsB = 0;
        int b_size = arrSize;
        secondOpt(brr, &b_size, &stepsB);
        avgB += stepsB;
    }
    avgA /= numLoops;
    avgB /= numLoops;

    printf("---- Phuong an 1 ----\n");
    printf("Average steps: %d\n\n", avgA);
    printf("---- Phuong an 2 ----\n");
    printf("Average steps: %d\n", avgB);

    if (avgA < avgB) {
        printf("Phuong an 1 tot hon");
    } else {
        printf("Phuong an 2 tot hon");
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));

    benchMark(100, 100000);
    return 0;
 }
