#include <stdio.h>
#define MAX 1010

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void readInput(char s[], int *k, char list[10][MAX]) {
    fgets(s, 1005, stdin);
    scanf("%d", k);
    while (getchar() != '\n');

    for (int i = 0; i < (*k); ++i) {
        fgets(list[i], 10, stdin);
    }
}

void normalize(char s[]) {
    int n = strLen(s);
    if (s[n - 1] == '\n') {
        n -= 1;
        s[n] = '\0';
    }
}

int findFirstIndex(int n, char s[], int m, char t[]) {
    for (int i = 0; i < n; ++i) {
        if (i + m - 1 >= n) break;

        int j = 0;
        while (j < m && s[i + j] == t[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

void deleteSubString(int *n, char s[], int startIndex, int len) {
    if (startIndex + len >= (*n)) {
        *n -= (*n) - startIndex;
        s[*n] = '\0';
        return;
    }
    for (int i = startIndex + len; i < (*n); ++i) {
        s[i - len] = s[i];
    }
    *n -= len;
    s[*n] = '\0';
}

void process(int *n, char s[], int k, char list[][MAX]) {
    int index[MAX];
    for (int i = 0; i < k; ++i) {
        int m = strLen(list[i]);

        int position = findFirstIndex(*n, s, m, list[i]);
        while (position != -1) {
            deleteSubString(n, s, position, m);
            position = findFirstIndex(*n, s, m, list[i]);
        }
    }
}

int main() {
    int k;
    char s[MAX], list[10][MAX];

    readInput(s, &k, list);
    normalize(s);
    for (int i = 0; i < k; ++i) normalize(list[i]);

    int n = strLen(s);
    process(&n, s, k, list);
    printf("%s\n", s);
    return 0;
}
