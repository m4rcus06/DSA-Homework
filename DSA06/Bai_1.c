#include <stdio.h>
#define MAX 1010

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

typedef struct {
    char a[MAX];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

int isFull(stack *s) {
    if (s->top == MAX - 1) return 1;
    return 0;
}

int isEmpty(stack *s) {
    if (s->top == -1) return 1;
    return 0;
}

void push(stack *s, char c) {
    if (isFull(s) == 1) return;
    s->top += 1;
    s->a[s->top] = c;
}

char pop(stack *s) {
    if (isEmpty(s)) return '\0';
    char ret = s->a[s->top];
    s->top -= 1;
    return ret;
}

void swap(char *a, char *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void arrayProcess(char str[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        swap(str + i, str + n - i - 1);
    }
}

void stackProcess(char str[], int n) {
    stack st;
    init(&st);
    for (int i = 0; i < n; ++i) {
        push(&st, str[i]);
    }

    int index = 0;
    while (isEmpty(&st) == 0) {
        str[index++] = pop(&st);
    }
}

void copy(char from[], char to[], int n) {
    for (int i = 0; i < n; ++i) to[i] = from[i];
    to[n] = '\0';
}

int main() {
    char str[MAX];
    fgets(str, 1000, stdin);

    int n = strLen(str);
    if (str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n -= 1;
    }

    char s1[MAX], s2[MAX];
    copy(str, s1, n);
    copy(str, s2, n);

    arrayProcess(s1, n);
    stackProcess(s2, n);

    printf("Using array: %s\n", s1);
    printf("Using stack: %s\n", s2);
    return 0;
}
