#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isAscending(int n, int *comps) {
    int lastDigit = n % 10;
    n /= 10;
    while (n > 0) {
        int curDigit = n % 10;
        n /= 10;
        (*comps)++;
        if (curDigit > lastDigit) return 0;
        lastDigit = curDigit;
    }
    return 1;
}

int main() {
    int avgComps = 0;
    for (int i = 1000; i <= 9999; ++i) {
        isAscending(i, &avgComps);
    }
    avgComps /= (9999 - 1000 + 1);

    printf("So phep so sanh trung binh: %d\n", avgComps);
    return 0;
}
