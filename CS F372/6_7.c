#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define N 5
pthread_mutex_t mutex ;
sem_t empty, full ;
int in = 0, out = 0 ;
int buffer[N];
int a[3] = {1,2,3};
void *producer(void *pno)
{
    int item ;
    for(int i = 0; i < N; i++)
    {
        item = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item ;
        printf("Producer %d: Inserting item %d at location %d\n", *((int*)pno), buffer[in], in);
        in = (in+1)%N ;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *pno)
{
    for(int i = 0; i < N; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Reading item %d from location %d\n", *((int*)pno), item, out);
        out = (out+1)%N ;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main()
{
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    srand(time(NULL));
    pthread_t prod[3], cons[3];
    pthread_mutex_init(&mutex, NULL);
    for(int i  = 0; i < 3; i++)
    {
        pthread_create(&prod[i], NULL, (void*)producer, (void*)&a[i]);
        pthread_create(&prod[i], NULL, (void*)consumer, (void*)&a[i]);
    }
    for(int i = 0; i < 3; i++)
        pthread_join(prod[i], NULL);
    for(int i = 0; i < 3; i++)
        pthread_join(cons[i], NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}