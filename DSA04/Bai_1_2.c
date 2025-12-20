#include <stdio.h>

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

int main() {
    int n;
    char s[1010];

    scanf("%d", &n);
    while(getchar() != '\n');
    scanf("%s", s);

    bubbleSort(s, n);

    printf("Sorted string:\n");
    printf("%s", s);
    return 0;
}
