#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter A: ");
    if (scanf("%d", &a) != 1) return 1;
    printf("Enter B: ");
    if (scanf("%d", &b) != 1) return 1;

    printf("A + B = %d\n", a + b);
    printf("A - B = %d\n", a - b);
    printf("A * B = %d\n", a * b);

    if (b != 0) {
        printf("A / B = %d\n", a / b); // integer division
        printf("A %% B = %d\n", a % b);
    }
    else {
        printf("A / B = undefined (division by zero)\n");
        printf("A %% B = undefined (modulo by zero)\n");
    }

    return 0;
}