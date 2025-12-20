#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f(int a[], int n, int *shifts, int *assignments) {
    for (int d = n/2; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            int t = a[i];
            (*assignments)++;
            int j;
            for (j = i; j >=d && a[j-d] > t; j -= d) {
                (*assignments)++;
                (*shifts)++;
                a[j] = a[j-d];
            }
            (*assignments)++;
            a[j] = t;
        }
    }
}

int main() {
    int a[] = {34, 29, 10, 3, 2, 44, 88, 1, 21, 12, 3, 18, 21, 23, 37, 17, 8, 9, 4, 0};
    int n = 20;
    int shifts = 0, assignments = 0;
    f(a,n, &shifts, &assignments);

    printf("So phep gan: %d\n", assignments);
    printf("So phep dich chuyen: %d\n", shifts);
    return 0;
}
