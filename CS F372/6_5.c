#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

clock_t s1, e1, s2, e2 ;
double lockt = 0.0, unlockt = 0.0 ;

#define N 10000

int sum = 0 ;
int inc = 5 ;

pthread_mutex_t lock ;

void *fun(void *cal)
{
    s1 = clock();
    pthread_mutex_lock(&lock);
    e1 = clock();
    lockt += (double)(e1-s1)/(double)(CLOCKS_PER_SEC);
    // critical section start
    sum += inc ;
    // printf("Value %d\n", sum);
    inc += 5 ;
    s2 = clock();
    pthread_mutex_unlock(&lock);
    e2 = clock();
    unlockt+= (double)(e2-s2)/(double)(CLOCKS_PER_SEC);
    // critical section end

    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t t[N];
    int errcode ;

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < N; i++)
    {
        if(pthread_create(&t[i], NULL, fun, NULL)){
            printf("Error creating thread\n");
            exit(0);
        }
    }
    for(int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("\n\n%lf %lf", lockt/N, unlockt/N);
    execlp("ls", "ls", "-lrtai", NULL);
}