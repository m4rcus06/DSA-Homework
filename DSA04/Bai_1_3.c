#include <stdio.h>

typedef struct {
    int x, y, z;
} triples;

void swap(triples *a, triples *b) {
    triples tmp = *a;
    *a = *b;
    *b = tmp;
}

int F(triples A) {
    return A.x - 2*A.y + 3*A.z;
}

void bubbleSort(triples arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (F(arr[j - 1]) > F(arr[j])) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

int main() {
    int n;
    triples A[1010];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("A[%d] = ", i);
        scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].z);
    }

    bubbleSort(A, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; ++i) {
        printf("A[%d] = {%d, %d, %d}, F(A[%d]) = %d\n", i, A[i].x, A[i].y, A[i].z, i, F(A[i]));

    }
    return 0;
}
