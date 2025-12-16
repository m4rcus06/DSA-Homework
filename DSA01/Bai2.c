#include <stdio.h>

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return c;
}

void normalize(char s[], int len) {
    for (int i = 0; i < len; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = toLower(s[i]);
        }
    }
}

int findChar(char s[], int len, char c) {
    int index = 0;
    while (index < len && s[index] != toLower(c)) index++;
    return index;
}

int main() {
    char s[1024];
    char c;

    printf("Nhap chuoi s: ");
    fgets(s, 1005, stdin);

    printf("Nhap ki tu can tim: ");
    scanf("%c", &c);

    int len = strLen(s);
    if (s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len -= 1;
    }
    normalize(s, len);

    int index = findChar(s, len, c);
    if (index < len) {
        printf("Found %c at %d\n", c, index);
    } else {
        printf("Not Found!\n");
    }
    return 0;
}
