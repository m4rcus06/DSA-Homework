#include <stdio.h>
#define MAX 30

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void readInput(char s[]) {
    scanf("%s", s);
}

int binarySearch(int n, char s[]) {
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        char c = 'a' + mid;
        if (s[mid] == c) l = mid;
        else r = mid;
    }
    return r;
}

void fillMissing(int *n, char s[], int index) {
    char missingChar = 'a' + index;
    for (int i = (*n) - 1; i >= index; --i) s[i + 1] = s[i];
    s[index] = missingChar;
    *n += 1;
    s[*n] = '\0';
}

int main() {
    char s[MAX];
    readInput(s);

    int n = strLen(s);
    int missingIndex = binarySearch(n, s);
    char missingChar = 'a' + missingIndex;
    printf("%c at %d is missing!\n", missingChar, missingIndex);

    fillMissing(&n, s, missingIndex);
    printf("%s\n", s);

    return 0;
}
