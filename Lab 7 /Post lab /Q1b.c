#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREADS 10

float A[SIZE], B[SIZE], C[SIZE];

typedef struct {
    int start, end;
} ThreadArgs;

void* threaded_addition(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    for (int i = args->start; i < args->end; i++) {
        C[i] = A[i] + B[i];
    }
    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    ThreadArgs args[THREADS];
    int chunk = SIZE / THREADS;

    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
    }

    for (int i = 0; i < THREADS; i++) {
        args[i].start = i * chunk;
        args[i].end = (i == THREADS - 1) ? SIZE : (i + 1) * chunk;
        pthread_create(&threads[i], NULL, threaded_addition, &args[i]);
    }

    for (int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("Parallel Addition: C[0] = %.1f, C[%d] = %.1f\n", C[0], SIZE - 1, C[SIZE - 1]);
    return 0;
}
