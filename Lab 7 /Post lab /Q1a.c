#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main() 
{
    float *A = (float*)malloc(SIZE * sizeof(float));
    float *B = (float*)malloc(SIZE * sizeof(float));
    float *C = (float*)malloc(SIZE * sizeof(float));

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) 
    {
        A[i] = i * 1.0f;
        B[i] = (SIZE - i) * 1.0f;
    }

    // Perform C = A + B
    for (int i = 0; i < SIZE; i++) 
    {
        C[i] = A[i] + B[i];
    }

    printf("First 5 results: %.2f, %.2f, %.2f, %.2f, %.2f\n", C[0], C[1], C[2], C[3], C[4]);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
