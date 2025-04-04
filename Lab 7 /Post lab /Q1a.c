#include <stdio.h>

#define SIZE 10000000
float A[SIZE], B[SIZE], C[SIZE];

int main() {
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
    }

    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Serial Addition: C[0] = %.1f, C[%d] = %.1f\n", C[0], SIZE - 1, C[SIZE - 1]);
    return 0;
}
