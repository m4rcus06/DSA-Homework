#include <stdio.h>

void copy(char from[], char to[], int m) {
    for (int i = 0; i < m; ++i) {
        to[i] = from[i];
    }
}

void insert(char s[][105], int *n, int m, char t[], int at) {
    for (int i = (*n) - 1; i >= at; --i) {
        copy(s[i], s[i + 1], m);
    }
    copy(t, s[at], m);
    *n += 1;
}

void readArr(int n, char s[][105]) {
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
}

int main() {
    int n, m, at;
    char s[105][105];
    char t[105];
    scanf("%d%d", &n, &m);

    readArr(n, s);

    scanf("%d", &at);
    scanf("%s", t);

    insert(s, &n, m, t, at);
    for (int i = 0; i < n; ++i) printf("%s ", s[i]);
    return 0;
}
