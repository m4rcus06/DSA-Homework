#include <stdio.h>
#define MAX 1010

typedef struct {
    double x, y;
} Point;

void readInput(int *n, Point p[], Point *req) {
    scanf("%d", n);
    for (int i = 0; i < (*n); ++i) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    scanf("%lf%lf", &req->x, &req->y);
}

int findPoint(int n, Point p[], Point need) {
    for (int i = 0; i < n; ++i) {
        if (p[i].x == need.x && p[i].y == need.y) return i;
    }
    return -1;
}

void deleteAt(int *n, Point p[], int at) {
    for (int i = at + 1; i < (*n); ++i) {
        p[i - 1] = p[i];
    }
    (*n) -= 1;
}

void outputArr(int n, Point p[]) {
    for (int i = 0; i < n; ++i) {
        printf("%lg %lg\n", p[i].x, p[i].y);
    }
}

int main() {
    int n;
    Point p[MAX];
    Point req;
    readInput(&n, p, &req);
    printf("\n");

    int index = findPoint(n, p, req);
    if (index != -1) {
        deleteAt(&n, p, index);
        outputArr(n, p);
        printf("Delete %lg %lg at %d\n", req.x, req.y, index);
    } else {
        printf("Can not delete %lg %lg from the array!\n", req.x, req.y);
    }
    return 0;
}
