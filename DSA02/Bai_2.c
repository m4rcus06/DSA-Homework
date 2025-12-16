#include <stdio.h>
#define MAX 1010

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void readInput(char s[], char *value) {
    scanf("%s", s);
    while(getchar() != '\n');
    scanf("%c", value);
}

int isAscending(char s[], int n) {
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] > s[i + 1]) return 0;
    }
    return 1;
}

int linearSearch(char s[], int n, char c) {
    for (int i = 0; i < n; ++i) {
        if (s[i] > c) break;
        if (s[i] == c) return i;
    }
    return -1;
}

int binarySearch(char s[], int n, char c) {
    int l = 0, r = n - 1;
    int result = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (s[mid] == c) {
            result = mid;
            r = mid - 1;
        }
        else if (s[mid] > c) r = mid - 1;
        else l = mid + 1;
    }
    return result;
}


int main() {
    char s[MAX];
    char value;

    readInput(s, &value);
    int n = strLen(s);

    if (isAscending(s, n) == 1) {
        int linearIndex = linearSearch(s, n, value);
        int bsIndex = binarySearch(s, n, value);

        if (linearIndex == bsIndex) {
            printf("Ket qua trung khop\n");
        } else {
            printf("Ket qua khong khop: Linear = %d, Binary search = %d\n", linearIndex, bsIndex);
        }
    } else {
        printf("Mang khong tang dan\n");
    }
    return 0;
}
