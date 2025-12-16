#include <stdio.h>
#define MAX 1010

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void readInput(char s[], int *at) {
    fgets(s, 1000, stdin);
    scanf("%d", at);
}

void deleteAt(char s[], int *n, int at) {
    for (int i = at + 1; i < *n; ++i) {
        s[i - 1] = s[i];
    }
    (*n) -= 1;
    s[*n] = '\0';
}

int main() {
    char s[MAX];
    int at;
    readInput(s, &at);

    int n = strLen(s);
    if (s[n - 1] == '\n') {
        n -= 1;
        s[n] = '\0';
    }

    deleteAt(s, &n, at);
    printf("%s\n", s);
    return 0;
}
