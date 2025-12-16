#include <stdio.h>

void inputArr(double arr[], int n) {
    for (int i = 0; i < n; ++i) scanf("%lf", &arr[i]);
}

void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%lg ", arr[i]);
}

int binarySearch(double arr[], int n, double value) {
    int L = 0, R = n - 1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (arr[mid] == value) return mid;

        if (arr[mid] > value) R = mid - 1;
        else L = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    double arr[2006];
    double value;

    printf("Nhap so nguyen N: ");
    scanf("%d", &n);

    printf("Nhap %d so nguyen theo thu tu: ", n);
    inputArr(arr, n);

    printf("Nhap gia tri can tim: ");
    scanf("%lf", &value);

    int index = binarySearch(arr, n, value);
    if (index == -1) printf("Not found!");
    else printf("%d", index);

    return 0;
}
