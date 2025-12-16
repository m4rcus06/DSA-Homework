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

int listPosition(int n, char s[], int m, char t[], int index[]) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i + m - 1 >= n) break;

        int j = 0;
        while (j < m && s[i + j] == t[j]) j++;
        if (j == m) {
            index[cnt++] = i;
        }
    }
    return cnt;
}

void copy(char from[], char to[], int n) {
    for (int i = 0; i < n; ++i) to[i] = from[i];
    to[n] = '\0';
}

void process(int *n, char s[], int k, char list[][MAX]) {
    int has[MAX] = {};
    int index[MAX];

    for (int i = 0; i < k; ++i) {
        int m = strLen(list[i]);
        int numPositions = listPosition(*n, s, m, list[i], index);
        if (numPositions == 0) continue;

        for (int j = 0; j < numPositions; ++j) {
            int start = index[j];
            int end = index[j] + m;
            for (int k = start; k < end; ++k) has[k] = 1;
        }
    }

    char new_s[2 * MAX];
    int new_n = 0;
    for (int i = 0; i < (*n); ++i) {
        new_s[new_n++] = s[i];
        if (has[i] == 1) {
            char c = s[i] + 1;
            new_s[new_n++] = c;
        }
    }
    copy(new_s, s, new_n);
    *n = new_n;
}

int main() {
    int k;
    char s[2 * MAX], list[10][MAX];

    readInput(s, &k, list);
    normalize(s);
    for (int i = 0; i < k; ++i) normalize(list[i]);

    int n = strLen(s);
    process(&n, s, k, list);
    printf("%s\n", s);
    return 0;
}
