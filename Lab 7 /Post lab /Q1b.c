#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREADS 10

float *A, *B, *C;

typedef struct 
{
    int start, end;
} ThreadData;

void* add_arrays(void* arg) 
{
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->start; i < data->end; i++) 
    {
        C[i] = A[i] + B[i];
    }
    pthread_exit(NULL);
}

int main() 
{
    A = (float*)malloc(SIZE * sizeof(float));
    B = (float*)malloc(SIZE * sizeof(float));
    C = (float*)malloc(SIZE * sizeof(float));

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) 
    {
        A[i] = i * 1.0f;
        B[i] = (SIZE - i) * 1.0f;
    }

    pthread_t threads[THREADS];
    ThreadData thread_data[THREADS];
    int chunk_size = SIZE / THREADS;

    // Create threads
    for (int i = 0; i < THREADS; i++) 
    {
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == THREADS - 1) ? SIZE : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, add_arrays, &thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    printf("First 5 results: %.2f, %.2f, %.2f, %.2f, %.2f\n", C[0], C[1], C[2], C[3], C[4]);

    free(A);
    free(B);
    free(C);

    return 0;
}
