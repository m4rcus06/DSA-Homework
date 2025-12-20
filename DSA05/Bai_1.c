#include <stdio.h>

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

int main() {
    int n = 10;
    int a[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int b[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int c[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};


    int stepA = 0, stepB = 0, stepC = 0;
    insertionSort(a, n, &stepA);
    bubbleSort(b, n, &stepB);
    selectionSort(c, n, &stepC);

    printf("Insertion sort: %d\n", stepA);
    printf("Bubble sort: %d\n", stepB);
    printf("Selection sort: %d\n", stepC);
    return 0;
}
