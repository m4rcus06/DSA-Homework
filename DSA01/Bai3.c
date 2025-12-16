#include <stdio.h>

char S[1001][1001];
char T[1001];

void clear() {
    while (getchar() != '\n');
}

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int match(char s[], int k, char t[], int lenT) {
    if (k != lenT) return 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] != t[i]) return 0;
    }
    return 1;
}

int findIndex(char s[][1001], int n, int k, char t[], int lenT) {
    for (int i = 0; i < n; ++i) {
        if (match(s[i], k, t, lenT) == 1) return i;
    }
    return -1;
}

void readArr(int n, char s[][1001]) {
    printf("Nhap mang serial key:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
}

int main() {
    int n, k;
    printf("Nhap n: ");
    scanf("%d", &n);

    printf("Nhap k: ");
    scanf("%d", &k);

    readArr(n, S);

    printf("Nhap chuoi can tim: ");
    scanf("%s", T);
    int lenT = strLen(T);

    int index = findIndex(S, n, k, T, lenT);
    if (index != -1) {
        printf("Found %s at %d\n", S[index], index);
    } else {
        printf("Not Found!\n");
    }
    return 0;
}
