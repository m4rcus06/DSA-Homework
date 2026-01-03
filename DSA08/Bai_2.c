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
        (*steps) += 1;

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

        if (index != i) {
            swap(arr + i, arr + index);
            (*steps) += 3;
        }
    }
}

int partition(int a[], int left, int right, int *steps) {
    int pivot = right;
    right--;
    while (left <= right) {
        while (left <= right && a[left] < a[pivot]) {
            left++;
            (*steps) += 1;
        }
        (*steps) += 1;

        while (left <= right && a[right] > a[pivot]) {
            right--;
            (*steps) += 1;
        }
        (*steps) += 1;

        if (left <= right) {
            swap(a + left, a + right);
            (*steps) += 3;
            left++;
            right--;
        }
    }

    swap(a + left, a + pivot);
    (*steps) += 3;
    return left;
}

void quickSort(int a[], int left, int right, int *steps) {
    if (left >= right) return;
    int mid = partition(a, left, right, steps);
    quickSort(a, left, mid - 1, steps);
    quickSort(a, mid + 1, right, steps);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copy(int n, int from[], int to[]) {
    for (int i = 0; i < n; ++i) to[i] = from[i];
}

void test(int arr[], int n) {
    int temp[MAX];
    int stepsIns = 0, stepsBub = 0, stepsSel = 0, stepsQui = 0;

    printf("==========================================\n");
    printf("N = %d\n", n);
    printf("Array: ");
    printArray(arr, n);
    printf("------------------------------------------\n");

    copy(n, arr, temp);
    insertionSort(temp, n, &stepsIns);
    printf("Insertion Sort: %d steps\n", stepsIns);

    copy(n, arr, temp);
    bubbleSort(temp, n, &stepsBub);
    printf("Bubble Sort:    %d steps\n", stepsBub);

    copy(n, arr, temp);
    selectionSort(temp, n, &stepsSel);
    printf("Selection Sort: %d steps\n", stepsSel);

    copy(n, arr, temp);
    quickSort(temp, 0, n - 1, &stepsQui);
    printf("Quick Sort:     %d steps\n", stepsQui);

    int steps[] = {stepsIns, stepsBub, stepsSel, stepsQui};
    char names[][20] = {"Insertion Sort", "Bubble Sort", "Selection Sort", "Quick Sort"};

    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < 4; i++) {
        if (steps[i] < steps[min_idx]) min_idx = i;
        if (steps[i] > steps[max_idx]) max_idx = i;
    }

    printf("\nKET QUA:\n");
    printf("   NHANH NHAT: %s (%d steps)\n", names[min_idx], steps[min_idx]);
    printf("   CHAM NHAT:  %s (%d steps)\n", names[max_idx], steps[max_idx]);
    printf("\n\n");
}

int main() {
    int n;

    // N = 5
    n = 5;
    int a[] = {3, 2, 9, 7, 5};
    test(a, n);

    //N = 10
    n = 10;
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    test(b, n);

    //N = 20
    n = 20;
    int c[] = {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2};
    test(c, n);

    //N = 20
    n = 20;
    int d[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};
    test(d, n);
    return 0;
}
