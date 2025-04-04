#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables to store results
double average;
int minimum, maximum;

// Structure to pass arguments to threads
typedef struct {
    int *arr;
    int size;
} ThreadData;

// Function to compute the average
void *compute_average(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    double sum = 0;
    for (int i = 0; i < data->size; i++)
        sum += data->arr[i];
    average = sum / data->size;
    pthread_exit(NULL);
}

// Function to compute the maximum
void *compute_maximum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    maximum = data->arr[0];
    for (int i = 1; i < data->size; i++)
        if (data->arr[i] > maximum)
            maximum = data->arr[i];
    pthread_exit(NULL);
}

// Function to compute the minimum
void *compute_minimum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    minimum = data->arr[0];
    for (int i = 1; i < data->size; i++)
        if (data->arr[i] < minimum)
            minimum = data->arr[i];
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <list of numbers>\n", argv[0]);
        return 1;
    }

    int size = argc - 1;
    int numbers[size];

    // Convert command-line arguments to integers
    for (int i = 0; i < size; i++)
        numbers[i] = atoi(argv[i + 1]);

    pthread_t threads[3];
    ThreadData data = {numbers, size};

    // Create threads
    pthread_create(&threads[0], NULL, compute_average, &data);
    pthread_create(&threads[1], NULL, compute_maximum, &data);
    pthread_create(&threads[2], NULL, compute_minimum, &data);

    // Wait for threads to finish
    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    // Print results
    printf("The average value is %.2f\n", average);
    printf("The maximum value is %d\n", maximum);
    printf("The minimum value is %d\n", minimum);

    return 0;
}
