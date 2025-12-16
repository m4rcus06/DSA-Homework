#include <stdio.h>

void inputArr(double arr[], int n) {
    for (int i = 0; i < n; ++i) scanf("%lf", &arr[i]);
}

void outputArr(double arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%lg ", arr[i]);
}

int orderedLinearSearch(double arr[], int n, double value) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value) return i;
        else if (arr[i] > value) return -1;
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

    int index = orderedLinearSearch(arr, n, value);
    if (index == -1) printf("Not found!");
    else printf("%d", index);

    return 0;
}
