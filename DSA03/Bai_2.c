#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

void swap(float *a, float *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(float arr[], int n, int *comps) {
    *comps = 0;
    for (int i = 0; i < n; ++i) {
        int index = i;
        for (int j = i + 1; j < n; ++j) {
            (*comps)++;
            if (arr[j] < arr[index]) index = j;
        }
        swap(&arr[i], &arr[index]);
    }
}

void generateArray(int n, float arr[], int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void process(int arrSize, float arr[], int loopTimes) {
    int avgComps = 0;
    for (int t = 0; t < loopTimes; ++t) {
        generateArray(arrSize, arr, 0, 10);

        int curComps = 0;
        sort(arr, arrSize, &curComps);
        avgComps += curComps;
    }
    avgComps /= loopTimes;

    printf("---- Loop times = %d ----\n", loopTimes);
    printf("Average comps: %d\n", avgComps);
}

int main() {
    int n;
    float arr[MAX];

    process(40, arr, 100000);
    printf("Thuat toan co do phuc tap O(N^2)\n");
    return 0;
}
