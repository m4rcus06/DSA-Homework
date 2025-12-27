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

int isOpen(char c) {
    return (c == '(' || c == '{' || c == '[');
}

int isClose(char c) {
    return (c == ')' || c == '}' || c == ']');
}

char getMatch(char c) {
    if (isOpen(c) == 0) return '\0';
    if (c == '(') return ')';
    if (c == '[') return ']';
    return '}';
}

void process(char str[], int n) {
    stack st;
    init(&st);

    int index = 0;
    int errorIndex[MAX];
    for (int i = 0; i < n; ++i) {
        if (isOpen(str[i]) == 1) {
            push(&st, str[i]);
        } else if (isClose(str[i]) == 1) {
            char lastOp = pop(&st);
            if (str[i] != getMatch(lastOp)) {
                errorIndex[index] = i;
                str[i] = getMatch(lastOp);
                index++;
            }
        }
    }

    if (index == 0) {
        printf("No error.");
        return;
    }

    printf("Error at:");
    for (int i = 0; i < index; ++i) {
        if (i > 0) printf(",");
        printf(" %d", errorIndex[i]);
    }
    printf("\n%s\n", str);
}

int main() {
    char str[MAX];
    fgets(str, 1000, stdin);

    int n = strLen(str);
    if (str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n -= 1;
    }

    process(str, n);
    return 0;
}
