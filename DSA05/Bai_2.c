#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int index = i;
        int value = arr[i];
        while (index > 0 && arr[index - 1] < value) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j - 1] < arr[j]) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[index]) {
                index = j;
            }
        }
        if (index != i) {
            swap(arr + i, arr + index);
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

int main() {
    time_t t;
    srand((unsigned)time(&t));

    int n = 10;
    int arr[1010], tmp[1010];

    generateArray(tmp, n, 1, 10);

    printf("Array: ");
    printArray(tmp, n);

    copy(n, tmp, arr);
    insertionSort(arr, n);
    printf("Insertion sort: ");
    printArray(arr, n);

    copy(n, tmp, arr);
    bubbleSort(arr, n);
    printf("Bubble sort: ");
    printArray(arr, n);

    copy(n, tmp, arr);
    selectionSort(arr, n);
    printf("Selection sort: ");
    printArray(arr, n);
    return 0;
}

/*
y tuong: Chi can thay doi toan tu so sanh
*/
