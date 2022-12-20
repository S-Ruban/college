#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem ;
int counter ;

void handler(void *ptr)
{
    int x ;
    x = *((int*)ptr);

    printf("thread %d waiting to enter CS\n", x);
    sem_wait(&sem);

    // CS starts
    printf("thread %d entered CS\n", x);
    printf("Thread %d counter value %d\n", x, counter);
    counter++ ;
    printf("Thread %d new counter value %d\n", x, counter);
    printf("Thread %d exiting CS\n", x);
    // CS ends
    sem_post(&sem);
}

int main()
{
    int i[2];
    pthread_t thread_a ;
    pthread_t thread_b ;

    i[0] = 0 ;
    i[1] = 1 ;

    sem_init(&sem, 0, 1);
    pthread_create(&thread_a, NULL, (void*)&handler, (void*)&i[0]);
    pthread_create(&thread_b, NULL, (void*)&handler, (void*)&i[1]);

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);

    sem_destroy(&sem);
    return 0 ;
}