#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n, int *comps) {
    *comps = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            *comps += 1;
            if (arr[j - 1] > arr[j]) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

void generateArr(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void process(int arrSize, int arr[], int loopTimes) {
    int avgComps = 0;
    for (int t = 0; t < loopTimes; ++t) {
        generateArr(arr, arrSize, -1000, 1000);

        int curComps = 0;
        bubbleSort(arr, arrSize, &curComps);
        avgComps += curComps;
    }
    avgComps /= loopTimes;

    printf("---- N = %d ----\n", arrSize);
    printf("---- Loop times = %d ----\n", loopTimes);
    printf("Avgerage Comps = %d ~ N * (N - 1) / 2\n", avgComps);
    printf("\n");
}

int main() {
    int n;
    int arr[MAX];

    time_t t;
    srand((unsigned)time(&t));

    int sizeT = 6;
    int T[] = {10, 20, 50, 100, 1000, 10000};
    for (int size = 10; size <= 100; size += 10) {
        for (int i = 0; i < sizeT; ++i) {
            process(size, arr, T[i]);
        }
    }
    printf("Thuat toan co do phuc tap O(N^2)");
    return 0;
}
