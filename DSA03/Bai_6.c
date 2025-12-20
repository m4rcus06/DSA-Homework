#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

int maxProduct(int arr[], int n, int *steps, int *assignments) {
    *steps = *assignments = 1;
    int max = arr[0] * arr[1];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int prod = arr[i] * arr[j];
            (*steps)++;
            if (prod > max) {
                max = prod;
                (*assignments)++;
            }
        }
    }
}

void generateArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

#define arrSize 4
#define min 1
#define max 100
void runTest(int K) {
    int arr[arrSize];
    int freq[arrSize * arrSize] = {};
    int avgAssignments = 0;
    for (int t = 0; t < K; ++t) {
        generateArray(arr, arrSize, min, max);

        int curSteps = 0, curAssignments = 0;
        int maxProd = maxProduct(arr, arrSize, &curSteps, &curAssignments);
        freq[curAssignments]++;
        avgAssignments += curAssignments;
    }
    avgAssignments /= K;

    printf("---- Loop times = %d ----\n", K);
    printf("Average assignments = %d\n", avgAssignments);

    int maxFreq = arrSize * arrSize;
    for (int i = 0; i < maxFreq; ++i) {
        printf("freq[%d] = %d\n", i, freq[i]);
    }
}
#undef min
#undef max
#undef arrSize

int main() {
    time_t t;
    srand((unsigned)time(&t));

    int n = 4;
    int arr[] = {4, 1, 3, 2};
    int steps = 0, tmp = 0;
    int max = maxProduct(arr, n, &steps, &tmp);

    printf("max = %d\n", max);
    printf("So steps = %d\n", steps);
    printf("So steps theo tham so N = N * (N - 1) / 2\n");
    printf("So steps theo Big O: O(N ^ 2)\n");
    runTest(10000);
    return 0;
}
