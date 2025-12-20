#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1010

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int arr[], int n, int *steps) {
    for (int i = 1; i < n; ++i) {
        int index = i;
        int value = arr[i];
        while (index > 0 && arr[index - 1] > value) {
            (*steps) += 2;
            arr[index] = arr[index - 1];
            index--;
        }
        (*steps)++;

        arr[index] = value;
        (*steps)++;
    }
}

void bubbleSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            (*steps)++;
            if (arr[j - 1] > arr[j]) {
                swap(arr + j - 1, arr + j);
                (*steps) += 3;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n; ++i) {
        int index = i;
        for (int j = i + 1; j < n; ++j) {
            (*steps)++;
            if (arr[j] < arr[index]) {
                index = j;
                (*steps)++;
            }
        }
        (*steps)++;
        if (index != i) {
            swap(arr + i, arr + index);
            (*steps) += 3;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void copy(int n, int from[], int to[]) {
    for (int i = 0; i < n; ++i) to[i] = from[i];
}

void benchMark(int n) {
    int loopTimes = 10000;

    int arr[MAX], tmp[MAX];
    int avgA = 0, avgB = 0, avgC = 0;
    for (int t = 0; t < loopTimes; ++t) {
        generateArray(tmp, n, 1, 1000);

        copy(n, tmp, arr);
        insertionSort(arr, n, &avgA);

        copy(n, tmp, arr);
        bubbleSort(arr, n, &avgB);

        copy(n, tmp, arr);
        selectionSort(arr, n, &avgC);
    }
    avgA /= loopTimes;
    avgB /= loopTimes;
    avgC /= loopTimes;

    printf("---- N = %d ----\n", n);
    printf("Average steps: \n");
    printf("Insertion sort: %d\n", avgA);
    printf("Bubble sort: %d\n", avgB);
    printf("Selection sort: %d\n", avgC);
    puts("\n");
}

int main() {
    benchMark(10);
    benchMark(20);
    benchMark(50);
    benchMark(100);

    printf("Bubble sort ton nhieu thao tac nhat\n");
    printf("Insertion va Selection on dinh hon voi bo du lieu ngau nhien");
    return 0;
}
