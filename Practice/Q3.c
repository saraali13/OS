#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int balance = 1000;
pthread_mutex_t lock;

void *teller(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 3; i++) {
        pthread_mutex_lock(&lock);
        int trans = (rand() % 200) - 100; // Deposit or Withdraw
        balance += trans;
        printf("Teller %d processed: %d. New balance: %d\n", id, trans, balance);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tellers[3];
    int ids[3] = {1, 2, 3};
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&tellers[i], NULL, teller, &ids[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(tellers[i], NULL);

    pthread_mutex_destroy(&lock);
    printf("Final balance: %d\n", balance);
    return 0;
}
