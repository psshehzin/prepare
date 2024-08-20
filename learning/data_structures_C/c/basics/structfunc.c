#include <stdio.h>

struct Point {
    int x;
    int y;
};

void printPoint(struct Point *p) {
    printf("Point: (%d, %d)\n", p->x, p->y);
}

int main() {
    struct Point myPoint = {3, 4};
    printPoint(&myPoint);
    return 0;
}

// #include <stdio.h>

// struct Point {
//     int x;
//     int y;
// };

// void printPoint(struct Point p) {
//     printf("Point: (%d, %d)\n", p.x, p.y);
// }

// int main() {
//     struct Point myPoint = {3, 4};
//     printPoint(myPoint);
//     return 0;
// }