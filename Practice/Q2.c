#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10
int arr[SIZE] = {9, 5, 2, 4, 8, 1, 3, 7, 6, 0};

void *sort_first_half(void *arg) {
    for (int i = 0; i < SIZE/2 - 1; i++)
        for (int j = 0; j < SIZE/2 - i - 1; j++)
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
            }
    pthread_exit(NULL);
}

void *sort_second_half(void *arg) {
    for (int i = SIZE/2; i < SIZE-1; i++)
        for (int j = SIZE/2; j < SIZE - 1 - (i - SIZE/2); j++)
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
            }
    pthread_exit(NULL);
}

void merge() {
    int temp[SIZE];
    int i = 0, j = SIZE/2, k = 0;
    while (i < SIZE/2 && j < SIZE)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while (i < SIZE/2) temp[k++] = arr[i++];
    while (j < SIZE) temp[k++] = arr[j++];
    for (int l = 0; l < SIZE; l++) arr[l] = temp[l];
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, sort_first_half, NULL);
    pthread_create(&t2, NULL, sort_second_half, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    merge();

    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
