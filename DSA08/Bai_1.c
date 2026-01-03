#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1010

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int left, int right) {
    int pivot = right;
    right--;
    while (left < right) {
        while (a[left] < a[pivot]) left++;
        while (a[right] > a[pivot]) right--;
        if (left < right) {
            swap(a + left, a + right);
            left++;
            right--;
        }
    }
    swap(a + left, a + pivot);
    return left;
}

void quickSort(int a[], int left, int right, int *steps) {
    if (left >= right) return;
    *steps += 1;
    int mid = partition(a, left, right);
    quickSort(a, left, mid - 1, steps);
    quickSort(a, mid + 1, right, steps);
}

void generateArray(int a[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) a[i] = min + rand() % (max - min + 1);
}

void makeFreqTable(int n, int k) {
    int freq[MAX] = {}, a[MAX];
    int avgSteps = 0;
    int max = 0;
    for (int i = 0; i < k; ++i) {
        generateArray(a, n, 1, 2026);
        int curSteps = 0;
        quickSort(a, 0, n - 1, &curSteps);

        avgSteps += curSteps;
        freq[curSteps]++;
        if (max < curSteps) max = curSteps;
    }
    avgSteps /= k;

    printf("---- N = %d, K = %d ----\n", n, k);
    printf("Average steps: %d\n", avgSteps);
    for (int i = 0; i <= max; ++i) {
        printf("freq[%d] = %d\n", i, freq[i]);
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));

    int k[] = {10, 100, 1000, 10000};
    for (int i = 0; i < 4; ++i) {
        makeFreqTable(10, k[i]);
    }
    return 0;
}
