#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

void readInput(int *n, float arr[]) {
    scanf("%d", n);
    for (int i = 0; i < (*n); ++i) scanf("%f", &arr[i]);
}

int minIndex(float arr[], int n, int *comps) {
    *comps = 0;
    int index = 0;
    for (int i = 1; i < n; ++i) {
        (*comps)++;
        if (arr[i] < arr[index]) index = i;
    }
    return index;
}

void generateArray(int n, float arr[], int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void makeTable(int arrSize, float arr[], int loopTimes) {
    int avgComps = 0;
    int freq[MAX] = {};
    for (int t = 0; t < loopTimes; ++t) {
        generateArray(arrSize, arr, -2 * arrSize, 2 * arrSize);

        int curComps = 0;
        int index = minIndex(arr, arrSize, &curComps);
        freq[curComps]++;
        avgComps += curComps;
    }
    avgComps /= loopTimes;

    printf("---- K = %d ----\n", loopTimes);
    printf("Average comps: %d\n", avgComps);
    for (int i = 0; i <= 10; ++i) {
        printf("comps = %d, \t count = %d\n", i, freq[i]);
    }
}

int main() {
    int n;
    float arr[MAX];

    time_t t;
    srand((unsigned)time(&t));

    makeTable(10, arr, 100);
    makeTable(10, arr, 1000);
    return 0;
}
