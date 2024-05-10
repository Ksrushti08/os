#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define buffer_size 5

int in = 0;
int out = 0;
int buff[buffer_size];

sem_t s, f, e;

void *producer(void *arg) {
    int data;
    sem_wait(&e);
    printf("Thread id of producer is %ld\n", pthread_self());
    data = rand() % 100 + 1;
    buff[in] = data;
    printf("Producer produced data %d at index %d\n", data, in);
    in = (in + 1) % buffer_size;
    sem_post(&s);
    sem_post(&f);
    return NULL;
}

void *consumer(void *arg) {
    int data, var;
    do {
        sem_wait(&f);
        sem_wait(&s);
        data = buff[out];
        printf("Thread id of consumer is %ld\n", pthread_self());
        printf("Consumer consumed data %d at index %d\n", data, out);
        out = (out + 1) % buffer_size;
        sem_post(&s);
        sem_post(&e);
        sem_getvalue(&e, &var);
    } while (var != buffer_size);
    return NULL;
}

int main() {
    sem_init(&e, 0, buffer_size);
    sem_init(&f, 0, 0);
    sem_init(&s, 0, 1);

    pthread_t tid[buffer_size], ctid;

    for (int i = 0; i < buffer_size; i++) {
        pthread_create(&tid[i], NULL, producer, NULL);
    }

    pthread_create(&ctid, NULL, consumer, NULL);

    for (int i = 0; i < buffer_size; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_join(ctid, NULL);

    return 0;
}
