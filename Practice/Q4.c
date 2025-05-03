#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CUSTOMERS 5

pthread_mutex_t order_lock;
sem_t chefs;

void *customer(void *arg) {
    int id = *(int *)arg;
    
    printf("Customer %d placed an order\n", id);
    sem_wait(&chefs); // Wait for a chef
    pthread_mutex_lock(&order_lock);

    printf("Chef is preparing food for customer %d\n", id);
    sleep(2); // Simulate cooking
    printf("Order for customer %d is ready\n", id);

    pthread_mutex_unlock(&order_lock);
    sem_post(&chefs);
    return NULL;
}

int main() {
    pthread_t cust_threads[NUM_CUSTOMERS];
    int ids[NUM_CUSTOMERS];

    pthread_mutex_init(&order_lock, NULL);
    sem_init(&chefs, 0, 2); // Only 2 chefs available

    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        ids[i] = i + 1;
        pthread_create(&cust_threads[i], NULL, customer, &ids[i]);
    }

    for (int i = 0; i < NUM_CUSTOMERS; i++)
        pthread_join(cust_threads[i], NULL);

    sem_destroy(&chefs);
    pthread_mutex_destroy(&order_lock);
    return 0;
}
