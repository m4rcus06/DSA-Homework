#include <stdio.h>

void inputArr(double arr[], int n) {
    printf("Nhap %d so thuc: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i]);
    }
}

double myabs(double x) {
    if (x < 0) x = -x;
    return x;
}

int findNearest(double arr[], int n, int m) {
    int index = 0;
    double minDist = myabs(arr[0] - m);
    for (int i = 1; i < n; ++i) {
        double dist = myabs(arr[i] - m);
        if (minDist > dist) {
            index = i;
            minDist = dist;
        }
    }
    return index;
}

int main() {
    int n;
    int m;
    double arr[1001];
    printf("Nhap n: ");
    scanf("%d", &n);
    inputArr(arr, n);

    printf("Nhap m: ");
    scanf("%d", &m);

    int index = findNearest(arr, n, m);
    printf("%lg at index %d nearest to %d", arr[index], index, m);
    return 0;
}
