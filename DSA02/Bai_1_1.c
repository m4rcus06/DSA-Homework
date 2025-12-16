#include <stdio.h>

int findFirstGeq(double arr[], int n, double value) {
    int result = n;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= value) {
            result = i;
            break;
        }
    }
    return result;
}

void insertOrderedArray(double arr[], int *n, double value) {
    int insertPos = findFirstGeq(arr, *n, value);
    if (insertPos == *n) {
        arr[*n] = value;
        *n += 1;
        return;
    }

    for (int i = *n - 1; i >= insertPos; --i) {
        arr[i + 1] = arr[i];
    }
    arr[insertPos] = value;
    *n += 1;
}

void inputArr(double arr[], int n) {
    for (int i = 0; i < n; ++i) scanf("%lf", &arr[i]);
}

void outputArr(double arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%lg ", arr[i]);
}

int main() {
    int n;
    double arr[2006];
    double value;

    printf("Nhap so nguyen N: ");
    scanf("%d", &n);

    printf("Nhap %d so nguyen theo thu tu: ", n);
    inputArr(arr, n);

    printf("Nhap gia tri can chen: ");
    scanf("%lf", &value);

    insertOrderedArray(arr, &n, value);

    printf("Mang sau khi chen: ");
    outputArr(arr, n);
    return 0;
}
