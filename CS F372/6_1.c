#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 5
void *PrintHello(void *threadno)
{
    long tid = (long)threadno ;
    printf("Hello world, its me, thread no %ld\n", pthread_self());
    while(1) {};
}
int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc ;
    for(long t = 0; t < NUM_THREADS; t++)
    {
        printf("In main, creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void*)t);
        if(rc)
        {
            printf("ERROR %d in pthread_create()\n", rc);
            exit(1);
        }
        // pthread_join(threads[t], NULL);
    }
    sleep(1);
}