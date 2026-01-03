#include <stdio.h>

// 1 + 1/2 + 1/3 + ... + 1/n
float S1(int n) {
    if (n == 1) return 1;
    return (1.0 / (float) n) + S1(n - 1);
}

// 1/2 + 1/4 + ... + 1/2n
float S2(int n) {
    if (n == 1) return 1.0 / 2.0;
    return 1.0 / (2.0 * n) + S2(n - 1);
}

// 1/2 + 2/3 + ... + n / n+1
float S3(int n) {
    if (n == 1) return 1.0 / 2.0;
    return ((float) n / (float) (n + 1)) + S3(n - 1);
}

/*
    f(0) = 2
    f(1) = 3
    f(n) = 6f(n-1) - 9f(n - 2)
*/
int f(int n) {
    if (n == 0) return 2;
    if (n == 1) return 3;
    return 6 * f(n - 1) - 9 * f(n - 2);
}

int main() {
    return 0;
}
