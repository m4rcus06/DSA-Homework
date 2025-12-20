#include <stdio.h>

void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

int main() {
    int n;
    float arr[1010];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%f", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%g ", arr[i]);
    }
    return 0;
}
