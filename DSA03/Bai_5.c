#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1010

int negativeSum(int arr[], int n, int *count) {
    *count = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
            (*count)++;
        }
    }
    return sum;
}

void generateArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int main() {
    int n;
    int arr[MAX];

    time_t t;
    srand((unsigned)time(&t));

    int freq[11] = {};
    n = 10;
    for (int t = 0; t < 1000; ++t) {
        generateArray(arr, n, -100, 100);

        int curCount = 0;
        int sum = negativeSum(arr, n, &curCount);
        freq[curCount]++;
    }

    printf("---- Tan suat ----\n");
    for (int i = 0; i <= 10; ++i) {
        printf("freq[%d] = %d\n", i, freq[i]);
    }
    return 0;
}

/*
---- Tan suat ----
freq[0] = 0
freq[1] = 12
freq[2] = 57
freq[3] = 99
freq[4] = 223
freq[5] = 244
freq[6] = 198
freq[7] = 108
freq[8] = 46
freq[9] = 11
freq[10] = 2
*/
