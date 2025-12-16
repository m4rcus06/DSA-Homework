#include <stdio.h>
#define LEN 10
#define MAX 105

void readInput(int *n, char s[][MAX], int *m, char t[][MAX]) {
    scanf("%d", n);
    for (int i = 0; i < *n; ++i) scanf("%s", s[i]);
    scanf("%d", m);
    for (int i = 0; i < *m; ++i) scanf("%s", t[i]);
}

void process(int n, char s[][MAX], int m, char t[][MAX], char result[][MAX]) {
    for (int i = 0; i < n; ++i) {
        int index = (s[i][0] - '0') * 10 + (s[i][1] - '0');
        for (int j = 0; j < LEN; ++j) {
            result[index][j] = s[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int index = (t[i][0] - '0') * 10 + (t[i][1] - '0');
        for (int j = 0; j < LEN; ++j) {
            result[index][j] = t[i][j];
        }
    }
}

void output(int n, char result[][105]) {
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", result[i]);
    }
}

int main() {
    int n, m;
    char s[MAX][MAX], t[MAX][MAX];

    readInput(&n, s, &m, t);

    char result[2 * MAX][MAX];
    process(n, s, m, t, result);
    output(n + m, result);
    return 0;
}
