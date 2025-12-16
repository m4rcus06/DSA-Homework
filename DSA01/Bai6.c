#include <stdio.h>

void readInput(int *n, double arr[], int *numIns, double insValue[], int insIndex[]) {
    scanf("%d", n);
    for (int i = 0; i < (*n); ++i) scanf("%lf", &arr[i]);

    scanf("%d", numIns);
    for (int i = 0; i < (*numIns); ++i) {
        scanf("%lf%d", &insValue[i], &insIndex[i]);
    }
}

void copy(double from[], double to[], int n) {
    for (int i = 0; i < n; ++i) {
        to[i] = from[i];
    }
}

void insert(int *n, double arr[], int numIns, double insValue[], int insIndex[]) {
    int has[1005] = {};
    double value[1005];
    for (int i = 0; i < numIns; ++i) {
        int index = insIndex[i];
        has[index] = 1;
        value[index] = insValue[i];
    }

    double n_arr[2006];
    int count = 0;
    for (int i = 0; i <= (*n); ++i) {
        if (has[i] == 1) {
            n_arr[i + count] = value[i];
            count++;
        }
        n_arr[i + count] = arr[i];
    }
    (*n) += count;
    copy(n_arr, arr, *n);
}

void outputArr(int n, double arr[]) {
    for (int i = 0; i < n; ++i) {
        printf("%lg ", arr[i]);
    }
}

int main() {
    int n, numIns;
    double arr[2006], insValue[1005];
    int insIndex[1001];
    readInput(&n, arr, &numIns, insValue, insIndex);

    insert(&n, arr, numIns, insValue, insIndex);
    outputArr(n, arr);
    return 0;
}
