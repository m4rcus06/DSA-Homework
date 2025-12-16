#include <stdio.h>

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

void insert(char s[], int *n, char c, int at) {
    if (at < 0 || at > n) return;
    for (int i = (*n) - 1; i >= at; --i) {
        s[i + 1] = s[i];
    }
    s[at] = c;
    *n += 1;
    s[*n] = '\0';
}

int main() {
    char s[1010];
    char c;
    int at;

    printf("Nhap chuoi ki tu: ");
    fgets(s, 1005, stdin);

    printf("Nhap ki tu can chen: ");
    scanf("%c", &c);

    printf("Nhap vi tri chen: ");
    scanf("%d", &at);

    int lenS = strLen(s);
    if (s[lenS - 1] == '\n') {
        s[lenS - 1] = '\0';
        lenS -= 1;
    }

    insert(s, &lenS, c, at);
    printf("%s\n", s);
    return 0;
}
