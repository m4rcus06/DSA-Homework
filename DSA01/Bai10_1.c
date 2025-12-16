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

int check(int n, char s[], int m, char t[], int index[]) {
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

void process(int n, char s[], int k, char list[][MAX]) {
    int index[MAX];
    for (int i = 0; i < k; ++i) {
        int m = strLen(list[i]);
        int cnt = check(n, s, m, list[i], index);

        printf("%d %s ", cnt, list[i]);
        for (int j = 0; j < cnt; ++j) {
            printf("%d", index[j]);
            if (j + 1 < cnt) printf(", ");
        }
        printf("\n");
    }
}

int main() {
    int k;
    char s[MAX], list[10][MAX];

    readInput(s, &k, list);
    normalize(s);
    for (int i = 0; i < k; ++i) normalize(list[i]);

    int n = strLen(s);
    process(n, s, k, list);
    return 0;
}
