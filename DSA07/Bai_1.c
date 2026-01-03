#include <stdio.h>

int sum(int a[], int n) {
    if (n == 1) return a[0];
    return a[n - 1] + sum(a, n - 1);
}

/*
    1. Base case: n = 1.
    2. sum(a, 1) = a[0]
    3. Before base case: sum(a, 2) = a[1] + sum(a, 1) = a[1] + a[0]
    4. Before and before: sum(a, 3) = a[2] + sum(a, 2) = a[2] + a[1] + a[0]
*/

int main() {
    int n = 4;
    int a[] = {1, 2, 3, 4};
    printf("sum(a, %d) = %d\n", n, sum(a, 4));
    return 0;
}
