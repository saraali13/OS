#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

int *numbers;
int count;

typedef struct 
{
    int result;
} ThreadResult;

void* calculate_average(void* arg) 
{
    ThreadResult* res = (ThreadResult*)malloc(sizeof(ThreadResult));
    int sum = 0;
    for (int i = 0; i < count; i++) 
    {
        sum += numbers[i];
    }
    res->result = sum / count;
    pthread_exit(res);
}

void* find_max(void* arg) 
{
    ThreadResult* res = (ThreadResult*)malloc(sizeof(ThreadResult));
    int max = INT_MIN;
    for (int i = 0; i < count; i++) 
    {
        if (numbers[i] > max) max = numbers[i];
    }
    res->result = max;
    pthread_exit(res);
}

void* find_min(void* arg) 
{
    ThreadResult* res = (ThreadResult*)malloc(sizeof(ThreadResult));
    int min = INT_MAX;
    for (int i = 0; i < count; i++) 
    {
        if (numbers[i] < min) min = numbers[i];
    }
    res->result = min;
    pthread_exit(res);
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s num1 num2 ... numN\n", argv[0]);
        return 1;
    }

    count = argc - 1;
    numbers = (int*)malloc(count * sizeof(int));
    
    for (int i = 0; i < count; i++) 
    {
        numbers[i] = atoi(argv[i + 1]);
    }

    pthread_t avg_thread, max_thread, min_thread;
    ThreadResult *avg_result, *max_result, *min_result;

    pthread_create(&avg_thread, NULL, calculate_average, NULL);
    pthread_create(&max_thread, NULL, find_max, NULL);
    pthread_create(&min_thread, NULL, find_min, NULL);

    pthread_join(avg_thread, (void**)&avg_result);
    pthread_join(max_thread, (void**)&max_result);
    pthread_join(min_thread, (void**)&min_result);

    printf("Average: %d\n", avg_result->result);
    printf("Maximum: %d\n", max_result->result);
    printf("Minimum: %d\n", min_result->result);

    free(numbers);
    free(avg_result);
    free(max_result);
    free(min_result);

    return 0;
}
