#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define N 5
int sum = 0 ;
void *addNum(void *val)
{
    int *n = (int*)val ;
    sum += *n ;
    return NULL ;
}
int main(int argc, char *argv[])
{
    pthread_t threads[N];
    int data[N];
    int rc ;
    for(long t = 0; t < N; t++)
    {
        data[t] = atoi(argv[t+1]);
        printf("In main, creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, addNum, (void*)&data[t]);
        if(rc)
        {
            printf("ERROR %d in pthread_create()\n", rc);
            exit(1);
        }
        // pthread_join(threads[t], NULL);
    }
    for(long t = 0; t < N; t++)
        pthread_join(threads[t], NULL);
    printf("Sum %d\n", sum);
}