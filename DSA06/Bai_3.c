#include <stdio.h>
#define MAX 1010

int strLen(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

#define MAKE_STACK(Type, GARBAGE)               \
typedef struct {                                \
    Type a[MAX];                                \
    int top;                                    \
} stack_##Type;                                 \
                                                \
void init_##Type(stack_##Type *s) {             \
    s->top = -1;                                \
}                                               \
                                                \
int isFull_##Type(stack_##Type *s) {            \
    if (s->top == MAX - 1) return 1;            \
    return 0;                                   \
}                                               \
                                                \
int isEmpty_##Type(stack_##Type *s) {           \
    if (s->top == -1) return 1;                 \
    return 0;                                   \
}                                               \
                                                \
void push_##Type(stack_##Type *s, Type c) {     \
    if (isFull_##Type(s) == 1) return;          \
    s->top += 1;                                \
    s->a[s->top] = c;                           \
}                                               \
                                                \
Type top_##Type(stack_##Type *s) {              \
    if (isEmpty_##Type(s)) return GARBAGE;      \
    return s->a[s->top];                        \
}                                               \
                                                \
Type pop_##Type(stack_##Type *s) {              \
    if (isEmpty_##Type(s)) return GARBAGE;      \
    Type ret = s->a[s->top];                    \
    s->top -= 1;                                \
    return ret;                                 \
}

MAKE_STACK(char, '\0')
MAKE_STACK(double, 0)

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int opsValue(char c) {
    if (c == '-' || c == '+') return 0;
    // *, /
    return 1;
}

void makePostfix(char str[], int n, char out[]) {
    stack_char st;
    init_char(&st);

    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (isDigit(str[i]) == 1) {
            out[index++] = str[i];
        } else {
            while (isEmpty_char(&st) == 0 && opsValue(top_char(&st)) >= opsValue(str[i])) {
                out[index++] = pop_char(&st);
            }
            push_char(&st, str[i]);
        }
    }
    while (isEmpty_char(&st) == 0) {
        out[index++] = pop_char(&st);
    }
}

double calc(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
}

double calculatePostfix(char str[], int n) {
    double sum = 0;
    stack_double st;
    init_double(&st);

    for (int i = 0; i < n; ++i) {
        if (isDigit(str[i])) {
            double value = (str[i] - '0');
            push_double(&st, value);
        } else {
            double y = pop_double(&st);
            double x = pop_double(&st);
            double value = calc(x, y, str[i]);
            push_double(&st, value);
        }
    }

    double total = pop_double(&st);
    return total;
}

int main() {
    char str[MAX];
    fgets(str, 1000, stdin);

    int n = strLen(str);
    if (str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n -= 1;
    }

    char postfix[MAX];
    makePostfix(str, n, postfix);
    double ans = calculatePostfix(postfix, n);

    printf("%s\n", postfix);
    printf("Result = %g\n", ans);
    return 0;
}
